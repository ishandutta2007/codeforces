#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 405;

int n,MOD;

ll ans;
ll f[MAXN];
ll fac[MAXN];
ll inv[MAXN];
ll g[MAXN][MAXN];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

ll C(int x,int y)
{
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	scanf("%d%d",&n,&MOD);
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n] = power(fac[n],MOD - 2);
	for (int i = n;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= i;j++)
			(f[i] += C(i - 1,j - 1)) %= MOD;
	g[0][0] = 1;
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= i;j++)
			if (g[i][j])
				for (int k = i + 2;k <= n + 1;k++)
					(g[k][j + (k - i - 1)] += g[i][j] * inv[k - i - 1] % MOD * f[k - i - 1]) %= MOD;
	for (int j = 0;j <= n;j++)
		(ans += g[n + 1][j] * fac[j]) %= MOD;
	printf("%lld\n",ans);
	return 0;
}