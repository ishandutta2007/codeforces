#include<bits/stdc++.h>
using namespace std;

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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto query = [&](int u, int v) -> int {
		cout << '?' << ' ' << u+1 << ' ' << v+1 << '\n' << flush;
		int r; cin >> r; r--;
		return r;
	};

	int ans = std::y_combinator([&](auto self, int cur, int prv) -> int {
		while (adj[cur].size() >= 2) {
			int u = adj[cur].back(); adj[cur].pop_back();
			adj[u].erase(find(adj[u].begin(), adj[u].end(), cur));
			int v = adj[cur].back(); adj[cur].pop_back();
			adj[v].erase(find(adj[v].begin(), adj[v].end(), cur));

			int r = query(u, v);
			if (r == cur) continue;
			else if (r == u) return self(u, cur);
			else if (r == v) return self(v, cur);
			else assert(false);
		}
		if (adj[cur].empty()) return cur;
		assert(adj[cur].size() == 1);
		int nxt = adj[cur][0];
		if (nxt != prv) {
			return self(nxt, cur);
		} else {
			return query(cur, nxt);
		}
	})(0, -1);

	cout << '!' << ' ' << ans+1 << '\n';

	return 0;
}