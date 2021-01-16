//
//  main.c
//  Bataille navale
//
//  Created by Thomas_Froger on 15/04/2019.
//  Copyright © 2019 Thomas_Froger. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>

#include <time.h>



void creationofthegrid(int size, int GB1[100][100], int GB2[100][100], char GS1[100][100], char GS2[100][100])

{
    
    int i, j;
    
    for (i = 0; i <= size; i++)
        
    {
        
        for (j = 0; j <= size; j++)                 /*GB1 will be the grid where the user will place its boats*/
            
        {                                                                                                              /* 0 simbolizes water and numbers such as 2, 3, 4, 5 and 6 will simbolize boats*/
            
            GB1[i][j] = 0;
            
        }
        
    }
    
    for (i = 0; i <= size; i++)
        
    {
        
        for (j = 0; j <= size; j++)                 /*GB2 will be the grid where the user will place its boats*/
            
        {                                                                                                              /* 0 simbolizes water and numbers such as 2, 3, 4, 5 and 6 will simbolize boats*/
            
            GB2[i][j] = 0;
            
        }
        
    }
    
    for (i = 0; i <= size; i++)
        
    {
        
        for (j = 0; j <= size; j++)                                         /*GS1 will be the grid where the user will see where did he shoot*/
            
        {                                                                                                              /*Water will be simbolized with x, m will means missed and h will means hit */
            
            GS1[i][j] = 'x';
            
        }
        
    }
    
    for (i = 0; i <= size; i++)
        
    {
        
        for (j = 0; j <= size; j++)
            
        {                                                                                                              /*GS2 will be the grid where the user will see where did he shoot*/
            
            GS2[i][j] = 'x';                                                         /*Water will be simbolized with x, m will means missed and h will means hit */
            
        }
        
    }
    
    
    
    
    
}



void displaygridboat(int size, int GB1[100][100])  /* This function will be used to display the grid where the user and the computer will place their boats*/

{
    
    int i, j;
    
    printf("  ");
    
    for (i = 0; i < size; i++)
        
    {
        
        printf(" %d", i);
        
    }
    
    printf("\n");
    
    printf("----------------------\n");
    
    for (i = 0; i < size; i++)
        
    {
        
        printf("%d ", i);
        
        for (j = 0; j < size; j++)
            
        {
            
            printf(" %d", GB1[i][j]);
            
        }
        
        printf("\n");
        
    }
    
}



void displaygridscore (int size, char GS1[100][100])   /* This function will be used to display the grid where the user and the computer will try to shoot the boat of the other player*/

{
    
    int i, j;
    
    printf("  ");
    
    for (i = 0; i < size; i++)
        
    {
        
        printf(" %d", i);
        
    }
    
    printf("\n");
    
    printf("----------------------\n");
    
    for (i = 0; i < size; i++)
        
    {
        
        printf("%d ", i);
        
        for (j = 0; j < size; j++)
            
        {
            
            printf(" %c", GS1[i][j]);
            
        }
        
        printf("\n");
        
    }
    
    
    
}



int ChoosePlayer(){
    
    
    
    char A;
    
    int player = 0;
    
    do {
        
        printf("Press A to choose the first player!\n");
        
        scanf_s(" %c", &A);
        
    } while (A != 'A'&& A != 'a');
    
    srand(time(NULL));
    
    player = (rand() % 2) + 1;
    
    printf("The player that starts is the player %d !\n", player);
    
    return player;
    
    
    
}



void check(int size, int sizeboat, int line, int column, int Checkplace[], int GB1[100][100])

