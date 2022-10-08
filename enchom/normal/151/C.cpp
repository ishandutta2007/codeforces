#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

int main()
{
    Int q;
    Int org=q;
    Int i;
    Int divisors=0;
    Int times=0,multi=1;
    
    scanf("%I64d",&q);
    
    for (i=2;i*i<=q;i++)
    {
        while (q%i==0)
        {
            divisors++;
            q=q/i;
            
            if (times<2)
            {
                multi=multi*i;
                times++;
            }
        }
    }
    if (q>1)
    {
        if (divisors>0)
        divisors++;
    }
    
    if (divisors<2)
    {
        printf("1\n0\n");
        return 0;
    }
    else if (divisors==2)
    {
        printf("2\n");
        return 0;
    }
    else
    {
        printf("1\n%I64d\n",multi);
        return 0;
    }
}