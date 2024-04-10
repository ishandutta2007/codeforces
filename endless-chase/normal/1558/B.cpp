#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, mod, sum[4444444], nw, pre, dp[4444444], l, r;
int main()
{
	scanf("%d%d", &n, &mod);
	sum[n] = dp[n] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		dp[i] = sum[i + 1];
		for (int j = 2; i * j <= n; j++)
		{
			l = i * j; r = min(i * j + j - 1, n);
			dp[i] = (sum[l] - sum[r + 1] + dp[i]) % mod;
			dp[i] = (dp[i] + mod) % mod;
		}
		sum[i] = (sum[i + 1] + dp[i]) % mod;
	}
	printf("%d\n", dp[1]);
	return Accepted;
}