#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define INF 0x3f3f3f3f

int n, mn, cnt, A[N], Ord[N], Dp[N], Last[N], Col[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, [](int u, int v) {
		return A[u] < A[v];
	});
	Dp[1] = Dp[2] = INF;
	for (int i = 3; i <= n; i ++)
	{
		Dp[i] = Dp[mn] + A[Ord[i]] - A[Ord[mn + 1]];
		Last[i] = mn;
		if (Dp[i - 2] - A[Ord[i - 1]] < Dp[mn] - A[Ord[mn + 1]])
			mn = i - 2;
	}
	for (int i = n; i; i = Last[i])
	{
		cnt ++;
		for (int j = i; j > Last[i]; j --)
			Col[Ord[j]] = cnt;
	}
	printf("%d %d\n", Dp[n], cnt);
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Col[i], i == n ? '\n' : ' ');
	return 0;
}