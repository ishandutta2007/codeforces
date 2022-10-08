#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

bool Prime(Int k)
{
    Int i;
    
    for (i=2;i*i<=k;i++)
    {
        if (k%i==0)
        return false;
    }
    return true;
}

int main()
{
    Int i;
    Int n,m;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=n+1;i<=m-1;i++)
    {
        if (Prime(i))
        {
            printf("NO\n");
            return 0;
        }
    }
    if (Prime(m))
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}