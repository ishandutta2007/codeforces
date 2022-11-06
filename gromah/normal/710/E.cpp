#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 10000000 + 5

int n, x, y;
LL Dp[N];

int main()
{
	scanf("%d%d%d", &n, &x, &y);
	Dp[1] = x;
	for (int i = 2; i <= n; i ++)
		if (i & 1) Dp[i] = min(Dp[i - 1] + x, Dp[i + 1 >> 1] + y + x);
			else Dp[i] = min(Dp[i >> 1] + y, Dp[i - 1] + x);
	printf("%I64d\n", Dp[n]);
	return 0;
}