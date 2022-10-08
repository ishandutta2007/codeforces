#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n;

int main()
{
    Int l,r,mid,best;
    Int ans=0;

    scanf("%I64d",&n);

    l=0;
    r=10000000;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (2LL*n >= 3LL*mid*mid+mid)
        {
            best=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    if (n%3==0)
    ans=best/3;
    if (n%3==1)
    ans=(best+1)/3;
    if (n%3==2)
    ans=(best+2)/3;

    printf("%I64d\n",ans);

    return 0;
}