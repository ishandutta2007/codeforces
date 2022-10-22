#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> from[100010];
set <int> G[100010];
int sum[100010], ins[100010], vis[100010];
int f[100010], g[100010], cho[100010];
vector <pii> ans, Era;
vector <int> path;

void dfs(int x, int last) {
	ins[x] = vis[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		if (!vis[v]) dfs(v, x);
		else if (ins[v]) sum[x]++, sum[v]--;
	}
	ins[x] = 0;
}

int GetSum(int x, int last) {
	vis[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		if (!vis[v]) {
			int tmp = GetSum(v, x);
			if (!tmp) G[x].insert(v), G[v].insert(x);
			sum[x] += tmp;
		}
	}
	return sum[x];
}

int solve(int x, int last) {
	vis[x] = 1;
	for (auto v : G[x]) {
		if (v == last) continue;
		if (solve(v, x) && G[x].size() % 2 == 1 && !cho[x]) cho[x] = cho[v] = 1, Era.push_back(mp(x, v));
	}
	return G[x].size() % 2 == 1 && !cho[x];
}

void GetPath(int x) {
	while (G[x].size()) {
		int v = *G[x].begin(); G[x].erase(G[x].begin()), G[v].erase(x);
		GetPath(v), path.push_back(v);
	}
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) G[i].clear(), from[i].clear(), vis[i] = 0, sum[i] = 0;
		while (m--) {
			int k; scanf("%d", &k);
			int lst = -1;
			while (k--) {
				int x; scanf("%d", &x);
				if (lst != -1) from[lst].push_back(x), from[x].push_back(lst);
				lst = x;
			}
		}
		dfs(1, 1);
		for (int i = 1; i <= n; i++) vis[i] = 0;
		GetSum(1, 1);
		for (int i = 1; i <= n; i++) vis[i] = 0, cho[i] = 0;
		ans.clear(), Era.clear();
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			solve(i, i);
		}
		for (auto it : Era) G[it.fi].erase(it.se), G[it.se].erase(it.fi);
		G[0].clear();
		for (int i = 1; i <= n; i++) if (G[i].size() & 1) G[i].insert(0), G[0].insert(i);
		path.clear(), GetPath(0), reverse(path.begin(), path.end());
		for (int i = 0; i < path.size(); i++) {
			int j = i; while (path[j]) j++;
			ans.push_back(mp(path[i], path[j - 1])), i = j;
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d %d\n", ans[i].fi, ans[i].se);
		}
	}
	return 0;
}