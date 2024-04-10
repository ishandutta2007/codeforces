#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int i;
    Int passengers=0,pmax=0;
    Int a,b;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        
        passengers-=a;
        passengers+=b;
        if (passengers>pmax)
        pmax=passengers;
    }
    printf("%I64d\n",pmax);
    return 0;
}