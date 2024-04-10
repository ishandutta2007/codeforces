#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n;
Int k;
Int coef[200111];
Int org[200111];
Int threshold;

Int ABS(Int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

int main()
{
    int i,j;
    int firstnonzero=-1;
    Int cursum=0;
    Int newval;
    int ans=0;

    scanf("%d",&n);
    scanf("%lld",&k);

    n++;

    threshold=4LL*k;

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&coef[i]);
        org[i]=coef[i];
    }

    for (i=1;i<n;i++)
    {
        if (ABS(coef[i])%2==0)
        {
            coef[i+1]+=coef[i]/2;
            coef[i]=0;
        }
        else
        {
            coef[i+1]+=(coef[i]-1)/2;
            coef[i]=1;
        }

        if (coef[i]!=0 && firstnonzero==-1)
        {
            firstnonzero=i;
        }
    }

    if (firstnonzero==-1)
    firstnonzero=n;

    cursum=0;
    for (i=n;i>=firstnonzero;i--)
    {
        cursum*=2LL;
        cursum+=coef[i];

        if (cursum>threshold || cursum<-threshold)
        {
            printf("0\n");
            return 0;
        }
    }

    for (i=firstnonzero;i>=1;i--)
    {
        newval=org[i]-cursum;

        if (newval>=-k && newval<=k)
        {
            if (firstnonzero!=n || newval!=0)
            ans++;
        }
        cursum*=2LL;

        if (cursum>threshold || cursum<-threshold)
        break;
    }

    printf("%d\n",ans);

    return 0;
}

/**
3 12
10 -9 -3 5
**/