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

typedef long long ll;

const int MAXN = 1400005;
const ll MOD = 1000000007;

struct Edge
{
	int to;
	int len;
	int nxt;
}edge[MAXN << 1];

int n,m,id;
int first[MAXN];
int dis[MAXN];
int pid[MAXN];
int pre[MAXN][25];

bool mark[MAXN];

ll ans[MAXN];

map<int,int> match;

struct Info
{
	int cur,pre,v,d;
};

bool fl;
struct cmp
{
	bool operator ()(const Info &a,const Info &b)
	{
		int u = a.pre,v = b.pre;
		if (!u)
			return 1;
		if (!v)
			return 0;
		if (a.d != b.d)
			return a.d > b.d;
		if (ans[u] == ans[v])
			return a.v > b.v;
		for (int i = 20;i >= 0;i--)
			if (ans[pre[u][i]] != ans[pre[v][i]])
			{
				u = pre[u][i];
				v = pre[v][i];
			}
		return pid[u] > pid[v];
	}
}A;

priority_queue<Info,vector<Info>,cmp> Q;

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

void Dijkstra()
{
	Q.push((Info){1,0,0});
	while (!Q.empty())
	{
		int u = Q.top().cur;
		Q.pop();
		if (mark[u])
			continue;
		mark[u] = 1;
		for (int i = first[u];i;i = edge[i].nxt)
			if (!mark[edge[i].to] && !A((Info){edge[i].to,u,edge[i].len,dis[u] + 1},(Info){edge[i].to,pre[edge[i].to][0],pid[edge[i].to],dis[edge[i].to]}))
			{
				pre[edge[i].to][0] = u;
				dis[edge[i].to] = dis[u] + 1;
				pid[edge[i].to] = edge[i].len;
				for (int j = 1;j <= 20;j++)
					pre[edge[i].to][j] = pre[pre[edge[i].to][j - 1]][j - 1];
				ans[edge[i].to] = (ans[u] * 10 + edge[i].len) % MOD;
				Q.push((Info){edge[i].to,u,edge[i].len,dis[u] + 1});
			}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	int N = n;
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		int I = i,lst = u;
		while (I > 0)
		{
			if (I < 10)
				addE(v,lst,I);
			else
				addE(++N,lst,I % 10);
			lst = N;
			I /= 10;
		}
		I = i,lst = v;
		while (I > 0)
		{
			if (I < 10)
				addE(u,lst,I);
			else
				addE(++N,lst,I % 10);
			lst = N;
			I /= 10;
		}
	}
	Dijkstra();
	for (int i = 2;i <= n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}