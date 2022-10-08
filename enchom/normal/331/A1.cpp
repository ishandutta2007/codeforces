#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long Int;

struct tree
{
    Int orgind,val;
};

tree trees[300001];
Int orgtrees[300001];
Int prefixsums[300001];

Int Sum(Int l,Int r)
{
    return prefixsums[r]-prefixsums[l-1];
}

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

bool STrees(tree a,tree b)
{
    if (a.val<b.val)
    return true;
    else if (a.val>b.val)
    return false;
    else
    {
        return a.orgind<b.orgind;
    }
}

vector<Int> tocut;

int main()
{
    Int i;
    Int n;
    Int maxsum,cursum;
    Int m1,m2;
    Int currentkind;
    Int curstart;
    bool first=true;

    scanf("%I64d",&n);

    prefixsums[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&trees[i].val);
        trees[i].orgind=i;
        orgtrees[i]=trees[i].val;

        prefixsums[i]=prefixsums[i-1]+MAX(orgtrees[i],0);
    }

    sort(trees+1,trees+1+n,STrees);

    currentkind=trees[1].val;
    curstart=1;
    for (i=2;i<=n;i++)
    {
        if (trees[i].val==currentkind)
        {
            cursum=Sum(trees[curstart].orgind,trees[i].orgind);

            if (currentkind<0)
            {
                cursum+=2*currentkind;
            }

            if (cursum>maxsum || first)
            {
                first=false;
                maxsum=cursum;
                m1=curstart;
                m2=i;
            }
        }
        else
        {
            currentkind=trees[i].val;
            curstart=i;
        }
    }

    for (i=1;i<=trees[m1].orgind-1;i++)
    {
        tocut.push_back(i);
    }
    for (i=trees[m1].orgind+1;i<=trees[m2].orgind-1;i++)
    {
        if (orgtrees[i]<0)
        tocut.push_back(i);
    }
    for (i=trees[m2].orgind+1;i<=n;i++)
    {
        tocut.push_back(i);
    }

    printf("%I64d %I64d\n",maxsum,(Int)tocut.size());

    for (i=0;i<(Int)tocut.size();i++)
    {
        printf("%I64d",tocut[i]);

        if (i!=(Int)tocut.size()-1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}
///What the hell does judgement fail means?