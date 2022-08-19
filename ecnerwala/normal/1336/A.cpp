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
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N, K; cin >> N >> K;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> depth(N);
	vector<int> sz(N);
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		depth[cur] = (prv == -1 ? 0 : depth[prv] + 1);
		sz[cur] = 1;
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur);
			sz[cur] += sz[nxt];
		}
	})(0, -1);

	vector<int> val(N);
	for (int i = 0; i < N; i++) {
		val[i] = depth[i] - (sz[i] - 1);
	}
	sort(val.begin(), val.end());

	int64_t ans = 0;
	for (int i = 0; i < K; i++) {
		ans += val.back();
		val.pop_back();
	}
	cout << ans << '\n';

	return 0;
}