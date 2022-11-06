#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, Max, Deg[N], Col[N], Fa[N];
vector <int> Vec[N];

void dfs(int z)
{
	int ban_1 = Col[z], ban_2 = Col[Fa[z]], cur = 0;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == Fa[z]) continue ;
		Fa[d] = z;
		cur ++;
		if (cur == ban_1) cur ++;
		if (cur == ban_2) cur ++;
		if (cur == ban_1) cur ++;
		Col[d] = cur;
		dfs(d);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
		Deg[u] ++, Deg[v] ++;
	}
	for (int i = 1; i <= n; i ++)
		Max = max(Max, Deg[i] + 1);
	Col[1] = 1;
	dfs(1);
	printf("%d\n", Max);
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Col[i], i == n ? '\n' : ' ');
	return 0;
}