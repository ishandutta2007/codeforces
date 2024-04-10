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

typedef double db;
typedef long long ll;

const int MAXN = 55;
const int MAXM = 2505;
const int MAXQ = 100005;

int n,m,q,tot;
int flw[MAXM];

db ans[MAXQ];

pair<int,int> x[MAXQ];

namespace NetworkFlow
{

struct Edge
{
	int to;
	int w;
	int cap;
	int nxt;
}edge[MAXM << 1];

int S,T,id = 1;
int dis[MAXN];
int first[MAXN];

bool vis[MAXN];
bool inqueue[MAXN];

queue<int> Q;

void addE(int u,int v,int w,int c)
{
	edge[++id] = (Edge){v,w,c,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,-w,0,first[v]};
	first[v] = id;
}

bool bfs()
{
	for (int i = 1;i <= n;i++)
		dis[i] = 1e9;
	dis[S] = 0;
	Q.push(S);
	inqueue[S] = 1;
	while (!Q.empty())
	{
		int u = Q.front();
		inqueue[u] = 0;
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap > 0 && dis[edge[i].to] > dis[u] + edge[i].w)
			{
				dis[edge[i].to] = dis[u] + edge[i].w;
				if (!inqueue[edge[i].to])
				{
					inqueue[edge[i].to] = 1;
					Q.push(edge[i].to);
				}
			}
	}
	return dis[T] != 1e9;
}

int dfs(int u,int f)
{
	if (u == T)
		return f;
	vis[u] = 1;
	int res = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (!vis[edge[i].to] && edge[i].cap > 0 && dis[edge[i].to] == dis[u] + edge[i].w)
		{
			int ret = dfs(edge[i].to,min(edge[i].cap,f));
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			if (!f)
				break;
		}
	vis[u] = 0;
	if (!res)
		dis[u] = 1e9;
	return res;
}

void Dinic()
{
	S = 1,T = n;
	while (bfs())
	{
		int r = dfs(S,1e9);
		while (r--)
			flw[++tot] = dis[T];
	}
}

}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,w,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		NetworkFlow::addE(u,v,w,1);
	}
	NetworkFlow::Dinic();
	scanf("%d",&q);
	for (int i = 1;i <= q;i++)
	{
		scanf("%d",&x[i].first);
		x[i].second = i;
	}
	sort(x + 1,x + q + 1);
	for (int i = 1;i <= tot;i++)
		flw[i] += flw[i - 1];
	for (int i = 1,j = 1;i <= q;i++)
	{
		while (j + 1 <= tot && (ll)(flw[j] + x[i].first) * (j + 1) > (ll)(flw[j + 1] + x[i].first) * j)
			j++;
		ans[x[i].second] = (db)(flw[j] + x[i].first) / j;
	}
	for (int i = 1;i <= q;i++)
		printf("%.10lf\n",ans[i]);
	return 0;
}