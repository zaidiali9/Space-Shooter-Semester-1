/*This is the spaceshotter game
developed by
1.Sultan Sheikh (21L-5170)
2.Saad Amer(21L-5278)
3.Syed Ali Hassan Zaidi(21L-5274)*/
#include<iostream>
#include<windows.h>    //Windows.h is used because of system("cls") command
#include<conio.h>      //conio.h is used because of kbhit function and getch
#include<fstream>      //fstream is used beacuse of filehandling
using namespace std;
int a;
char layout[20][100], score[10][100];
int x = 18, y = 48;
double life = 5;
int xfire = x - 1, yfire = y;
int score1 = 0;
int level = 1;
bool gameover = false;
int xalien1 = 1;
int yalien1;
int xalien2 = 1;
int yalien2;
int xalien3 = 2;
int yalien3;
int xalien4 = 1;
int yalien4;
int xalien5 = 1;
int yalien5;
int xalien6 = 2;
int yalien6;
int xalien7 = 1;
int yalien7;
int xalien8 = 1;
int yalien8;
int xalien9 = 2;
int yalien9;
int xalien10 = 1;
int yalien10;
int xalien11 = 1;
int yalien11;
int xalien12 = 2;
int yalien12;
int xalien13 = 1;
int yalien13;
int xalien14 = 1;
int yalien14;
int xalien15 = 2;
int yalien15;

int check = 0;

