#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long llong;

int n,s;
llong nums[500111];

vector<llong> bigger,smaller;
llong ans = 0;

int main()
{
    int i,j;
    int limit;

    scanf("%d %d",&n,&s);

    limit = n / 2;

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&nums[i]);

        if (nums[i] < s)
            smaller.push_back(nums[i]);
        else if (nums[i] > s)
            bigger.push_back(nums[i]);
    }

    sort(bigger.begin(), bigger.end());
    reverse(bigger.begin(), bigger.end());

    while(bigger.size() > limit)
    {
        ans += bigger.back() - (llong)s;
        bigger.pop_back();
    }

    sort(smaller.begin(), smaller.end());

    while(smaller.size() > limit)
    {
        ans += (llong)s - smaller.back();
        smaller.pop_back();
    }

    printf("%lld\n",ans);

    return 0;
}