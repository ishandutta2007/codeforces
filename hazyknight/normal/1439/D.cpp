#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 505;

int n,m;

ll MOD;
ll C[MAXN][MAXN];
ll g[MAXN];
ll f[MAXN];
ll F[MAXN][MAXN];
ll G[MAXN][MAXN];

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

int main()
{
	scanf("%d%d%lld",&n,&m,&MOD);
	for (int i = 0;i <= n;i++)
	{
		C[i][0] = 1;
		for (int j = 1;j <= i;j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
	g[0] = 1;
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= i;j++)
			(g[i] += (i + 1) * g[j - 1] % MOD * g[i - j] % MOD * C[i - 1][j - 1]) %= MOD;
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= i;j++)
		{
			ll t = 0;
			(t += ((j - 1) * j / 2 + (i - j) * (i - j + 1) / 2) * g[j - 1] % MOD * g[i - j]) %= MOD;
			(t += (i + 1) * (f[j - 1] * g[i - j] % MOD + f[i - j] * g[j - 1] % MOD)) %= MOD;
			(f[i] += t * C[i - 1][j - 1]) %= MOD;
		}
	G[0][0] = 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= i;j++)
		{
			for (int k = 0;j + k <= m && i + k <= n;k++)
			{
				(F[min(n,i + k + 1)][j + k] += C[j + k][j] * (F[i][j] * g[k] % MOD + f[k] * G[i][j] % MOD)) %= MOD;
				(G[min(n,i + k + 1)][j + k] += C[j + k][j] * G[i][j] % MOD * g[k]) %= MOD;
			}
		}
	printf("%lld\n",F[n][m]);
	return 0;
}