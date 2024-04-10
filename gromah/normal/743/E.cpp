#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define M 512 + 5

int n, ans, A[N], T[N], R[N][N][9], Dp[M][9];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= n; i ++)
	{
		for (int k = 1; k <= n; k ++)
			for (int j = 1; j <= 8; j ++)
				R[i][k][j] = n + 1;
		for (int j = 1; j <= 8; j ++)
			T[j] = 0, R[i][0][j] = i;
		for (int j = i; j <= n; j ++)
			R[i][++ T[A[j]]][A[j]] = j;
	}
	for (int t = 0; t <= n / 8; t ++)
	{
		for (int s = 0; s < (1 << 8); s ++)
			for (int i = 0; i < 8; i ++)
				Dp[s][i] = n + 1;
		Dp[0][0] = 0;
		for (int s = 0; s < (1 << 8); s ++)
			for (int i = 0; i < 8; i ++)
			{
				if (Dp[s][i] == n + 1) continue ;
				for (int j = 1; j <= 8; j ++)
				{
					if ((s >> j - 1) & 1) continue ;
					int _s = s | (1 << j - 1);
					if (t && Dp[s][i] < n)
						Dp[_s][i] = min(Dp[_s][i], R[Dp[s][i] + 1][t][j]);
					else if (!t) Dp[_s][i] = min(Dp[_s][i], Dp[s][i]);
					if (i < 7 && Dp[s][i] < n)
						Dp[_s][i + 1] = min(Dp[_s][i + 1], R[Dp[s][i] + 1][t + 1][j]);
				}
			}
		for (int i = 0; i < 8; i ++)
			if (Dp[(1 << 8) - 1][i] <= n)
				ans = max(ans, t * 8 + i);
	}
	printf("%d\n", ans);
	return 0;
}