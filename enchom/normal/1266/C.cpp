#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int n,m;
int grid[1011][1011];

int main()
{
    int i,j;

    scanf("%d %d",&n,&m);

    if (n == 1 && m == 1)
    {
        printf("0\n");
        return 0;
    }

    if (m == 1)
    {
        for (i=1;i<=n;i++)
        {
            printf("%d\n", i+1);
        }

        return 0;
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            grid[i][j] = i;
        }
    }

    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            grid[j][i] *= (n + i);
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            printf("%d",grid[i][j]);

            if (j != m)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}