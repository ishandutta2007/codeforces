#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long Int;

bool dragons[100001];

int main()
{
    Int k,l,m,n,d;
    Int i;
    Int dr=0;
    
    scanf("%I64d %I64d %I64d %I64d %I64d",&k,&l,&m,&n,&d);
    
    for (i=1;i<=100000;i++)
    dragons[i]=false;
    
    for (i=1;i<=d;i++)
    {
        if (i%k==0)
        dragons[i]=true;
        if (i%l==0)
        dragons[i]=true;
        if (i%m==0)
        dragons[i]=true;
        if (i%n==0)
        dragons[i]=true;
    }
    for (i=1;i<=d;i++)
    {
        if (dragons[i])
        {
            dr++;
        }
    }
    printf("%I64d\n",dr);
    return 0;
}