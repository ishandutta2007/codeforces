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
	int N, M; cin >> N >> M;

	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> par(N);
	vector<int> st(N);
	vector<int> en(N);
	int idx = 0;
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		par[cur] = prv;
		st[cur] = idx++;
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur);
		}
		en[cur] = idx;
	})(0, 0);

	while (M--) {
		int K; cin >> K;
		vector<int> verts(K);
		int lo = 0;
		int hi = N;
		for (int i = 0; i < K; i++) {
			cin >> verts[i]; verts[i]--;
			verts[i] = par[verts[i]];
			lo = max(lo, st[verts[i]]);
			hi = min(hi, en[verts[i]]);
		}
		cout << ((lo < hi) ? "YES" : "NO") << '\n';
	}

	return 0;
}