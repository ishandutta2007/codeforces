#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
int B[101][101];
int A[101][101];

int main()
{
    int i,j,in;
    bool good;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            A[i][j]=1;
            scanf("%d",&B[i][j]);
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (B[i][j]==0)
            {
                for (in=1;in<=n;in++)
                {
                    A[in][j]=0;
                }

                for (in=1;in<=m;in++)
                {
                    A[i][in]=0;
                }
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (B[i][j]==1)
            {
                good=false;

                for (in=1;in<=n;in++)
                {
                    if (A[in][j]==1)
                    good=true;
                }

                for (in=1;in<=m;in++)
                {
                    if (A[i][in]==1)
                    good=true;
                }

                if (!good)
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }

    printf("YES\n");

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            printf("%d",A[i][j]);

            if (j!=m)
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}