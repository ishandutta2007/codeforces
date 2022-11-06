#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
#define N 128 + 5

int n, m, cnt_1, cnt_2, Size[N], Dp[2][N];
bool Flag[233];
LL ans;

inline int dfs(int dep, int top, int lim, int cur, int pow, int sta)
{
	if (dep == top) return cur < lim;
	int res = 0;
	for (int i = 0; i < 7; i ++)
	{
		if (Flag[i] || (sta & (1 << i)) == 0) continue ;
		Flag[i] = 1;
		res += dfs(dep + 1, top, lim, cur + pow * i, pow * 7, sta);
		Flag[i] = 0;
	}
	return res;
}

inline void Solve()
{
	for (int i = 1; i < 128; i ++)
		Size[i] = Size[i - (i & -i)] + 1;
	for (int i = 1; i < 128; i ++)
	{
		if (Size[i] == cnt_1) Dp[0][i] = dfs(0, cnt_1, n, 0, 1, i);
		if (Size[i] == cnt_2) Dp[1][i] = dfs(0, cnt_2, m, 0, 1, i);
	}
	for (int u = 0; u < 128; u ++)
		for (int v = 0; v < 128; v ++)
			if (Size[u] == cnt_1 && Size[v] == cnt_2 && (u & v) == 0)
				ans += Dp[0][u] * Dp[1][v];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = n - 1; i; i /= 7) cnt_1 ++;
	for (int i = m - 1; i; i /= 7) cnt_2 ++;
	if (!cnt_1) cnt_1 = 1;
	if (!cnt_2) cnt_2 = 1;
	if (cnt_1 + cnt_2 > 7) ans = 0;
		else Solve();
	cout << ans << endl;
	return 0;
}