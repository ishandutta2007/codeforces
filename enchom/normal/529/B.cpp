#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

pair<int,int> nums[1011];
int n;

bool laying[1011];

void FLIP(int k)
{
    int d;

    d=nums[k].first;
    nums[k].first=nums[k].second;
    nums[k].second=d;

    return;
}

void Clear()
{
    int i;

    for (i=1;i<=n;i++)
    {
        if (laying[i])
        FLIP(i);
    }

    memset(laying,false,sizeof(laying));

    return;
}

int Evaluate(int hlimit)
{
    int flipped=0;
    int i;
    int ans=0;
    int sum=0,maxh=0;

    for (i=1;i<=n;i++)
    {
        if (nums[i].second>hlimit)
        {
            laying[i]=true;
            FLIP(i);
            flipped++;
        }

        if (nums[i].second>hlimit && nums[i].first>hlimit)
        {
            Clear();
            return -1;
        }
    }

    if (flipped>n/2)
    {
        Clear();
        return -1;
    }

    for (i=1;i<=n;i++)
    {
        if (flipped+1>n/2)
        break;

        if (laying[i])
        continue;

        if (nums[i].first<nums[i].second)
        break;

        if (nums[i].first>hlimit)
        continue;

        laying[i]=true;
        FLIP(i);
        flipped++;
    }

    for (i=1;i<=n;i++)
    {
        sum+=nums[i].first;

        if (maxh<nums[i].second)
        maxh=nums[i].second;
    }

    ans=maxh*sum;

    Clear();

    return ans;
}

bool MYSORT(pair<int,int> a,pair<int,int> b)
{
    return (a.first-a.second)>(b.first-b.second);
}

int main()
{
    int i;
    int val,bestval=-1;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&nums[i].first,&nums[i].second);
    }

    sort(nums+1,nums+1+n,MYSORT);

    for (i=1;i<=1000;i++)
    {
        val=Evaluate(i);

        if (val==-1)
        continue;

        if (val<bestval || bestval==-1)
        bestval=val;
    }

    printf("%d\n",bestval);

    return 0;
}