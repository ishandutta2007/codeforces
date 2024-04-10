#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,m,id;
int first[MAXN];
int degree[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	degree[v]++;
	first[u] = id;
}

int ans;

bool mark[MAXN];

bool dfs(int now)
{
	bool mar = true;
	if (degree[now] != 2)
		mar = false;
	if (mark[now])
		return true;
	mark[now] = true;
	for (int i = first[now];i;i = edge[i].next)
		if (!dfs(edge[i].to))
			mar = false;
	return true & mar;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u,v,i = 1;i <= m;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	for (int i = 1;i <= n;i++)
		if (!mark[i])
			ans += dfs(i);
	cout << ans << endl;
	return 0;
}