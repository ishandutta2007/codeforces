#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n;
Int k;
Int a[100111];
Int b[100111];

inline Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

bool Okay(Int p)
{
    int i;
    Int need=0;

    for (i=1;i<=n;i++)
    {
        need+=MAX(0,p*a[i]-b[i]);

        if (need>k)
        return false;
    }

    return true;
}

int main()
{
    int i;
    Int l,r,mid,best=0;
    Int sumhave,sumneed=0;

    scanf("%d %lld",&n,&k);

    sumhave=k;

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);

        sumneed+=a[i];
    }

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);

        sumhave+=b[i];
    }

    l=1;
    r=sumhave/sumneed+2LL;

    while(l<=r)
    {
        mid=(l+r)/2LL;

        if (Okay(mid))
        {
            best=mid;
            l=mid+1LL;
        }
        else
        {
            r=mid-1LL;
        }
    }

    printf("%lld\n",best);

    return 0;
}