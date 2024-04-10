#include <iostream>
#include <vector>

#define ll long long

using namespace std;

bool tf = true;
ll n, m, ver, edg;
vector <bool> used;
vector <vector <ll>> g;

void dfs(ll u) {
	used[u] = true;
	ver++;
	edg += g[u].size();
	for (ll i = 0; i < g[u].size(); i++)
		if (!used[g[u][i]])
			dfs(g[u][i]);
}
int main() {
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (ll i = 0; i < n; i++) {
		if (used[i])
			continue;
		ver = 0;
		edg = 0;
		dfs(i);
		if (ver * (ver - 1) != edg)
			tf = false;
	}
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}