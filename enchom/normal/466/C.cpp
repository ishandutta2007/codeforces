#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long Int;

Int n;
Int sums[500001];
map<Int,int> mymap;
map<Int,int>::iterator myit;

int main()
{
    Int i;
    Int k;
    Int exp1,exp2;
    Int ans=0;

    scanf("%I64d",&n);

    sums[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&k);
        sums[i]=sums[i-1]+k;

        myit=mymap.find(sums[i]);

        if (i==n)
        continue;

        if (myit==mymap.end())
        {
            mymap.insert(make_pair(sums[i],1));
        }
        else
        {
            (*myit).second++;
        }
    }

    if (sums[n]%3!=0)
    {
        printf("0\n");
        return 0;
    }

    for (i=1;i<=n-2;i++)
    {
        myit=mymap.find(sums[i]);
        (*myit).second--;

        if (sums[n]/3!=sums[i])
        continue;

        myit=mymap.find(2*sums[i]);
        ans+=(*myit).second;
    }

    printf("%I64d\n",ans);

    return 0;
}