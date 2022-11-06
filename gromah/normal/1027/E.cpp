#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500 + 5
#define Mod 998244353

int n, m, ans, f[N][N], Dp[N][N];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

int main()
{
	scanf("%d%d", &n, &m);
	f[0][0] = 1;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j <= i; j ++)
		{
			if (!f[i][j]) continue ;
			for (int k = 1; k <= n - i && k < m; k ++)
				f[i + k][max(k, j)] = Inc(f[i + k][max(k, j)], f[i][j]);
		}
	for (int i = 1, _ = min(n, m - 1); i <= _; i ++)
		Dp[0][i] = Inc(f[n][i], f[n][i]);
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < i; j ++)
			for (int k = 1, _ = min(n, m - 1); k <= _; k ++)
			{
				if ((i - j) * k < m)
					Dp[i][k] = Inc(Dp[i][k], Dp[j][k]);
				else break ;
			}
	for (int k = 1, _ = min(n, m - 1); k <= _; k ++)
		ans = Inc(ans, Dp[n][k]);
	printf("%d\n", ans);
	return 0;
}