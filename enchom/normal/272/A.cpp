#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int i;
    Int ctr=0;
    Int a;
    Int total=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        ctr+=a;
    }
    
    for (i=1;i<=5;i++)
    {
        if ( (ctr+i)%(n+1)!=1 )
        total++;
    }
    
    printf("%I64d\n",total);
    return 0;
}