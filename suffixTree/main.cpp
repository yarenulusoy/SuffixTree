//190201069
//200201128
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <graphics.h>
void menu();
void agac();
int agacOlustur(int x,int y,int index,int total,char *kelime,int sayi);
void islem(int sec);
char kelimeKontrol(char kelime[100]);
char harfkontrol(char gec[100],int a);
void sonekmi(char girilenkelime[100]);
int onekmi(char *onek,char *sonek);
void altkatar(char girilenkelime[100]);
int enuzuntekrar(char girilenkelime[100]);
int encoktekrar(char girilenkelime[100]);
int max(int num1, int num2);


void menu()
{
    int sec;
    while (1)
    {
           printf("\n--- PROBLEMLER---\n\n1-s katari icin sonek agaci olusturulabilir mi?\n2-Sonek agaci olusturulan bir s katari icinde p katari geciyor mu, geciyorsa ilk bulundugu yerin baslangic pozisyonu nedir, kac kez tekrar etmektedir?\n3-Sonek agaci olusturulan bir s katari icinde tekrar eden en uzun altkatar nedir, kac kez tekrar etmektedir?\n4-Sonek agaci olusturulan bir s katari icinde en cok tekrar eden altkatar nedir, kac kez tekrar etmektedir?\n5-Grafik Olustur\n6-Cikis");
        printf("\n\nYapmak istediginiz islemi seciniz: ");
        fflush(stdin);
        scanf("%d", &sec);
        printf("\n");

        if (sec >= 1 && sec <= 8)
          	islem(sec);
        else
            printf("\n\nHATALI SECIM\n\n");
    }
}

void islem(int sec)
{
	FILE *fp;
	char girilenkelime[100];

	 if ( (fp = fopen("proje.txt","r"))==NULL) {
        printf("Dosya açýlamadý");
        exit(1);
    }
	fscanf(fp, "%s\t",girilenkelime);
		int z=0;
	
    switch (sec)
    {
    case 1:
    	system("cls");
    	sonekmi(girilenkelime);
        break;
    
    case 2:
    	system("cls");
    	altkatar(girilenkelime);
        break;
    case 3:
    
    	system("cls");
    	enuzuntekrar(girilenkelime);
        break;
    case 4:
    	system("cls");
    	encoktekrar(girilenkelime);
        break;
		
	case 5:
		agac();
		break;
    case 6:
    	exit(0);
        break;
    
    default:
        printf("Hatali Secim\n");
    }
}


void agac(){
		FILE *fp;
	char girilenkelime[100];

	 if ( (fp = fopen("proje.txt","r"))==NULL) {
        printf("Dosya açýlamadý");
        exit(1);
    }
	fscanf(fp, "%s\t",girilenkelime);
	
	int gm,gd;
	gd=DETECT;
	gm=0;
	char driver[] = "";
	initgraph(&gd, &gm,driver);
	
	agacOlustur(700,100,0,5,girilenkelime,5);	

	getch();

	closegraph();
	
}

void sonekmi(char girilenkelime[100]){
	int uzunluk = strlen(girilenkelime);
	char *sonek[uzunluk];
	char *onek[uzunluk];
	char alt[100];
	int	s; int b=0;
	for(int i=1; i<uzunluk; i++){
	sonek[i]=&girilenkelime[i];
	}
	int c=0;
	for (int i = 1; i <uzunluk; i++) {
	while (c < i) {
      alt[c] = girilenkelime[c];
      c++;
   }
      alt[c] = '\0';
      onek[i]=alt;
   //printf("%s \n",onek[i);

   
	for(int i=1;i<uzunluk;i++){
	s=onekmi(onek[1],sonek[i]);
	if(s==1)
	{	
	printf("Sonek agaci olusturulamaz.\n");
	
	}
	else{
		b++;
		if(((uzunluk-1)*(uzunluk-1))==b)
			printf("Sonek agaci olusturulabilir.\n");
	}

}
}
}
int onekmi(char *onek,char *sonek)
{
	int s=0;

	if( strcmp(onek,sonek) == 0 )
		s++;	
	return s;
}

void altkatar(char girilenkelime[100]){
	printf("Katar: %s \n",girilenkelime);
	int a=0;
	char aranankelime[100];
	printf("Aranilacak katari giriniz: ");
    scanf("%s",&aranankelime); 
    int bul;
    int kelimeuzunluk  = strlen(girilenkelime); 
    int arananuzunluk = strlen(aranankelime); 

    for(int i=0; i<=kelimeuzunluk - arananuzunluk; i++)
    { 
        bul= 1;
        for(int j=0; j<arananuzunluk; j++)
        {
            if(girilenkelime[i + j] != aranankelime[j])
            {
                bul = 0;
                break;
            }
        }

        if(bul == 1)
        {
        	a++;
            printf("%s katari %d. baslangic pozisyonunda bulundu. \n", aranankelime, i);
        }
       
    }
     printf("Tekrar sayisi: %d \n\n",a);

}