{
    
    int above = 0;
    
    int under = 0;                                                                                        /*This function is used for the placement of the ships. It checks whether there is the place to put the boat above, under, on the right or on the left*/
    
    int right = 0;
    
    int left = 0;
    
    int revelator, l;
    
    revelator = 0;
    
    for (l = 1; l < sizeboat; l++)                                             /*The value of revelator changes if from the front of the boat to the end of the boat, there is at least one case different from 0. As the water is symbilized by a 0, it means that there is a boat on the road*/
        
    {
        
        if (GB1[line - l][column] != 0)
            
        {
            
            revelator = 1;
            
        }
        
    }
    
    if ((line - (sizeboat - 1) >= 0) && (revelator == 0))
        
    {
        
        above = 1;                                                                                   /*If there is the place to put the boat, the value of the variable (above for this example) takes the value of 1*/
        
    }
    
    
    
    revelator = 0;
    
    for (l = 1; l < sizeboat; l++)
        
    {
        
        if (GB1[line + l][column] != 0)
            
        {
            
            revelator = 1;
            
        }
        
    }
    
    if ((line + (sizeboat - 1) < size) && (revelator == 0))
        
    {
        
        under = 1;
        
    }
    
    
    
    revelator = 0;
    
    for (l = 1; l < sizeboat; l++)
        
    {
        
        if (GB1[line][column + l] != 0)
            
        {
            
            revelator = 1;
            
        }
        
    }
    
    if ((column + (sizeboat - 1) < size) && (revelator == 0))
        
    {
        
        right = 1;
        
    }
    
    
    
    revelator = 0;
    
    for (l = 1; l < sizeboat; l++)
        
    {
        
        if (GB1[line][column - l] != 0)
            
        {
            
            revelator = 1;
            
        }
        
    }
    
    if ((column - (sizeboat - 1) >= 0) && (revelator == 0))
        
    {
        
        left = 1;
        
    }
    
    
    
    Checkplace[0] = above;                                                            /*Finally, we put the value of each variable in this array*/
    
    Checkplace[1] = under;
    
    Checkplace[2] = right;
    
    Checkplace[3] = left;
    
    
    
    
    
}







int ask(int Checkplace[4], int *position) {                             /*During this function, we shox the user the possibilities where he can put his boat*/
    
    if (Checkplace[0] == 1)
        
    {
        
        printf("Enter 0 to place your boat above, ");
        
    }
    
    if (Checkplace[1] == 1)
        
    {
        
        printf("Enter 1 to place your boat under, ");
        
    }
    
    if (Checkplace[2] == 1)
        
    {
        
        printf("Enter 2 to place your boat on the right, ");
        
    }
    
    if (Checkplace[3] == 1)
        
    {
        
        printf("Enter 3 to place your boat on the left.");
        
    }
    
    scanf_s("%d", position);
    
    while (Checkplace[*position] == 0)
        
    {
        
        printf("\nThere isn't enough place to put your boat here. Reenter the position\n");
        
        scanf_s("%d", position);
        
    }
    
    return *position;                                                   /*The value of position is return for the next function finalplace*/
    
    
    
    
    
}





