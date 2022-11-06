#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 16 + 5
#define M 10000 + 5
#define S 65536 + 5
#define INF 0x7fffffff

int n, m, ans, A[N][M], Dis[N][N], _Dis[N][N], Dp[S][N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", A[i] + j);
	if (n == 1)
	{
		int Min = INF;
		for (int j = 1; j < m; j ++)
			Min = min(Min, abs(A[1][j] - A[1][j + 1]));
		printf("%d\n", Min);
		return 0;
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (i != j)
			{
				int Min = INF;
				for (int k = 1; k < m; k ++)
					Min = min(Min, abs(A[j][k] - A[i][k + 1]));
				_Dis[i][j] = Min;
				Min = INF;
				for (int k = 1; k <= m; k ++)
					Min = min(Min, abs(A[i][k] - A[j][k]));
				Dis[i][j] = Min;
			}
	for (int b = 1; b <= n; b ++)
	{
		memset(Dp, 0x80, sizeof(Dp));
		int src = (1 << b - 1);
		Dp[src][b - 1] = INF;
		for (int s = src + 1, _ = 1 << n; s < _; s ++)
		{
			if ((s & src) != src) continue ;
			for (int i = 1; i <= n; i ++)
				if (((s >> (i - 1)) & 1) && i != b)
				{
					int _s = s ^ (1 << i - 1);
					for (int j = 1; j <= n; j ++)
						if ((_s >> (j - 1)) & 1)
						{
							int t = min(Dp[_s][j - 1], Dis[j][i]);
							Dp[s][i - 1] = max(Dp[s][i - 1], t);
						}
				}
		}
		for (int i = 1; i <= n; i ++)
			if (i != b)
			{
				int t = min(Dp[(1 << n) - 1][i - 1], _Dis[b][i]);
				ans = max(ans, t);
			}
	}
	printf("%d\n", ans);
	return 0;
}