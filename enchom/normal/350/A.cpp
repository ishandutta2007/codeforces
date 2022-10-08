#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n,m;

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    Int i;
    Int min1=999,max1=-1,min2=999;
    Int k;
    Int ans;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&k);

        min1=MIN(min1,k);
        max1=MAX(max1,k);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&k);

        min2=MIN(min2,k);
    }

    ans=MAX(max1,min1*2);

    if (ans>=min2)
    {
        printf("-1\n");
    }
    else
    {
        printf("%I64d\n",ans);
    }

    return 0;
}