#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
    system("color 8b");

    printf("\e[1;1H\e[2J");
    char bhs1[2];
    printf("\tWelcome to Guess the Dice! :U \n");
    printf("\tSelamat datang di Tebak Dadu itu! :U\n\n");
    printf("--------------------------------------------------------------------------------\n");


    while(1)
    {
        printf("--------------------------------------------------------------------------------\n");
        printf("Don't worry about case sensitive! Just type one of those options\nJangan khawatir dengan permasalahaan kapitalisasi hurufnya! cukup ketik salah satu pilihan yang ada saja\n");
        printf("Press 0 to exit\nKetik 0 untuk keluar\n");
        printf("\nPlease choose the versions you want (en/id) \nSilahkan pilih versi yang anda inginkan (en/id) : ");
        scanf("%s",&bhs1);
        fflush(stdin);

        if(strcasecmp(bhs1, "en") == 0){
            EngMenu();
            break;
        }
        if(strcasecmp(bhs1, "id") == 0){
            IndoMenu();
            break;
        }
        if(strcasecmp(bhs1, "0") == 0){
            break;
        }
        else printf("You might want to see again those options again\nAnda mungkin perlu liat ulang pilihannya yang tersedia\n\n\n\n");
    }
    IdCredits();
    printf("\n");
    EnCredits();

    return 0;
}

int EngMenu()
{
    char choices[10];

    printf("\e[1;1H\e[2J");
    printf("Hi!\n");
    system("hostname");
    printf("\nWelcome to Guess that Dice! Game :U\n");
    printf("In this game, you have to guess the numbers from the dice that has been rolled\n");
    printf("Ranging from 1-6\n");
    printf("There are 3 difficulties in here: \n");
    printf("1. Easy = You need to guess 1 number from one dice\n");
    printf("2. Medium = You need to guess 2 number from 2 dice\n");
    printf("3. Hard [Still in Development] = You need to guess the number of the dices in which the number have been added up\n");
    printf("0. Back to menu\n\n");
    printf("So, Are you ready Player? Let's get started\n\n");
    getchar();



    while(1)
    {

        printf("Make your choice! [Easy|Medium|Hard] :\n");
        scanf("%s", &choices);
        fflush(stdin);

        if(strcasecmp(choices, "easy") == 0){
            EnEasy();
            break;
        }
        if(strcasecmp(choices, "medium") == 0){
            EnMed();
            break;
        }
        if(strcasecmp(choices, "hard") == 0){
            EnHard();
            break;
        }
        if(strcasecmp(choices, "0") == 0){
            main();
            break;
        }
        else printf("\nAre you kidding me right? -_- \nIt's just 3 options, don't ask more!");
    }
    return 0;
}

int IndoMenu()
{
    char choices[10];

    printf("\e[1;1H\e[2J");
    printf("Hai!\n");
    system("hostname");
    printf("Selamat datang di game Tebak Dadu itu! :U\n");
    printf("Jadi pada game ini, Anda harus menebak angka-angka dari dadu-dadu yang sudah dilempar\n");
    printf("Dari angka 1 sampai 6\n");
    printf("Ada 3 tingkat kesulitan di game ini: \n");
    printf("1. Mudah = Anda harus menebak 1 angka dari 1 dadu yang sudah dilempar\n");
    printf("2. Sedang = Anda harus menebak 2 angka dari 2 dadu yang sudah dilempar\n");
    printf("3. Sulit [Mungkin(?)] = Anda harus menebak 2 angka dari 2 dadu YANG kedua angka dari 2 dadunya sudah dijumlahkan\n");
    printf("0. Untuk kembali ke menu utama\n\n");
    printf("Jadi, Apakah anda sudah siap! Kuy mulai aja\n");


    while(1)
    {

        printf("\nTentukan pilihanmu! [Mudah|Sedang|Sulit] : ");
        scanf("%s", &choices);

        if(strcasecmp(choices, "mudah") == 0){
            IdEasy();
            break;
        }
        if(strcasecmp(choices, "sedang") == 0){
            IdMed();
            break;
        }
        if(strcasecmp(choices, "sulit") == 0){
            IdHard();
            break;
        }
        if(strcasecmp(choices, "0") == 0){
            main();
            break;
        }
        else printf("\nMonggo mungkin boleh kali baca ulang opsinya -_-\n");
    }

    return 0;
}

void IdCredits(){
    printf("\nTerima kasih untuk mau memainkan game yang biasa & membosankan ini\n");
    printf("Semoga suka dan maaf jika masih banyak kekurangan (^-^)\n");
    printf("\nDibuat oleh xileFerdianto08\n\n");
}

