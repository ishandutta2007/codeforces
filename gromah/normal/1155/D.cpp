#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5

int n, x, A[N];
LL ans, Dp[N][3];

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= n; i ++)
	{
		Dp[i][0] = A[i] + max(Dp[i - 1][0], 0LL);
		Dp[i][1] = 1LL * x * A[i] + max(max(Dp[i - 1][0], Dp[i - 1][1]), 0LL);
		Dp[i][2] = A[i] + max(Dp[i - 1][1], Dp[i - 1][2]);
		ans = max(max(ans, Dp[i][0]), max(Dp[i][1], Dp[i][2]));
	}
	printf("%lld\n", ans);
	return 0;
}