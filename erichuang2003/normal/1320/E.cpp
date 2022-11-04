#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

struct Event
{
	int t,id,v,pos,st,len;
	
	bool operator < (const Event &p)const
	{
		if (t == p.t)
			return id > p.id;
		return t > p.t;
	}
};

int n,q,k,m,id,tot,top;
int first[MAXN];
int fa[MAXN][20];
int depth[MAXN];
int dfn[MAXN];
int R[MAXN];
int u[MAXN];
int v[MAXN];
int s[MAXN];
int S[MAXN];
int p[MAXN << 1];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	for (int i = 1;i <= 17;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	dfn[u] = ++id;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
		{
			depth[edge[i].to] = depth[u] + 1;
			fa[edge[i].to][0] = u;
			dfs(edge[i].to);
		}
	R[u] = id;
}

bool in(int u,int v)
{
	return dfn[u] >= dfn[v] && dfn[u] <= R[v];
}

bool cmp(const int &u,const int &v)
{
	return dfn[u] < dfn[v];
}

int getlca(int u,int v)
{
	if (depth[u] < depth[v])
		swap(u,v);
	int dif = depth[u] - depth[v];
	for (int i = 17;i >= 0;i--)
		if (dif >> i & 1)
			u = fa[u][i];
	if (u == v)
		return u;
	for (int i = 17;i >= 0;i--)
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}

namespace BFS
{

struct Edge
{
	int to;
	int len;
	int nxt;
}edge[MAXN << 1];

int id;
int vis[MAXN];
int first[MAXN];

pair<int,int> dis[MAXN];

vector<int> rb;

priority_queue<Event> Q;

void clear()
{
	for (int i = 0;i < rb.size();i++)
		first[rb[i]] = 0;
	rb.clear();
	id = 0;
	while (!Q.empty())
		Q.pop();
}

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
	rb.push_back(u);
}

void solve()
{
	while (!Q.empty())
	{
		int t = Q.top().t;
		int cur = Q.top().id;
		int v = Q.top().v;
		int at = Q.top().pos;
		int st = Q.top().st;
		int ds = Q.top().len;
		Q.pop();
		if (vis[at])
			continue;
		vis[at] = cur;
		for (int i = first[at];i;i = edge[i].nxt)
		{
			int to = (ds + edge[i].len + v - 1) / v;
			if (dis[edge[i].to].first > to || (dis[edge[i].to].first == to && dis[edge[i].to].second > cur))
			{
				dis[edge[i].to] = make_pair(to,cur);
				Q.push((Event){to,cur,v,edge[i].to,st,ds + edge[i].len});
			}
		}
	}
}

}

int main()
{
	scanf("%d",&n);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	id = 0;
	dfs(1);
	scanf("%d",&q);
	for (int i = 1;i <= q;i++)
	{
		scanf("%d%d",&k,&m);
		tot = 0;
		for (int j = 1;j <= k;j++)
		{
			scanf("%d%d",&s[j],&v[j]);
			p[++tot] = s[j];
		}
		for (int j = 1;j <= m;j++)
		{
			scanf("%d",&u[j]);
			p[++tot] = u[j];
		}
		sort(p + 1,p + tot + 1,cmp);
		tot = unique(p + 1,p + tot + 1) - p - 1;
		int N = tot;
		for (int j = 1;j < N;j++)
			p[++tot] = getlca(p[j],p[j + 1]);
		sort(p + 1,p + tot + 1,cmp);
		tot = unique(p + 1,p + tot + 1) - p - 1;
		top = 0;
		BFS::clear();
		for (int j = 1;j <= tot;j++)
		{
			BFS::vis[p[j]] = 0;
			BFS::dis[p[j]] = make_pair(1e9,1e9);
			while (S[top] >= 1 && !in(p[j],S[top]))
				top--;
			if (top >= 1)
			{
				BFS::addE(S[top],p[j],depth[p[j]] - depth[S[top]]);
				BFS::addE(p[j],S[top],depth[p[j]] - depth[S[top]]);
			}
			S[++top] = p[j];
		}
		for (int j = 1;j <= k;j++)
			BFS::Q.push((Event){0,j,v[j],s[j],s[j],0});
		BFS::solve();
		for (int j = 1;j <= m;j++)
			printf("%d ",BFS::vis[u[j]]);
		printf("\n");
	}
	return 0;
}