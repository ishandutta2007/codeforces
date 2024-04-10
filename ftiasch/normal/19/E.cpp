// Codeforces Beta Round #19
// Problem E -- Fairy
#include <cstdio>
#include <cstring>

#define N 10000

using namespace std;

int n, m;
int first[N], begin[N + N], end[N + N], next[N + N];
int color[N], parent[N], lca[N], err, sum[2][N];
bool tree[N], can[N];

void insert_edge(int i, int u, int v)
{
	begin[i] = u;
	end[i] = v;
	next[i] = first[u];
	first[u] = i;
}

int find(int u)
{
	if(parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}

void dfs(int p, int u)
{
	for(int i = first[u]; i != -1; i = next[i])
	{
		int v = end[i];
		if(v == p)
			continue;
		if(color[v] == -1)
		{
			tree[i >> 1] = true;
			color[v] = 1 - color[u];
			dfs(u, v);
			parent[v] = u;
		}
		else
			lca[i >> 1] = find(v);
	}
}

void sta(int p, int u)
{
	if(color[u] == -1)
	{
		color[u] = 0;
		for(int i = first[u]; i != -1; i = next[i])
		{
			int v = end[i];
			if(v == p || !tree[i >> 1])
				continue;
			sta(u, v);
			sum[0][u] += sum[0][v];
			sum[1][u] += sum[1][v];			
			can[i >> 1] |= (sum[0][v] == 0 || err == 0) && sum[1][v] == err;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(first, -1, sizeof(first));
	for(int i = 0; i != m; ++ i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		insert_edge(i + i, u - 1, v - 1);
		insert_edge(i + i + 1, v - 1, u - 1);
	}
	memset(tree, 0, sizeof(tree));
	memset(color, -1, sizeof(color));
	for(int i = 0; i != n; ++ i)
		parent[i] = i;
	for(int i = 0; i != n; ++ i)
		if(color[i] == -1)
		{
			color[i] = 0;
			dfs(-1, i);
		}
	memset(can, 0, sizeof(can));
	err = 0;
	for(int i = 0; i != m; ++ i)
		err += !tree[i] && color[begin[i << 1]] == color[end[i << 1]];
	if(err == 0)
		for(int i = 0; i != m; ++ i)
			can[i] |= !tree[i];
	else
	if(err == 1)
		for(int i = 0; i != m; ++ i)
			can[i] |= !tree[i] && color[begin[i << 1]] == color[end[i << 1]];
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i != m; ++ i)
		if(!tree[i])
		{
			int u = begin[i << 1], v = end[i << 1], t = color[u] == color[v];
			sum[t][u] ++;
			sum[t][v] ++;
			sum[t][lca[i]] -= 2;
		}
	memset(color, -1, sizeof(color));
	for(int i = 0; i != n; ++ i)
		sta(-1, i);
	int ans = 0;
	for(int i = 0; i != m; ++ i)
		ans += can[i];	
	printf("%d\n", ans);
	for(int i = 0; i != m; ++ i)
		if(can[i])
			printf("%d ", i + 1);
	printf("\n");
	return 0;
}