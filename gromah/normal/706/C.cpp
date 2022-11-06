#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define INF 1234567890987654321LL

int n, W[N], Len[N], Head[N];
LL ans, Dp[N][2];
char s[N];

inline bool Check(int u, int op_u, int v, int op_v)
{
	int len = min(Len[u], Len[v]);
	for (int i = 0; i < len; i ++)
	{
		int p = !op_u ? Head[u] + i : Head[u + 1] - i - 1;
		int q = !op_v ? Head[v] + i : Head[v + 1] - i - 1;
		if (s[p] < s[q]) return 1;
		if (s[q] < s[p]) return 0;
	}
	return Len[u] <= Len[v];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", W + i);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", s + Head[i]);
		Len[i] = strlen(s + Head[i]);
		Head[i + 1] = Head[i] + Len[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		Dp[i][0] = Dp[i][1] = INF;
		for (int p = 0; p < 2; p ++)
			for (int q = 0; q < 2; q ++)
				if (Check(i - 1, p, i, q))
					Dp[i][q] = min(Dp[i][q], Dp[i - 1][p] + W[i] * q);
	}
	ans = min(Dp[n][0], Dp[n][1]);
	if (ans == INF) puts("-1");
		else printf("%I64d\n", ans);
	return 0;
}