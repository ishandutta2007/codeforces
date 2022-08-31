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
	std::vector<int> H(N);
	for (auto& h : H) cin >> h;

	std::vector<std::vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int root = int(std::max_element(H.begin(), H.end()) - H.begin());
	int64_t ans = 0;
	int root_max_1 = 0, root_max_2 = 0;
	for (int root_ch : adj[root]) {
		int v = std::y_combinator([&](auto self, int cur, int prv) -> int {
			int ch_max = 0;
			for (int nxt : adj[cur]) {
				if (nxt == prv) continue;
				ch_max = std::max(ch_max, self(nxt, cur));
			}
			if (H[cur] > ch_max) {
				ans += H[cur] - ch_max;
				ch_max = H[cur];
			}
			return ch_max;
		})(root_ch, root);
		if (v > root_max_1) {
			root_max_2 = root_max_1;
			root_max_1 = v;
		} else if (v > root_max_2) {
			root_max_2 = v;
		}
	}
	ans += H[root] - root_max_1;
	ans += H[root] - root_max_2;

	cout << ans << '\n';

	return 0;
}