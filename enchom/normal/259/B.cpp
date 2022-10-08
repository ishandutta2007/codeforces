#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;

Int table[4][4];

int main()
{
    Int i,j;
    Int total;
    Int x1,x2,x3;
    
    for (i=1;i<=3;i++)
    {
        for (j=1;j<=3;j++)
        {
            scanf("%I64d",&table[i][j]);
        }
    }
    
    total=1;
    while(1)
    {
        x1=total-(table[2][1]+table[3][1]);
        x2=total-(table[1][2]+table[3][2]);
        x3=total-(table[1][3]+table[2][3]);
        
        if (x1>0 && x1<=100000 && x2>0 && x2<=100000 && x3>0 && x3<=100000 && x1+x2+x3==total)
        {
            table[1][1]=x1;
            table[2][2]=x2;
            table[3][3]=x3;
            break;
        }
        total++;
    }
    
    for (i=1;i<=3;i++)
    {
        for (j=1;j<=3;j++)
        {
            printf("%I64d",table[i][j]);
            
            if (j!=3)
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}