#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

bool Lucky(Int k)
{
    while(k>0)
    {
        if (k%10!=4 && k%10!=7)
        return false;
        
        k=k/10;
    }
    return true;
}

int main()
{
    Int n;
    Int i;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        if (Lucky(i))
        {
            if (n%i==0)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}