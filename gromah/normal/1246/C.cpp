#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5
#define Mod 1000000007

int n, m, Dp[N][N][2], B[N][N][2], R[N][N], C[N][N];
char Map[N][N];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%s", Map[i] + 1);
	if (n == 1 && m == 1)
	{
		puts("1");
		return 0;
	}
	for (int i = n; i; i --)
		for (int j = m; j; j --)
		{
			B[i][j][0] = (Map[i][j] == '.') + (i < n ? B[i + 1][j][0] : 0);
			B[i][j][1] = (Map[i][j] == '.') + (j < m ? B[i][j + 1][1] : 0);
		}
	Dp[1][1][0] = Dp[1][1][1] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
		{
			R[i][j] = Inc(R[i][j], R[i - 1][j]);
			C[i][j] = Inc(C[i][j], C[i][j - 1]);
			Dp[i][j][0] = Inc(Dp[i][j][0], R[i][j]);
			Dp[i][j][1] = Inc(Dp[i][j][1], C[i][j]);
			if (j < m)
			{
				C[i][j + 1] = Inc(C[i][j + 1], Dp[i][j][0]);
				C[i][j + B[i][j + 1][1] + 1] = Inc(C[i][j + B[i][j + 1][1] + 1], Mod - Dp[i][j][0]);
			}
			if (i < n)
			{
				R[i + 1][j] = Inc(R[i + 1][j], Dp[i][j][1]);
				R[i + B[i + 1][j][0] + 1][j] = Inc(R[i + B[i + 1][j][0] + 1][j], Mod - Dp[i][j][1]);
			}
		}
	printf("%d\n", Inc(Dp[n][m][0], Dp[n][m][1]));
	return 0;
}