#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n,m;
    Int i;
    
    scanf("%I64d %I64d",&n,&m);
    
    m=m%( ( n*(n+1) )/2 );
    
    for (i=1;i<=n;i++)
    {
        if (i<=m)
        m-=i;
        else
        break;
    }
    printf("%I64d\n",m);
    return 0;
}