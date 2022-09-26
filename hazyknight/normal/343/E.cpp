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

const int MAXN = 205;
const int MAXM = 1005;

struct Edge
{
	int to;
	int Cap;
	int cap;
	int nxt;
}edge[MAXM << 1];

int n,m,ans,id = 1;
int a[MAXN];
int b[MAXN];
int first[MAXN];
int cur[MAXN];
int dis[MAXN];

queue<int> Q;

namespace GomoryTree
{

struct Edge
{
	int to;
	int w;
	int nxt;
	bool vis;
}edge[MAXM << 1];

int MX,id = 1;
int first[MAXN];

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u],0};
	first[u] = id;
}

void dfs(int u,int fa)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (!edge[i].vis && edge[i].to != fa)
		{
			dfs(edge[i].to,u);
			if (!MX || edge[i].w < edge[MX].w)
				MX = i;
		}
}

void solve(int u)
{
	MX = 0;
	dfs(u,0);
	if (!MX)
	{
		printf("%d ",u);
		return;
	}
	int tmp = MX;
	edge[tmp].vis = edge[tmp ^ 1].vis = 1;
	solve(edge[tmp].to);
	solve(edge[tmp ^ 1].to);
}

}

void addE(int u,int v,int c)
{
	edge[++id] = (Edge){v,c,c,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,c,c,first[v]};
	first[v] = id;
}

bool bfs(int S,int T)
{
	for (int i = 1;i <= n;i++)
		dis[i] = -1;
	dis[S] = 0;
	Q.push(S);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap && dis[edge[i].to] == -1)
			{
				dis[edge[i].to] = dis[u] + 1;
				Q.push(edge[i].to);
			}
	}
	return ~dis[T];
}

int dfs(int u,int f,int T)
{
	if (u == T)
		return f;
	int res = 0;
	for (int &i = cur[u];i;i = edge[i].nxt)
		if (edge[i].cap && dis[edge[i].to] == dis[u] + 1)
		{
			int ret = dfs(edge[i].to,min(f,edge[i].cap),T);
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			if (!f)
				break;
		}
	return res;
}

int Dinic(int S,int T)
{
	for (int i = 1;i <= id;i++)
		edge[i].cap = edge[i].Cap;
	int res = 0;
	while (bfs(S,T))
	{
		memcpy(cur,first,sizeof(cur));
		res += dfs(S,1e9,T);
	}
	return res;
}

void solve(int l,int r)
{
	if (l == r)
		return;
	int mincut = Dinic(a[l],a[r]);
	ans += mincut;
	GomoryTree::addE(a[l],a[r],mincut);
	GomoryTree::addE(a[r],a[l],mincut);
	int L = l - 1,R = r + 1;
	for (int i = l;i <= r;i++)
	{
		if (~dis[a[i]])
			b[++L] = a[i];
		else
			b[--R] = a[i];
	}
	for (int i = l;i <= r;i++)
		a[i] = b[i];
	solve(l,L);
	solve(R,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,c,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		addE(u,v,c);
	}
	for (int i = 1;i <= n;i++)
		a[i] = i;
	solve(1,n);
	printf("%d\n",ans);
	GomoryTree::solve(1);
	printf("\n");
	return 0;
}