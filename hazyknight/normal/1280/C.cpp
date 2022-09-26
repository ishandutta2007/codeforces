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

typedef long long ll;

const int MAXN = 200005;

struct Edge
{
	int to;
	int w;
	int nxt;
}edge[MAXN << 1];

int T,n,id;
int first[MAXN];
int size[MAXN];
int u[MAXN];
int v[MAXN];
int w[MAXN];

ll MIN,MAX;
ll W[MAXN];

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

void dfs(int u,int fa)
{
	size[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			W[edge[i].to] = edge[i].w;
			dfs(edge[i].to,u);
			size[u] += size[edge[i].to];
		}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		n <<= 1;
		for (int i = 1;i <= n;i++)
			first[i] = 0;
		id = 0;
		for (int i = 1;i < n;i++)
		{
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
			addE(u[i],v[i],w[i]);
			addE(v[i],u[i],w[i]);
		}
		dfs(1,0);
		MIN = MAX = 0;
		for (int i = 2;i <= n;i++)
		{
			MIN += (size[i] & 1) * W[i];
			MAX += min(size[i],n - size[i]) * W[i];
		}
		printf("%lld %lld\n",MIN,MAX);
	}
	return 0;
}