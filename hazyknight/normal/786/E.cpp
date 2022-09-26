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

const int MAXN = 400005;
const int MAXM = 650005;
const int INF = 1 << 30;

struct Edge
{
	int to;
	int cap;
	int nxt;
}edge[MAXM << 1];

int n,m,id,cn,S,T,cnt,tot;
int tofa[MAXN];
int q[MAXN];
int first[MAXN];
int depth[MAXN];
int lev[MAXN];
int cur[MAXN];
int fa[MAXN][15];
int ID[MAXN][15];

bool vis[MAXN];

queue<int> Q;

void addE(int u,int v,int c)
{
	edge[++id] = (Edge){v,c,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,0,first[v]};
	first[v] = id;
}

void DFS(int u)
{
	q[++tot] = u;
	for (int i = 1;i <= 14;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
		{
			tofa[edge[i].to] = max(edge[i].cap,edge[i ^ 1].cap);
			depth[edge[i].to] = depth[u] + 1;
			fa[edge[i].to][0] = u;
			DFS(edge[i].to);
		}
}

int dfs(int u,int f)
{
	if (u == T)
		return f;
	int res = 0;
	for (int &i = cur[u];i;i = edge[i].nxt)
		if (edge[i].cap > 0 && lev[edge[i].to] == lev[u] + 1)
		{
			int ret = dfs(edge[i].to,min(f,edge[i].cap));
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			if (!f)
				break;
		}
	return res;
}

bool bfs()
{
	memset(lev,-1,sizeof(lev));
	lev[S] = 0;
	Q.push(S);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap > 0 && !~lev[edge[i].to])
			{
				lev[edge[i].to] = lev[u] + 1;
				Q.push(edge[i].to);
			}
	}
	return ~lev[T];
}

int Dinic()
{
	int res = 0;
	while (bfs())
	{
		memcpy(cur,first,sizeof(cur));
		res += dfs(S,INF);
	}
	return res;
}

void go(int u)
{
	if (vis[u])
		return;
	vis[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].cap > 0)
			go(edge[i].to);
}

int main()
{
	scanf("%d%d",&n,&m);
	id = 1;
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v,i);
	}
	DFS(1);
	memset(first,0,sizeof(first));
	id = 1;
	S = 0,T = 15 * n + m + 1;
	for (int i = 1;i <= m;i++)
		addE(S,++cn,1);
	for (int i = 2;i <= n;i++)
	{
		int cur = q[i];
		addE(ID[cur][0] = ++cn,T,1);
		for (int j = 1;j <= 14;j++)
		{
			if (!fa[cur][j])
				break;
			ID[cur][j] = ++cn;
			addE(ID[cur][j],ID[cur][j - 1],INF);
			addE(ID[cur][j],ID[fa[cur][j - 1]][j - 1],INF);
		}
	}
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		if (depth[u] < depth[v])
			swap(u,v);
		int diff = depth[u] - depth[v];
		for (int j = 14;j >= 0;j--)
			if (diff >> j & 1)
			{
				addE(i,ID[u][j],1);
				u = fa[u][j];
			}
		if (u == v)
			continue;
		for (int j = 14;j >= 0;j--)
			if (fa[u][j] != fa[v][j])
			{
				addE(i,ID[u][j],1);
				addE(i,ID[v][j],1);
				u = fa[u][j];
				v = fa[v][j];
			}
		addE(i,ID[u][0],1);
		addE(i,ID[v][0],1);
	}
	printf("%d\n",Dinic());
	go(S);
	for (int i = 1;i <= m;i++)
		cnt += !vis[i];
	printf("%d ",cnt);
	for (int i = 1;i <= m;i++)
		if (!vis[i])
			printf("%d ",i);
	printf("\n");
	cnt = 0;
	for (int i = 2;i <= n;i++)
		cnt += vis[ID[i][0]];
	printf("%d ",cnt);
	for (int i = 2;i <= n;i++)
		if (vis[ID[i][0]])
			printf("%d ",tofa[i]);
	printf("\n");
	return 0;
}