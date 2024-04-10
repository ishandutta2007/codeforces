#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define maxn 200005
using namespace std;
int n, m1, m2, u, v;
vector<int> G[2][maxn], p[2];
int color[2][maxn];
void dfs(int type, int x)
{
	color[type][x] = 1;
	for (int i = 0; i < G[type][x].size(); i++)
	{
		int V = G[type][x][i];
		if(color[type][V]) continue;
		dfs(type, V);
	}
}
int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++)
	{
		scanf("%d%d", &u, &v);
		G[0][u].push_back(v);
		G[0][v].push_back(u);
	}
	for (int i = 1; i <= m2; i++)
	{
		scanf("%d%d", &u, &v);
		G[1][u].push_back(v);
		G[1][v].push_back(u);
	}
	printf("%d\n", min(n - m1 - 1, n - m2 - 1));
	dfs(0, 1);
	dfs(1, 1);
	for (int i = 2; i <= n; i++)
	{
		if(color[0][i] == 0 && color[1][i] == 0) 
		{
			printf("%d %d\n", 1, i);
			dfs(0, i);
			dfs(1, i);
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if(!color[0][i])
		{
			p[0].push_back(i);
			dfs(0, i);
		}
		if(!color[1][i])
		{
			p[1].push_back(i);
			dfs(1, i);
		}
	}
	if(p[0].size() == 0) return 0;
	for (int i = 0; i < min(p[0].size(), p[1].size()); i++)
	{
		printf("%d %d\n", p[0][i], p[1][i]);
	}
	return 0;
}