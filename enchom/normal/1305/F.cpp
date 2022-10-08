#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long llong;

vector<llong> primes;

bool quickPrime(llong k)
{
    for (int i = 0; i < 10; i++)
    {
        if (k % primes[i] == 0)
            return false;
    }

    return true;
}

int n;
pair<llong, llong> nums[200111];
llong bn[200111];

llong bestAns;

llong tryVal(llong p)
{
    int i;
    llong res = 0;

    for (i=1;i<=n;i++)
    {
        if (nums[i].first < p)
            res += (p - nums[i].first) * nums[i].second;
        else
        {
            llong mod  = nums[i].first % p;
            res += min(mod, p - mod) * nums[i].second;
        }

        if (res > bestAns)
            return bestAns;
    }

    return res;
}

bool sieve[1000111];

int main()
{
    //freopen("t.txt","r",stdin);

    int i,j;

    for (i=2;i<=1000000;i++)
    {
        sieve[i] = true;
    }

    for (i=2;i<=1000000;i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (j=i+i;j<=1000000;j+=i)
            {
                sieve[j] = false;
            }
        }
    }

    scanf("%d",&n);

    int realN = n;

    bestAns = n;

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&bn[i]);
    }
    sort(bn+1,bn+1+n);
    int L = 1;
    nums[1] = make_pair(bn[1], 1);
    for (i=2;i<=n;i++)
    {
        if (bn[i] == nums[L].first)
        {
            nums[L].second++;
        }
        else
        {
            L++;
            nums[L] = make_pair(bn[i], 1);
        }
    }
    n = L;

    random_shuffle(nums+1,nums+1+n);

    for (i=0;i<primes.size();i++)
    {
        bestAns = min(bestAns, tryVal(primes[i]));
    }

    llong minnum = nums[1].first;
    for (i=1;i<=n;i++)
    {
        minnum = min(minnum, nums[i].first);
    }

    for (i=1;i<=1000000;i++)
    {
        llong res = round((double)minnum / (double)i);
        llong range = (realN + i - 1) / (llong)i + 3;

        for (llong k=res-range;k<=res+range;k++)
        {
            if (k < 1000000)
                continue;
            if (!quickPrime(k))
                continue;
            bestAns = min(bestAns, tryVal(k));
        }
    }

    printf("%lld\n",bestAns);

    return 0;
}