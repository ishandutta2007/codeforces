#include <iostream>
#include <stdio.h>
using namespace std;

int def[5];
int atk[5];

int main()
{
    int i;
    int result[5];

    for (i=1;i<=4;i++)
    {
        scanf("%d %d",&atk[i],&def[i]);
    }

    ///1 2 3 4
    if ( def[1]>atk[4] && atk[2]>def[3] )
    result[1]=1;
    else if ( def[1]<atk[4] && atk[2]<def[3] )
    result[1]=2;
    else
    result[1]=0;

    ///1 2 4 3
    if ( def[1]>atk[3] && atk[2]>def[4] )
    result[2]=1;
    else if ( def[1]<atk[3] && atk[2]<def[4] )
    result[2]=2;
    else
    result[2]=0;

    ///2 1 3 4
    if ( def[2]>atk[4] && atk[1]>def[3] )
    result[3]=1;
    else if ( def[2]<atk[4] && atk[1]<def[3] )
    result[3]=2;
    else
    result[3]=0;

    ///2 1 4 3
    if ( def[2]>atk[3] && atk[1]>def[4] )
    result[4]=1;
    else if ( def[2]<atk[3] && atk[1]<def[4] )
    result[4]=2;
    else
    result[4]=0;

    if ( (result[1]==1 && result[2]==1) || (result[3]==1 && result[4]==1) )
    {
        printf("Team 1\n");
    }
    else if ( (result[1]==2 || result[2]==2) && (result[3]==2 || result[4]==2) )
    {
        printf("Team 2\n");
    }
    else
    {
        printf("Draw\n");
    }

    return 0;
}