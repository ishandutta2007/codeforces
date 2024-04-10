#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> ppp;

vector <int> path;
int f[5010];
vector <pii> from[5010];

bool dfs(int x, int last, int y) {
	if (x == y) return 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, id = from[x][i].se;
		if (v == last) continue;
		path.push_back(id);
		if (dfs(v, x, y)) return 1;
		path.pop_back();
	}
	return 0;
}

void update(int x, int y, int v) {
	path.clear(), dfs(x, x, y);
	for (int i = 0; i < path.size(); i++) {
		f[path[i]] = v;
	}
}

int query(int x, int y) {
	path.clear(), dfs(x, x, y);
	int res = 10000000;
	for (int i = 0; i < path.size(); i++) {
		res = min(res, f[path[i]]);
	}
	return res;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(mp(v, i)), from[v].push_back(mp(u, i));
		f[i] = 1000000;
	}
	int m; scanf("%d", &m);
	vector <ppp> all;
	for (int i = 0; i < m; i++) {
		int x, y, v; scanf("%d%d%d", &x, &y, &v);
		all.push_back(mp(v, mp(x, y)));
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < all.size(); i++) {
		update(all[i].se.fi, all[i].se.se, all[i].fi);
	}
	for (int i = 0; i < all.size(); i++) {
		if (query(all[i].se.fi, all[i].se.se) != all[i].fi) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 1; i < n; i++) {
		printf("%d ", f[i]);
	}
	printf("\n");
	return 0;
}