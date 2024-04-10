#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int a[101];

int main()
{
    Int n;
    Int cansteal=0;
    Int i;
    Int sum=0;
    bool evenN;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        sum=sum+a[i];
    }
    
    for (i=1;i<=n;i++)
    {
        if ( (sum-a[i])%2==0 )
        cansteal++;
    }
    
    printf("%I64d\n",cansteal);
    return 0;
}