void EnCredits(){
    printf("\nThank you for want to playing this kind-of-game\n");
    printf("Hope you like it and Sorry if there's too many shortcoming! (^-^)\n");
    printf("\nMade By xileFerdianto08\n");
}

void EnEasy()
{
    int guess, dice_number;
    int attemps = 5;
    char decision;

    printf("\e[1;1H\e[2J");
    printf("This is the easy mode\n");
    printf("As the menu says, this mode need you to ONLY guess 1 number from 1 dice that has been rolled\n");
    printf("You'll be given %d chances to guess the number of the dice\n", attemps);
    printf("There's no 'YET' score counting, so yeah just have fun with it\n\n");
    getchar();

    srand(time(0));
    dice_number = rand() % 6 + 1;



    while(1)
    {

        printf("The dice has been rolled, guess the number\n");
        scanf("%d",&guess);

        if(guess == 0 || guess > 6) continue;

        if(guess == dice_number)
        {
            printf("\nGood job\n");
            printf("The number of the rolled dice is %d\n", dice_number);
            break;
        }
        attemps--;
        printf("\n\n%d more chances left\n\n", attemps);

        if(guess < dice_number) printf("\nThe number is to small, try again\n\n");
        if(guess > dice_number) printf("\nThe number is to big, try again\n\n");

        if(attemps == 1) printf("\t\tLast chance buddy, make it count!\n\n");

        if(attemps <= 0)
        {
            gameover();
            printf("The number of the rolled dice supposed to be %d\n", dice_number);
            break;
        }


    }



    while(1)
    {
        printf("\n\n\nDo you still want to continue? [y/n] : ");
        scanf(" %c", &decision);

        if(decision == 'y')EngMenu();
        if(decision == 'Y')EngMenu();

        if(decision =='n')break;
        if(decision == 'N')break;
    }
    EnCredits();
}


void IdEasy()
{
    int tebakdadu, angkadadu;
    int attemps = 5;
    char putusan;

    printf("\e[1;1H\e[2J");
    printf("Ini adalah mode mudahnya atau gampangnya\n");
    printf("Sesuai dengan apa yang ada di menu tadi, Anda hanya perlu menebak 1 angka dari 1 dadu yang sudah dilempar\n");
    printf("Anda akan diberikan %d kesempatan untuk menebaknya\n", attemps);
    printf("\nDisini 'MASIH' belum ada hitungan skornya, jadi dibawa santai dan senang saja\n\n");

    srand(time(NULL));
    angkadadu = rand() % 6 + 1 ;

    while(1)
    {

        printf("Sebuah dadu telah dilempar, tebak angkanya\n");
        scanf("%d",&tebakdadu);

        if(tebakdadu == angkadadu)
        {
            printf("\nTjakep\n");
            printf("Angka dadu yang terlempar adalah %d\n", angkadadu);
            break;
        }

        attemps--;
        printf("\nKesempatan tersisa %d\n",attemps);



        if(tebakdadu < angkadadu) printf("\nAngkanya kekecilan, coba lagi deh\n\n");
        if(tebakdadu > angkadadu) printf("\nAngkanya kebesaran, coba lagi yah\n\n");

        if(attemps == 1) printf("\t\tKesempatan terakhir, yok yok yok yang teliti!\n\n");

        if(attemps <=0)
        {
            gameover();
            printf("Angka dadu yang terlempar seharusnya %d\n", angkadadu);
            break;
        }
    }


    while(1)
    {
        printf("\nApa Anda ingin main lagi? [y/n] = ");
        scanf(" %c", &putusan);

        if(putusan == 'y')IndoMenu();
        if(putusan == 'Y')IndoMenu();

        if(putusan =='n')break;
        if(putusan == 'N')break;
    }
    IdCredits();
}


