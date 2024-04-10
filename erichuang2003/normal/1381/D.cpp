#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int T,n,x,y,id;
int first[MAXN];
int dfn[MAXN];
int R[MAXN];
int u[MAXN];
int v[MAXN];
int depth[MAXN];
int fa[MAXN][18];
int vis[MAXN];
int len[MAXN];
int dep[MAXN];

pair<int,int> pt[MAXN];
vector<int> path;
queue<pair<int,int> > Q;
map<int,int> mark[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

bool getp(int u,int pr,int v)
{
	if (u == v)
	{
		path.push_back(v);
		vis[v] = 2;
		return 1;
	}
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != pr && getp(edge[i].to,u,v))
		{
			path.push_back(u);
			vis[u] = 2;
			return 1;
		}
	return 0;
}

void work(int u,int fa)
{
	dep[u] = u;
	len[u] = -1;
	int MX1 = 0,MX2 = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && vis[edge[i].to] != 2)
		{
			depth[edge[i].to] = depth[u] + 1;
			work(edge[i].to,u);
			if (depth[dep[edge[i].to]] > depth[dep[u]])
				dep[u] = dep[edge[i].to];
			if (depth[dep[edge[i].to]] >= depth[MX1])
			{
				MX2 = MX1;
				MX1 = dep[edge[i].to];
			}
			else if (depth[dep[edge[i].to]] > depth[MX2])
				MX2 = dep[edge[i].to];
			if (len[edge[i].to] > len[u])
			{
				len[u] = len[edge[i].to];
				pt[u] = pt[edge[i].to];
			}
		}
	if (MX1 && MX2 && min(depth[MX1] - depth[u],depth[MX2] - depth[u]) > len[u])
	{
		len[u] = min(depth[MX1] - depth[u],depth[MX2] - depth[u]);
		pt[u] = make_pair(MX1,MX2);
	}
	if (0 > len[u])
	{
		len[u] = 0;
		pt[u] = make_pair(u,dep[u]);
	}
}

bool paint(int u,int fa)
{
	bool r = vis[u];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && vis[edge[i].to] != 2 && paint(edge[i].to,u))
			r = 1;
	if (r)
		vis[u] = max(vis[u],1);
}

void dfs(int u)
{
	dfn[u] = ++id;
	for (int i = 1;i <= 17;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
		{
			depth[edge[i].to] = depth[u] + 1;
			fa[edge[i].to][0] = u;
			dfs(edge[i].to);
		}
	R[u] = id;
}

int getnxt(int a,int b)
{
	if (dfn[b] >= dfn[a] && dfn[b] <= R[a])
	{
		int t = depth[b] - depth[a] - 1;
		for (int i = 0;i <= 17;i++)
			if (t >> i & 1)
				b = fa[b][i];
		return b;
	}
	return fa[a][0];
}

int main()
{
	depth[0] = -1;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&x,&y);
		id = 0;
		for (int i = 1;i <= n;i++)
		{
			first[i] = vis[i] = pt[i].first = pt[i].second = dep[i] = 0;
			memset(fa[i],0,sizeof(fa[i]));
			dfn[i] = R[i] = vis[i] = dep[i] = 0;
		}
		path.clear();
		for (int i = 1;i < n;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			addE(u[i],v[i]);
			addE(v[i],u[i]);
		}
		getp(x,0,y);
		for (int i = 0;i < path.size();i++)
		{
			int u = path[i];
			depth[u] = 0;
			work(u,0);
			vis[pt[u].first] = max(vis[pt[u].first],1);
			vis[pt[u].second] = max(vis[pt[u].second],1);
			paint(u,0);
		}
		id = 0;
		for (int i = 1;i <= n;i++)
			first[i] = 0;
		for (int i = 1;i < n;i++)
			if (vis[u[i]] && vis[v[i]])
			{
				addE(u[i],v[i]);
				addE(v[i],u[i]);
			}
		id = 0;
		dfs(x);
		while (!Q.empty())
			Q.pop();
		Q.push(make_pair(x,y));
		bool ok = 0;
		for (int i = 1;i <= n;i++)
			mark[i].clear();
		while (!Q.empty() && !ok)
		{
			int a = Q.front().first,b = Q.front().second;
			Q.pop();
			int na = getnxt(a,b),nb = getnxt(b,a);
			for (int i = first[a];i;i = edge[i].nxt)
				if (edge[i].to != na)
				{
					if (mark[edge[i].to][nb])
						continue;
					if (edge[i].to == y && nb == x)
					{
						ok = 1;
						break;
					}
					mark[edge[i].to][nb] = 1;
					Q.push(make_pair(edge[i].to,nb));
				}
			if (ok)
				break;
			for (int i = first[b];i;i = edge[i].nxt)
				if (edge[i].to != nb)
				{
					if (mark[na][edge[i].to])
						continue;
					if (na == y && edge[i].to == x)
					{
						ok = 1;
						break;
					}
					mark[na][edge[i].to] = 1;
					Q.push(make_pair(na,edge[i].to));
				}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}