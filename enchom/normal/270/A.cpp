#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int t,a;
    Int i,j;
    Int n;
    
    scanf("%I64d",&t);
    
    for (i=1;i<=t;i++)
    {
        scanf("%I64d",&a);
        
        if (360%(180-a)==0)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}