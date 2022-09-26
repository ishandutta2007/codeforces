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

const int MAXN = 105;
const int MAXM = 405;
const int INF = 1000000000;

struct Edge
{
	int to;
	int cap;
	int w;
	int nxt;
}edge[MAXM << 1];

int n,m,id = 1,S,T,ans;
int first[MAXN];
int cur[MAXN];
int dis[MAXN];
int in[MAXN];
int out[MAXN];

bool vis[MAXN];
bool inqueue[MAXN];

queue<int> Q;

void addE(int u,int v,int c,int w)
{
	if (!c)
		return;
	edge[++id] = (Edge){v,c,w,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,0,-w,first[v]};
	first[v] = id;
}

void addedge(int u,int v,int c,int f)
{
	in[v] += f;
	out[u] += f;
	addE(u,v,INF,2);
	if (f > c)
	{
		ans += f - c;
		addE(v,u,f - c,0);
		addE(v,u,c,1);
	}
	else
	{
		addE(u,v,c - f,1);
		addE(v,u,f,1);
	}
}

bool SPFA()
{
	for (int i = S;i <= T;i++)
		dis[i] = INF;
	dis[S] = 0;
	Q.push(S);
	inqueue[S] = 1;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		inqueue[u] = 0;
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap && dis[edge[i].to] > dis[u] + edge[i].w)
			{
				dis[edge[i].to] = dis[u] + edge[i].w;
				if (!inqueue[edge[i].to])
				{
					Q.push(edge[i].to);
					inqueue[edge[i].to] = 1;
				}
			}
	}
	return dis[T] != INF;
}

int dfs(int u,int f)
{
	if (u == T)
		return f;
	vis[u] = 1;
	int res = 0;
	for (int &i = cur[u];i;i = edge[i].nxt)
		if (edge[i].cap && !vis[edge[i].to] && dis[edge[i].to] == dis[u] + edge[i].w)
		{
			int ret = dfs(edge[i].to,min(f,edge[i].cap));
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			ans += ret * edge[i].w;
			if (!f)
				break;
		}
	vis[u] = 0;
	return res;
}

void mcmf()
{
	while (SPFA())
	{
		do
		{
			memcpy(cur,first,sizeof(cur));
		}while (dfs(S,INF));
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	S = 0,T = n + 1;
	addE(n,1,INF,0);
	for (int u,v,f,c,i = 1;i <= m;i++)
	{
		scanf("%d%d%d%d",&u,&v,&c,&f);
		addedge(u,v,c,f);
	}
	for (int i = 1;i <= n;i++)
	{
		if (in[i] > out[i])
			addE(S,i,in[i] - out[i],0);
		else
			addE(i,T,out[i] - in[i],0);
	}
	mcmf();
	printf("%d\n",ans);
	return 0;
}