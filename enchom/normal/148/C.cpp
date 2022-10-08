#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int grooms[1001];
Int gL=0;

int main()
{
    Int n,a,b;
    Int i;
    
    scanf("%I64d %I64d %I64d",&n,&a,&b);
    
    gL=1;
    grooms[1]=1;
    
    for (i=1;i<=b;i++)
    {
        gL++;
        grooms[gL]=grooms[gL-1]*2;
    }
    for (i=1;i<=a;)
    {
        if (gL==1)
        {
            gL++;
            grooms[gL]=grooms[gL-1];
        }
        else
        {
            gL++;
            grooms[gL]=grooms[gL-1]+1;
            i++;
        }
    }
    if (gL>n)
    {
        printf("-1\n");
        return 0;
    }
    while(gL<n)
    {
        gL++;
        grooms[gL]=grooms[gL-1];
    }
    for (i=1;i<=gL;i++)
    {
        printf("%I64d",grooms[i]);
        if (i==gL)
        printf("\n");
        else
        printf(" ");
    }
    return 0;
}