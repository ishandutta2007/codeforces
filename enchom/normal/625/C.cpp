#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n,k;
int grid[511][511];

int main()
{
    int i,j;
    Int sum=0;
    int ctr;

    scanf("%d %d",&n,&k);

    ctr=n*n;

    for (i=1;i<=n;i++)
    {
        for (j=n;j>=k;j--)
        {
            grid[i][j]=ctr;
            ctr--;
        }

        sum+=(Int)grid[i][k];
    }

    for (i=1;i<=n;i++)
    {
        for (j=k-1;j>=1;j--)
        {
            grid[i][j]=ctr;
            ctr--;
        }
    }

    printf("%lld\n",sum);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (j!=1)
            printf(" ");
            printf("%d",grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}