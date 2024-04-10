#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
 
using namespace std;

const int MAXN = 100005;
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id,G,SIZE;
int first[MAXN];
int size[MAXN];
int MAX[MAXN];

char lev[MAXN];

bool mark[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
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

void getsize(int u,int fa)
{
	size[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			getsize(edge[i].to,u);
			size[u] += size[edge[i].to];
		}
}

void solve(int u,char cur)
{
	lev[u] = cur;
	mark[u] = 1;
	getsize(u,0);
	for (int i = first[u];i;i = edge[i].nxt)
		if (!mark[edge[i].to])
		{
			G = 0;
			SIZE = size[edge[i].to];
			getG(edge[i].to,u);
			solve(G,cur + 1);
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
	MAX[G = 0] = INF;
	SIZE = n;
	getG(1,0);
	solve(G,'A');
	for (int i = 1;i <= n;i++)
	{
		putchar(lev[i]);
		putchar(' ');
	}
	putchar('\n');
	return 0;
}