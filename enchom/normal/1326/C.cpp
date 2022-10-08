#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

const llong MOD = 998244353LL;

int n,k;
int p[200111];

vector<int> good;

int main()
{
    int i,j;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }

    llong ans = 0;
    llong cnt = 1;
    for (i=1;i<=n;i++)
    {
        if (p[i] > n - k)
        {
            ans += (llong)p[i];
            good.push_back(i);
        }
    }

    for (i=1;i<good.size();i++)
    {
        cnt *= (llong)(good[i] - good[i-1]);
        cnt %= MOD;
    }

    printf("%lld %lld\n",ans,cnt);

    return 0;
}