#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 23
#define M 4200000
#define INF 0x3f3f3f3f

int n, m, id, Cnt[N], Stack[N];
int ans, Dp[M], Fa[M], Connect[M], Pre[M], Last[M];
bool Map[N][N];

bool Check(int _s, int id, int s)
{
	for (int i = 0; i < n; i ++)
		if (Map[id][i])
			_s |= (1 << i);
	return _s == s;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		Map[i][i] = 1;
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		u --, v --;
		Map[u][v] = Map[v][u] = 1;
		Connect[1 << u] |= (1 << v);
		Connect[1 << v] |= (1 << u);
	}
	for (int s = 1; s < (1 << n); s ++)
		Connect[s] = Connect[s - (s & -s)] | Connect[s & -s];
	if (m == n * (n - 1) / 2)
	{
		puts("0");
		return 0;
	}
	memset(Dp, 0x3f, sizeof(Dp));
	for (int i = 0; i < n; i ++)
	{
		int _s = 0;
		for (int j = 0; j < n; j ++)
			if (Map[i][j]) _s |= (1 << j);
		Dp[_s] = 1;
		Fa[_s] = i;
		Pre[_s] = 0;
	}
	for (int state = 1; state < (1 << n); state ++)
	{
		if (Dp[state] == INF) continue ;
		for (int i = 0; i < n; i ++)
			if (state >> i & 1)
			{
				int _state = state | Connect[1 << i];
				if (Dp[_state] <= Dp[state] + 1) continue ;
				Dp[_state] = Dp[state] + 1;
				Fa[_state] = i;
				Pre[_state] = state;
			}
	}
	ans = Dp[(1 << n) - 1];
	printf("%d\n", ans);
	for (int x = ans, s = (1 << n) - 1; x; x --)
	{
		Stack[x] = Fa[s];
		if (x == 1) break ;
		s = Pre[s];
	}
	for (int i = 1; i <= ans; i ++)
		printf("%d%c", Stack[i] + 1, i == ans ? '\n' : ' ');
	return 0;
}