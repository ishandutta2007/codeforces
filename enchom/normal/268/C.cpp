#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n,m;
    Int d;
    bool swaper=false;
    Int a,b;
    Int i;
    
    scanf("%I64d %I64d",&n,&m);
    
    if (n<m)
    {
        d=n;
        n=m;
        m=d;
        swaper=true;
    }
    
    printf("%I64d\n",m+1);
    for (i=0;i<=m;i++)
    {
        a=i;
        b=m-i;
        
        if (swaper)
        {
            printf("%I64d %I64d\n",b,a);
        }
        else
        {
            printf("%I64d %I64d\n",a,b);
        }
    }
    
    return 0;
}