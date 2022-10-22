#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
     	
const int MAXN = 1e5 + 7;
const int MAXK = 107;
const int INF = 1e9 + 7;

int d[MAXN][MAXK];
int a[MAXN];
vector <int> g[MAXN];

void bfs(int c, int n) {
	for (int i = 0; i < n; ++i) d[i][c] = INF;

 	queue <int> q;
 	for (int i = 0; i < n; ++i) {
 	 	if (a[i] == c) {
 	 	 	d[i][c] = 0;
 	 	 	q.push(i);
 	 	}
 	}

 	while (!q.empty()) {
 	 	int u = q.front();
 	 	q.pop();

 	 	for (int v : g[u]) {
 	 	 	if (d[u][c] + 1 < d[v][c]) {
 	 	 	 	d[v][c] = d[u][c] + 1;
 	 	 	 	q.push(v);
 	 	 	}
 	 	}
 	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	for (int i = 0; i < m; ++i) {
	 	int u, v;
	 	cin >> u >> v;
	 	--u; --v;
	 	g[u].push_back(v);
	 	g[v].push_back(u);
	}

	for (int i = 0; i < k; ++i) {
		bfs(i, n);
	}

	for (int i = 0; i < n; ++i) {
		sort(d[i], d[i] + k);
		int ans = 0;
		for (int j = 0; j < s; ++j) ans += d[i][j];
		cout << ans << ' ';
	}
	cout << '\n';

	return 0;
}