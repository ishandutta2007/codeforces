#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

vector <int> g[MAXN];
vector <int> ng[MAXN];
int tin[MAXN], fup[MAXN];
int timer = 0;

bool used1[MAXN];
set <pair <int, int> > ms;
void dfs1(int u, int parent) {
	tin[u] = fup[u] = timer++;
	used1[u] = 1;
	for (int v : g[u]) {
		if (v == parent) continue;

	 	if (used1[v]) {
	 		fup[u] = min(fup[u], tin[v]);
	 	}
	 	else {
			dfs1(v, u);
			if (tin[u] < fup[v]) {
				ms.insert({u, v});
				ms.insert({v, u});
			}
			fup[u] = min(fup[u], fup[v]);
	 	}
	}
}

int c[MAXN];
bool used2[MAXN];
void dfs2(int u, int cm) {
	c[u] = cm;
	used2[u] = 1;
	for (int v : g[u]) {
		if (ms.find({u, v}) != ms.end()) continue;
		if (used2[v]) continue;
		dfs2(v, cm);
	}
}

bool used3[MAXN];
pair <int, int> dfs3(int u, int parent) {
	pair <int, int> ans = {0, u};
	for (int v : ng[u]) {
	 	if (v == parent) continue;
	 	pair <int, int> tmp = dfs3(v, u);
	 	ans = max(ans, {tmp.first + 1, tmp.second});
	}
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
	 	int u, v;
	 	cin >> u >> v;
	 	--u; --v;
	 	g[u].push_back(v);
	 	g[v].push_back(u);
	}

	dfs1(0, 0);

	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (!used2[i]) {
		 	dfs2(i, k);
		 	++k;
		}
	}

	for (auto el : ms) {
		int u = c[el.first];
		int v = c[el.second];
		ng[u].push_back(v);
	}

	auto t1 = dfs3(0, 0);
	auto ans = dfs3(t1.second, t1.second);

	cout << ans.first << '\n';
    return 0;
}