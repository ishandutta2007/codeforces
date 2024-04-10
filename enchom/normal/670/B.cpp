#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n;
Int k;
Int id[100111];

int main()
{
    int i;
    int l,r,mid,best;
    Int said;
    int speaker;

    scanf("%d %lld",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&id[i]);
    }

    l=1;
    r=n-1;
    best=0;

    while(l<=r)
    {
        mid=(l+r)/2;

        said=((Int)mid*(Int)(mid+1))/2LL;

        if (said<k)
        {
            best=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    speaker=best+1;
    k-=((Int)best*(Int)(best+1))/2LL;

    printf("%lld\n",id[k]);

    return 0;
}