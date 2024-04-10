#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int grid[5][5];
Int endgrid[5][5];

int main()
{
    Int i,j;
    
    for (i=0;i<=4;i++)
    {
        for (j=0;j<=4;j++)
        grid[i][j]=0;
    }
    
    for (i=1;i<=3;i++)
    {
        for (j=1;j<=3;j++)
        {
            scanf("%I64d",&grid[i][j]);
        }
    }
    
    for (i=1;i<=3;i++)
    {
        for (j=1;j<=3;j++)
        {
            endgrid[i][j]=(grid[i][j]+grid[i+1][j]+grid[i-1][j]+grid[i][j-1]+grid[i][j+1]+1)%2;
            printf("%I64d",endgrid[i][j]);
        }
        printf("\n");
    }
    return 0;
}