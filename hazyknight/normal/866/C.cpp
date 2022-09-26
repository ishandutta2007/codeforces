#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

typedef double db;

const int MAXN = 105;
const int MAXM = 100005;
const int MAXV = 10005;
const db INF = 1e9;
const db eps = 1e-10;

struct Edge
{
	int to;
	int val;
	int por;
	int nxt;
}edge[MAXM];

int n,m,L,id;
int first[MAXN];
int sum[MAXN];

db f[MAXN][MAXV];

bool mark[MAXN];

void addE(int u,int v,int w,int x)
{
	edge[++id] = (Edge){v,w,x,first[u]};
	first[u] = id;
}

void dfs(int u,db v)
{
	mark[u] = 1;
	for (int j = L + 1;j <= L + 100;j++)
		f[u][j] = j + v;
	if (!first[u])
	{
		for (int j = 0;j <= L;j++)
			f[u][j] = j;
		return;
	}
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (!mark[edge[i].to])
			dfs(edge[i].to,v);
		db p = (db)edge[i].por / sum[u];
		for (int j = 0;j <= L;j++)
			f[u][j] += p * f[edge[i].to][j + edge[i].val];
	}
	if (u != 1)
	{
		for (int j = 0;j <= L;j++)
			f[u][j] = min(f[u][j],j + v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
//	cin >> n >> m >> L;
	cin >> n >> L;
	n++;
	m = n - 1;
	for (int u,v,w,x,i = 1;i <= m;i++)
	{
	//	cin >> u >> v >> w >> x;
		u = i,v = i + 1;
		int w1,w2;
		cin >> w1 >> w2 >> x;
		w = w1;
		sum[u] += x;
		addE(u,v,w,x);
		w = w2;
		x = 100 - x;
		sum[u] += x;
		addE(u,v,w,x);
	}
	db low = 0,high = INF;
	for (int i = 1;i <= 233;i++)
	{
		db mid = (low + high) * 0.5;
		memset(f,0,sizeof(f));
		memset(mark,0,sizeof(mark));
		dfs(1,mid);
		if (f[1][0] > mid)
			low = mid + eps;
		else
			high = mid;
	}
	cout << fixed << setprecision(10) << low << endl;
	return 0;
}