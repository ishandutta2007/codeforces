#include <iostream>
#include <stdio.h>
using namespace std;
typedef long double Double;

Double MAX(Double a,Double b)
{
    if (a>b)
    return a;
    else
    return b;
}

int n;
Double arr[200111];
Double bestsum,worstsum;

void GetSums(Double x)
{
    int i;
    Double cursum,val;

    bestsum=0.0;
    worstsum=0.0;

    cursum=0.0;
    for (i=1;i<=n;i++)
    {
        cursum+=(arr[i]-x);
        if (cursum<0.0)
        cursum=0.0;

        if (cursum>bestsum)
        bestsum=cursum;
    }

    cursum=0.0;
    for (i=1;i<=n;i++)
    {
        cursum+=(arr[i]-x);
        if (cursum>0.0)
        cursum=0.0;

        if (cursum<worstsum)
        worstsum=cursum;
    }

    worstsum=-worstsum;

    return;
}

int main()
{
    int i;
    Double l,r,mid;
    Double ans=0.0;
    int a;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a);
        arr[i]=(Double)a;
    }

    GetSums(0.0);
    ans=MAX(bestsum,worstsum);
    l=-200000.0;
    r=200000.0;

    while( (r-l)>0.00000000001 )
    {
        mid=(l+r)/2.0;

        GetSums(mid);

        if ( MAX(bestsum,worstsum)<ans )
        ans=MAX(bestsum,worstsum);

        if (bestsum>worstsum)
        l=mid;
        else
        r=mid;
    }

    printf("%.7f\n",(double)ans);

    return 0;
}