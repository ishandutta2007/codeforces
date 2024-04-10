#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int gcdcomplexity(Int a,Int b)
{
    Int d;
    Int r;
    Int ctr=0;
    
    if (a<b)
    {
        d=a;
        a=b;
        b=d;
    }
    
    while(b!=0)
    {
        r=a%b;
        ctr=ctr+a/b;
        a=b;
        b=r;
    }
    return ctr;
}

int main()
{
    Int a,b;
    Int t;
    Int i;
    
    scanf("%I64d",&t);
    
    for (i=1;i<=t;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        printf("%I64d\n",gcdcomplexity(a,b));
    }
    return 0;
}