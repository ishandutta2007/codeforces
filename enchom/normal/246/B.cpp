#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int arr[100001];

int main()
{
    Int n;
    Int i;
    Int sum=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&arr[i]);
        sum=sum+arr[i];
    }
    if (sum%n==0)
    printf("%I64d\n",n);
    else
    printf("%I64d\n",n-1);
    
    return 0;
}