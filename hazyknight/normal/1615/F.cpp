#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 4005;
const ll MOD = 1000000007;

int n,T;

ll f[MAXN][MAXN];
ll g[MAXN][MAXN];

char s[MAXN];
char t[MAXN];
char S[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s%s",&n,s + 1,t + 1);
		for (int i = 1;i <= n;i++)
		{
			S[i * 2 - 1] = s[i];
			S[i * 2] = t[i];
		}
		for (int i = 0;i <= 2 * n;i++)
			for (int j = 0;j <= 2 * n;j++)
				f[i][j] = g[i][j] = 0;
		f[0][n] = 0;
		g[0][n] = 1;
		for (int i = 0;i <= n;i++)
			for (int j = !i;j <= 1;j++)
				for (int k = -n;k <= n;k++)
				{
					int I = (i << 1 | j) - 1,ni = i + j,nj = j ^ 1;
					if (g[I][k + n])
					{
						int nk = k + ((ni ^ nj) & 1 ? -1 : 1) + n;
						if (S[I + 1] != '0')
						{
							int v = (abs(k) > abs(k + ((ni ^ nj) & 1 ? -1 : 1)) ? 1 : -1);
							(f[I + 1][nk] += f[I][k + n] + g[I][k + n] * ((I + 2) >> 1) * v) %= MOD;
							(g[I + 1][nk] += g[I][k + n]) %= MOD;
						}
						if (S[I + 1] != '1')
						{
							(f[I + 1][k + n] += f[I][k + n]) %= MOD;
							(g[I + 1][k + n] += g[I][k + n]) %= MOD;
						}
					}
				}
		printf("%lld\n",(f[2 * n][n] + MOD) % MOD);
	}
	return 0;
}