#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000 + 5

int n, q, Max, L[N], R[N];
short Pre[N][N], Pre1[N], Suf[N][N];

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i ++)
		scanf("%d%d", L + i, R + i);
	for (int i = q; i; i --)
	{
		for (int j = 1; j <= n; j ++)
			Suf[i][j] = Suf[i + 1][j];
		for (int j = L[i]; j <= R[i]; j ++)
			Suf[i][j] ++;
	}
	for (int i = 1; i <= q; i ++)
	{
		for (int j = 1; j <= n; j ++)
			Pre[i][j] = Pre[i - 1][j];
		for (int j = L[i]; j <= R[i]; j ++)
			Pre[i][j] ++;
		int cnt = 0;
		for (int j = 1; j <= n; j ++)
		{
			Pre1[j] = Pre1[j - 1] + (Pre[i - 1][j] + Suf[i + 1][j] == 1);
			cnt += (Pre[i - 1][j] + Suf[i + 1][j] > 0);
		}
		for (int l = 1; l < i; l ++)
			Max = max(Max, cnt - (Pre1[R[l]] - Pre1[L[l] - 1]));
	}
	printf("%d\n", Max);
	return 0;
}