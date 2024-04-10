#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long Int;

int n;
Int nums[100111];
Int k;
Int goals[111];
int L=0;

map<Int,int> mymap;
map<Int,int>::iterator myit;

Int ABS(Int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

int main()
{
    int i,j;
    Int orgk;
    Int ans=0;
    Int need;
    Int sum=0;

    scanf("%d %lld",&n,&k);
    orgk=k;

    L=1;
    goals[L]=1;

    if (k==-1)
    {
        L++;
        goals[L]=-1;
    }
    else if (k!=1)
    {
        while(ABS(k)<=(Int)n*1000000000LL)
        {
            L++;
            goals[L]=k;
            k*=orgk;
        }
    }

    mymap.insert(make_pair(0,1));

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&nums[i]);

        sum+=nums[i];

        for (j=1;j<=L;j++)
        {
            need=sum-goals[j];

            myit=mymap.find(need);

            if (myit!=mymap.end())
            {
                ans+=(Int)( (*myit).second );
            }
        }

        myit=mymap.find(sum);

        if (myit==mymap.end())
        {
            mymap.insert(make_pair(sum,1));
        }
        else
        {
            (*myit).second=(*myit).second+1;
        }
    }

    printf("%lld\n",ans);

    return 0;
}