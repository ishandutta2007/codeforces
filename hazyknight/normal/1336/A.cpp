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

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,k,id;
int first[MAXN];
int sz[MAXN];
int w[MAXN];

long long ans;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int fa,int d)
{
	sz[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,u,d + 1);
			sz[u] += sz[edge[i].to];
		}
	w[u] = sz[u] - 1 - d;
}

int main()
{
	scanf("%d%d",&n,&k);
	k = n - k;
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	dfs(1,0,0);
	sort(w + 1,w + n + 1);
	reverse(w + 1,w + n + 1);
	for (int i = 1;i <= k;i++)
		ans += w[i];
	printf("%lld\n",ans);
	return 0;
}