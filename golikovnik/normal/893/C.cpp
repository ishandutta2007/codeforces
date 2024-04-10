#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

vector<int> gold, comp;
vector<char> used;
vector<vector<int>> g;

const int INF = 1e9 + 10;

void dfs(int v) {
	used[v] = true;
	*comp.rbegin() = min(gold[v], *comp.rbegin());
	for (int u: g[v]) {
		if (!used[u]) {
			dfs(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	gold.resize(n);
	for(int i = 0; i < n; ++i) cin >> gold[i];
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			comp.push_back(INF);
			dfs(i);
		}
	}
	ll sum = 0;
	for(int u: comp) {
		sum += u;
	}
	cout << sum;
	return 0;
}