#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const ll MOD = 998244353;

int T,n;

ll a[MAXN];
ll sum[MAXN];
ll ssum[MAXN];

ll SSUM(int l,int r)
{
	return (l % 2 ? -1 : 1) * (ssum[r] - ssum[l - 1]);
}

ll SUM(int l,int r)
{
	return sum[r] - sum[l - 1];
}

ll solve(int l,int r,ll dif)
{
	ll ans = 0;
	for (int i = 0,j = (r - l + 1) & 1;i + j <= r - l + 1;i += 2)
	{
		while (i + j <= r - l + 1 && dif - SUM(l,l + i - 1) + SSUM(l + i,r - j) + SUM(r - j + 1,r) <= 0)
			j += 2;
		if (i + j > r - l + 1)
			break;
		(ans += (r - l + 1 - i - j) / 2 + 1) %= MOD;
	}
	for (int i = 1,j = ~(r - l + 1) & 1;i + j <= r - l + 1;i += 2)
	{
		while (i + j <= r - l + 1 && dif - SUM(l,l + i - 1) + SSUM(l + i,r - j) + SUM(r - j + 1,r) <= 0)
			j += 2;
		if (i + j > r - l + 1)
			break;
		(ans += (r - l + 1 - i - j) / 2 + 1) %= MOD;
	}
	return ans;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i] = sum[i - 1] + a[i];
			ssum[i] = ssum[i - 1] + (i % 2 ? -a[i] : a[i]);
		}
		ll ANS = 0;
		ANS += solve(1,n,0);
		if (n - 3 >= 0)
		{
			ANS += solve(4,n,a[1] - a[2] - a[3]);
			ANS += solve(1,n - 3,a[n - 2] + a[n - 1] - a[n]);
		}
		if (n - 6 >= 0)
			ANS += solve(4,n - 3,a[1] - a[2] - a[3] + a[n - 2] + a[n - 1] - a[n]);
		for (int i = 2;i <= n - 2;i++)
			if (SUM(1,i) - SUM(i + 1,n) > 0)
				ANS++;
		printf("%lld\n",ANS % MOD);
	}
	return 0;
}