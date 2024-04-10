#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int Gaus(Int k)
{
    return ( k*(k+1) )/2;
}

int main()
{
    Int n,k;
    Int toplimit;
    Int l,r;
    Int mid;
    Int sum,amount;
    Int bestamount,bestsum;

    scanf("%I64d %I64d",&n,&k);
    k--;
    n--;

    if (Gaus(k)<n)
    {
        printf("-1\n");
        return 0;
    }
    if (n==0)
    {
        printf("0\n");
        return 0;
    }
    if (n<=k)
    {
        printf("1\n");
        return 0;
    }

    l=1;
    r=k;

    while(l<=r)
    {
        mid=(l+r)/2;

        sum=Gaus(k)-Gaus(mid-1);
        amount=k-mid+1;

        if (sum<=n)
        {
            bestamount=amount;
            bestsum=sum;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    n-=bestsum;
    k=k-bestamount;

    if (n==0)
    {
        printf("%I64d\n",bestamount);
    }
    else
    {
        printf("%I64d\n",bestamount+1);
    }

    return 0;
}