#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

int t;
int n, e;

int a[200111];
bool prime[1000111];

llong solve(vector<int> nums)
{
    int i;
    llong ans = 0;

    /*
    printf("Testing:\n");
    for (i=0;i<nums.size();i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    */

    int lastPrime = -1;
    int lastKiller = -1;
    for (i=0;i<nums.size();i++)
    {
        /// Calculate those that end here
        //printf("At %d\n", i);

        if (nums[i] == 1)
        {
            if (lastPrime != -1)
            {
                //printf("Add1 %d\n", lastPrime - lastKiller);
                ans += (llong)(lastPrime - lastKiller);
            }
        }
        else if (prime[ nums[i] ])
        {
            if (lastPrime == -1)
            {
                lastPrime = i;
            }
            else
            {
                lastKiller = lastPrime;
                lastPrime = i;
            }
            //printf("Add2 %d\n", i - lastKiller - 1);
            ans += (llong)(i - lastKiller - 1);
        }
        else /// Killer
        {
            lastKiller = i;
            lastPrime = -1;
        }
    }

    return ans;
}

int main()
{
    //freopen("test.txt", "r", stdin);

    int i, j;
    int test;

    for (i=2;i<=1000000;i++)
    {
        prime[i] = true;
    }

    for (i=2;i<=1000000;i++)
    {
        if (prime[i])
        {
            for (j=i+i;j<=1000000;j+=i)
            {
                prime[j] = false;
            }
        }
    }

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        llong ans = 0;

        scanf("%d %d", &n, &e);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
        }

        vector<int> seq;
        for (i=1;i<=e;i++)
        {
            seq.clear();
            for (j=i;j<=n;j+=e)
            {
                seq.push_back(a[j]);
            }
            ans += solve(seq);
        }

        printf("%lld\n", ans);
    }

    return 0;
}