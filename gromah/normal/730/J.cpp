#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5
#define M 10000 + 5
#define INF 1234567890

int n, sum, _sum, cnt, Max, A[N], B[N], Ord[N], Dp[N][M];

inline bool cmp(int u, int v)
{
	return B[u] > B[v];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		sum += A[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", B + i);
		_sum += B[i];
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, cmp);
	for (int i = 1, _s = 0; !cnt && i <= n; i ++)
	{
		_s += B[Ord[i]];
		if (_s >= sum) cnt = i;
	}
	for (int i = 0; i <= cnt; i ++)
		for (int j = 0; j <= _sum; j ++)
			Dp[i][j] = -INF;
	Dp[0][0] = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = cnt - 1; ~j; j --)
			for (int k = 0; k + B[i] <= _sum; k ++)
				Dp[j + 1][k + B[i]] = max(Dp[j + 1][k + B[i]], Dp[j][k] + A[i]);
	for (int i = sum; i <= _sum; i ++)
		Max = max(Max, Dp[cnt][i]);
	printf("%d %d\n", cnt, sum - Max);
	return 0;
}