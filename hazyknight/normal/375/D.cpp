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

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,id,top;
int first[MAXN];
int dfn[MAXN];
int R[MAXN];
int c[MAXN];
int up[MAXN][20];
int depth[MAXN];
int ans[MAXN];
int S[MAXN];
int sum[MAXN];

vector<int> e[MAXN];
vector<int> nodes[MAXN];
vector<pair<int,int> > tag[MAXN];
vector<pair<int,int> > qry[MAXN];

bool in(int u,int v)
{
	return dfn[u] >= dfn[v] && dfn[u] <= R[v];
}

bool cmp(const int &a,const int &b)
{
	return dfn[a] < dfn[b];
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void modify(int p,int v)
{
	while (p <= n)
	{
		sum[p] += v;
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

int getlca(int u,int v)
{
	if (depth[u] < depth[v])
		swap(u,v);
	int dif = depth[u] - depth[v];
	for (int i = 19;i >= 0;i--)
		if (dif >> i & 1)
			u = up[u][i];
	if (u == v)
		return u;
	for (int i = 19;i >= 0;i--)
		if (up[u][i] != up[v][i])
		{
			u = up[u][i];
			v = up[v][i];
		}
	return up[u][0];
}

void dfs1(int u,int fa)
{
	for (int i = 1;i <= 19;i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	dfn[u] = ++id;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			depth[edge[i].to] = depth[u] + 1;
			up[edge[i].to][0] = u;
			dfs1(edge[i].to,u);
		}
	R[u] = id;
}

int dfs2(int u,int fa,int cc)
{
	int sz = (c[u] == cc);
	for (int i = 0;i < e[u].size();i++)
		sz += dfs2(e[u][i],u,cc);
	e[u].clear();
	tag[u].push_back(make_pair(sz,1));
	tag[fa].push_back(make_pair(sz,-1));
	return sz;
}

void dfs3(int u,int fa)
{
	for (int i = 0;i < qry[u].size();i++)
		ans[qry[u][i].second] -= query(n - qry[u][i].first + 1);
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			dfs3(edge[i].to,u);
	for (int i = 0;i < tag[u].size();i++)
		modify(n - tag[u][i].first + 1,tag[u][i].second);
	for (int i = 0;i < qry[u].size();i++)
		ans[qry[u][i].second] += query(n - qry[u][i].first + 1);
}
 
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&c[i]);
		nodes[c[i]].push_back(i);
	}
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	id = 0;
	dfs1(1,0);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		qry[u].push_back(make_pair(v,i));
	}
	for (int i = 1;i <= 100000;i++)
	{
		if (!nodes[i].size())
			continue;
		sort(nodes[i].begin(),nodes[i].end(),cmp);
		int s = nodes[i].size();
		for (int j = 0;j < s - 1;j++)
			nodes[i].push_back(getlca(nodes[i][j],nodes[i][j + 1]));
		sort(nodes[i].begin(),nodes[i].end(),cmp);
		nodes[i].resize(unique(nodes[i].begin(),nodes[i].end()) - nodes[i].begin());
		S[top = 1] = nodes[i][0];
		for (int j = 1;j < nodes[i].size();j++)
		{
			int v = nodes[i][j];
			while (!in(v,S[top]))
			{
				e[S[top - 1]].push_back(S[top]);
				top--;
			}
			S[++top] = v;
		}
		while (top > 1)
		{
			e[S[top - 1]].push_back(S[top]);
			top--;
		}
		dfs2(S[1],0,i);
	}
	dfs3(1,0);
	for (int i = 1;i <= m;i++)
		printf("%d\n",ans[i]);
	return 0;
}