int enuzuntekrar(char girilenkelime[100]){ 
	printf("Katar: %s \n",girilenkelime);
	int n = strlen(girilenkelime);
    int encok[n+1][n+1];
 
    memset(encok, 0, sizeof(encok));
 
    int uzunluk  = 0;

    int i, index = 0;
    for (i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (girilenkelime[i-1] == girilenkelime[j-1] &&
                encok[i-1][j-1] < (j - i))
            {
                encok[i][j] = encok[i-1][j-1] + 1;
 
                if (encok[i][j] > uzunluk)
                {
                    uzunluk = encok[i][j];
                    index = max(i, index);
                }
            }
            else
                encok[i][j] = 0;
        }
    }
 
    if (uzunluk > 0) 
    printf("En uzun tekrar eden alt katar: "); 
        for (i = index - uzunluk + 1; i <= index; i++)
      		 printf("%c",girilenkelime[i-1]);
      	 	 printf("\nTekrar sayisi:%d");	 
	printf("\n\n");
return 0;	
}

int max(int sayi1, int sayi2)
{
    return (sayi1 > sayi2 ) ? sayi1 : sayi2;
}	

int encoktekrar(char girilenkelime[100]){ 
 	printf("Katar: %s \n",girilenkelime);
 	int encok[100] = { 0 };
 
    int max = -1;
 

    char sonuc;
 	int	uzunluk = strlen(girilenkelime);
 
    for (int i = 0; i < uzunluk; i++)
        encok[girilenkelime[i] - 'a']++;
 
    for (int i = 0; i < 100; i++)
        if (max < encok[i]) {
            max = encok[i];
            sonuc = (char)(i + 'a');
        }
        
        printf("En cok tekrar eden: %c\n\n",sonuc);

	
return 0;	
}	

int agacOlustur(int x,int y,int index,int total,char *kelime,int sayi)
{
		FILE *fp;
	char girilenkelime[100];

	 if ( (fp = fopen("proje.txt","r"))==NULL) {
        printf("Dosya açýlamadý");
        exit(1);
    }
	fscanf(fp, "%s\t",girilenkelime);
	
size_t z =1 ;
int pozisyon = 0;
int uzunluk = strlen(girilenkelime);
int geciciuzunluk ,geciciuzunluk2;
char* gecici[100];
char* dugum[100];
char* tumdugumler[100];
char kelime2[100];
char* sonek[uzunluk];
char* gecicidugum[uzunluk];
char* alt;
char* alt2;
int q=0;
int s=0;

for(int i=0; i<uzunluk; i++){
	kelime[i+ uzunluk] = '\0';
	alt = &kelime[i];
	sonek[i]=alt;
}
dugum[0]=sonek[0];
tumdugumler[0]=sonek[0];
int a=0;
int say=0;
char harf1 , harf2, harf3,harf4;
int j;
int gd=0;
int geci=0;
int tum=1;
for(int i=1;i<uzunluk;i++)
{
    int a1=0;
	for(j=0;j<i;j++)
	{
        say=0;

		if(kelimeKontrol(sonek[i])==kelimeKontrol(sonek[j])){
          say++;
        for(int k=0;k<=a1;k++){
		 harf3=harfkontrol(sonek[i],a1);
		 harf4=harfkontrol(sonek[j],a1);
		if(harf3==harf4)
		{
    	a1++;
		}
    	else{
		geciciuzunluk=strlen(sonek[i]);
        tumdugumler[tum]=sonek[i]+a1;

	tum++;

		a1=0;

		}
    	}
    	break;
	}
	}

if(say==0 || i==j-1){
            dugum[z]=sonek[i];
            tumdugumler[tum]=sonek[i];
            z++;
            tum++;


            }
}

for(int h=0; h<12; h++){
    printf("%s [%d] \n",tumdugumler[h],h);
}
printf("\n\n");
        for(int h=0; h<z; h++){
printf("%s \n",dugum[h]);
	 setcolor(BLUE);
      	 outtextxy(150, 150+q,dugum[h]);
    	line(150, 150+q, 100, 150+q);
    	q+=20;
for(int r=0; r<uzunluk; r++){
    if(dugum[h]!= sonek[r]){
     if(kelimeKontrol(dugum[h])==kelimeKontrol(sonek[r])){
        for(int hk=0;hk<=geci;hk++){
		 harf1=harfkontrol(dugum[h],geci);
		 harf2=harfkontrol(sonek[r],geci);
		if(harf1==harf2)
		{
				s+=10;
    	geci++;
		}

    	else{
    		setcolor(RED);
		geciciuzunluk2=strlen(dugum[h]);
		for(int j =0; j<uzunluk;j++){

        gecicidugum[gd]=sonek[r]+geci;
        }
        for(int bosluk=0;bosluk<geci-1;bosluk++){
            printf(" ");
        }
        printf(" |%s \n",gecicidugum[gd]  );
        outtextxy(150+s, 150+q,gecicidugum[gd]);
    	line(150+s, 150+q, 120, 150+q);
      q+=20;
	//q=+50;
      geci=0;
      s=0;
  gd++;
		}

    	}
           }

	}
                }
            }



	
	return 1;


}

			


char kelimeKontrol(char kelime[100]){
	char kelime1=kelime[0];
//	printf("%c",ecici[0]);
	return kelime1;
}
char harfkontrol(char gec[100],int a){
	char harf3=gec[a];
	return harf3;
}


int main() {


//	enuzuntekrar(girilenkelime);
//	altkatar(girilenkelime);
	//sonekmi(girilenkelime);
	menu();


	return 0;
}
