#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
	int to;
	int id;
};

const int N = 222222;
vector<Edge> a[N];
char banned[N];
int sz[N];
int pid[N];

const int L = 30;
int fs[L];

void dfs(int v, int p) {
	sz[v] = 1;
	for (auto [to, id] : a[v]) {
		if (to == p || banned[id]) {
			continue;
		}
		pid[to] = id;
		dfs(to, v);
		sz[v] += sz[to];
	}
}

int find_sz(int v, int p, int need) {
	if (sz[v] == need) {
		return v;
	}
	for (auto [to, id] : a[v]) {
		if (to == p || banned[id]) {
			continue;
		}
		if (int tmp = find_sz(to, v, need); tmp > -1) {
			return tmp;
		}
	}
	return -1;
}

bool check(int v, int k) {
	if (fs[k] == 1) {
		return true;
	}
	dfs(v, v);
	int g = -1;
	if (int tmp = find_sz(v, v, fs[k - 1]); tmp > -1) {
		g = tmp;
	}
	if (g == -1) {
		if (int tmp = find_sz(v, v, fs[k - 2]); tmp > -1) {
			g = tmp;
		}
	}
	if (g == -1) {
		return false;
	}
	banned[pid[g]] = true;
	if (sz[g] == fs[k - 1]) {
		return check(v, k - 2) && check(g, k - 1);
	} else {
		return check(g, k - 2) && check(v, k - 1);
	}
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back({v, i});
		a[v].push_back({u, i});
	}
	fs[0] = 0;
	fs[1] = 1;
	for (int i = 2; i < L; ++i) {
		fs[i] = fs[i - 1] + fs[i - 2];
	}

	int k = 2;
	while (fs[k] < n) {
		++k;
	}
	if (fs[k] != n) {
		puts("NO");
		return;
	}
	puts(check(0, k) ? "YES" : "NO");
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}