#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int ans;
    
    scanf("%I64d",&n);
    
    if (n<=2)
    {
        printf("%I64d\n",n);
        return 0;
    }
    if (n==3)
    {
        printf("6\n");
        return 0;
    }
    
    if (n%2==0)
    {
        if (n%3==0)
        ans=(n-1)*(n-2)*(n-3);
        else
        ans=n*(n-1)*(n-3);
    }
    else
    {
        ans=n*(n-1)*(n-2);
    }
    printf("%I64d\n",ans);
    return 0;
}