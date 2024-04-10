#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;

bool dig[10];

bool SameDigits(Int k)
{
    while(k>0)
    {
        if ( dig[k%10] )
        return true;
        else
        k=k/10;
    }
    return false;
}

int main()
{
    Int i;
    Int z,x;
    Int copy;
    Int num1,num2;
    Int ctr=0;
    
    for (i=0;i<=9;i++)
    dig[i]=false;
    
    scanf("%I64d",&x);
    copy=x;
    
    while(copy>0)
    {
        dig[copy%10]=true;
        copy=copy/10;
    }
    
    z=sqrt(x);
    
    for (i=1;i<=z;i++)
    {
        if (i*i==x)
        {
            if (SameDigits(i))
            ctr++;
        }
        else
        {
            if (x%i==0)
            {
                if (SameDigits(i))
                ctr++;
                
                if (SameDigits(x/i))
                ctr++;
            }
        }
    }
    printf("%I64d\n",ctr);
    return 0;
}