#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

template <class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template <class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template <class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<pair<int, int>>> a(n);
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back({v, i});
		a[v].push_back({u, i});
		edges[i] = {u, v};
	}
	vector<char> used(n);
	vector<int> color(m, 1);
	vector<int> par_id(n, -1);
	vector<int> level(n);
	auto dfs = y_combinator([&](auto self, int v, int pid) -> void {
		par_id[v] = pid;
		used[v] = 1;
		for (auto [x, i] : a[v]) {
			if (i == pid) {
				continue;
			}
			if (used[x]) {
				continue;
			}
			color[i] = 0;
			level[x] = level[v] + 1;
			self(x, i);
		}
	});
	dfs(0, -1);

	auto is_triangle = [&](vector<int> eids) {
		if ((int)eids.size() != 3) {
			return false;
		}
		set<int> vs;
		for (int i : eids) {
			vs.insert(edges[i].first);
			vs.insert(edges[i].second);
		}
		return (int)vs.size() == 3;
	};

	vector<int> ones;
	for (int i = 0; i < m; ++i) {
		if (color[i] == 1) {
			ones.push_back(i);
		}
	}
	if (is_triangle(ones)) {
		int eid = ones[0];
		auto [u, v] = edges[eid];
		if (level[u] > level[v]) {
			swap(u, v);
		}
		color[eid] = 0;
		color[par_id[v]] = 1;
	}
	string s(m, '0');
	for (int i = 0; i < m; ++i) {
		s[i] += color[i];
	}
	cout << s << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}