#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int F[511][511];
int c[511];
int n;

inline int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    int i,j,in;
    int L,R;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }

    memset(F,0,sizeof(F));

    for (i=1;i<=n;i++)
    {
        F[i][i]=1;
    }

    for (i=1;i<n;i++)
    {
        if (c[i]==c[i+1])
        F[i][i+1]=1;
        else
        F[i][i+1]=2;
    }

    for (i=2;i<=n-1;i++)
    {
        for (j=1;j<=n-i;j++)
        {
            L=j;
            R=j+i;

            F[L][R]=F[L+1][R]+1;
            if (c[L]==c[L+1])
            F[L][R]=MIN(F[L][R],1+F[L+2][R]);

            for (in=L+2;in<=R;in++)
            {
                if (c[in]==c[L])
                F[L][R]=MIN(F[L][R],F[L+1][in-1]+F[in+1][R]);
            }
        }
    }

    printf("%d\n",F[1][n]);

    return 0;
}