void EnMed()
{
    int guess1, dice_number1, guess2, dice_number2, result;
    int attemps = 6;
    char decision;

    printf("\e[1;1H\e[2J");
    printf("As the menu says, this mode need you to guess the number of the dices that have been rolled\n");
    printf("But, both of the number have been added up. So, careful with your answer\n");
    printf("You'll be given %d chances to guess the number of the dice\n", attemps);
    printf("There's no 'OR NEVER' score counting, so yeah just have fun with it.\n");
    getchar();

    srand(time(0));
    dice_number1 = rand() % 6 + 1;
    dice_number2 = rand() % 6 + 1;
    result = dice_number1 + dice_number2;


    do
    {

        printf("\nThe 2 dice has been rolled and the total is %d\n", result);
        printf("So, what is the number for both of the dice that equals to %d?\n", result);
        printf("Dice 1 is ");
        scanf("%d", &guess1);
        printf("\nDice 2 is ");
        scanf("%d", &guess2);


        if(guess1 == 0 || guess1 > 6 || guess2 == 0 || guess2 > 6) continue;

        if(guess1 == dice_number1 && guess2 == dice_number2)
        {
            printf("\nGood job\n");
            printf("%d is from %d (from 1st dice) and %d (from 2nd dice)\n", result, dice_number1, dice_number2);
            break;
        }

        attemps--;
        printf("\n\n%d more chances left\n", attemps);

        if(attemps <=2)
        {
            if(guess1 < dice_number1) printf("\nThe number for first dice is to small\n");
            if(guess2 < dice_number2) printf("\nThe number for second dice is to small\n");

            if(guess1 > dice_number1) printf("\nThe number for first dice is to big\n\n");
            if(guess2 > dice_number2) printf("\nThe number for second dice is to big\n\n\n");
        }


        if(attemps == 1) printf("\nLast chance buddy, make it count!\n\n");

        if(attemps <= 0)
        {
            gameover();
            printf("%d is from %d (from 1st dice) and %d (from 2nd dice)\n", result, dice_number1, dice_number2);
            break;
        }
    }while(1);


    while(1)
    {
        printf("\nDo you still want to continue? [y/n] : ");
        scanf(" %c", &decision);

        if(decision == 'y')EngMenu();
        if(decision == 'Y')EngMenu();

        if(decision =='n')break;
        if(decision == 'N')break;
    }
    EnCredits();
}

void IdMed()
{
    int tebak1, angkadadu1, tebak2, angkadadu2, hasil;
    int attemps = 6;
    char putusan;

    printf("\e[1;1H\e[2J");
    printf("Ini adalah mode mediumnya\n");
    printf("Sesuai dengan apa yang ada di menu tadi, Anda hanya perlu menebak 2 angka dari 2 dadu yang sudah dilempar\n");
    printf("Anda akan diberikan %d kesempatan untuk menebaknya\n", attemps);
    printf("\nDisini belum atau 'GA BAKAL' ada hitungan skornya, jadi dibawa santai dan senang saja\n");
    getchar();

    srand(time(0));
    angkadadu1 = rand() % 6 + 1;
    angkadadu2 = rand() % 6 + 1;
    hasil = angkadadu1 + angkadadu2;


    do
    {

        printf("\n2 dadu sudah dilempar, jika dijumlahkan maka menghasilkan %d\n", hasil);
        printf("Maka, angka berapa saja yang dikeluarkan oleh dadu tsb untuk menghasilkan si %d ini?\n", hasil);
        printf("Dadu ke-1 adalah ");
        scanf("%d", &tebak1);
        printf("\nDadu ke-2 adalah ");
        scanf("%d", &tebak2);

        if(tebak1 == 0 || tebak1 > 6 || tebak2 == 0 || tebak2 > 6) continue;

        if(tebak1 == angkadadu1 && tebak2 == angkadadu2)
        {
            printf("\nTjakep\n");
            printf("Angka %d dihasilkan dari %d (dari dadu pertama) dan %d (dari dadu kedua)\n", hasil, angkadadu1, angkadadu2);
            break;
        }

        attemps--;
        printf("\nKesempatan tersisa %d lagi\n", attemps);

        if(attemps <= 2)
        {
            if(tebak1 < angkadadu1) printf("\nAngka dadu pertama kekecilan\n");
            if(tebak2 < angkadadu2) printf("\nAngka dadu kedua kekecilan\n");

            if(tebak1 > angkadadu1) printf("\nAngka dadu pertama kebesaran, jadi coba lagi deh\n\n");
            if(tebak2 > angkadadu2) printf("\nAngka dadu kedua kebesaran, jadi coba lagi deh\n\n");
        }


        if(attemps == 1) printf("\t\tKesempatan terakhir, yok yok yok yang teliti!\n\n");

        if(attemps <= 0)
        {
            gameover();
            printf("Kedua angka dadu yang terlempar seharusnya %d dan %d", angkadadu1, angkadadu2);
            break;
        }

    }while(1);

    while(1)
    {
        printf("\nApa Anda ingin main lagi? [y/n] = ");
        scanf(" %c", &putusan);

        if(putusan == 'y')IndoMenu();
        if(putusan == 'Y')IndoMenu();

        if(putusan =='n')break;
        if(putusan == 'N')break;
    }
    IdCredits();
}


