#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int games;
Int a[100001];
Int n;

bool Check(Int k)
{
    Int i;
    Int val;
    Int supervisors=0;

    for (i=1;i<=n;i++)
    {
        val=a[i]-k;

        if (val>0)
        return false;
        else
        supervisors+=0-val;
    }

    return supervisors>=k;
}

int main()
{
    Int i;
    Int l,r,mid,best;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }

    l=0;
    r=10000000000;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (Check(mid))
        {
            best=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    printf("%I64d\n",best);

    return 0;
}