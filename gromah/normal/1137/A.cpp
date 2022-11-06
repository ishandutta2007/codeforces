#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, m, A[N][N], T[N], Sr[N], Sc[N], Cntl[N][N], Cntr[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", A[i] + j);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
			T[j] = A[i][j];
		sort(T + 1, T + m + 1);
		Sr[i] = unique(T + 1, T + m + 1) - T - 1;
		for (int j = 1; j <= m; j ++)
			Cntl[i][j] = lower_bound(T + 1, T + Sr[i] + 1, A[i][j]) - T;
	}
	for (int j = 1; j <= m; j ++)
	{
		for (int i = 1; i <= n; i ++)
			T[i] = A[i][j];
		sort(T + 1, T + n + 1);
		Sc[j] = unique(T + 1, T + n + 1) - T - 1;
		for (int i = 1; i <= n; i ++)
			Cntr[i][j] = lower_bound(T + 1, T + Sc[j] + 1, A[i][j]) - T;
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
		{
			int ans = max(Sr[i], Sc[j]);
			ans = max(ans, max(Cntl[i][j], Cntr[i][j]) + max(Sr[i] - Cntl[i][j], Sc[j] - Cntr[i][j]));
			printf("%d%c", ans, j == m ? '\n' : ' ');
		}
	return 0;
}