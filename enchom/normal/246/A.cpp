#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int i;
    scanf("%I64d",&n);
    
    if (n==1 || n==2)
    {
        printf("-1\n");
    }
    else
    {
        printf("%I64d %I64d ",n,n-1);
        for (i=1;i<=n-2;i++)
        {
            printf("%I64d",i);
            if (i!=n-2)
            printf(" ");
            else
            printf("\n");
        }
    }
    return 0;
}