void clearscreen()   //It is used beacuse to reduce the flickering of the screen
{
    COORD cursorPosition; cursorPosition.X = 0; cursorPosition.Y = 0; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
void instruction()   //It is used to display instruction on  the main page
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                =============================================" << endl;
    cout << "                                ============  SPACE SHOOTER GAME  ===========" << endl;
    cout << "                                =        SHOOT THE ALIENS UNTIL ITS         =" << endl;
    cout << "                                =                 TO LATE                   =" << endl;
    cout << "                                =          INSTRUCTIONS FOR THE GAME        =" << endl;
    cout << "                                =         Press Esc to Pause the Game       =" << endl;
    cout << "                                =            Press A to Move Left           =" << endl;
    cout << "                                =            Press D to Move Right          =" << endl;
    cout << "                                =       Press Space Bar to shoot Aliens     =" << endl;
    cout << "                                =            Press Q to Move Quit           =" << endl;
    cout << "                                =============================================" << endl;
    cout << "                                =================  TARGET  ==================" << endl;
    cout << "                                =           Your Target is To Score         =" << endl;
    cout << "                                =                250 Points                 =" << endl;
    cout << "                                =           If You Score 250 Points         =" << endl;
    cout << "                                =          You Win Otherwise You lose       =" << endl;
    cout << "                                =           Now Press Enter Key To          =" << endl;
    cout << "                                =              Start The Game               =" << endl;
    cout << "                                =============================================" << endl;

}
void draw()    // It is used for the drawing the layout
{

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i == 0 || j == 0 || i == 19 || j == 99)
            {
                layout[i][j] = '=';
                cout << layout[i][j];
            }
            else if (i == xalien1 && j == yalien1)
            {
                layout[xalien1][yalien1] = 12;
                cout << layout[xalien1][yalien1];
            }
            else if (i == xalien2 && j == yalien2)
            {
                layout[xalien2][yalien2] = 12;
                cout << layout[xalien2][yalien2];
            }
            else if (i == xalien3 && j == yalien3)
            {
                layout[xalien3][yalien3] = 12;
                cout << layout[xalien3][yalien3];
            }
            else if ((i == xalien4 && j == yalien4) && score1 >= 50)
            {
                if (score1 >= 50 && score1 < 100)
                {
                    level = 2;
                }
                layout[xalien4][yalien4] = 12;
                cout << layout[xalien4][yalien4];
            }
            else if ((i == xalien5 && j == yalien5) && score1 >= 50)
            {
                layout[xalien5][yalien5] = 12;
                cout << layout[xalien5][yalien5];
            }
            else if ((i == xalien6 && j == yalien6) && score1 >= 50)
            {
                layout[xalien6][yalien6] = 12;
                cout << layout[xalien6][yalien6];
            }
            else if ((i == xalien7 && j == yalien7) && score1 >= 100)
            {
                if (score1 >= 100 && score1 < 150)
                {
                    level = 3;
                }
                layout[xalien7][yalien7] = 12;
                cout << layout[xalien7][yalien7];
            }
            else if ((i == xalien8 && j == yalien8) && score1 >= 100)
            {
                layout[xalien8][yalien8] = 12;
                cout << layout[xalien8][yalien8];
            }
            else if ((i == xalien9 && j == yalien9) && score1 >= 100)
            {
                layout[xalien9][yalien9] = 12;
                cout << layout[xalien9][yalien9];
            }
            else if ((i == xalien10 && j == yalien10) && score1 >= 150)
            {
                if (score1 >= 150 && score1 < 200)
                {
                    level = 4;
                }
                layout[xalien10][yalien10] = 12;
                cout << layout[xalien10][yalien10];
            }
            else if ((i == xalien11 && j == yalien11) && score1 >= 150)
            {
                layout[xalien11][yalien11] = 12;
                cout << layout[xalien11][yalien11];
            }
            else if ((i == xalien12 && j == yalien12) && score1 >= 150)
            {
                layout[xalien12][yalien12] = 12;
                cout << layout[xalien12][yalien12];
            }
            else if ((i == xalien13 && j == yalien13) && score1 >= 200)
            {
                if (score1 >= 200)
                {
                    level = 5;
                }

                layout[xalien13][yalien13] = 12;
                cout << layout[xalien13][yalien13];
            }
            else if ((i == xalien14 && j == yalien14) && score1 >= 200)
            {
                layout[xalien14][yalien14] = 12;
                cout << layout[xalien14][yalien14];
            }
            else if ((i == xalien15 && j == yalien15) && score1 >= 200)
            {
                layout[xalien15][yalien15] = 12;
                cout << layout[xalien15][yalien15];
            }
            else if (i == x && j == y)
            {
                layout[i][j] = 202;
                cout << layout[i][j];
            }
            else if (i == xfire && j == yfire)
            {
                layout[xfire][y] = 30;
                cout << layout[xfire][y];
            }
            else
            {
                layout[i][j] = ' ';
                cout << layout[i][j];
            }

        }
        cout << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i == 0 || j == 0 || i == 9 || j == 99)
            {
                score[i][j] = '=';
                cout << score[i][j];
            }
            else if ((i == 4 && j == 16) || (i == 4 && j == 17) || (i == 4 && j == 18) || (i == 4 && j == 19) || (i == 4 && j == 20) || (i == 4 && j == 66) || (i == 4 && j == 67) || (i == 4 && j == 68) || (i == 4 && j == 69) || (i == 4 && j == 70) || (i == 4 && j == 42) || (i == 4 && j == 43) || (i == 4 && j == 44) || (i == 4 && j == 45) || (i == 4 && j == 46) || (i == 4 && j == 83) || (i == 4 && j == 84) || (i == 4 && j == 85) || (i == 4 && j == 86) || (i == 4 && j == 87) || (i == 4 && j == 88) || (i == 4 && j == 89) || (i == 4 && j == 90) || (i == 4 && j == 91))
            {
                score[i][16] = 'S';
                score[i][17] = 'C';
                score[i][18] = 'O';
                score[i][19] = 'R';
                score[i][20] = 'E';
                if (j >= 16 && j <= 20)
                {
                    cout << score[i][j];
                }
                if (j >= 66 && j <= 70)
                {
                    score[i][66] = 'L';
                    score[i][67] = 'I';
                    score[i][68] = 'V';
                    score[i][69] = 'E';
                    score[i][70] = 'S';
                    cout << score[i][j];
                }
                if (j >= 42 && j <= 46)
                {
                    score[i][42] = 'L';
                    score[i][43] = 'E';
                    score[i][44] = 'V';
                    score[i][45] = 'E';
                    score[i][46] = 'L';
                    cout << score[i][j];
                }
                if (j >= 83 && j <= 91)
                {
                    score[i][83] = 'H';
                    score[i][84] = 'I';
                    score[i][85] = 'G';
                    score[i][86] = 'H';
                    score[i][87] = 'S';
                    score[i][88] = 'C';
                    score[i][89] = 'O';
                    score[i][90] = 'R';
                    score[i][91] = 'E';
                    cout << score[i][j];
                }

            }
            else if (i == 5 && j == 84)
            {
                cout << a;
            }

            else if (i == 5 && j == 43)
            {
                cout << level;
            }
            else if (i == 5 && j == 17)
            {
                cout << score1;
            }
            else if (i == 5 && j == 67)
            {
                cout << life;
            }
            else
            {
                score[i][j] = ' ';
                cout << score[i][j];
            }
        }
        cout << endl;
    }
}
void pause()   //It is used to pause the game by using esc button
{
    system("cls");
    char a;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                =============================================" << endl;
    cout << "                                =================  PAUSED  ==================" << endl;
    cout << "                                                  SCORE " << score1 << endl;
    cout << "                                                  LEVEL " << level << endl;
    cout << "                                                  LIVES " << life << endl;
    cout << "                                            PRESS ESC to RESUME " << endl;
    cout << "                                          PRESS Q TO QUIT THE GAME" << endl;
    cout << "                                            AND RETURN TO WINDOWS " << endl;
    cout << "                                =============================================" << endl;
    cout << endl;
    for (int i = 0; i < 1;)
    {
        a = _getch();
        if (a == 27)
        {
            system("cls");
            break;
        }
        if (a == 'q')
        {
            system("cls");
            gameover = true;
            break;
        }
    }
}
void placemantofalien()   //It is used to place the aliem randomly in the layout
{
    xalien1 = 1;
    yalien1 = rand() % 90;
    yalien1 -= yalien1 % 3;
    xalien2 = 1;
    yalien2 = rand() % 90;
    yalien2 -= yalien2 % 3;
    xalien3 = 2;
    yalien3 = rand() % 90;
    yalien3 -= yalien3 % 3;
    if (score1 >= 50) {
        xalien4 = 1;
        yalien4 = rand() % 90;
        yalien4 -= yalien4 % 3;
        xalien5 = 1;
        yalien5 = rand() % 90;
        yalien5 -= yalien5 % 3;
        xalien6 = 2;
        yalien6 = rand() % 90;
        yalien6 -= yalien6 % 3;
    }
    if (score1 >= 100)
    {
        xalien7 = 1;
        yalien7 = rand() % 90;
        yalien7 -= yalien7 % 3;
        xalien8 = 1;
        yalien8 = rand() % 90;
        yalien8 -= yalien8 % 3;
        xalien9 = 2;
        yalien9 = rand() % 90;
        yalien9 -= yalien9 % 3;
    }
    if (score1 >= 100)
    {
        xalien10 = 1;
        yalien10 = rand() % 90;
        yalien10 -= yalien10 % 3;
        xalien11 = 1;
        yalien11 = rand() % 90;
        yalien11 -= yalien11 % 3;
        xalien12 = 2;
        yalien12 = rand() % 90;
        yalien12 -= yalien12 % 3;
    }
    if (score1 >= 200)
    {
        xalien13 = 1;
        yalien13 = rand() % 90;
        yalien13 -= yalien13 % 3;
        xalien14 = 1;
        yalien14 = rand() % 90;
        yalien14 -= yalien14 % 3;
        xalien15 = 2;
        yalien15 = rand() % 90;
        yalien15 -= yalien15 % 3;
    }
}
void movementleft()   //It is used to move the space ship to the left of the layout
{
    if (y > 3)
    {
        y = y - 3;
        if (check != 1)
        {
            yfire = y;
        }
    }

}
void movementright()   //It is used to move the space ship to the right of the layout
{
    if (y < 96)
    {
        y = y + 3;
        if (check != 1)
        {
            yfire = y;
        }
    }
}
void movementup()   //It is used to move the bullet to the upside of the layout
{
    if (xfire > 0)
    {
        xfire = xfire - 1;
    }
    if (xfire != 0)
    {
        check = 1;
    }
    else
    {
        check = 0;
        xfire = x - 1;
        yfire = y;
    }

}
void movementdown()     //It is used to move the aliens to the downnward of the layout
{
    xalien1++;
    xalien2++;
    xalien3++;
    if (score1 >= 50)
    {
        xalien4++;
        xalien5++;
        xalien6++;
    }
    if (score1 >= 100)
    {
        xalien7++;
        xalien8++;
        xalien9++;
    }
    if (score1 >= 150)
    {
        xalien10++;
        xalien11++;
        xalien12++;
    }
    if (score1 >= 200)
    {
        xalien13++;
        xalien14++;
        xalien15++;
    }
}
int main()
{
    int aa = 1, bb = 1, cc = 1, dd = 1, ee = 1;
    char c, z;
    fstream file;
    instruction();   //Instruction function is called
    for (int o = 0; o < 1;)
    {
        c = _getch();    //It takes the key from the keyboard
        if (c == 13)
        {
            break;
        }

    }
    if (c == 13)     //If enter is pressed the game starts
    {
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "                          LOADING...." << endl;
        Sleep(1000);   //It is placed for the loading
        system("cls");
        while (gameover != true)
        {
            file.open("highscore.txt", ios::in);
            if (file)
            {
                file >> a;
                if (score1 > a)
                {
                    a = score1;
                }
                file.close();
                file.open("highscore.txt", ios::out);
                {
                    file << a;
                }
                file.close();
            }
            if (score1 == 0)
            {
                while (aa == 1)
                {
                    system("cls");
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "                        ============" << endl;
                    cout << "                        =  LEVEL1  =" << endl;
                    cout << "                        ============" << endl;
                    Sleep(1000);
                    system("cls");
                    life = 5;
                    aa++;
                    placemantofalien();
                }
            }
            if (score1 == 50)
            {
                while (bb == 1)
                {
                    system("cls");
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "                        ============" << endl;
                    cout << "                        =  LEVEL2  =" << endl;
                    cout << "                        ============" << endl;
                    Sleep(1000);
                    system("cls");
                    life = 5;
                    bb++;
                }
            }
            if (score1 == 100)
            {
                while (cc == 1)
                {
                    system("cls");
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "                        ============" << endl;
                    cout << "                        =  LEVEL3  =" << endl;
                    cout << "                        ============" << endl;                    Sleep(1000);
                    system("cls");
                    life = 5;
                    cc++;
                }
            }
            if (score1 == 150)
            {
                while (dd == 1)
                {
                    system("cls");
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "                        ============" << endl;
                    cout << "                        =  LEVEL4  =" << endl;
                    cout << "                        ============" << endl;                    Sleep(1000);
                    system("cls");
                    life = 5;
                    dd++;
                }
            }
            if (score1 == 200)
            {
                while (ee == 1)
                {
                    system("cls");
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "                        ============" << endl;
                    cout << "                        =  LEVEL5  =" << endl;
                    cout << "                        ============" << endl;                    Sleep(1000);
                    system("cls");
                    life = 5;
                    ee++;
                }
            }
            clearscreen();
            draw();
            if (_kbhit())
            {
                c = _getch();
                if (c == 27)
                {
                    pause();
                }
                if (c == 'a')
                {
                    if (y == 1)
                    {
                        continue;
                    }
                    movementleft();
                }
                if (c == 'd')
                {
                    if (y == 98)
                    {
                        continue;
                    }
                    movementright();
                }
                if (c == 32)
                {
                    yfire = y;
                    movementup();
                }

            }

            if ((xfire == xalien1 && yfire == yalien1) || (xfire == xalien1 + 1 && yfire == yalien1))
            {

                xfire = 18;
                score1 = score1 + 10;
                xalien1 = 1;
                yalien1 = rand() % 90;
                yalien1 -= yalien1 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien1 > 18)
            {
                xalien1 = 1;
                yalien1 = rand() % 90;
                yalien1 -= yalien1 % 3;
            }
            if ((xfire == xalien2 && yfire == yalien2) || (xfire == xalien2 + 1 && yfire == yalien2))
            {


                xfire = 18;
                score1 = score1 + 10;
                xalien2 = 1;
                yalien2 = rand() % 90;
                yalien2 -= yalien2 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien2 > 18)
            {
                xalien2 = 1;
                yalien2 = rand() % 90;
                yalien2 -= yalien2 % 3;
            }
            if ((xfire == xalien3 && yfire == yalien3) || (xfire == xalien3 + 1 && yfire == yalien3))
            {
                xfire = 18;
                score1 = score1 + 10;
                xalien3 = 1;
                yalien3 = rand() % 90;
                yalien3 -= yalien3 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien3 > 18)
            {
                xalien3 = 1;
                yalien3 = rand() % 90;
                yalien3 -= yalien3 % 3;
            }
            if ((xfire == xalien4 && yfire == yalien4) || (xfire == xalien4 + 1 && yfire == yalien4))
            {

                xfire = 18;
                score1 = score1 + 10;
                xalien4 = 1;
                yalien4 = rand() % 90;
                yalien4 -= yalien4 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien4 > 18)
            {
                xalien4 = 1;
                yalien4 = rand() % 90;
                yalien4 -= yalien4 % 3;
            }
            if ((xfire == xalien5 && yfire == yalien5) || (xfire == xalien5 + 1 && yfire == yalien5))
            {


                xfire = 18;
                score1 = score1 + 10;
                xalien5 = 1;
                yalien5 = rand() % 90;
                yalien5 -= yalien5 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien5 > 18)
            {
                xalien5 = 1;
                yalien5 = rand() % 90;
                yalien5 -= yalien5 % 3;
            }
            if ((xfire == xalien6 && yfire == yalien6) || (xfire == xalien6 + 1 && yfire == yalien6))
            {
                xfire = 18;
                score1 = score1 + 10;
                xalien6 = 1;
                yalien6 = rand() % 90;
                yalien6 -= yalien6 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien6 > 18)
            {
                xalien6 = 1;
                yalien6 = rand() % 90;
                yalien6 -= yalien6 % 3;
            }
            if ((xfire == xalien7 && yfire == yalien7) || (xfire == xalien7 + 1 && yfire == yalien7))
            {

                xfire = 18;
                score1 = score1 + 10;
                xalien7 = 1;
                yalien7 = rand() % 90;
                yalien7 -= yalien7 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien7 > 18)
            {
                xalien7 = 1;
                yalien7 = rand() % 90;
                yalien7 -= yalien7 % 3;
            }
            if ((xfire == xalien8 && yfire == yalien8) || (xfire == xalien8 + 1 && yfire == yalien8))
            {


                xfire = 18;
                score1 = score1 + 10;
                xalien8 = 1;
                yalien8 = rand() % 90;
                yalien8 -= yalien8 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien8 > 18)
            {
                xalien8 = 1;
                yalien8 = rand() % 90;
                yalien8 -= yalien8 % 3;
            }
            if ((xfire == xalien9 && yfire == yalien9) || (xfire == xalien9 + 1 && yfire == yalien9))
            {
                xfire = 18;
                score1 = score1 + 10;
                xalien9 = 1;
                yalien9 = rand() % 90;
                yalien9 -= yalien9 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien9 > 18)
            {
                xalien9 = 1;
                yalien9 = rand() % 90;
                yalien9 -= yalien9 % 3;
            }
            if ((xfire == xalien10 && yfire == yalien10) || (xfire == xalien10 + 1 && yfire == yalien10))
            {

                xfire = 18;
                score1 = score1 + 10;
                xalien10 = 1;
                yalien10 = rand() % 90;
                yalien10 -= yalien10 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien10 > 18)
            {
                xalien10 = 1;
                yalien10 = rand() % 90;
                yalien10 -= yalien10 % 3;
            }
            if ((xfire == xalien11 && yfire == yalien11) || (xfire == xalien11 + 1 && yfire == yalien11))
            {


                xfire = 18;
                score1 = score1 + 10;
                xalien11 = 1;
                yalien11 = rand() % 90;
                yalien11 -= yalien11 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien11 > 18)
            {
                xalien11 = 1;
                yalien11 = rand() % 90;
                yalien11 -= yalien11 % 3;
            }
            if ((xfire == xalien12 && yfire == yalien12) || (xfire == xalien12 + 1 && yfire == yalien12))
            {
                xfire = 18;
                score1 = score1 + 10;
                xalien12 = 1;
                yalien12 = rand() % 90;
                yalien12 -= yalien12 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien12 > 18)
            {
                xalien12 = 1;
                yalien12 = rand() % 90;
                yalien12 -= yalien12 % 3;
            }
            if ((xfire == xalien13 && yfire == yalien13) || (xfire == xalien13 + 1 && yfire == yalien13))
            {

                xfire = 18;
                score1 = score1 + 10;
                xalien13 = 1;
                yalien13 = rand() % 90;
                yalien13 -= yalien13 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien13 > 18)
            {
                xalien13 = 1;
                yalien13 = rand() % 90;
                yalien13 -= yalien13 % 3;
            }
            if ((xfire == xalien14 && yfire == yalien14) || (xfire == xalien14 + 1 && yfire == yalien14))
            {


                xfire = 18;
                score1 = score1 + 10;
                xalien14 = 1;
                yalien14 = rand() % 90;
                yalien14 -= yalien14 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien14 > 18)
            {
                xalien14 = 1;
                yalien14 = rand() % 90;
                yalien14 -= yalien14 % 3;
            }
            if ((xfire == xalien15 && yfire == yalien15) || (xfire == xalien15 + 1 && yfire == yalien15))
            {
                xfire = 18;
                score1 = score1 + 10;
                xalien15 = 1;
                yalien15 = rand() % 90;
                yalien15 -= yalien15 % 3;
                check = 0;
                xfire = x - 1;
                yfire = y;

            }
            if (xalien15 > 18)
            {
                xalien15 = 1;
                yalien15 = rand() % 90;
                yalien15 -= yalien3 % 3;
            }
            if (score1 >= 0 && (xfire < xalien1) && (xfire < xalien2) && (xfire < xalien3))
            {
                xfire = 18;
                check = 0;
                xfire = x - 1;
                yfire = y;
            }
            if (score1 >= 50 && (xfire < xalien4) && (xfire < xalien5) && (xfire < xalien6))
            {
                xfire = 18;
                check = 0;
                xfire = x - 1;
                yfire = y;
            }
            if (score1 >= 100 && (xfire < xalien7) && (xfire < xalien8) && (xfire < xalien9))
            {
                xfire = 18;
                check = 0;
                xfire = x - 1;
                yfire = y;
            }
            if (score1 >= 150 && (xfire < xalien10) && (xfire < xalien11) && (xfire < xalien12))
            {
                xfire = 18;
                check = 0;
                xfire = x - 1;
                yfire = y;
            }
            if (score1 >= 200 && (xfire < xalien13) && (xfire < xalien14) && (xfire < xalien15))
            {
                xfire = 18;
                check = 0;
                xfire = x - 1;
                yfire = y;
            }
            if (check == 1)
            {
                movementup();
            }
            movementdown();
            if (xalien1 > 18 || xalien2 > 18 || xalien3 > 18 || xalien4 > 18 || xalien5 > 18 || xalien6 > 18 || xalien7 > 18 || xalien8 > 18 || xalien9 > 18 || xalien10 > 18 || xalien11 > 18 || xalien12 > 18 || xalien13 > 18 || xalien14 > 18 || xalien15 > 18)
            {
                life = life - 0.5;
            }

            clearscreen();
            if (life == 0)
            {
                system("cls");
                system("cls");
                clearscreen();
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "                                ==========================================" << endl;
                cout << "                                =============   GAME  OVER    =============" << endl;
                cout << "                                                SCORE " << score1 << endl;
                cout << "                                                 YOU LOST " << endl;
                cout << "                                            PRESS  ENTER KEY TO" << endl;
                cout << "                                            PLAY THE GAME AGAIN" << endl;
                cout << "                                           OR PRESS Q  TO RETURN" << endl;
                cout << "                                                TO WINDOWS" << endl;
                cout << "                                ==========================================" << endl;
                for (int xx = 0; xx < 1;)
                {
                    z = _getch();
                    if (z == 13)
                    {
                        y = 48;
                        xfire = 17;
                        yfire = y;
                        aa = 1;
                        bb = 1;
                        cc = 1;
                        dd = 1;
                        ee = 1;
                        score1 = 0;
                        life = 5;
                        level = 1;
                        system("cls");
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << "                          LOADING...." << endl;
                        Sleep(1000);
                        system("cls");
                        placemantofalien();
                        break;
                    }
                    if (z == 'q')
                    {
                        gameover = true;
                        break;

                    }
                }
            }
            if (score1 == 250)
            {
                system("cls");
                system("cls");
                clearscreen();
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "                                ==========================================" << endl;
                cout << "                                =============   GAME  OVER    =============" << endl;
                cout << "                                                SCORE " << score1 << endl;
                cout << "                                                 YOU WON " << endl;
                cout << "                                            PRESS  ENTER KEY TO" << endl;
                cout << "                                            PLAY THE GAME AGAIN" << endl;
                cout << "                                           OR PRESS Q  TO RETURN" << endl;
                cout << "                                                TO WINDOWS" << endl;
                cout << "                                ==========================================" << endl;
                for (int xx = 0; xx < 1;)
                {
                    z = _getch();
                    if (z == 13)
                    {
                        y = 48;
                        xfire = 17;
                        yfire = y;
                        aa = 1;
                        bb = 1;
                        cc = 1;
                        dd = 1;
                        ee = 1;
                        score1 = 0;
                        life = 5;
                        level = 1;
                        system("cls");
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << "                          LOADING...." << endl;
                        Sleep(1000);
                        system("cls");
                        placemantofalien();
                        break;
                    }
                    if (z == 'q')
                    {
                        gameover = true;
                        break;

                    }
                }
            }


        }
    }

    return 0;
}