void finalplace(int sizeboat, int GB1[100][100], int position, int line, int column) {              /*This function is used to replace water by boat on the grid.*/
    
    int i = 1;
    
    int copiedsize;
    
    copiedsize = sizeboat;
    
    if (position == 0)                                                    /*Here, if the user or the computer has chosen position=0; so to put the boat above, we use a while loop to replace 0 of each case by the value of the size of the boat*/
        
    {
        
        
        
        sizeboat--;
        
        while (sizeboat > 0)
            
        {
            
            GB1[line - i][column] = copiedsize;                                        /*We change 0 by the value of the size of the boat for a function that will check whether a boat is sinked or not. We thought that it was therefore easier to attribute a value for each boat*/
            
            sizeboat--;
            
            i++;
            
        }
        
    }
    
    else {
        
        
        
        if (position == 1)
            
        {
            
            sizeboat--;
            
            while (sizeboat > 0)
                
            {
                
                GB1[line + i][column] = copiedsize;
                
                sizeboat--;
                
                i++;
                
            }
            
        }
        
        else {
            
            if (position == 2)
                
            {
                
                sizeboat--;
                
                while (sizeboat > 0)
                    
                {
                    
                    GB1[line][column + i] = copiedsize;
                    
                    sizeboat--;
                    
                    i++;
                    
                }
                
            }
            
            else {
                
                if (position == 3)
                    
                {
                    
                    sizeboat--;
                    
                    while (sizeboat > 0)
                        
                    {
                        
                        GB1[line][column - i] = copiedsize;
                        
                        sizeboat--;
                        
                        i++;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
}



void finalplaceboat3(int sizeboat, int GB1[100][100], int position, int line, int column) {                  /*As there are 2 boats of three, we only find this solution to attribute a value for each boat*/
    
    int i = 1;
    
    if (position == 0)                                                                                   /*The process of this function is the same as the function finalplace just above*/
        
    {
        
        
        
        sizeboat--;
        
        while (sizeboat > 0)
            
        {
            
            GB1[line - i][column] = 6;
            
            sizeboat--;
            
            i++;
            
        }
        
    }
    
    else {
        
        
        
        if (position == 1)
            
        {
            
            sizeboat--;
            
            while (sizeboat > 0)
                
            {
                
                GB1[line + i][column] = 6;
                
                sizeboat--;
                
                i++;
                
            }
            
        }
        
        else {
            
            if (position == 2)
                
            {
                
                sizeboat--;
                
                while (sizeboat > 0)
                    
                {
                    
                    GB1[line][column + i] = 6;
                    
                    sizeboat--;
                    
                    i++;
                    
                }
                
            }
            
            else {
                
                if (position == 3)
                    
                {
                    
                    sizeboat--;
                    
                    while (sizeboat > 0)
                        
                    {
                        
                        GB1[line][column - i] = 6;
                        
                        sizeboat--;
                        
                        i++;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
}











void placeboat(int size, int sizeboat, int GB1[100][100])                        /*This function is used for the placement of each boat */

{
    
    int k, line, column, Checkplace[4];
    
    int position = -1;
    
    printf("Now you have to place a boat of size %d\n", sizeboat);                               /*First we ask the user the coordinates of the front of the boat*/
    
    printf("Enter the coordinates of the front of the boat\n");
    
    scanf_s("%d%d", &line, &column);
    
    while ((line > size) || (column > size) || (GB1[line][column] != 0))
        
    {
        
        printf("The coordinates must be in your grid of size %d and can't corresponds to the location of another boat, reenter the coordinates of the front of your boat\n", size);
        
        scanf_s("%d%d", &line, &column);
        
    }
    
    printf("The coordinates of the front of your boat is : line %d and column %d\n", line, column);
    
    GB1[line][column] = sizeboat;
    
    printf("The front of your boat is rempresented by a %d\n", sizeboat);
    
    displaygridboat(size, GB1);
    
    check(size, sizeboat, line, column, Checkplace, GB1);                            /*Here we call this function to determine the possibilities where the user can put his boat*/
    
    ask(Checkplace, &position);                                                                                            /*Here we ask the user where he wants to place his boat depending on the possible locations*/
    
    finalplace(sizeboat, GB1, position, line, column);                                   /*Here we replace 0 by the value of the size of the boat*/
    
    displaygridboat(size, GB1);
    
    
    
}



void placeboatsize3(int size, int sizeboat, int GB1[100][100])               /*This function as the same goal as the one above*/

{                                                                                                                                                                            /*Again, because each boat has a different value, we only thought of this possibility*/
    
    int k, line, column, Checkplace[4];
    
    int position = -1;
    
    printf("Now you have to place a boat of size %d\n", sizeboat);
    
    printf("Enter the coordinates of the front of the boat\n");
    
    scanf_s("%d%d", &line, &column);
    
    while ((line > size) || (column > size) || (GB1[line][column] != 0))
        
    {
        
        printf("The coordinates must be in your grid of size %d and can't corresponds to the location of another boat, reenter the coordinates of the front of your boat\n", size);
        
        scanf_s("%d%d", &line, &column);
        
    }
    
    printf("The coordinates of the front of your boat is : line %d and column %d\n", line, column);
    
    GB1[line][column] = 6;
    
    printf("The front of your boat is rempresented by a 6\n");
    
    displaygridboat(size, GB1);
    
    check(size, sizeboat, line, column, Checkplace, GB1);
    
    ask(Checkplace, &position);
    
    finalplaceboat3(sizeboat, GB1, position, line, column);
    
    displaygridboat(size, GB1);
    
    
    
}



void askcomputer(int Checkplace[4], int *position)           /*This function as the same principle as the function ask for the user. It just take a random value for the position, by checking that the boat can be properly inserted at this point*/

{
    
    srand(time(NULL));
    
    *position = (rand() % 4);
    
    while (Checkplace[*position] == 0)
        
    {
        
        srand(time(NULL));
        
        *position = (rand() % 4);
        
    }
    
    
    
    
    
}





void PlaceBoatComputer(int size, int sizeboat, int GB2[100][100])                /*This time, this function is used to place the boat of the computer*/

{
    
    int linecom, columncom, Checkplace[4];
    
    int position = -1;
    
    
    
    linecom = (rand() % size);                                                                   /*We ask the computer for a random choice of the line and the column*/
    
    columncom = (rand() % size);
    
    while (GB2[linecom][columncom] != 0)
        
    {
        
        linecom = (rand() % size);
        
        columncom = (rand() % size);
        
    }
    
    GB2[linecom][columncom] = sizeboat;
    
    check(size, sizeboat, linecom, columncom, Checkplace, GB2);
    
    askcomputer(Checkplace, &position);
    
    finalplace(sizeboat, GB2, position, linecom, columncom);
    
}



void PlaceBoatComputer3(int size, int sizeboat, int GB2[100][100])             /*As for the user, we decided to have a special function for the second boat of three*/

{
    
    int linecom, columncom, Checkplace[4];
    
    int position = -1;
    
    
    
    linecom = (rand() % 10);
    
    columncom = (rand() % 10);
    
    while (GB2[linecom][columncom] != 0)
        
    {
        
        linecom = (rand() % 10);
        
        columncom = (rand() % 10);
        
    }
    
    GB2[linecom][columncom] = 6;
    
    check(size, sizeboat, linecom, columncom, Checkplace, GB2);
    
    askcomputer(Checkplace, &position);
    
    finalplaceboat3(sizeboat, GB2, position, linecom, columncom);
    
}



int boatsink(int GB2[100][100], int size, int value)                        /*This function is used to say if a boat is sinked after each shot.*/

{
    
    int i, j;
    
    for (i = 0; i < size; i++)
        
    {
        
        for (j = 0; j < size; j++)
            
        {
            
            if (GB2[i][j] == value)                                                                           /*This is the reason why each boat as a different value*/
                
            {
                
                return 1;
                
            }
            
        }
        
    }
    
    return 0;
    
}



int presenceofboat(int GB1[100][100], int size)                            /*This function is used to check if there is still some boat on each grid*/

{                                                                                                                                             /*From the moment there is no more boat on a grid, the while loop used to pull in the main stops and the game is over.*/
    
    int i, j;
    
    for (i = 0; i < size; i++)
        
    {
        
        for (j = 0; j < size; j++)
            
        {
            
            if (GB1[i][j] != 0)
                
            {
                
                return 1;
                
            }
            
        }
        
    }
    
    return 0;
    
}



void smartcomputer(int linecom, int columncom, char GS2[100][100], int *smart)                           /*This function is part of the trivial intelligence artificial. There, we give the choice to the compyter to choose between the case above, under, on the right and on the left*/

{
    
    int i;
    
    int above = 0;
    
    int under = 0;
    
    int right = 0;
    
    int left = 0;
    
    int Checkplace[4];
    
    if (GS2[linecom - 1][columncom] == 'x')                                /*Here we check if the case above has already been targeted. If not, the variable above takes the value 1 and the computer will have the right to choose this case*/
        
    {
        
        above = 1;
        
    }
    
    if (GS2[linecom + 1][columncom] == 'x')
        
    {
        
        under = 1;
        
    }
    
    if (GS2[linecom][columncom + 1] == 'x')
        
    {
        
        right = 1;
        
    }
    
    if (GS2[linecom][columncom - 1] == 'x')
        
    {
        
        left = 1;
        
    }
    
    
    
    Checkplace[0] = above;                                                                      /*Here we enter the value of each variable in this array*/
    
    Checkplace[1] = under;
    
    Checkplace[2] = right;
    
    Checkplace[3] = left;
    
    
    
    
    
    *smart = (rand() % 4);                                                               /*Here the computer choose randomly where he is going to shoot next*/
    
    while (Checkplace[*smart] = 0)
        
    {
        
        *smart = (rand() % 4);
        
    }
    
}



int afterhit(int linecom, int columncom, int GB1[100][100], char GS2[100][100], int size)                   /*This function is part of the trivial intelligence artificial. It is used when the computer shoots on a boat*/

{
    
    int smart = -1;
    
    int linecopy, columncopy;
    
    smartcomputer(linecom, columncom, GS2, &smart);                                                /*After the choice made, we now know where does the computer has decided to shoot next*/
    
    linecopy = linecom;
    
    columncopy = columncom;
    
    if (smart == 0)                                                                                                                                /*If the computer has choosen 0, so the case above, we change the line, and the computer shoots again*/
        
    {
        
        linecom--;
        
        if (GB1[linecom][columncom] != 0)                                                                      /*Again, if the value of the case where where he has shot is different from 0, it mean sthath he has shot on a boat again*/
            
        {
            
            GS2[linecom][columncom] = 'h';
            
        }
        
        else
            
        {
            
            GS2[linecom][columncom] = 'm';
            
        }
        
    }
    
    else {
        
        if (smart == 1)
            
        {
            
            linecom++;
            
            if (GB1[linecom][columncom] != 0)
                
            {
                
                GS2[linecom][columncom] = 'h';
                
            }
            
            else
                
            {
                
                GS2[linecom][columncom] = 'm';
                
            }
            
        }
        
        else {
            
            if (smart == 2)
                
            {
                
                columncom++;
                
                if (GB1[linecom][columncom] != 0)
                    
                {
                    
                    GS2[linecom][columncom] = 'h';
                    
                }
                
                else
                    
                {
                    
                    GS2[linecom][columncom] = 'm';
                    
                }
                
                
                
            }
            
            else {
                
                if (smart == 3)
                    
                {
                    
                    columncom--;
                    
                    if (GB1[linecom][columncom] != 0)
                        
                    {
                        
                        GS2[linecom][columncom] = 'h';
                        
                    }
                    
                    else
                        
                    {
                        
                        GS2[linecom][columncom] = 'm';
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    if (GB1[linecom][columncom] != 0)                                        /*If the computer has shot a boat again, he has the right to shhot again. So we recall the function afterhit*/
        
    {
        
        if (presenceofboat(GB1, size) == 0)
            
        {
            
            return 0;
            
        }
        
        afterhit(linecom, columncom, GB1, GS2, size);
        
    }
    
    return 1;
    
    
    
}



int computershoot(int GB1[100][100], char GS2[100][100], int size)            /*This is the function where the computer shoot on the boat of the user*/

{
    
    int linecom, columncom, valuecom;
    
    srand(time(NULL));
    
    linecom = (rand() % size);                                                                             /*Here the computer select randomly the line and the column where he is going to shoot*/
    
    columncom = (rand() % size);
    
    while ((GS2[linecom][columncom] == 'm') && (GS2[linecom][columncom] == 'h'))
        
    {
        
        linecom = (rand() % size);                                                                   /*If the computer already shot at this place, he can choose other coordinates*/
        
        columncom = (rand() % size);
        
    }
    
    if (GB1[linecom][columncom] != 0)                                                            /*If it's different from 0 on the grid GB1, it means that the user placed a boat there, and that he has shot a boat*/
        
    {
        
        valuecom = GB1[linecom][columncom];
        
        GB1[linecom][columncom] = 0;
        
        printf("\n\n\n\n");
        
        GS2[linecom][columncom] = 'h';                                                      /*Here we replace 'x' by 'h' on the grid score of the computer because he shoots a boat*/
        
        boatsink(GB1, size, valuecom);                                                         /*Here we check if the boat has sinked one of the boat of the user*/
        
        if (boatsink(GB1, size, valuecom) == 0)
            
        {
            
            printf("One of your boat is sinked\n");
            
        }
        
        if (presenceofboat(GB1, size) == 0)
            
        {
            
            return 0;
            
        }
        
        afterhit(linecom, columncom, GB1, GS2, size);                                        /*As he shot a boat, the computer has the right to shoot again*/
        
        displaygridscore(size, GS2);
        
        
        
    }
    
    else
        
    {
        
        GS2[linecom][columncom] = 'm';                                                     /*Here we replace 'x' by 'm' on the grid score of the computer because he shoots a boat*/
        
        displaygridscore(size, GS2);
        
    }
    
    return 1;
    
}







int usershoot(int GB2[100][100], char GS1[100][100], int size)                      /*This is the function where the user will shoots on the grid of the computer*/

{
    
    int lineuser, columnuser, value;
    
    displaygridscore(size, GS1);                                                                                             /*First, we display the grid score to show to the user where he has already shot*/
    
    printf("Enter the line and the column where you want to shoot\n");
    
    scanf_s("%d%d", &lineuser, &columnuser);
    
    while (GS1[lineuser][columnuser] != 'x')                                                             /*If he has already shot on a case, he has the right to reenter the coordinates*/
        
    {
        
        printf("You already shoot there. Enter other coordinates.\n");
        
        scanf_s("%d%d", &lineuser, &columnuser);
        
    }
    
    while ((lineuser > size) || (columnuser > size))
        
    {
        
        printf("The coordinates are not in the grid. Reenter the coordinates where you want to shoot\n");
        
        scanf_s("%d%d", &lineuser, &columnuser);
        
    }
    
    printf("Launching the missile at line %d, column %d\n", lineuser, columnuser);
    
    if (GB2[lineuser][columnuser] != 0)                                                                                           /*If it's different from 0 on the grid GB2, it means that the computer placed a boat there, and that he has shot a boat*/
        
    {
        
        value = GB2[lineuser][columnuser];
        
        GB2[lineuser][columnuser] = 0;
        
        boatsink(GB2, size, value);                                                                                                /*Here we check if one of the boat of the computer is sinked*/
        
        if (boatsink(GB2, size, value) == 0)
            
        {
            
            printf("Boat sinked\n");
            
        }
        
        presenceofboat(GB2, size);
        
        if (presenceofboat(GB2, size) == 0)
            
        {
            
            return 0;
            
        }
        
        printf("Vessels affected, you can shoot again\n");
        
        GS1[lineuser][columnuser] = 'h';                                                                          /*If the user has shot on a boat  we replace 'x' by 'h' on the grid score of the user because he shoots a boat*/
        
        usershoot(GB2, GS1, size);                                                                                                /*We call the function usershoot while the user shoots on a boat*/
        
    }
    
    else
        
    {
        
        printf("The missile arrived in the water\n");
        
        GS1[lineuser][columnuser] = 'm';
        
        displaygridscore(size, GS1);
        
        printf("Your turn is over\n");
        
    }
    
    return 1;
    
    
    
}













int main() {
    
    
    
    srand(time(NULL));
    
    int GB1[100][100], GB2[100][100];
    
    int size, sizeboat, pl, linecopy, columncopy;
    
    char GS1[100][100], GS2[100][100];
    
    char P;
    
    pl = ChoosePlayer();
    
    do {
        
        printf("Hello, are you ready to start the fight ?\nPress p to play.\n");
        
        scanf_s(" %c", &P);
        
    } while (P != 'P'&& P != 'p');
    
    
    
    ;
    
    while (pl == 1 || pl == 2) {
        
        // system("cls");
        
        
        
        printf("You will have the possibility to choose between three game modes. The first one will be a fast mode where the size of your grid will be between 4 and 6, and you will only have to place 4 boats.\nThe second game mode will be the classic battleship game with a size of 10, and you will have 5 boats to place.\nThe last one will be a customize mode where the size will be between 7 and 25, and you will have 5 boats to place.\n");
        
        printf("Enter the size of your grids\n");                                          /*Here we present the different game modes which are possible.*/
        
        scanf_s("%d", &size);
        
        while ((size < 4) || (size > 25))
            
        {
            
            printf("The size of your grids must bebetwenn 4 and 25. Reenter the size of your grids\n");
            
            scanf_s("%d", &size);
            
        }
        
        creationofthegrid(size, GB1, GB2, GS1, GS2);
        
        printf("This is the grid where you will place your boat\n");
        
        displaygridboat(size, GB1);
        
        printf("This is the grid where you will try to shoot the boat\n");
        
        displaygridscore(size, GS1);
        
        printf("You will be player 1 and the computer will be player 2 \n");
        
        
        
        if (size > 6)                                                    /*As the number of boat to place depends on the game mode, if the size of the grid is bigger than 6, we have to place 5 boats and the computer will have to place also 5 boats*/
            
        {
            
            sizeboat = 5;
            
            placeboat(size, sizeboat, GB1);
            
            
            
            sizeboat = 4;
            
            placeboat(size, sizeboat, GB1);
            
            
            
            sizeboat = 3;
            
            placeboat(size, sizeboat, GB1);
            
            
            
            sizeboat = 3;
            
            placeboatsize3(size, sizeboat, GB1);
            
            
            
            sizeboat = 2;
            
            placeboat(size, sizeboat, GB1);
            
            
            
            
            
            sizeboat = 5;
            
            PlaceBoatComputer(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            sizeboat = 4;
            
            PlaceBoatComputer(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            sizeboat = 3;
            
            PlaceBoatComputer(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            sizeboat = 3;
            
            PlaceBoatComputer3(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            sizeboat = 2;
            
            PlaceBoatComputer(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            
            
            presenceofboat(GB1, size);
            
            presenceofboat(GB2, size);
            
            while ((presenceofboat(GB1, size) == 1) && (presenceofboat(GB2, size) == 1))           /*The firing loop stops as soon as, on one of the 2 boat grids, there are no more boats.*/
                
            {
                
                printf("Players  %d turn\n", pl);
                
                if (usershoot(GB2, GS1, size) == 0)
                    
                {
                    
                    break;
                    
                }
                
                computershoot(GB1, GS2, size);
                
            }
            
            printf("\n\n\n\n\nIt's finally over\n");
            
            if (presenceofboat(GB1, size) == 0)                                                                                 /*If there is no more boat on the grid 1, it means that the computer has shots all the boats first, and so the computer has won*/
                
            {
                
                printf("You have lost\n");
                
            }
            
            else
                
            {
                
                printf("You have won\n");
                
            }
            
            printf("Press a button to start again\n");
            
            system("pause");
            
        }
        
        else
            
        {                                                                                                                                                                            /*Here we do the same process, but the game mode changes because the size of the grids is less or equal to 6. So the user and the computer have just to place 4 boats*/
            
            sizeboat = 4;
            
            placeboat(size, sizeboat, GB1);
            
            
            
            sizeboat = 3;
            
            placeboat(size, sizeboat, GB1);
            
            
            
            sizeboat = 3;
            
            placeboatsize3(size, sizeboat, GB1);
            
            
            
            sizeboat = 2;
            
            placeboat(size, sizeboat, GB1);
            
            
            
            sizeboat = 4;
            
            PlaceBoatComputer(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            sizeboat = 3;
            
            PlaceBoatComputer(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            sizeboat = 3;
            
            PlaceBoatComputer3(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            sizeboat = 2;
            
            PlaceBoatComputer(size, sizeboat, GB2);
            
            displaygridboat(size, GB2);
            
            
            
            
            
            presenceofboat(GB1, size);
            
            presenceofboat(GB2, size);
            
            while ((presenceofboat(GB1, size) == 1) && (presenceofboat(GB2, size) == 1))
                
            {
                
                printf("Players  %d turn\n", pl);
                
                if (usershoot(GB2, GS1, size) == 0)
                    
                {
                    
                    break;
                    
                }
                
                computershoot(GB1, GS2, size);
                
            }
            
            printf("\n\n\n\n\nIt's finally over\n");
            
            if (presenceofboat(GB1, size) == 0)
                
            {
                
                printf("You have lost\n");
                
            }
            
            else
                
            {
                
                printf("You have won\n");
                
            }
            
            printf("Press a button to start again\n");
            
            system("pause");
            
        }
        
        
        
    }
