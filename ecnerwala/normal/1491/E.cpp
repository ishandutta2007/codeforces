#include <bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	/*
	int N = 196418;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u = e, v = e+1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	*/

	vector<int> fib; fib.push_back(1);
	fib.push_back(1);
	while (fib.back() < N) fib.push_back(fib.end()[-2] + fib.end()[-1]);

	if (fib.back() != N) {
		cout << "NO" << '\n';
		exit(0);
	}

	for (int i = 0; i < N; i++) {
		if (adj[i].size() > fib.size()) {
			cout << "NO" << '\n';
			exit(0);
		}
	}

	bool ans = std::y_combinator([&](auto self, int rt, int idx) -> bool {
		if (fib[idx] <= 3) return true; // all small trees are good
		std::vector<pair<int, int>> cnds; cnds.reserve(2); // big, small
		int max_deg = 0;
		std::y_combinator([&](auto dfs, int cur, int prv) -> int {
			int sz = 1;
			max_deg = max(max_deg, int(adj[cur].size()));
			for (int nxt : adj[cur]) {
				if (nxt == prv) continue;
				sz += dfs(nxt, cur);
			}
			if (sz == fib[idx-1]) {
				cnds.push_back({cur, prv});
			} else if (sz == fib[idx-2]) {
				cnds.push_back({prv, cur});
			}
			return sz;
		})(rt, -1);
		if (max_deg > idx-1) return false;
		for (auto [big, small] : cnds) {
			bool is_good = true;

			if (is_good) {
				auto it = find(adj[small].begin(), adj[small].end(), big);
				adj[small].erase(it);
				is_good = self(small, idx-2);
				adj[small].push_back(big);
			}
			if (is_good) {
				auto it = find(adj[big].begin(), adj[big].end(), small);
				adj[big].erase(it);
				is_good = self(big, idx-1);
				adj[big].push_back(small);
			}

			if (is_good) return true;
		}
		return false;
	})(0, int(fib.size())-1);

	cout << (ans ? "YES" : "NO") << '\n';

	return 0;
}