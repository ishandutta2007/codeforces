#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Edge {
	int to;
	int idx;
};

const int N = 555'555;
vector<Edge> g[N];
char used_edge[N];
int ptr[N];

void euler(int v, vector<int>& res) {
	while (ptr[v] < (int)g[v].size() && used_edge[g[v][ptr[v]].idx]) {
		++ptr[v];
	}
	if (ptr[v] == (int)g[v].size()) {
		return;
	}
	const auto& e = g[v][ptr[v]];
	used_edge[e.idx] = 1;
	euler(e.to, res);
	res.push_back(e.idx);
	euler(v, res);
}

void add_edge(int u, int v, int i) {
	g[u].push_back({v, i});
	g[v].push_back({u, i});
}

void solve() {
	int n = nxt();
	vector<vector<int>> a(n);
	vector<int> everything;
	for (int i = 0; i < n; ++i) {
		a[i].resize(nxt());
		for (int& x : a[i]) {
			x = nxt();
			everything.push_back(x);
		}
	}
	make_unique(everything);
	for (auto& v : a) {
		for (int& x : v) {
			x = lower_bound(all(everything), x) - everything.begin();
		}
	}
	const int sz = everything.size();

	int cur = 0;
	vector<pair<int, int>> poss;
	vector<string> ans(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			add_edge(i, a[i][j] + n, cur++);
			poss.push_back({i, j});
		}
		ans[i] = string(a[i].size(), 'L');
	}

	for (int i = n; i < n + sz; ++i) {
		if ((int)g[i].size() % 2) {
			cout << "NO\n";
			return;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (ptr[i] < (int)g[i].size()) {
			vector<int> res;
			euler(i, res);
			reverse(all(res));
			for (int i = 0; i < (int)res.size(); i += 2) {
				auto [x, y] = poss[res[i]];
				ans[x][y] = 'R';
			}
		}
	}
	cout << "YES\n";
	for (auto s : ans) {
		cout << s << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}