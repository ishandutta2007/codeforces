#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int F[2001][2001];
Int p[2001];
Int n;
Int fact[2001];
const Int MOD=1000000007;
bool ontheinput[2001];

int main()
{
    Int i,j;
    Int k=0;
    Int N;

    memset(ontheinput,false,sizeof(ontheinput));

    fact[0]=1;
    for (i=1;i<=2000;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }

    scanf("%I64d",&n);
    N=n;

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&p[i]);

        ontheinput[ p[i] ]=true;

        if (p[i]!=-1)
        N--;
    }

    for (i=1;i<=n;i++)
    {
        if (p[i]==-1 && !ontheinput[i])
        {
            k++;
        }
    }

    F[1][0]=1;
    F[1][1]=0;

    for (i=2;i<=n;i++)
    {
        F[i][0]=fact[i];
        F[i][1]=( F[i-1][0]*(i-1) )%MOD;
        for (j=2;j<=i;j++)
        {
            F[i][j]=( ( F[i-1][j-1]*(i-j) ) + ( F[i-1][j-2]*(j-1) ) )%MOD;
        }
    }

    printf("%I64d\n",F[N][k]);

    return 0;
}