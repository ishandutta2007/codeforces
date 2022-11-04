// problem F

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100 + 100;
const int MAXV = 100000 + 1000;
const int MAXE = 1000000 + 1000;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int next, to, w, c;
}
e[MAXE];
int p[MAXV], head[MAXV], l = 2;

void addE(int a, int b, int c, int d)
{
	e[l] = (Edge){p[a], b, c, d}, p[a] = l++;
	e[l] = (Edge){p[b], a, 0, -d}, p[b] = l++;
}

int S, T, totp = 0;
int dis[MAXV];
bool vis[MAXV];
int flow = 0, cost = 0;
queue<int> que;

bool spfa()
{
	memset(dis, 63, (totp + 2) * sizeof(dis[0]));
	memset(vis, 0, (totp + 2) * sizeof(vis[0]));
	vis[S] = true, dis[S] = 0, que.push(S);
	while(!que.empty())
	{
		int x = que.front();
		que.pop();
		vis[x] = false;
		for(int i = p[x]; i; i = e[i].next)
			if(e[i].w > 0 && dis[e[i].to] > dis[x] + e[i].c)
			{
				int y = e[i].to;
				dis[y] = dis[x] + e[i].c;
				if(!vis[y])
					que.push(y), vis[y] = true;
			}
	}
	return dis[T] < INF;
}
int dfs(int x, int s)
{
	if(x == T)
		return s;
	int ret = 0;
	vis[x] = true;
	for(int &i = head[x]; i; i = e[i].next)
		if(e[i].w > 0 && !vis[e[i].to] && dis[e[i].to] == dis[x] + e[i].c)
		{
			int y = e[i].to, t = dfs(y, min(s, e[i].w));
			e[i].w -= t, e[i ^ 1].w += t;
			s -= t, ret += t;
			cost += e[i].c * t;
			if(s <= 0)
				break;
		}
	// cerr << x << endl;
	vis[x] = false;
	return ret;
}

void dinic()
{
	while(spfa())
	{
		memcpy(head, p, (totp + 2) * sizeof(p[0]));
		// cerr << "!" << endl;
		// cerr << dis[T] << endl;
		flow += dfs(S, INF);
		// cerr << flow << endl;
	}
}

int n, m;
int a[MAXN], b[MAXN];
int id1[MAXN], id2[MAXN], id3[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		a[i] = 1, b[i] = n;
	for(int i = 1; i <= m; i++)
	{
		int t, l, r, v;
		cin >> t >> l >> r >> v;
		if(t == 1)
			for(int j = l; j <= r; j++)
				a[j] = max(a[j], v);
		else
			for(int j = l; j <= r; j++)
				b[j] = min(b[j], v);
	}
	for(int i = 1; i <= n; i++)
		if(a[i] > b[i])
		{
			cout << -1 << endl;
			exit(0);
		}
	totp = 0, S = ++totp, T = ++totp;
	for(int i = 1; i <= n; i++)
		id1[i] = ++totp;
	for(int i = 1; i <= n; i++)
		id2[i] = ++totp;
	for(int i = 1; i <= n; i++)
		for(int j = a[i]; j <= b[i]; j++)
			id3[i][j] = ++totp;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			addE(S, id1[i], 1, 2 * j - 1);
	for(int i = 1; i <= n; i++)
		addE(id2[i], T, 1, 0);
	for(int i = 1; i <= n; i++)
		for(int j = a[i]; j <= b[i]; j++)
		{
			addE(id1[j], id3[i][j], 1, 0);
			addE(id3[i][j], id2[i], 1, 0);
		}

	dinic();
	// cerr << flow << endl;
	cout << cost << endl;

	return 0;
}