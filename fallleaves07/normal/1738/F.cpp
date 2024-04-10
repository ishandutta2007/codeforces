#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct DSU {
	vector<int> fa;
	DSU(int n) : fa(n + 1) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int getfa(int v) {
		return (fa[v] == v) ? v : (fa[v] = getfa(fa[v]));
	}
	bool merge(int u, int v) {
		u = getfa(u), v = getfa(v);
		if (u == v) {
			return false;
		}
		fa[u] = v;
		return true;
	}
};

int query(int v) {
	printf("? %d\n", v);
	fflush(stdout);
	int u;
	cin >> u;
	return u;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> deg(n);
	for (int i = 0; i < n; i++) {
		cin >> deg[i].first;
		deg[i].second = i + 1;
	}
	sort(deg.begin(), deg.end());
	vector<int> col(n + 1);
	int cnt = 0;
	DSU dsu(n);
	for (int i = n - 1; i >= 0; i--) {
		int v = deg[i].second;
		if (col[dsu.getfa(v)]) {
			continue;
		}
		for (int j = 0; j < deg[i].first; j++) {
			int u = query(v);
			if (col[dsu.getfa(u)]) {
				dsu.merge(v, u);
				break;
			} else {
				dsu.merge(u, v);
			}
		}
		if (!col[dsu.getfa(v)]) {
			col[dsu.getfa(v)] = ++cnt;
		}
	}
	printf("! ");
	for (int i = 1; i <= n; i++) {
		printf("%d ", col[dsu.getfa(i)]);
	}
	printf("\n");
	fflush(stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}