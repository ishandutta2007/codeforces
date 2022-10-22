#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int MAXN = 2e5 + 7;

int cnt = 0;
int n, m, q;
pair <int, int> a[MAXN];

vector <int> g[2][MAXN];
bool used[2][MAXN];
bool usedx[MAXN], usedy[MAXN];

void dfs(int u, bool t) {
	used[t][u] = 1;
	for (int v : g[t][u]) {
	 	if (!used[t ^ 1][v]) {
	 	 	dfs(v, t ^ 1);
	 	}
	}
}

void read() {
	cin >> n >> m >> q;
	for (int i = 0; i < q; ++i) {
		cin >> a[i].x >> a[i].y;		
		--a[i].x;
		--a[i].y;
		g[0][a[i].x].push_back(a[i].y);
		g[1][a[i].y].push_back(a[i].x);
		usedx[a[i].x] = 1;
		usedy[a[i].y] = 1;
	}
}

void solve() {
	for (int i = 0; i < n; ++i) {
		if (!usedx[i]) continue;
	 	if (!used[0][i]) {
	 		++cnt;
	 		dfs(i, 0);
	 	}
	}
	for (int i = 0; i < m; ++i) {
		if (!usedy[i]) continue;
	 	if (!used[1][i]) {
	 		++cnt;
	 		dfs(i, 1);
	 	}
	}
}

void print() {
	int ans = 0;
	for (int i = 0; i < n; ++i) ans += !usedx[i];
	for (int i = 0; i < m; ++i) ans += !usedy[i];
	ans += cnt - 1;
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	read();
	solve();
	print();

 	return 0;
}