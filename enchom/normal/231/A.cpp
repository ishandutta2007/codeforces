#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int a,b,c;
    Int ctr=0;
    Int i;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d %I64d",&a,&b,&c);
        if (a+b+c>=2)
        ctr++;
    }
    printf("%I64d\n",ctr);
    return 0;
}