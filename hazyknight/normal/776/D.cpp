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
	int v;
	int nxt;
}edge[MAXN << 1];

int n,m,id;
int tp[MAXN];
int first[MAXN];
int col[MAXN];
int p[MAXN];

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

bool dfs(int u,int c)
{
	if (~col[u])
		return col[u] == c;
	col[u] = c;
	for (int i = first[u];i;i = edge[i].nxt)
		if (!dfs(edge[i].to,c ^ edge[i].v))
			return 0;
	return 1;
}

int main()
{
	memset(col,-1,sizeof(col));
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&tp[i]);
	for (int i = 1;i <= m;i++)
	{
		int k;
		scanf("%d",&k);
		for (int u,j = 1;j <= k;j++)
		{
			scanf("%d",&u);
			if (p[u])
			{
				addE(p[u],i,tp[u] ^ 1);
				addE(i,p[u],tp[u] ^ 1);
			}
			else
				p[u] = i;
		}
	}
	for (int i = 1;i <= m;i++)
		if (col[i] == -1 && !dfs(i,0))
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}