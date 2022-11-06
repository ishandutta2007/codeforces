#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100 + 5
#define INF 1234567890987654321LL

int n, m, t, Col[N], W[N][N], Min[N][N][2];
LL Dp[N][N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i ++)
		scanf("%d", Col + i);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", W[i] + j);
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
			for (int k = 0; k <= t; k ++)
				Dp[i][j][k] = INF;
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= t; j ++)
			for (int k = 0; k < 2; k ++)
				Min[i][j][k] = m + 1;
	Dp[0][0][0] = 0;
	Min[0][0][0] = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
		{
			if (Col[i] && Col[i] != j) continue ;
			for (int k = 1; k <= t; k ++)
			{
				int u = Min[i - 1][k - 1][0], v = Min[i - 1][k - 1][1];
				if (u != j && u <= m)
					Dp[i][j][k] = Dp[i - 1][u][k - 1] + (Col[i] ? 0 : W[i][j]);
				else if (v != j && v <= m)
					Dp[i][j][k] = Dp[i - 1][v][k - 1] + (Col[i] ? 0 : W[i][j]);
				Dp[i][j][k] = min(Dp[i][j][k], Dp[i - 1][j][k] + (Col[i] ? 0 : W[i][j]));
				if (Dp[i][j][k] == INF) continue ;
				if (Min[i][k][1] > m || Dp[i][j][k] < Dp[i][Min[i][k][1]][k])
				{
					if (Min[i][k][0] > m || Dp[i][j][k] < Dp[i][Min[i][k][0]][k])
						Min[i][k][1] = Min[i][k][0], Min[i][k][0] = j;
					else Min[i][k][1] = j;
				}
			}
		}
	if (Min[n][t][0] > m) puts("-1");
		else printf("%I64d\n", Dp[n][Min[n][t][0]][t]);
	return 0;
}