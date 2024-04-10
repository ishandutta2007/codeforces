#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int n;
const Int LEAFOFFSET=131071;
Int IT[262144];
Int L[262144];
Int R[262144];

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

void Update(Int ver,Int val)
{
    Int ind=ver+LEAFOFFSET;

    IT[ind]=val;
    ind/=2;

    while(ind>0)
    {
        IT[ind]=MAX(IT[2*ind],IT[2*ind+1]);
        ind/=2;
    }

    return;
}

Int GetMax(Int ver,Int l,Int r)
{
    if (R[ver]<l || L[ver]>r)
    {
        return 0;
    }
    else if (L[ver]>=l && R[ver]<=r)
    {
        return IT[ver];
    }
    else
    {
        return MAX(GetMax(2*ver,l,r),GetMax(2*ver+1,l,r));
    }
}

int main()
{
    Int i;
    Int p;
    Int MaxNum;

    memset(IT,0,sizeof(IT));

    for (i=LEAFOFFSET+1;i<=LEAFOFFSET*2+1;i++)
    {
        L[i]=i-LEAFOFFSET;
        R[i]=i-LEAFOFFSET;
    }
    for (i=LEAFOFFSET;i>=1;i--)
    {
        L[i]=L[2*i];
        R[i]=R[2*i+1];
    }

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&p);

        MaxNum=GetMax(1,1,p);

        Update(p,MaxNum+1);
    }

    printf("%I64d\n",GetMax(1,1,n));

    return 0;
}