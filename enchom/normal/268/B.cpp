#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int sum=0;
    Int i;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        sum=sum+(n-i)*i+1;
    }
    
    printf("%I64d\n",sum);
    return 0;
}