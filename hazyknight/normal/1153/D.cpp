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
#include <bitset>

using namespace std;

const int MAXN = 300005;
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

int n,id,ans;
int f[MAXN];
int first[MAXN];

bool tp[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	if (!first[u])
	{
		ans++;
		f[u] = 1;
		return;
	}
	if (tp[u])
	{
		f[u] = INF;
		for (int i = first[u];i;i = edge[i].nxt)
		{
			dfs(edge[i].to);
			f[u] = min(f[u],f[edge[i].to]);
		}
	}
	else
	{
		for (int i = first[u];i;i = edge[i].nxt)
		{
			dfs(edge[i].to);
			f[u] += f[edge[i].to];
		}
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&tp[i]);
	for (int fa,i = 2;i <= n;i++)
	{
		scanf("%d",&fa);
		addE(fa,i);
	}
	dfs(1);
	printf("%d\n",ans - f[1] + 1);
	return 0;
}