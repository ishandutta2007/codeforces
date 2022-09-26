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
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

struct Set
{
	priority_queue<int,vector<int>,greater<int> > Q,rQ;
	
	void insert(int v)
	{
		Q.push(v);
	}
	
	void erase(int v)
	{
		rQ.push(v);
	}
	
	int MIN()
	{
		while (!rQ.empty() && Q.top() == rQ.top())
		{
			Q.pop();
			rQ.pop();
		}
		return Q.top();
	}
}S[MAXN];

int n,m,q,id,cc,cn;
int w[MAXN];
int first[MAXN];
int depth[MAXN];
int fa[MAXN];
int dfn[MAXN];
int low[MAXN];
int top[MAXN];
int bel[MAXN];
int sz[MAXN];
int pos[MAXN];
int hson[MAXN];
int MIN[MAXN << 2];

bool vis[MAXN];

stack<int> st;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void tarjan(int u,int pre)
{
	dfn[u] = low[u] = ++id;
	vis[u] = 1;
	st.push(u);
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (edge[i].to == pre)
			continue;
		if (!dfn[edge[i].to])
		{
			int cnt = st.size();
			tarjan(edge[i].to,u);
			low[u] = min(low[u],low[edge[i].to]);
			if (low[edge[i].to] >= dfn[u])
			{
				cc++;
				fa[cc + n] = u;
				while (st.size() > cnt)
				{
					vis[st.top()] = 0;
					fa[st.top()] = cc + n;
					st.pop();
				}
			}
		}
		else if (vis[edge[i].to])
			low[u] = min(low[u],dfn[edge[i].to]);
	}
}

void dfs1(int u)
{
	sz[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u])
		{
			depth[edge[i].to] = depth[u] + 1;
			dfs1(edge[i].to);
			sz[u] += sz[edge[i].to];
			if (sz[edge[i].to] > sz[hson[u]])
				hson[u] = edge[i].to;
		}
}

void dfs2(int u)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u] && edge[i].to != hson[u])
			dfs2(edge[i].to);
	if (!hson[u])
		pos[top[bel[u] = ++cn] = u] = ++id;
	else
	{
		dfs2(hson[u]);
		pos[top[bel[u] = bel[hson[u]]] = u] = ++id;
	}
}

void modify(int o,int l,int r,int p,int v)
{
	if (l == r)
	{
		MIN[o] = v;
		return;
	}
	int mid = l + r >> 1;
	if (mid >= p)
		modify(o << 1,l,mid,p,v);
	else
		modify(o << 1 | 1,mid + 1,r,p,v);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

int query(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return MIN[o];
	int mid = l + r >> 1;
	if (mid < x)
		return query(o << 1 | 1,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(o << 1,l,mid,x,y);
	return min(query(o << 1,l,mid,x,y),query(o << 1 | 1,mid + 1,r,x,y));
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= n;i++)
		scanf("%d",&w[i]);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	id = 0;
	tarjan(1,0);
	memset(first,0,sizeof(first));
	id = 0;
	for (int i = 2;i <= n + cc;i++)
		addE(fa[i],i);
	id = 0;
	dfs1(1);
	dfs2(1);
	for (int i = 2;i <= n;i++)
		S[fa[i]].insert(w[i]);
	for (int i = 1;i <= n;i++)
		modify(1,1,n + cc,pos[i],w[i]);
	for (int i = n + 1;i <= n + cc;i++)
		modify(1,1,n + cc,pos[i],S[i].MIN());
	while (q--)
	{
		int u,v;
		char tp = getchar();
		while (tp != 'C' && tp != 'A')
			tp = getchar();
		if (tp == 'C')
		{
			scanf("%d%d",&u,&v);
			if (u > 1)
				S[fa[u]].erase(w[u]);
			w[u] = v;
			if (u > 1)
			{
				S[fa[u]].insert(w[u]);
				modify(1,1,n + cc,pos[fa[u]],S[fa[u]].MIN());
			}
			modify(1,1,n + cc,pos[u],w[u]);
		}
		else
		{
			scanf("%d%d",&u,&v);
			int ans = INF;
			while (bel[u] != bel[v])
			{
				if (depth[top[bel[u]]] < depth[top[bel[v]]])
					swap(u,v);
				ans = min(ans,query(1,1,n + cc,pos[u],pos[top[bel[u]]]));
				u = fa[top[bel[u]]];
			}
			if (depth[u] < depth[v])
				swap(u,v);
			ans = min(ans,query(1,1,n + cc,pos[u],pos[v]));
			if (v > n)
				ans = min(ans,w[fa[v]]);
			printf("%d\n",ans);
		}
	}
	return 0;
}