#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int arr[200111];
int n;
int k,x;
Int preOR[200111];
Int sufOR[200111];

int main()
{
    int i;
    Int bigval=-1;
    int bigind;
    Int ans=0;
    Int multi=1;
    Int MAXOR,CUROR;

    scanf("%d %d %d",&n,&k,&x);

    for (i=1;i<=k;i++)
    {
        multi*=(Int)x;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    preOR[0]=0;
    for (i=1;i<=n;i++)
    {
        preOR[i]=(preOR[i-1]|arr[i]);
    }

    sufOR[n+1]=0;
    for (i=n;i>=1;i--)
    {
        sufOR[i]=(sufOR[i+1]|arr[i]);
    }

    MAXOR=preOR[n];

    for (i=1;i<=n;i++)
    {
        CUROR=(preOR[i-1]|sufOR[i+1]|(arr[i]*multi));
        if (CUROR>MAXOR)
        MAXOR=CUROR;
    }

    printf("%lld\n",MAXOR);

    return 0;
}