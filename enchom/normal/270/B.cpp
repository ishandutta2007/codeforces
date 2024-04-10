#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int perm[100001];

int main()
{
    Int n;
    Int i;
    Int ctr=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&perm[i]);
    }
    
    ctr=1;
    for (i=n-1;i>=1;i--)
    {
        if (perm[i]<perm[i+1])
        ctr++;
        else
        break;
    }
    printf("%I64d\n",n-ctr);
    return 0;
}