#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ABS(Int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

void PrintIt(Int k)
{
    Int i;
    for (i=0;i<=k;i++)
    {
        printf("%I64d",i);
        if (i!=k)
        printf(" ");
    }
    for (i=k-1;i>=0;i--)
    {
        if (i==k-1)
        printf(" ");
        
        printf("%I64d",i);
        if (i!=0)
        printf(" ");
    }
    return;
}

int main()
{
    Int n;
    Int i,j;
    Int ctr;
    bool godown=false;
    
    scanf("%I64d",&n);
    
    
    ctr=0;
    for (i=n*2;i>=n*-2;i-=2)
    {
        for (j=1;j<=ABS(i);j++)
        printf(" ");
        
        PrintIt(ctr);
        if (ctr==n)
        godown=true;
        
        if (godown)
        ctr--;
        else
        ctr++;
        
        printf("\n");
    }
}