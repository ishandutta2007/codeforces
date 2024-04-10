#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 300005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,m,id,cc;
int u[MAXN];
int v[MAXN];
int first[MAXN];
int low[MAXN];
int dfn[MAXN];
int belong[MAXN];

bool vis[MAXN];

stack<int> S;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void tarjan(int now,int fa)
{
	dfn[now] = low[now] = ++id;
	vis[now] = true;
	S.push(now);
	for (int i = first[now];i;i = edge[i].next)
	{
		if (edge[i].to == fa)
			continue;
		if (!dfn[edge[i].to])
		{
			tarjan(edge[i].to,now);
			low[now] = min(low[now],low[edge[i].to]);
		}
		else if (vis[edge[i].to])
			low[now] = min(low[now],dfn[edge[i].to]);
	}
	if (dfn[now] == low[now])
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

pair<int,int> dfs(int now,int fa)
{
	pair<int,int> ret(0,now);
	for (int i = first[now];i;i = edge[i].next)
	{
		if (edge[i].to == fa)
			continue;
		pair<int,int> res = dfs(edge[i].to,now);
		res.first++;
		if (res.first > ret.first)
			ret = res;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i];
		addE(u[i],v[i]);
		addE(v[i],u[i]);
	}
	id = 0;
	for (int i = 1;i <= n;i++)
		if (!dfn[i])
			tarjan(i,0);
	id = 0;
	memset(first,0,sizeof(first));
	for (int i = 1;i <= m;i++)
		if (belong[u[i]] != belong[v[i]])
		{
			addE(belong[u[i]],belong[v[i]]);
			addE(belong[v[i]],belong[u[i]]);
		}
	cout << dfs(dfs(1,0).second,0).first << endl;
	return 0;
}