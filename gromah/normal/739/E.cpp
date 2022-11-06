#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5

int n, a, b;
double P[N], U[N], Dp[N][N];

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i ++)
		scanf("%lf", P + i);
	for (int i = 1; i <= n; i ++)
		scanf("%lf", U + i);
	for (int i = 1; i <= n; i ++)
	{
		double p = P[i], u = U[i], s = 1 - (1 - p) * (1 - u);
		int Max_j = min(a, i - 1);
		int Min_j = max(0, a - (n - i + 1));
		int Max_k = min(b, i - 1);
		int Min_k = max(0, b - (n - i + 1));
		for (int j = Max_j; j >= Min_j; j --)
			for (int k = Max_k; k >= Min_k; k --)
			{
				Dp[j + 1][k] = max(Dp[j + 1][k], Dp[j][k] + p);
				Dp[j][k + 1] = max(Dp[j][k + 1], Dp[j][k] + u);
				Dp[j + 1][k + 1] = max(Dp[j + 1][k + 1], Dp[j][k] + s);
			}
	}
	printf("%.6lf\n", Dp[a][b]);
	return 0;
}