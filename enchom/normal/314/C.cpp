#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int TheLastOne[1000001];
Int F[100001];
Int NonMultiF[100001];
Int SumNonMulti[100001];
Int IndexTree[2100001];
const Int LEAFOFFSET=1048575;
const Int MOD=1000000007;

///1048576~2097151

void Update(Int ind,Int add)
{
    while(ind>0)
    {
        IndexTree[ind]=(IndexTree[ind]+add)%MOD;
        ind=ind/2;
    }

    return;
}

Int GetSum(Int k)
{
    Int ind=k+LEAFOFFSET;
    Int totalsum=IndexTree[ind];

    while(ind>1)
    {
        if (ind%2==1)
        {
            totalsum+=IndexTree[ind-1];
        }
        ind=ind/2;
    }

    return totalsum%MOD;
}

int main()
{
    Int n;
    Int i;
    Int totalans=0;
    Int a;

    for (i=0;i<=2100000;i++)
    {
        IndexTree[i]=0;
    }

    for (i=0;i<=1000000;i++)
    {
        TheLastOne[i]=-1;
    }

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);

        if (TheLastOne[a]==-1)
        {
            TheLastOne[a]=i;

            NonMultiF[i]=GetSum(a)+1;

            SumNonMulti[a]=NonMultiF[i];

            F[i]=(NonMultiF[i]*a)%MOD;

            Update(a+LEAFOFFSET,F[i]);

            totalans+=F[i];

            if (totalans>MOD)
            {
                totalans-=MOD;
            }
        }
        else
        {
            NonMultiF[i]=(GetSum(a)-SumNonMulti[ a ]+1)%MOD;

            if (NonMultiF[i]<0)
            {
                NonMultiF[i]+=MOD;
            }

            TheLastOne[a]=i;
            SumNonMulti[a]+=NonMultiF[i];

            F[i]=(NonMultiF[i]*a)%MOD;

            Update(a+LEAFOFFSET,F[i]);

            totalans+=F[i];

            if (totalans>MOD)
            {
                totalans-=MOD;
            }
        }
    }

    printf("%I64d\n",totalans);

    return 0;
}