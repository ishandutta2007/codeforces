#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define LOGN 10

int n, m, q, Dp[N][N], Log[N], ST[N][N][LOGN][LOGN];
char Map[N][N];

inline int getint()
{
	char ch = '\n';
	for (; ch > '9' || ch < '0'; ch = getchar()) ;
	int res = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

inline int Get(int x_1, int y_1, int x_2, int y_2)
{
	int log_x = Log[x_2 - x_1], log_y = Log[y_2 - y_1];
	int tmp_1 = max(ST[x_1][y_1][log_x][log_y], ST[x_1][y_2 - (1 << log_y)][log_x][log_y]);
	int tmp_2 = max(ST[x_2 - (1 << log_x)][y_1][log_x][log_y], ST[x_2 - (1 << log_x)][y_2 - (1 << log_y)][log_x][log_y]);
	return max(tmp_1, tmp_2);
}

int main()
{
	n = getint(), m = getint();
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
		{
			char ch = '\n';
			for (ch = getchar(); ch != '0' && ch != '1'; ch = getchar()) ;
			Map[i][j] = ch - '0';
		}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			Dp[i][j] = Map[i][j] ? min(min(Dp[i - 1][j], Dp[i][j - 1]), Dp[i - 1][j - 1]) + 1 : 0;
	for (int i = 2; i < N; i ++) Log[i] = Log[i >> 1] + 1;
	for (int u = 0; u < LOGN; u ++)
		for (int v = 0; v < LOGN; v ++)
			for (int i = 1; i + (1 << u) - 1 <= n; i ++)
				for (int j = 1; j + (1 << v) - 1 <= m; j ++)
				{
					if (!u && !v)
					{
						ST[i][j][u][v] = Dp[i][j];
						continue ;
					}
					if (u)
						ST[i][j][u][v] = max(ST[i][j][u - 1][v], ST[i + (1 << u - 1)][j][u - 1][v]);
					else ST[i][j][u][v] = max(ST[i][j][u][v - 1], ST[i][j + (1 << v - 1)][u][v - 1]);
				}
	for (q = getint(); q; q --)
	{
		int x_1 = getint(), y_1 = getint();
		int x_2 = getint(), y_2 = getint();
		int l = 0, r = min(x_2 - x_1 + 1, y_2 - y_1 + 1);
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			int t = Get(x_1 + mid - 1, y_1 + mid - 1, x_2 + 1, y_2 + 1);
			if (t >= mid) l = mid;
				else r = mid - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}