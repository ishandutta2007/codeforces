#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int digs[21];
Int dL=0;

Int NoZero(Int k)
{
    Int i,num;
    dL=0;
    while(k>0)
    {
        if (k%10==0)
        {
            k=k/10;
            continue;
        }
        
        dL++;
        digs[dL]=k%10;
        k=k/10;
    }
    num=0;
    for (i=dL;i>=1;i--)
    {
        num=num*10+digs[i];
    }
    return num;
}

int main()
{
    Int a,b;
    Int c;
    Int nza,nzb,nzc;
    
    scanf("%I64d %I64d",&a,&b);
    c=a+b;
    
    nza=NoZero(a);
    nzb=NoZero(b);
    nzc=NoZero(c);
    
    if (nza+nzb==nzc)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}