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
const int MAXM = 40005;
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int cap;
	int nxt;
}edge[MAXM << 1];

int n,h,m,S,T,id = 1,totx,toty;
int first[MAXN];
int lev[MAXN];
int cur[MAXN];
int xa[MAXN];
int ya[MAXN];
int xb[MAXN];
int yb[MAXN];
int valx[MAXN];
int valy[MAXN];

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
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d%d%d",&xa[i],&ya[i],&xb[i],&yb[i]);
		valx[++totx] = xa[i] - 1;
		valx[++totx] = xb[i];
		valy[++toty] = ya[i] - 1;
		valy[++toty] = yb[i];
	}
	sort(valx + 1,valx + totx + 1);
	totx = unique(valx + 1,valx + totx + 1) - valx - 1;
	sort(valy + 1,valy + toty + 1);
	toty = unique(valy + 1,valy + toty + 1) - valy - 1;
	S = 0,T = totx + toty + m * 2 + 2;
	for (int i = 1;i < totx;i++)
		addE(S,i,valx[i + 1] - valx[i]);
	for (int i = 1;i < toty;i++)
		addE(i + totx,T,valy[i + 1] - valy[i]);
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j < totx;j++)
			if (xa[i] <= valx[j] + 1 && xb[i] >= valx[j + 1])
				addE(j,totx + toty + i * 2 - 1,INF);
		for (int j = 1;j < toty;j++)
			if (ya[i] <= valy[j] + 1 && yb[i] >= valy[j + 1])
				addE(totx + toty + i * 2,j + totx,INF);
		addE(totx + toty + i * 2 - 1,totx + toty + i * 2,INF);
	}
	printf("%d\n",Dinic());
	return 0;
}