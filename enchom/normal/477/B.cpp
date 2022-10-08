#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;
int sets[10001][5];

int main()
{
    int i,j;
    int cur;
    int m;

    scanf("%d %d",&n,&k);

    cur=1;
    for (i=1;i<=n;i++)
    {
        sets[i][1]=cur;
        sets[i][2]=cur+1;
        sets[i][3]=cur+2;
        sets[i][4]=cur+4;

        cur+=6;
    }

    m=sets[n][4]*k;

    printf("%d\n",m);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=4;j++)
        {
            printf("%d",sets[i][j]*k);
            if (j!=4)
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}