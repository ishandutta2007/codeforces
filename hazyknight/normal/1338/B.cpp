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

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,rt,ok[2],ans,id;
int deg[MAXN];
int first[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
	deg[u]++;
}

void dfs1(int u,int fa,int d)
{
	if (deg[u] == 1)
		ok[d & 1] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			dfs1(edge[i].to,u,d + 1);
}

bool dfs2(int u,int fa)
{
	if (deg[u] == 1)
		return 1;
	int cnt = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			cnt += dfs2(edge[i].to,u);
	ans -= (cnt ? cnt - 1 : 0);
	return 0;
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
	for (int i = 1;i <= n;i++)
		if (deg[i] > 1)
		{
			rt = i;
			break;
		}
	dfs1(rt,0,0);
	printf("%d ",(ok[0] && ok[1] ? 3 : 1));
	ans = n - 1;
	dfs2(rt,0);
	printf("%d\n",ans);
	return 0;
}