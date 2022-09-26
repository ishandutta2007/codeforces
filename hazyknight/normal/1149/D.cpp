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
#include <unordered_map>

using namespace std;

const int MAXN = 75;
const int MAXM = 205;
const int INF = 2e9;

struct Path
{
	int S,cur,dis;
	bool operator < (const Path &p)const
	{
		return dis > p.dis;
	}
};

int n,m,a,b,tot;
int u[MAXM];
int v[MAXM];
int w[MAXM];
int fa[MAXN];
int ans[MAXN];
int sz[MAXN];
int match[MAXN];
int f[1 << 17][MAXN];

bool mark[1 << 17][MAXN];

priority_queue<Path> Q;
vector<pair<int,int> > e[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void Dijkstra()
{
	ans[1] = 0;
	for (int i = 2;i <= n;i++)
		ans[i] = INF;
	for (int i = 0;i < (1 << tot);i++)
		for (int j = 1;j <= n;j++)
			f[i][j] = INF;
	if (sz[fa[1]] >= 4)
	{
		f[1 << match[fa[1]]][1] = 0;
		Q.push((Path){1 << match[fa[1]],1,0});
	}
	else
	{
		f[0][1] = 0;
		Q.push((Path){0,1,0});
	}
	while (!Q.empty())
	{
		int u = Q.top().cur,S = Q.top().S,d = Q.top().dis;
		Q.pop();
		if (mark[S][u])
			continue;
		mark[S][u] = 1;
		for (int i = 0;i < e[u].size();i++)
		{
			int to = e[u][i].first,dis = d + e[u][i].second;
			if (sz[fa[to]] >= 4 && (fa[to] == fa[u] || (~S >> match[fa[to]] & 1)) && dis < f[S | (1 << match[fa[to]])][to])
			{
				ans[to] = min(ans[to],dis);
				Q.push((Path){S | (1 << match[fa[to]]),to,f[S | (1 << match[fa[to]])][to] = dis});
			}
			if (sz[fa[to]] < 4 && dis < f[S][to])
			{
				ans[to] = min(ans[to],dis);
				Q.push((Path){S,to,f[S][to] = dis});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> a >> b;
	for (int i = 1;i <= n;i++)
		fa[i] = i;
	for (int i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		if (w[i] == a)
		{
			e[u[i]].push_back(make_pair(v[i],w[i]));
			e[v[i]].push_back(make_pair(u[i],w[i]));
			fa[getroot(u[i])] = getroot(v[i]);
		}
	}
	for (int i = 1;i <= m;i++)
		if (w[i] == b && getroot(u[i]) != getroot(v[i]))
		{
			e[u[i]].push_back(make_pair(v[i],w[i]));
			e[v[i]].push_back(make_pair(u[i],w[i]));
		}
	for (int i = 1;i <= n;i++)
		sz[getroot(i)]++;
	for (int i = 1;i <= n;i++)
		if (sz[i] >= 4)
			match[i] = tot++;
	Dijkstra();
	for (int i = 1;i <= n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}