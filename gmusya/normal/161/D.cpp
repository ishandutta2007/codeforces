#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;
int n, k;
ll ans = 0;
vector <bool> used;
vector <int> d;
vector <vector <int>> g;
vector <map <int, ll>> cnt;

void dfs1(int v) {
	used[v] = true;
	for (int u : g[v]) 
		if (!used[u]) {
			d[u] = d[v] + 1;
			dfs1(u);
		}
}

void dfs2(int v) {
	used[v] = true;
	cnt[v][d[v]]++;
	for (ll u : g[v]) {
		if (!used[u]) {
			dfs2(u);
			if (cnt[u].size() > cnt[v].size())
				swap(cnt[u], cnt[v]);
			for (auto now : cnt[u]) 
				ans += now.second * cnt[v][d[v] + (k - (now.first - d[v]))];
			for (auto now : cnt[u])
				cnt[v][now.first] += now.second;
		}
	}
}

int main() {
	cin >> n >> k;
	used.resize(n), d.resize(n), g.resize(n), cnt.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs1(0);
	used.assign(n, false);
	dfs2(0);
	cout << ans;
	return 0;
}