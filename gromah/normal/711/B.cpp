#include <cstdio>
typedef long long LL;
#define N 500 + 5

int n, x, y;
LL ans, A[N][N], Sum_r[N], Sum_c[N], Sum_d[2];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		for (int j = 1, t; j <= n; j ++)
		{
			scanf("%d", &t);
			A[i][j] = t;
			if (!t) x = i, y = j;
		}
	if (n == 1) puts("1");
	else
	{
		int _x = x == 1 ? n : x - 1;
		for (int i = 1; i <= n; i ++)
			ans += A[_x][i] - A[x][i];
		if (ans <= 0) puts("-1");
		else
		{
			A[x][y] = ans;
			for (int i = 1; i <= n; i ++)
			{
				for (int j = 1; j <= n; j ++)
				{
					Sum_r[i] += A[i][j];
					Sum_c[j] += A[i][j];
				}
				Sum_d[0] += A[i][i];
				Sum_d[1] += A[i][n - i + 1];
			}
			bool ok = (Sum_d[0] == Sum_d[1]);
			for (int i = 1; ok && i <= n; i ++)
				ok = (Sum_r[i] == Sum_d[0] && Sum_c[i] == Sum_d[0]);
			if (!ok) puts("-1");
				else printf("%I64d\n", ans);
		}
	}
	return 0;
}