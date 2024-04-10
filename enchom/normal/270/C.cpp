#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ClosestSquareRoot(Int k)
{
    Int l=1,r=1000000,mid;
    Int rem;
    
    while(l<=r)
    {
        mid=(l+r)/2;
        
        if (mid*mid>=k)
        {
            rem=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return rem;
}

Int AmountOfTwos(Int k)
{
    Int ctr=1;
    Int power=2;
    
    while(power<k)
    {
        power=power*2;
        ctr++;
    }
    return ctr;
}

int main()
{
    Int n;
    Int i;
    Int a,k;
    Int q;
    Int req;
    Int maxreq=-1;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&k,&a);
        
        q=ClosestSquareRoot(a);
        q=AmountOfTwos(q);
        
        req=k+q;
        
        if (req>maxreq)
        maxreq=req;
    }
    printf("%I64d\n",maxreq);
    return 0;
}