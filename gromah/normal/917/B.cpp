#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int n, m, Map[N][N], Sg[N][N][26];
bool Vis[N][N][26];

void dfs(int u, int v, int last)
{
	if (Vis[u][v][last]) return ;
	Vis[u][v][last] = 1;
	if (u == v)
	{
		Sg[u][v][last] = 0;
		return ;
	}
	bool Flag[N];
	for (int i = 0; i <= n; i ++)
		Flag[i] = 0;
	for (int i = 1; i <= n; i ++)
		if (Map[u][i] >= last)
		{
			dfs(v, i, Map[u][i]);
			Flag[Sg[v][i][Map[u][i]]] = 1;
		}
	int& sg = Sg[u][v][last];
	for (sg = 0; Flag[sg]; sg ++) ;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			Map[i][j] = -1;
	for (int i = 1, u, v; i <= m; i ++)
	{
		char ch[9];
		scanf("%d%d%s", &u, &v, ch);
		Map[u][v] = ch[0] - 'a';
	}
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
		{
			dfs(i, j, 0);
			putchar(Sg[i][j][0] ? 'A' : 'B');
		}
		putchar('\n');
	}
	return 0;
}