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

const int MAXN = 10005;
const int MAXM = 1000005;
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int cap;
	int val;
	int nxt;
}edge[MAXM << 1];
 
int n,m,K,c,d,id,S,T,ans;
int t[55][105];
int first[MAXN];
int lev[MAXN];
int cur[MAXN];

bool vis[MAXN];
bool inqueue[MAXN];
 
queue<int> Q;
 
void addE(int u,int v,int c,int w)
{
	edge[++id] = (Edge){v,c,w,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,0,-w,first[v]};
	first[v] = id;
}
 
int dfs(int u,int f)
{
	if (u == T)
		return f;
	vis[u] = 1;
	int res = 0;
	for (int &i = cur[u];i;i = edge[i].nxt)
		if (!vis[edge[i].to] && edge[i].cap > 0 && lev[edge[i].to] == lev[u] + edge[i].val)
		{
			int ret = dfs(edge[i].to,min(f,edge[i].cap));
			ans += ret * edge[i].val;
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			if (!f)
				break;
		}
	return res;
}
 
bool bfs()
{
	for (int i = S;i <= T;i++)
		lev[i] = INF;
	Q.push(S);
	lev[S] = 0;
	inqueue[S] = 1;
	while (!Q.empty())
	{
		int u = Q.front();
		inqueue[u] = 0;
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap > 0 && lev[u] + edge[i].val < lev[edge[i].to])
			{
				lev[edge[i].to] = lev[u] + edge[i].val;
				if (!inqueue[edge[i].to])
				{
					inqueue[edge[i].to] = 1;
					Q.push(edge[i].to);
				}
			}
	}
	return lev[T] != INF;
}
 
int mcmf()
{
	int res = 0;
	while (bfs())
	{
		memcpy(cur,first,sizeof(cur));
		memset(vis,0,sizeof(vis));
		res += dfs(S,INF);
	}
	return ans;
}

int main()
{
	cin >> n >> m >> K >> c >> d;
	S = id = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= n + K;j++)
			t[i][j] = ++id;
	T = ++id;
	id = 1;
	for (int a,i = 1;i <= K;i++)
	{
		cin >> a;
		addE(S,t[a][0],1,0);
	}
	for (int i = 0;i <= n + K;i++)
		addE(t[1][i],T,K,0);
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < n + K;j++)
			addE(t[i][j],t[i][j + 1],K,c);
	for (int u,v,i = 1;i <= m;i++)
	{
		cin >> u >> v;
		for (int j = 0;j < n + K;j++)
			for (int k = 1;k <= K;k++)
				addE(t[u][j],t[v][j + 1],1,c + (2 * k - 1) * d);
		for (int j = 0;j < n + K;j++)
			for (int k = 1;k <= K;k++)
				addE(t[v][j],t[u][j + 1],1,c + (2 * k - 1) * d);
	}
	cout << mcmf() << endl;
	return 0;
}