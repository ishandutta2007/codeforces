#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;
#define INF 2000000000

int n,k;
int presums[4001][4001];

int Cost(int L,int R)
{
    return (presums[R][R]-presums[L-1][R]-presums[R][L-1]+presums[L-1][L-1])/2;
}

int F[801][4001];
int opt[801][4001];

void Solve(int gond,int L,int R,int optL,int optR)
{
    if (L>R)
    return;

    int M=(L+R)/2;
    int i;
    int val;
    int bestval=INF;

    for (i=optL;i<=optR;i++)
    {
        val=F[gond-1][i]+Cost(i+1,M);

        if (val<bestval)
        {
            bestval=val;
            opt[gond][M]=i;
        }
    }

    F[gond][M]=bestval;

    if (L==R)
    return;

    Solve(gond,L,M-1,optL,opt[gond][M]);
    Solve(gond,M+1,R,opt[gond][M],optR);

    return;
}

int main()
{
    int i,j;
    char p;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            p=getchar();

            if (p>='0' && p<='9')
            presums[i][j]=presums[i-1][j]+presums[i][j-1]-presums[i-1][j-1]+p-'0';
            else
            j--;
        }
    }

    for (i=1;i<=n;i++)
    {
        F[1][i]=Cost(1,i);
        ///printf("F[1][%d]=%d\n",i,F[1][i]);
    }

    for (i=2;i<=k;i++)
    {
        Solve(i,1,n,1,n);
    }

    printf("%d\n",F[k][n]);

    return 0;
}