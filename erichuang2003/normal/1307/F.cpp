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

const int MAXN = 400005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,L,q,a,b,id;
int first[MAXN];
int dis[MAXN];
int pre[MAXN];
int depth[MAXN];
int tag[MAXN];
int fa[MAXN][19];

queue<pair<int,int> > Q;

int getroot(int u)
{
	return u == pre[u] ? u : pre[u] = getroot(pre[u]);
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void merge(int u,int v)
{
	pre[getroot(u)] = getroot(v);
}

void dfs(int u)
{
	for (int i = 1;i <= 18;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
		{
			depth[edge[i].to] = depth[u] + 1;
			fa[edge[i].to][0] = u;
			dfs(edge[i].to);
		}
}

int getup(int u,int x)
{
	for (int i = 18;i >= 0;i--)
		if (x >> i & 1)
			u = fa[u][i];
	return u;
}

int getlca(int u,int v)
{
	if (depth[u] < depth[v])
		swap(u,v);
	u = getup(u,depth[u] - depth[v]);
	if (u == v)
		return u;
	for (int i = 18;i >= 0;i--)
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}

int main()
{
	scanf("%d%d%d",&n,&L,&m);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,i + n);
		addE(i + n,u);
		addE(v,i + n);
		addE(i + n,v);
	}
	dfs(1);
	memset(dis,-1,sizeof(dis));
	for (int a,i = 1;i <= m;i++)
	{
		scanf("%d",&a);
		dis[a] = 0;
		pre[a] = a;
		tag[a] = a;
		Q.push(make_pair(a,a));
	}
	while (!Q.empty())
	{
		int u = Q.front().first,ori = Q.front().second;
		Q.pop();
		if (dis[u] == L)
			break;
		for (int i = first[u];i;i = edge[i].nxt)
		{
			if (tag[edge[i].to])
			{
				merge(ori,tag[edge[i].to]);
				continue;
			}
			tag[edge[i].to] = ori;
			dis[edge[i].to] = dis[u] + 1;
			Q.push(make_pair(edge[i].to,ori));
		}
	}
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d",&a,&b);
		int lca = getlca(a,b),ds = depth[a] + depth[b] - 2 * depth[lca];
		if (ds <= 2 * L)
		{
			puts("YES");
			continue;
		}
		int A,B;
		if (depth[a] - depth[lca] >= L)
			A = getup(a,L);
		else
			A = getup(b,ds - L);
		if (depth[b] - depth[lca] >= L)
			B = getup(b,L);
		else
			B = getup(a,ds - L);
		if (tag[A] && tag[B] && getroot(tag[A]) == getroot(tag[B]))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}