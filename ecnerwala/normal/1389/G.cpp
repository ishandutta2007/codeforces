#include<bits/stdc++.h>

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

	int N, M, K; cin >> N >> M >> K;
	vector<bool> is_special(N, false);
	for (int k = 0; k < K; k++) {
		int v; cin >> v; v--;
		is_special[v] = true;
	}
	vector<int64_t> C(N); for (auto& c : C) cin >> c;
	vector<int64_t> W(M); for (auto& w : W) cin >> w;

	vector<vector<pair<int, int>>> adj(N);
	for (int e = 0; e < M; e++) {
		int x, y; cin >> x >> y; x--, y--;
		adj[x].emplace_back(y, e);
		adj[y].emplace_back(x, e);
	}

	vector<int> depth(N, -1);
	vector<int> lowval(N, -1);

	vector<bool> tree_edge(M, false);

	depth[0] = 0;
	std::y_combinator([&](auto self, int cur, int parE) -> int {
		lowval[cur] = depth[cur];

		int num_special = is_special[cur];

		for (auto [nxt, e] : adj[cur]) {
			if (e == parE) continue;
			if (depth[nxt] == -1) {
				depth[nxt] = depth[cur] + 1;
				auto ch = self(nxt, e);
				tree_edge[e] = true;
				if (lowval[nxt] == depth[nxt] && 0 < ch && ch < K) {
					// it's still costly
				} else {
					W[e] = 0;
				}
				num_special += ch;

				lowval[cur] = min(lowval[cur], lowval[nxt]);
			} else {
				lowval[cur] = min(lowval[cur], depth[nxt]);
			}
		}
		return num_special;
	})(0, -1);

	vector<int64_t> dp_down(N);
	std::y_combinator([&](auto self, int cur, int parE) -> void {
		dp_down[cur] = C[cur];
		for (auto [nxt, e] : adj[cur]) {
			if (!tree_edge[e]) continue;
			if (e == parE) continue;
			self(nxt, e);
			dp_down[cur] += max(int64_t(0), dp_down[nxt] - W[e]);
		}
	})(0, -1);
	vector<int64_t> dp_up(N);
	dp_up[0] = 0;
	vector<int64_t> ans(N);
	std::y_combinator([&](auto self, int cur, int parE) -> void {
		int64_t tot = max(int64_t(0), dp_up[cur]);
		tot += C[cur];
		for (auto [nxt, e] : adj[cur]) {
			if (!tree_edge[e]) continue;
			if (e == parE) continue;
			tot += max(int64_t(0), dp_down[nxt] - W[e]);
		}
		ans[cur] = tot;
		for (auto [nxt, e] : adj[cur]) {
			if (!tree_edge[e]) continue;
			if (e == parE) continue;
			dp_up[nxt] = tot - max(int64_t(0), dp_down[nxt] - W[e]) - W[e];
			self(nxt, e);
		}
	})(0, -1);

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}