#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int y,n,k;
    Int i;
    bool visit=false;
    
    scanf("%I64d %I64d %I64d",&y,&k,&n);
    
    for (i=k;i<=n;i+=k)
    {
        if (i>y)
        {
            if (!visit)
            printf("%I64d",i-y);
            else
            printf(" %I64d",i-y);
            
            visit=true;
        }
    }
    if (!visit)
    printf("-1");
    
    printf("\n");
    return 0;
}