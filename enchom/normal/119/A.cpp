#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

int main()
{
    Int a,b,n;
    bool SimonMove=true;
    Int gcd;
    Int i;
    
    scanf("%I64d %I64d %I64d",&a,&b,&n);
    
    while(1)
    {
        if (n==0)
        {
            if (SimonMove)
            {
                printf("1\n");
                break;
            }
            else
            {
                printf("0\n");
                break;
            }
        }
        
        for (i=n;i>=1;i--)
        {
            if (SimonMove)
            {
                if (a%i==0 && n%i==0)
                {
                    gcd=i;
                    break;
                }
            }
            else
            {
                if (b%i==0 && n%i==0)
                {
                    gcd=i;
                    break;
                }
            }
        }
        
        n=n-gcd;
        
        if (SimonMove)
        SimonMove=false;
        else
        SimonMove=true;
    }
    return 0;
}