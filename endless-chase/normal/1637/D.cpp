#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn = 10000;
int test, n, a[111], b[111], sum;
int ans, dp[111][11111], res;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += (a[i] * a[i] * (n - 2));
			ans += (b[i] * b[i] * (n - 2));
			sum += (a[i] + b[i]);
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= maxn; j++)
			dp[i][j] = 0;
		}
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= maxn; j++)
			{
				if (j - a[i] >= 0 && dp[i - 1][j - a[i]]) dp[i][j] = 1;
				if (j - b[i] >= 0 && dp[i - 1][j - b[i]]) dp[i][j] = 1;
			}
		}
		res = 2e9;
		for (int j = 0; j <= maxn; j++)
		{
			if (dp[n][j]) res = min(res, j * j + (sum - j) * (sum - j));
		}
		printf("%d\n", res + ans);
	}
	return Accepted;
}