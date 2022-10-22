#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppp;

int a[310], b[310], vis[310], vvv[310];
vector <int> from[310];
vector <int> node;
queue <int> q;
int lst[310];
vector <int> path;

void dfs(int x) {
	vis[x] = 1, node.push_back(x);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (vis[v]) continue;
		dfs(v);
	}
}

int V;
vector <ppp> all;

void give(int now, int val) {
	if (now + 2 == path.size()) {
		all.push_back(mp(mp(path[now], path[now + 1]), val));
		a[path[now]] -= val, a[path[now + 1]] += val;
		return ;
	}
	int x = path[now], y = path[now + 1];
	if (a[y] + val <= V) {
		all.push_back(mp(mp(x, y), val));
		a[x] -= val, a[y] += val;
		give(now + 1, val);
	} else {
		int tmp = V - a[y];
		all.push_back(mp(mp(x, y), tmp));
		a[x] -= tmp, a[y] += tmp;
		give(now + 1, val);
		all.push_back(mp(mp(x, y), val - tmp));
		a[x] -= val - tmp, a[y] += val - tmp;
	}
}

int main () {
	int n, m; scanf("%d%d%d", &n, &V, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	for (int it = 1; it <= n; it++) {
		if (vis[it]) continue;
		node.clear(), dfs(it);
		long long sa = 0, sb = 0;
		for (int i = 0; i < node.size(); i++) {
			int x = node[i];
			sa += a[x], sb += b[x];
		}
		if (sa != sb) {
			printf("NO\n");
			return 0;
		}
		while (1) {
			while (q.size()) q.pop();
			for (int i = 0; i < node.size(); i++) {
				int x = node[i]; vvv[x] = 0;
				if (a[x] < b[x]) q.push(x), vvv[x] = 1;
			}
			int pos = -1;
			while (!q.empty()) {
				int x = q.front(); q.pop();
				for (int i = 0; i < from[x].size(); i++) {
					int v = from[x][i];
					if (vvv[v]) continue;
					vvv[v] = 1, lst[v] = x;
					if (a[v] > b[v]) {
						pos = v;
						goto END;
					}
					q.push(v);
				}
			}
			END:;
			if (pos == -1) break;
			path.clear(), path.push_back(pos);
			while (a[pos] >= b[pos]) {
				pos = lst[pos];
				path.push_back(pos);
			}
			int X = path[0], Y = path.back(), tmp = min(a[X] - b[X], b[Y] - a[Y]);
			give(0, tmp);
		}
	}
	printf("%d\n", all.size());
	for (int i = 0; i < all.size(); i++) {
		printf("%d %d %d\n", all[i].fi.fi, all[i].fi.se, all[i].se);
	}
	return 0;
}