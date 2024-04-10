#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
typedef long long Int;

int n,k,b,c;
Int t[200111];

void SolveEasy()
{
    int i;
    Int sum;
    Int val,bestval=-1;

    sum=0;
    t[0]=0;
    for (i=1;i<=k-1;i++)
    {
        sum+=t[i];
    }

    for (i=k;i<=n;i++)
    {
        sum+=t[i];
        sum-=t[i-k];

        val=t[i]*k-sum;

        if (val<bestval || bestval==-1)
        bestval=val;
    }

    printf("%lld\n",bestval);

    return;
}

Int bestanswer=-1;

multiset<Int> myset;
multiset<Int>::iterator myit;
Int total=0;

void SolveRem(int r)
{
    int i;
    Int fix;
    Int specval;
    Int ans;

    myset.clear();
    total=0;

    for (i=1;i<=n;i++)
    {
        fix=t[i];
        while(fix%5!=r)
        fix++;

        specval=(fix-t[i])*(Int)c-(fix/5LL)*(Int)b;

        myset.insert(specval);
        total+=specval;

        if (myset.size()>k)
        {
            myit=myset.end();
            myit--;

            total-=(*myit);
            myset.erase(myit);
        }

        if (myset.size()==k)
        {
            ans=(Int)k*(fix/5LL)*(Int)b+total;

            if (ans<bestanswer || bestanswer==-1)
            bestanswer=ans;
        }
    }

    return;
}

int main()
{
    int i,j;
    Int minval;

    scanf("%d %d %d %d",&n,&k,&b,&c);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&t[i]);
    }

    sort(t+1,t+1+n);

    minval=t[1];

    if (5*c<=b)
    {
        SolveEasy();

        return 0;
    }

    for (i=1;i<=n;i++)
    {
        t[i]-=minval;
    }

    for (i=0;i<=4;i++)
    {
        SolveRem(i);
    }

    printf("%lld\n",bestanswer);

    return 0;
}