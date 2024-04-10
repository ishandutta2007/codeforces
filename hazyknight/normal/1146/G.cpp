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

const int MAXN = 5005;
const int MAXM = 20005;
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int cap;
	int nxt;
}edge[MAXM << 1];

int n,h,m,S,T,id;
int first[MAXN];
int lev[MAXN];
int cur[MAXN];

queue<int> Q;

void addE(int u,int v,int c)
{
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
	id = 1;
	cin >> n >> h >> m;
	S = 0,T = n * (h + 2) + m + 1;
	for (int i = 1;i <= n;i++)
	{
		addE(S,(i - 1) * (h + 2) + 1,INF);
		for (int j = 1;j <= h + 1;j++)
			addE((i - 1) * (h + 2) + j,(i - 1) * (h + 2) + j + 1,h * h - (j - 1) * (j - 1));
		addE(i * (h + 2),T,INF);
	}
	for (int l,r,x,c,i = 1;i <= m;i++)
	{
		cin >> l >> r >> x >> c;
		for (int j = l;j <= r;j++)
			addE((j - 1) * (h + 2) + 2 + x,n * (h + 2) + i,INF);
		addE(n * (h + 2) + i,T,c);
	}
	cout << n * h * h - Dinic() << endl;
	return 0;
}