#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

vector<Int> nums[100001];

int main()
{
    Int n,m,k;
    Int i,j;
    Int a;
    Int maxlen=0;
    Int curlen;
    Int l,r;
    Int cursum;
    Int L;

    scanf("%I64d %I64d %I64d",&n,&m,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        nums[a].push_back(i);
    }

    for (i=1;i<=m;i++)
    {
        L=nums[i].size();
        L--;

        for (j=0;j<L;j++)
        {
            nums[i][j]=nums[i][j+1]-nums[i][j]-1;
        }

        if (nums[i].size()>0)
        nums[i].pop_back();
    }

    for (i=1;i<=m;i++)
    {
        l=0;
        r=-1;
        cursum=0;
        curlen=0;
        for (j=0;j<nums[i].size();j++)
        {
            cursum=cursum+nums[i][j];
            r++;
            while (cursum>k)
            {
                cursum-=nums[i][l];
                l++;
            }

            if (r-l+1 > curlen)
            curlen=r-l+1;
        }

        if (curlen+1>maxlen)
        {
            maxlen=curlen+1;
        }
    }

    printf("%I64d\n",maxlen);

    return 0;
}
/**
94 10 20
2 3 4 4 4 4 4 4 4 4 4 4 5 5 5 5 3 3 3 3 6 6 5 1 5 5 5 2 2 2 2 4 1 1 1 1 8 8 10 5 2 2 4 4 4 4 4 3 3 3 3 3 6 6 6 6 2 2 2 2 2 2 2 2 1 10 10 2 2 2 6 6 6 8 4 4 4 8 1 1 1 1 1 1 6 6 2 2 8 7 7 7 3 4
**/