void EnHard()
{
    int guess1, dice_number1, guess2, dice_number2;
    int attemps = 4;
    char decision;

    printf("\e[1;1H\e[2J");
    printf("This is the hard mode\n");
    printf("As the menu says, this mode need you to guess 2 number from 2 dice that has been rolled\n");
    printf("You'll be given %d chances to guess the number of the dice\n", attemps);
    printf("There's no 'OR NEVER' score counting, so yeah just have fun with it\n\n");
    getchar();

    srand(time(0));
    dice_number1 = rand() % 6 + 1;
    dice_number2 = rand() % 6 + 1;



    do
    {
        printf("\nThe 2 dice has been rolled, guess the number of it\n");
        printf("Dice 1 is ");
        scanf("%d", &guess1);
        printf("\nDice 2 is ");
        scanf("%d", &guess2);

        if(guess1 == 0 || guess1 > 6 || guess2 == 0 || guess2 > 6){
           printf("\n\nOh come on, seriously??\n\n");
           continue;
        }


        attemps--;
        printf("\n\n%d more chances left\n", attemps);

        if(guess1 == dice_number1 && guess2 == dice_number2)
        {
            printf("\nGood job\n");
            printf("The number of the both rolled dice is %d and %d\n", dice_number1, dice_number2);
            break;
        }



        if(attemps == 1) printf("\t\tLast chance buddy, make it count!\n\n");

        if(attemps <= 0)
        {
            gameover();
            printf("The number from the both rolled dice supposed to be %d (first dice) and %d (second dice)\n\n", dice_number1, dice_number2);
            break;
        }

    }while(1);


    while(1)
    {
        printf("\n\nDo you still want to continue? [y/n] : ");
        scanf(" %c", &decision);

        if(decision == 'y')EngMenu();
        if(decision == 'Y')EngMenu();

        if(decision =='n')break;
        if(decision == 'N')break;
    }
    EnCredits();

}

void IdHard()
{
    int tebak1, angkadadu1, tebak2, angkadadu2;
    int attemps = 4;
    char putusan;

    printf("\e[1;1H\e[2J");
    printf("Ini adalah mode sulitnya\n");
    printf("Sesuai dengan apa yang ada di menu tadi, Anda hanya perlu menebak 2 angka dari 2 dadu yang sudah dilempar\n");
    printf("Anda akan diberikan %d kesempatan   untuk menebaknya\n", attemps);
    printf("\nDisini belum atau 'GA BAKAL' ada hitungan skornya, jadi dibawa santai dan senang saja\n");
    getchar();

    srand(time(0));
    angkadadu1 = rand() % 6 + 1;
    angkadadu2 = rand() % 6 + 1;



    do
    {

        printf("\n2 dadu sudah dilempar, tebak angka keduanya\n");
        printf("Dadu ke-1 adalah ");
        scanf("%d", &tebak1);
        printf("\nDadu ke-2 adalah ");
        scanf("%d", &tebak2);

        if(tebak1 == 0 || tebak1 > 6 || tebak2 == 0 || tebak2 > 6) {
            printf("\n\nGa usah ngelawak deh\n\n");
            continue;
        }

        if(tebak1 == angkadadu1 && tebak2 == angkadadu2)
        {
            printf("\nTjakep\n");
            printf("Kedua angka dadu yang terlempar adalah %d dan %d\n", angkadadu1, angkadadu2);
            break;
        }

        attemps--;
        printf("\nKesempatan tersisa %d lagi\n", attemps);



        if(attemps == 1) printf("\t\tKesempatan terakhir, yok yok yok yang teliti!\n\n");

        if(attemps <= 0)
        {
            gameover();
            printf("Kedua angka dadu yang terlempar seharusnya %d dan %d", angkadadu1, angkadadu2);
            break;
        }

    }while(1);

    while(1)
    {
        printf("\nApa Anda ingin main lagi? [y/n] = ");
        scanf(" %c", &putusan);

        if(putusan == 'y')IndoMenu();
        if(putusan == 'Y')IndoMenu();

        if(putusan =='n')break;
        if(putusan == 'N')break;
    }
    IdCredits();
}


int gameover()
{
    system("color 07");
    printf("\e[1;1H\e[2J");
    int x;
    double y;
    char text1[]= "\tGame Over ";
    for(x=0; text1[x]!=0; x++)
    {
         printf("%c",text1[x]);
         system("color 8");
         system("color b");
          for(y=0; y<=33333333; y++)
          {
          }
    }
   printf("\n\nTime Out! Try again next time\n");
   printf("Waktu abis! Coba lagi lain waktu\n");
   printf("\n\n");

   return 0;
}

