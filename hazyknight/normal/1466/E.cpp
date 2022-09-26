#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 500005;
const ll MOD = 1000000007;

int T,n;
int cnt0[60];
int cnt1[60];

ll ans;
ll x[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 0;i < 60;i++)
			cnt0[i] = cnt1[i] = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%lld",&x[i]);
			for (int j = 0;j < 60;j++)
			{
				cnt1[j] += (x[i] >> j & 1);
				cnt0[j] += (~x[i] >> j & 1);
			}
		}
		ans = 0;
		for (int i = 1;i <= n;i++)
		{
			ll sum1 = 0,sum2 = n * ((1ll << 60) % MOD - 1) % MOD;
			for (int j = 0;j < 60;j++)
				if (x[i] >> j & 1)
					(sum1 += (1ll << j) % MOD * cnt1[j]) %= MOD;
				else
					(sum2 -= (1ll << j) % MOD * cnt0[j]) %= MOD;
			(ans += sum1 * sum2) %= MOD;
		}
		printf("%lld\n",(ans + MOD) % MOD);
	}
	return 0;
}