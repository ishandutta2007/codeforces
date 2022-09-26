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

const int MAXN = 200005;

struct Edge
{
	int to;
	int w;
	int nxt;
}edge[MAXN << 1];

int n,id,ans,SIZE,G;
int w[MAXN];
int MAX[MAXN];
int size[MAXN];
int first[MAXN];

db ANS = 1e30;
db f[MAXN];
db g[MAXN];

bool mark[MAXN];

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

void getG(int u,int fa)
{
	size[u] = 1;
	MAX[u] = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			getG(edge[i].to,u);
			size[u] += size[edge[i].to];
			MAX[u] = max(MAX[u],size[edge[i].to]);
		}
	MAX[u] = max(MAX[u],SIZE - size[u]);
	if (MAX[u] < MAX[G])
		G = u;
}

int getsize(int u,int fa)
{
	int res = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
			res += getsize(edge[i].to,u);
	return res;
}

db getdist(int u,int fa,int d)
{
	db res = d * sqrt(d) * w[u];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			res += getdist(edge[i].to,u,d + edge[i].w);
	return res;
}

void solve(int u)
{
	db cur = getdist(u,0,0);
	if (cur < ANS)
	{
		ANS = cur;
		ans = u;
	}
	mark[u] = 1;
	int nxt = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (!mark[edge[i].to])
		{
			f[edge[i].to] = getdist(edge[i].to,u,edge[i].w + 1);
			g[edge[i].to] = getdist(edge[i].to,u,edge[i].w - 1);
			if (f[edge[i].to] - g[edge[i].to] > f[nxt] - g[nxt])
				nxt = edge[i].to;
		}
	if (!nxt)
	{
		printf("%d %.7lf\n",ans,ANS);
		exit(0);
	}
	SIZE = getsize(nxt,u);
	getG(nxt,u);
	solve(G);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&w[i]);
	for (int u,v,w,i = 1;i < n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addE(u,v,w);
		addE(v,u,w);
	}
	MAX[G = 0] = (1 << 30) - 1;
	SIZE = n;
	getG(1,0);
	solve(G);
	return 0;
}