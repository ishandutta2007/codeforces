#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int perm[100001];
Int whereis[100001];

int main()
{
    Int n,m;
    Int q;
    Int i;
    Int ctr1=0;
    Int ctr2=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&perm[i]);
        whereis[perm[i]]=i;
    }
    
    scanf("%I64d",&m);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&q);
        
        ctr1=ctr1+(whereis[q]);
        ctr2=ctr2+(n-whereis[q]+1);
    }
    printf("%I64d %I64d\n",ctr1,ctr2);
    return 0;
}