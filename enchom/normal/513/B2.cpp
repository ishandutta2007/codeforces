#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int seq[101];

void Get(Int n,Int ctr)
{
    if (n==1)
    {
        seq[1]=1;
        return;
    }

    Int mid=(1LL<<(n-2));
    int i;
    Int swp;

    if (ctr<=mid)
    {
        Get(n-1,ctr);

        for (i=n;i>1;i--)
        {
            seq[i]=seq[i-1]+1;
        }
        seq[1]=1;
    }
    else
    {
        Get(n-1,2*mid-ctr+1);

        for (i=1;i<=(n-1)/2;i++)
        {
            swp=seq[i];
            seq[i]=seq[n-i];
            seq[n-i]=swp;
        }

        for (i=1;i<=n-1;i++)
        {
            seq[i]++;
        }

        seq[n]=1;
    }

    return;
}

int main()
{
    int i;
    Int n;
    Int c;

    scanf("%I64d",&n);
    scanf("%I64d",&c);

    Get(n,c);

    for (i=1;i<=n;i++)
    {
        printf("%lld",seq[i]);
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}