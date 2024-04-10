#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> from[10010];
vector <int> node, nd1, nd2;
int deg[10010], fa[10010];
int X[10010], Y[10010];
int cur[10010], vis[10010];

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

int merge(int x, int y) {
	if (find(x) == find(y)) return 0;
	fa[find(x)] = find(y);
	return 1;
}

vector <int> path;

void get_path(int x) {
	for (int &i = cur[x]; i < from[x].size(); ) {
		int v = from[x][i].fi, id = from[x][i].se;
		i++;
		if (vis[id]) continue;
		vis[id] = 1;
		get_path(v), path.push_back(id);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m; scanf("%d", &m);
	if (m <= 1) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(mp(y, i));
		from[y].push_back(mp(x, i));
		X[i] = x, Y[i] = y;
		deg[x]++, deg[y]++;
		node.push_back(x), node.push_back(y);
	}
	sort(node.begin(), node.end()), node.resize(unique(node.begin(), node.end()) - node.begin());
	for (auto x : node) fa[x] = x;
	int tot = node.size();
	for (auto x : node) {
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i].fi;
			tot -= merge(x, v);
		}
	}
	if (tot > 2) {
		printf("-1\n");
		return 0;
	}
	if (tot == 2) {
		int X = -1, Y = -1;
		for (auto x : node) {
			if (find(x) == x) {
				if (X == -1) X = x;
				else Y = x;
			}
		}
		for (auto x : node) {
			if (find(x) == X) nd1.push_back(x);
			else nd2.push_back(x);
		}
		int cnt = 0, rt = nd1[0];
		for (auto x : nd1) {
			if (deg[x] & 1) cnt++, rt = x;
		}
		if (cnt > 2) {
			printf("-1\n");
			return 0;
		}
		cnt = 0;
		for (auto x : nd2) cnt += deg[x] & 1;
		if (cnt > 2) {
			printf("-1\n");
			return 0;
		}
		get_path(rt);
		printf("%d\n", (int)path.size());
		for (auto x : path) printf("%d ", x);
		printf("\n");
		path.clear();
		cnt = 0, rt = nd2[0];
		for (auto x : nd2) {
			if (deg[x] & 1) cnt++, rt = x;
		}
		get_path(rt);
		printf("%d\n", (int)path.size());
		for (auto x : path) printf("%d ", x);
		printf("\n");
		return 0;
	}
	tot = 0;
	for (auto x : node) tot += deg[x] & 1;
	if (tot > 4) {
		printf("-1");
		return 0;
	}
	if (tot < 4) {
		int rt = node[0];
		for (auto x : node) {
			if (deg[x] & 1) rt = x;
		}
		get_path(rt), reverse(path.begin(), path.end());
		printf("1\n");
		printf("%d\n", path[0]);
		printf("%d\n", (int)path.size() - 1);
		for (int i = 1; i < path.size(); i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return 0;
	}
	int lst = -1;
	for (auto x : node) {
		if (deg[x] & 1) {
			if (lst == -1) lst = x;
			else {
				deg[x]++, deg[lst]++;
				from[x].push_back(mp(lst, ++m)), from[lst].push_back(mp(x, m));
				break;
			}
		}
	}
	for (auto x : node) {
		if (deg[x] & 1) {
			get_path(x);
			int cur = 0;
			while (path[cur] != m) cur++;
			printf("%d\n", cur);
			for (int i = 0; i < cur; i++) {
				printf("%d ", path[i]);
			}
			printf("\n");
			printf("%d\n", (int)path.size() - cur - 1);
			for (int i = cur + 1; i < path.size(); i++) {
				printf("%d ", path[i]);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}