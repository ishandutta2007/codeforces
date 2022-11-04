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

const int MAXN = 80005;
const int MAXM = 1000005;
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int cap;
	int nxt;
}edge[MAXM << 1];

int n,h,m,S,T,id = 1,ans;
int first[MAXN];
int lev[MAXN];
int cur[MAXN];

char s[205][205];

queue<int> Q;

void addE(int u,int v,int c)
{
	if (c == 1)
		ans -= c;
	edge[++id] = (Edge){v,c,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,0,first[v]};
	first[v] = id;
}

bool bfs()
{
	memset(lev,0,sizeof(lev));
	lev[S] = 1;
	Q.push(S);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap && !lev[edge[i].to])
			{
				lev[edge[i].to] = lev[u] + 1;
				Q.push(edge[i].to);
			}
	}
	return lev[T];
}

int dfs(int u,int f)
{
	if (u == T)
		return f;
	int res = 0;
	for (int &i = cur[u];i;i = edge[i].nxt)
		if (edge[i].cap && lev[edge[i].to] == lev[u] + 1)
		{
			int ret = dfs(edge[i].to,min(f,edge[i].cap));
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			if (!f)
				break;
		}
	return res;
}

int Dinic()
{
	int res = 0;
	while (bfs())
	{
		memcpy(cur,first,sizeof(cur));
		res += dfs(S,INF);
	}
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",s[i] + 1);
		for (int j = 1;j <= m;j++)
			ans += (s[i][j] == '#');
	}
	S = 0,T = 2 * n * m + 1;
	for (int i = 1;i < n;i++)
		for (int j = 1;j <= m;j++)
			if (s[i][j] == '#' && s[i + 1][j] == '#')
				addE(S,(i - 1) * m + j,1);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j < m;j++)
			if (s[i][j] == '#' && s[i][j + 1] == '#')
				addE(n * m + (i - 1) * m + j,T,1);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			if (i > 1 && j > 1)
				addE((i - 2) * m + j,n * m + (i - 1) * m + j - 1,1e9);
			if (i > 1 && j < m)
				addE((i - 2) * m + j,n * m + (i - 1) * m + j,1e9);
			if (i < n && j > 1)
				addE((i - 1) * m + j,n * m + (i - 1) * m + j - 1,1e9);
			if (i < n && j < m)
				addE((i - 1) * m + j,n * m + (i - 1) * m + j,1e9);
		}
	printf("%d\n",ans + Dinic());
	return 0;
}