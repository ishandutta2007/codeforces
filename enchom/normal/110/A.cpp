#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int ctr=0;
    
    scanf("%I64d",&n);
    
    while(n>0)
    {
        if (n%10==7 || n%10==4)
        ctr++;
        
        n=n/10;
    }
    if (ctr==4 || ctr==7)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}