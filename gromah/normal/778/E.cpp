#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define INF 0x3f3f3f3f

int n, len, Max, ans, C[10], Len[N], Dp[N][N], Rank[N][N], Ord[N][N];
char s[N], A[N][N];

int main()
{
	scanf("%s%d", s, &n);
	Max = len = strlen(s);
	reverse(s, s + len);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", A[i]);
		Len[i] = strlen(A[i]);
		Max = max(Max, Len[i]);
		reverse(A[i], A[i] + Len[i]);
	}
	for (int i = 0; i < 10; i ++)
		scanf("%d", C + i);
	for (int t = 0; t <= Max + 1; t ++)
		for (int i = 0; i <= n; i ++)
			Dp[t][i] = -INF;
	Dp[0][0] = 0;
	for (int t = 0; t <= Max; t ++)
	{
		for (int i = 1; i <= n; i ++)
		{
			Rank[t][i] = (Len[i] <= t ? 0 : ((A[i][t] - '0') << 10)) + (t ? Rank[t - 1][i] : i);
			Ord[t][i] = i;
		}
		sort(Ord[t] + 1, Ord[t] + n + 1, [&t] (int u, int v){
			return Rank[t][u] > Rank[t][v];
		});
		for (int i = 1; i <= n; i ++)
			Rank[t][Ord[t][i]] = n - i + 1;
		for (int d = (t == len - 1); d < 10; d ++)
			if (t < len && (s[t] == '?' || s[t] - '0' == d) || t >= len && d == 0)
			{
				int p = 1, add = 0;
				for (int i = 1; i <= n; i ++)
					add += (t < Len[i]) ? C[(A[i][t] - '0' + d) % 10] : (t < len ? C[d] : 0);
				for (; p <= n && t < Len[Ord[t][p]] && A[Ord[t][p]][t] - '0' + d >= 10; p ++) ;
				for (int i = 0, c = 0; i <= n; i ++)
				{
					if (i)
					{
						int tmp = t ? Ord[t - 1][i] : n - i + 1;
						add -= (t < Len[tmp]) ? C[(A[tmp][t] - '0' + d) % 10] : (t < len ? C[d] : 0);
						add += (t < Len[tmp]) ? C[(A[tmp][t] - '0' + d + 1) % 10] : C[(d + 1) % 10];
						if ((t < Len[tmp] ? A[tmp][t] - '0' : 0) + d + 1 == 10) c ++;
					}
					if (Dp[t][i] >= 0) Dp[t + 1][p - 1 + c] = max(Dp[t + 1][p - 1 + c], Dp[t][i] + add);
				}
			}
	}
	for (int i = 0; i <= n; i ++)
		ans = max(ans, Dp[Max + 1][i]);
	printf("%d\n", ans);
	return 0;
}