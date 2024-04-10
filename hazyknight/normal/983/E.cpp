#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

struct Query
{
	int D1,D2,val,id;
	bool operator < (const Query &p)const
	{
		return D1 < p.D1;
	}
}q[MAXN << 2];

int n,T,m,id,tot,totq;
int first[MAXN];
int dfn[MAXN];
int R[MAXN];
int sum[MAXN];
int ans[MAXN];
int cnt[MAXN];
int depth[MAXN];
int fa[MAXN][20];
int up[MAXN][20];

pair<int,int> p[MAXN << 1];

void add(int p)
{
	while (p <= n)
	{
		sum[p]++;
		p += p & -p;
	}
}

int query(int p)
{
	int res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs1(int u)
{
	dfn[u] = ++id;
	for (int i = 1;i <= 19;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
		{
			fa[edge[i].to][0] = u;
			depth[edge[i].to] = depth[u] + 1;
			dfs1(edge[i].to);
		}
	R[u] = id;
}

int getlca(int u,int v)
{
	if (depth[u] < depth[v])
		swap(u,v);
	int dif = depth[u] - depth[v];
	for (int i = 19;i >= 0;i--)
		if (dif >> i & 1)
			u = fa[u][i];
	if (u == v)
		return u;
	for (int i = 19;i >= 0;i--)
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}

void dfs2(int u)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
		{
			dfs2(edge[i].to);
			if (depth[up[u][0]] > depth[up[edge[i].to][0]])
				up[u][0] = up[edge[i].to][0];
		}
}

void dfs3(int u)
{
	for (int i = 1;i <= 19;i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
			dfs3(edge[i].to);
}

int main()
{
	scanf("%d",&n);
	for (int p,i = 2;i <= n;i++)
	{
		scanf("%d",&p);
		addE(p,i);
		addE(i,p);
	}
	id = 0;
	dfs1(1);
	scanf("%d",&T);
	for (int i = 1;i <= n;i++)
		up[i][0] = i;
	for (int u,v,i = 1;i <= T;i++)
	{
		scanf("%d%d",&u,&v);
		p[++tot] = make_pair(dfn[u],dfn[v]);
		p[++tot] = make_pair(dfn[v],dfn[u]);
		int lca = getlca(u,v);
		if (depth[up[u][0]] > depth[lca])
			up[u][0] = lca;
		if (depth[up[v][0]] > depth[lca])
			up[v][0] = lca;
	}
	dfs2(1);
	for (int i = 1;i <= n;i++)
		if (up[i][0] == i)
			up[i][0] = 0;
	dfs3(1);
//	for (int i = 1;i <= n;i++)
//		cerr << up[i][0] << ' ';
//	cerr << endl;
	scanf("%d",&m);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		int lca = getlca(u,v);
		for (int j = 19;j >= 0;j--)
			if (up[u][j] && depth[up[u][j]] > depth[lca])
			{
				u = up[u][j];
				ans[i] += 1 << j;
			}
		for (int j = 19;j >= 0;j--)
			if (up[v][j] && depth[up[v][j]] > depth[lca])
			{
				v = up[v][j];
				ans[i] += 1 << j;
			}
	//	cerr << lca << ' '<< u << ' ' << v << endl;
		if (u == v)
		{
			ans[i] = 0;
			cnt[i] = 1e9;
		}
		else if (u != lca && !up[u][0])
		{
			ans[i] = -1;
		//	cerr << "!" << endl;
		}
		else if (v != lca && !up[v][0])
		{
			ans[i] = -1;
		//	cerr << "!" << endl;
		}
		else if (u == lca || v == lca)
		{
			ans[i]++;
			cnt[i] = 1e9;
			u = v = lca;
		}
		else
		{
			ans[i]++;
			q[++totq] = (Query){R[u],R[v],1,i};
			q[++totq] = (Query){R[u],dfn[v] - 1,-1,i};
			q[++totq] = (Query){dfn[u] - 1,R[v],-1,i};
			q[++totq] = (Query){dfn[u] - 1,dfn[v] - 1,1,i};
		}
	//	cerr << ans[i] << endl;
	}
	sort(p + 1,p + tot + 1);
	sort(q + 1,q + totq + 1);
//	for (int i = 1;i <= tot;i++)
//		cerr << p[i].first << ',' << p[i].second << endl;
	for (int i = 1,j = 1;i <= totq;i++)
	{
		while (j <= tot && p[j].first <= q[i].D1)
		{
		//	cerr << p[j].second << endl;
			add(p[j++].second);
		}
	//	cerr << q[i].val << ' '<< q[i].D1 << ' ' << q[i].D2 << ' ' << q[i].id << ' ' << query(q[i].D2) << endl;
		cnt[q[i].id] += q[i].val * query(q[i].D2);
	}
	for (int i = 1;i <= m;i++)
	{
		if (ans[i] == -1)
			puts("-1");
		else
			printf("%d\n",ans[i] + !cnt[i]);
	}
	return 0;
}