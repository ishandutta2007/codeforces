#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int a[MAXN];
vector <int> g[MAXN];
bool used[MAXN];

void dfs(int u) {
	used[u] = true;
	for (int v : g[u]) if (!used[v]) dfs(v);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) --a[i];
	for (int i = 0; i < n; ++i) g[i].push_back(a[i]);
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
		 	dfs(i); ++k;
		}
	}

	if ((n - k) % 2 == (3 * n) % 2) {
		cout << "Petr\n";
	}
	else {
	 	cout << "Um_nik\n";
	}

	return 0;
}