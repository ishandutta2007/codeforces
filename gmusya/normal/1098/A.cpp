#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

bool tf = true;
int n;
ll ans = 0;
vector <ll> a, s, d;
vector <vector <int>> g;

void dfs1(int v) {
	for (int u : g[v]) {
		d[u] = d[v] + 1;
		dfs1(u);
	}
}

void dfs2(int v, int p) {
	if (p != -1 && d[v] % 2)
		ans += s[v] - s[p];
	if (d[v] % 2) {
		for (int u : g[v])
			dfs2(u, v);
		return;
	}
	if (!g[v].size()) return;
	for (int u : g[v])
		if (s[u] < s[p])
			tf = false;
	ll val = INF;
	for (int u : g[v])
		val = min(s[u], val);
	s[v] = val;
	ans += s[v] - s[p];
	for (int u : g[v])
		dfs2(u, v);
}

int main() {	
	cin >> n;
	a.resize(n), s.resize(n), d.resize(n), g.resize(n);
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		g[p - 1].push_back(i);
	}
	for (int i = 0; i < n; i++)
		cin >> s[i];
	ans = s[0];
	d[0] = 1;
	dfs1(0);
	dfs2(0, -1);
	if (!tf) cout << -1;
	else cout << ans;
	return 0;
}