#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

const int MAXN = 5005;

struct Edge
{
	int to;
	int next;
}edge[MAXN];

int n,m,id,cc,ans,st;
int u[MAXN];
int v[MAXN];
int dfn[MAXN];
int low[MAXN];
int first[MAXN];
int belong[MAXN];
int degree[MAXN];

bool vis[MAXN];

stack<int> S;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int now)
{
	dfn[now] = low[now] = ++id;
	vis[now] = true;
	S.push(now);
	for (int i = first[now];i;i = edge[i].next)
	{
		if (!dfn[edge[i].to])
		{
			dfs(edge[i].to);
			low[now] = min(low[now],low[edge[i].to]);
		}
		else if (vis[edge[i].to])
			low[now] = min(low[now],dfn[edge[i].to]);
	}
	if (low[now] == dfn[now])
	{
		cc++;
		while (S.top() != now)
		{
			belong[S.top()] = cc;
			vis[S.top()] = false;
			S.pop();
		}
		belong[now] = cc;
		vis[now] = false;
		S.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> st;
	for (int i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i];
		addE(u[i],v[i]);
	}
	id = 0;
	for (int i = 1;i <= n;i++)
		if (!dfn[i])
			dfs(i);
	for (int i = 1;i <= m;i++)
		if (belong[u[i]] != belong[v[i]])
			degree[belong[v[i]]]++;
	for (int i = 1;i <= cc;i++)
		if (!degree[i] && i != belong[st])
			ans++;
	cout << ans << endl;
	return 0;
}