#include  <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Inf = 1e9;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);
	vector <vector <int>> gr(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[v].push_back(u);
		gr[u].push_back(v);
	}
	int k;
	cin >> k;
	vector <int> p(k);
	for (int i = 0; i < k; ++i) {
		cin >> p[i];
		--p[i];
	}
	int s = p.front(), t = p.back();
	vector <int> d(n, Inf);
	d[t] = 0;
	queue <int> q;
	q.push(t);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	int mn = 0, mx = 0;
	for (int i = 0; i + 1 < (int)p.size(); ++i) {
		int u = p[i], v = p[i + 1];
		if (d[u] != d[v] + 1) {
			++mn;
			++mx;
		} else {
			bool fl = false;
	  	for (auto w : gr[u]) {
	  	 	if (w != v && d[u] == d[w] + 1) {
	  	 		fl = true;
	  	 	}
	  	}
	  	if (fl) ++mx;
		}
	}
	cout << mn << ' ' << mx << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}	
}