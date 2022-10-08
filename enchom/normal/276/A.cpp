#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n,k;
    Int i;
    Int f,t;
    Int maxjoy=-999999999999999;
    Int joy;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&f,&t);
        
        if (t<=k)
        {
            joy=f;
        }
        else
        {
            joy=f-(t-k);
        }
        if (maxjoy<joy)
        maxjoy=joy;
    }
    printf("%I64d\n",maxjoy);
    return 0;
}