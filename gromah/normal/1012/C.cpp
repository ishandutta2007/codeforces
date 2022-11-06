#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000 + 5
#define INF 0x3f3f3f3f

int n, A[N], L[N], R[N], Dp[N][N], Min[N][N], Ans[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= n; i ++)
	{
		if (i > 1) L[i] = max(0, A[i - 1] - A[i] + 1);
		if (i < n) R[i] = max(0, A[i + 1] - A[i] + 1);
		Dp[0][i] = INF;
	}
	for (int k = 1; k <= (n + 1 >> 1); k ++)
	{
		for (int i = 0; i <= n; i ++)
		{
			Dp[k][i] = INF;
			if (i >= 3)
				Dp[k][i] = min(Dp[k][i], Min[k - 1][i - 3] + L[i] + R[i]);
			if (i >= 2)
				Dp[k][i] = min(Dp[k][i], Dp[k - 1][i - 2] - R[i - 2] + max(R[i - 2], L[i]) + R[i]);
			if (k == 1 && i == 1)
				Dp[k][i] = L[i] + R[i];
		}
		Min[k][0] = Dp[k][0] + R[0];
		for (int i = 1; i <= n; i ++)
			Min[k][i] = min(Min[k][i - 1], Dp[k][i]);
		Ans[k] = Min[k][n];
	}
	for (int i = (n - 1 >> 1); i; i --)
		Ans[i] = min(Ans[i], Ans[i + 1]);
	for (int i = 1; i <= (n + 1 >> 1); i ++)
		printf("%d%c", Ans[i], i == (n + 1 >> 1) ? '\n' : ' ');
	return 0;
}