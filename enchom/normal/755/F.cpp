#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool TFO[1000111];
int n,k;
int p[1000111];

vector<int> nums;

void Go(int x,int sz)
{
    if (TFO[x])
    {
        nums.push_back(sz);
        return;
    }

    TFO[x]=true;

    Go(p[x],sz+1);

    return;
}

bool seen[500111];
int sums[500111];
int L=0;
int LN=0;

bool CanMake(int goal)
{
    int i,j;
    int oldL;

    sort(nums.begin(),nums.end());
    reverse(nums.begin(),nums.end());

    L=1;
    sums[1]=0;
    seen[0]=true;

    for (i=0;i<nums.size();i++)
    {
        if (i==0 || nums[i]!=nums[i-1])
        {
            oldL=L;
            LN=L+1;
            for (j=1;j<=oldL;j++)
            {
                if (sums[j]+nums[i]<=goal)
                {
                    if (!seen[ sums[j]+nums[i] ])
                    {
                        L++;
                        sums[L]=sums[j]+nums[i];
                        seen[ sums[L] ]=true;
                    }
                }
            }
        }
        else
        {
            oldL=L;
            for (j=LN;j<=oldL;j++)
            {
                if (sums[j]+nums[i]<=goal)
                {
                    if (!seen[ sums[j]+nums[i] ])
                    {
                        L++;
                        sums[L]=sums[j]+nums[i];
                        seen[ sums[L] ]=true;
                    }
                }
            }

            LN=oldL+1;
        }

        if (seen[goal])
        break;
    }

    return seen[goal];
}

int main()
{
    int i;
    int wins=0;
    int odds=0;
    int used=0;
    int goal;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            Go(i,0);
        }
    }

    goal=k;
    if (n-k<goal)
    goal=n-k;

    if (CanMake(goal))
    printf("%d ",k);
    else
    printf("%d ",k+1);

    for (i=0;i<nums.size();i++)
    {
        if (nums[i]%2==0)
        {
            wins+=nums[i];
            used+=nums[i]/2;
        }
        else
        {
            wins+=nums[i]-1;
            used+=nums[i]/2;
            odds++;
        }
    }

    if (used>=k)
    {
        printf("%d\n",2*k);
    }
    else
    {
        while(used<k && odds>0)
        {
            odds--;
            used++;
            wins++;
        }

        printf("%d\n",wins);
    }

    return 0;
}