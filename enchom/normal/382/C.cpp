#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int nums[100001];
vector<int> ans;
vector<int> ans_r;
int diff;

void Try()
{
    int i;
    bool used=false;
    int num;

    for (i=2;i<=n;i++)
    {
        if (nums[i]-nums[i-1]!=diff)
        {
            if (used)
            return;

            num=nums[i]+nums[i-1];
            num/=2;

            if (nums[i]-nums[i-1]!=diff*2)
            return;

            used=true;
        }
    }

    if (used)
    {
        ans_r.push_back(num);
    }
    else
    {
        ans_r.push_back(nums[1]-diff);
        ans_r.push_back(nums[n]+diff);
    }
}

int main()
{
    int i;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    sort(nums+1,nums+1+n);

    if (n==1)
    {
        printf("-1\n");
        return 0;
    }
    else if (n==2)
    {
        if ( (nums[1]+nums[2])%2==0 )
        {
            ans_r.push_back( (nums[1]+nums[2])/2 );
        }

        ans_r.push_back(nums[1]-(nums[2]-nums[1]));
        ans_r.push_back(nums[2]+(nums[2]-nums[1]));
    }
    else
    {
        diff=nums[2]-nums[1];

        Try();

        if (nums[3]-nums[2]!=nums[2]-nums[1])
        {
            diff=nums[3]-nums[2];
            Try();
        }
    }

    sort(ans_r.begin(),ans_r.end());

    if (ans_r.size()!=0)
    ans.push_back(ans_r[0]);

    for (i=1;i<ans_r.size();i++)
    {
        if (ans_r[i]!=ans_r[i-1])
        {
            ans.push_back(ans_r[i]);
        }
    }

    printf("%d\n",ans.size());

    for (i=0;i<ans.size();i++)
    {
        printf("%d",ans[i]);

        if (i!=ans.size()-1)
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