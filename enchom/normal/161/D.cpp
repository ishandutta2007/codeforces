#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
typedef long long Int;

Int n,k;
vector<Int> Graph[50001];
Int F[50001][501];
Int total=0;
Int add=0;

void Calc(Int ver,Int dad)
{
    Int i,j;

    F[ver][0]=1;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        Calc(Graph[ver][i],ver);

        for (j=1;j<=k;j++)
        {
            F[ver][j]+=F[ Graph[ver][i] ][j-1];
        }
    }

    total+=F[ver][k];

    return;
}

void Compute(Int ver,Int dad)
{
    Int i,j;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        Compute(Graph[ver][i],ver);

        for (j=1;j<=k-1;j++)
        {
            add=add+( F[ Graph[ver][i] ][j-1] )*( F[ver][k-j]-F[ Graph[ver][i] ][k-j-1] );
        }
    }
}

int main()
{
    Int i;
    Int a,b;

    memset(F,0,sizeof(F[0][0])*50001*501);

    scanf("%I64d %I64d",&n,&k);

    for (i=1;i<=n-1;i++)
    {
        scanf("%I64d %I64d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    Calc(1,0);

    Compute(1,0);

    add/=2;

    total+=add;

    printf("%I64d\n",total);

    return 0;
}