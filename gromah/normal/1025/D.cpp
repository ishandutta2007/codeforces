#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 700 + 5

int n, A[N], Dp[N][N][2];
bool ok, Map[N][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 0; i <= n + 1; i ++)
		for (int j = 0; j <= n + 1; j ++)
			Map[i][j] = (!i || !j || i > n || j > n || __gcd(A[i], A[j]) > 1);
	for (int l = 1; l <= n; l ++)
		for (int i = 1; i + l - 1 <= n; i ++)
		{
			int j = i + l - 1;
			for (int k = i; k <= j; k ++)
			{
				bool ok = (i > k - 1 || Dp[i][k - 1][1]) && (k + 1 > j || Dp[k + 1][j][0]);
				if (!ok) continue ;
				Dp[i][j][0] |= Map[i - 1][k];
				Dp[i][j][1] |= Map[k][j + 1];
			}
		}
	for (int i = 1; !ok && i <= n; i ++)
		ok = (i == 1 || Dp[1][i - 1][1]) && (i == n || Dp[i + 1][n][0]);
	puts(ok ? "YES" : "NO");
	return 0;
}