#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
int nums[5001];

vector<int> Buckets[21];

bool Exists(int num,int b)
{
    int l=0,r=(int)Buckets[b].size()-1,mid;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (Buckets[b][mid]==num)
        return true;
        else if (Buckets[b][mid]>num)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    return false;
}

int main()
{
    int i,j,in;
    int money;
    int test;
    int need;
    int ans;
    int q;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=k;j++)
        {
            Buckets[j].push_back(j*nums[i]);
        }
    }

    for (i=1;i<=k;i++)
    {
        sort(Buckets[i].begin(),Buckets[i].end());
    }

    scanf("%d",&q);

    for (test=1;test<=q;test++)
    {
        scanf("%d",&money);

        ans=999;

        for (i=1;i<=k;i++)
        {
            for (j=0;j<Buckets[i].size();j++)
            {
                if (Buckets[i][j]==money)
                {
                    if (ans>i)
                    ans=i;
                }
            }
        }

        for (i=1;i<=k;i++)
        {
            for (j=1;j<=k;j++)
            {
                if (i+j>=ans)
                continue;

                for (in=0;in<Buckets[i].size();in++)
                {
                    need=money-Buckets[i][in];

                    if (need<0)
                    continue;

                    if (Exists(need,j))
                    {
                        ans=i+j;
                        break;
                    }
                }
            }
        }

        if (ans>k)
        ans=-1;

        printf("%d\n",ans);
    }

    return 0;
}
/**
5 5
1 2 4 5 6
1
4
**/