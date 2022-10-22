#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, pii> ppp;

vector <ppp> edge;
vector <pii> from[210];
int fa[210], maxj[210], up[210], par[210], tot;
int n;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs(int x, int last) {
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, w = from[x][i].se;
		if (v == last) continue;
		maxj[v] = max(maxj[x], w), up[v] = w, par[v] = x, dfs(v, x);
	}
}

void Erase(int x, int y) {
	for (int i = 0; i < from[x].size(); i++) {
		if (from[x][i].fi == y) {
			from[x].erase(from[x].begin() + i);
			break;
		}
	}
	for (int i = 0; i < from[y].size(); i++) {
		if (from[y][i].fi == x) {
			from[y].erase(from[y].begin() + i);
			break;
		}
	}
}

void add_edge(int x, int y, int c) {
	if (find(x) != find(y)) {
		fa[find(x)] = find(y);
		from[x].push_back(mp(y, c));
		from[y].push_back(mp(x, c)); 
		tot--;
		return ;
	}
	maxj[x] = -1, dfs(x, x);
	if (maxj[y] <= c) return ;
	int cur = y;
	while (up[cur] != maxj[y]) cur = par[cur];
	Erase(par[cur], cur);
	from[x].push_back(mp(y, c));
	from[y].push_back(mp(x, c));
}

int get_s() {
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < from[i].size(); j++) {
			ans = max(ans, from[i][j].se);
		}
	}
	return ans;
}

int main () {
	int m, G, S; scanf("%d%d%d%d", &n, &m, &G, &S);
	for (int i = 0; i < m; i++) {
		int x, y, a, b; scanf("%d%d%d%d", &x, &y, &a, &b);
		edge.push_back(mp(mp(a, b), mp(x, y)));
	}
	sort(edge.begin(), edge.end());
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	tot = n;
	for (int i = 0; i < m; i++) {
		int g = edge[i].fi.fi, x = edge[i].se.fi, y = edge[i].se.se, c = edge[i].fi.se;
		add_edge(x, y, c);
		if (tot == 1) ans = min(ans, 1ll * g * G + 1ll * get_s() * S);
	}
	if (ans == 0x3f3f3f3f3f3f3f3f) ans = -1;
	printf("%lld\n", ans);
	return 0;
}
/*
3 3
2 1
1 2 10 15
1 2 4 20
1 3 5 1

*/