#include <iostream>

#include <cstdio>

#include <cstring>

#include <queue>

#include <vector>

#define maxn 20005

#define N 400005

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, u[maxn], v[maxn], uu, vv;

vector<int> T[maxn];

int maxson[maxn], siz[maxn], dep[maxn], f[maxn], top[maxn];

int dfn[maxn], rnk[maxn], numcolor;

struct Edge

{

	int v, nxt, w;

}G[N * 4];

int tot = -1, cnt = 0;

int adj[maxn * 4], cur[maxn * 4];

inline void add(int u, int v, int w)

{

	G[++tot] = (Edge){v, adj[u], w};

	adj[u] = tot;

	G[++tot] = (Edge){u, adj[v], 0};

	adj[v] = tot;

}

void dfs1(int x, int fa)

{

	f[x] = fa;

	siz[x] = 1;

	dep[x] = dep[fa] + 1;

	for (int i = 0; i < T[x].size(); i++)

	{

		int V = T[x][i];

		if(V == fa) continue;

		dfs1(V, x);

		siz[x] += siz[V];

		if(siz[V] > siz[maxson[x]]) maxson[x] = V;

	}

}

int lc[maxn], rc[maxn];

void dfs2(int x, int anc)

{

	dfn[x] = ++numcolor;

	rnk[numcolor] = x;

	top[x] = anc;

	if(!maxson[x]) return;

	dfs2(maxson[x], anc);

	for (int i = 0; i < T[x].size(); i++)

	{

		int V = T[x][i];

		if(V == f[x] || V == maxson[x]) continue;

		dfs2(V, V);

	}

}

int build(int l, int r)

{

	if(l == r) return rnk[l];

	int mid = (l + r) >> 1;

	int tmp = ++cnt;

	lc[tmp] = build(l, mid), rc[tmp] = build(mid + 1, r);

	add(lc[tmp], tmp, INF);

	add(rc[tmp], tmp, INF);

	return tmp;

}

void que(int x, int l, int r, int a, int b, int to)

{

	if(a <= l && r <= b)

	{

		add(x, to, INF);

		return;

	}

	int mid = (l + r) >> 1;

	if(a <= mid) que(lc[x], l, mid, a, b, to);

	if(b > mid) que(rc[x], mid + 1, r, a, b, to);

}

void work(int x, int y)

{

	cnt++;

	while(top[x] != top[y])

	{

		if(dep[top[x]] > dep[top[y]]) swap(x, y);

//		printf("%d %d\n", x, y);

		que(n + 1, 1, n, dfn[top[y]], dfn[y], cnt);

		y = f[top[y]]; 

	}

	if(dep[x] > dep[y]) swap(x, y);

//		printf("%d %d\n", dfn[x], dfn[y]);

	if(x != y) que(n + 1, 1, n, dfn[x] + 1, dfn[y], cnt);

}

int dis[maxn];

queue<int> q;

int bfs()

{

	for (int i = 1; i <= cnt; i++) dis[i] = INF;

	dis[0] = 0;

	q.push(0);

	while(!q.empty())	

	{

		int u = q.front();

		q.pop();

		for (int i = adj[u]; i != -1; i = G[i].nxt)

		{

			int V = G[i].v;

			if(G[i].w && dis[V] > dis[u] + 1) 

			{

				dis[V] = dis[u] + 1;

				q.push(V);

			}

		}

	}

	return dis[cnt] != INF; 

}

int dfs(int x, int flow)

{

	if(x == cnt) return flow;

	int rest = flow;

	for (int i = adj[x]; i != -1; i = G[i].nxt)

	{

		cur[x] = i;

		int V = G[i].v;

		if(!G[i].w || dis[V] != dis[x] + 1) continue;

		int tmp = dfs(V, min(rest, G[i].w));

		G[i].w -= tmp;

		G[i ^ 1].w += tmp;

		rest -= tmp;

	}

	return flow - rest;

}
int vis[maxn * 4];
int vis1[maxn], vis2[maxn], ans1, ans2;
void check(int x)
{
	vis[x] = 1;
	if(cnt - 1 >= x && x >= cnt - m) 
	{
		vis1[x - (cnt - m) + 1] = 1;
		ans1++;
	}
	if(1 <= x && x <= n) 
	{
		vis2[x] = 1;
		ans2--;
	}
	for (int i = adj[x]; i != -1; i = G[i].nxt)
	{
		int V = G[i].v;
		if(vis[V] || !G[i].w) continue;
		check(V);
	}
}

inline int read()

{

	int x = 0; char ch = getchar();

	while(ch < '0' || ch > '9') ch = getchar();

	while(ch >= '0' && ch <= '9')

	{

		x = (x << 3) + (x << 1) + ch - '0';

		ch = getchar();

	}

	return x;

}

int type[maxn];

int main()

{
//	freopen("pastel.in", "r", stdin);
//	freopen("pastel.out", "w", stdout);
	memset(adj, -1, sizeof(adj));

	scanf("%d%d", &n, &m);

	for (int i = 1; i < n; i++)

	{

		u[i] = read(), v[i] = read();

		T[u[i]].push_back(v[i]);

		T[v[i]].push_back(u[i]); 

	}

	dfs1(1, 1);

	dfs2(1, 1);

	for (int i = 1; i < n; i++)

	{

		if(dep[u[i]] > dep[v[i]]) swap(u[i], v[i]);

		type[v[i]] = i;

	}

	for (int i = 1; i <= n; i++) add(0, i, 1);

	cnt = n;

	build(1, n);

	for (int i = 1; i <= m; i++)

	{

		uu = read(), vv = read();

		work(uu, vv);

	}

	cnt++;

	for (int i = cnt - 1; i >= cnt - m; i--) add(i, cnt, 1);

	int ans = 0;

	while(bfs())

	{

		for (int i = 0; i <= cnt; i++) cur[i] = adj[i];

		ans += dfs(0, n + m);

//		printf("%d\n", ans);

	}
	printf("%d\n", ans);
	check(0);
	printf("%d ", ans1);
	for (int i = 1; i <= m; i++) if(vis1[i]) printf("%d ", i);
	printf("\n%d ", n + ans2);
	for (int i = 1; i <=n; i++) if(!vis2[i]) printf("%d ",type[i]);

	return 0;

}