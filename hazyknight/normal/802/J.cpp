#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 105;

struct Edge
{
	int to;
	int len;
	int next;
}edge[MAXN << 1];

int n,id;
int first[MAXN];

void addE(int u,int v,int c)
{
	edge[++id] = (Edge){v,c,first[u]};
	first[u] = id;
}

int ans = 0;

void dfs(int now,int cost,int fa)
{
	ans = max(ans,cost);
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
			dfs(edge[i].to,cost + edge[i].len,now);
}

int main()
{
	cin >> n;
	for (int u,v,c,i = 1;i < n;i++)
		cin >> u >> v >> c,addE(u,v,c),addE(v,u,c);
	dfs(0,0,0);
	cout << ans << endl;
	return 0;
}