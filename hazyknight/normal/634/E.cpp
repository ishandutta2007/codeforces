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

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,k,id;
int first[MAXN];
int a[MAXN];
int fa[MAXN];
int f[MAXN];
int g[MAXN];
int sz[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfsinfo(int u)
{
	sz[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u])
		{
			fa[edge[i].to] = u;
			dfsinfo(edge[i].to);
			sz[u] += sz[edge[i].to];
		}
}

void dfsf(int u,int lim)
{
	int MX = 0,sum = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u] && a[edge[i].to] >= lim)
		{
			dfsf(edge[i].to,lim);
			if (sz[edge[i].to] == f[edge[i].to])
				sum += f[edge[i].to];
			else
				MX = max(MX,f[edge[i].to]);
		}
	f[u] = MX + sum;
}

void dfsg(int u,int lim)
{
	int MX1 = 0,MX2 = 0,sum = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u] && a[edge[i].to] >= lim)
		{
			if (sz[edge[i].to] == f[edge[i].to])
				sum += f[edge[i].to];
			else if (f[edge[i].to] >= MX1)
			{
				MX2 = MX1;
				MX1 = f[edge[i].to];
			}
			else if (f[edge[i].to] > MX2)
				MX2 = f[edge[i].to];
		}
	if (n - sz[u] == g[u])
		sum += g[u];
	else if (g[u] >= MX1)
	{
		MX2 = MX1;
		MX1 = g[u];
	}
	else if (g[u] > MX2)
		MX2 = g[u];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u] && a[edge[i].to] >= lim)
		{
			if (sz[edge[i].to] == f[edge[i].to])
				g[edge[i].to] = sum - f[edge[i].to] + MX1;
			else if (f[edge[i].to] == MX1)
				g[edge[i].to] = sum + MX2;
			else
				g[edge[i].to] = sum + MX1;
			dfsg(edge[i].to,lim);
		}
}

int getans(int lim)
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	if (a[1] >= lim)
	{
		dfsf(1,lim);
		dfsg(1,lim);
	}
	for (int i = 1;i <= n;i++)
		if (a[i] < lim)
			for (int j = first[i];j;j = edge[j].nxt)
				if (edge[j].to != fa[i] && a[edge[j].to] >= lim)
				{
					dfsf(edge[j].to,lim);
					dfsg(edge[j].to,lim);
				}
	int res = 0;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] < lim)
			continue;
		int MX = 0,sum = 1;
		for (int j = first[i];j;j = edge[j].nxt)
			if (a[edge[j].to] >= lim)
			{
				int SZ = 0,FG = 0;
				if (edge[j].to == fa[i])
				{
					SZ = n - sz[i];
					FG = g[i];
				}
				else
				{
					SZ = sz[edge[j].to];
					FG = f[edge[j].to];
				}
				if (FG == SZ)
					sum += FG;
				else
					MX = max(MX,FG);
			}
		res = max(res,MX + sum);
	}
	return res;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	dfsinfo(1);
	int low = 1,high = 1000000;
	while (low < high)
	{
		int mid = low + high + 1 >> 1;
		if (getans(mid) >= k)
			low = mid;
		else
			high = mid - 1;
	}
	printf("%d\n",low);
	return 0;
}