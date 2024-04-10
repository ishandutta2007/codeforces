#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

bool grid[1001][1001];
int i,j;

int main()
{
    int n;
    int ctr=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        if (i%2==1)
        {
            grid[i][1]=true;
            ctr++;
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=2;j<=n;j++)
        {
            if (!grid[i][j-1])
            {
                grid[i][j]=true;
                ctr++;
            }
        }
    }

    printf("%d\n",ctr);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (grid[i][j])
            printf("C");
            else
            printf(".");
        }
        printf("\n");
    }

    return 0;
}