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

	int T; cin >> T;
	while (T--) {
		int N, A, B, DA, DB; cin >> N >> A >> B >> DA >> DB; A--, B--;
		vector<vector<int>> adj(N);
		for (int e = 0; e < N-1; e++) {
			int u, v; cin >> u >> v; u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		auto alice_wins = [&]() -> bool {
			// check if they win immediately
			int dist_AB = std::y_combinator([&](auto self, int cur, int prv) -> int {
				if (cur == B) return 0;
				for (int nxt : adj[cur]) {
					if (nxt == prv) continue;
					int ch = self(nxt, cur);
					if (ch == -1) continue;
					return ch+1;
				}
				return -1;
			})(A, -1);

			if (dist_AB <= DA) return true;

			auto get_furthest = std::y_combinator([&](auto self, int cur, int prv) -> pair<int, int> {
				pair<int, int> res(0, cur);
				for (int nxt : adj[cur]) {
					if (nxt == prv) continue;
					pair<int, int> ch = self(nxt, cur);
					ch.first++;
					res = max(res, ch);
				}
				return res;
			});

			auto d1 = get_furthest(B, -1);
			auto diam = get_furthest(d1.second, -1).first;
			DB = min(DB, diam);
			if (2 * DA >= DB) return true;
			return false;
		};

		bool ans = alice_wins();
		cout << (ans ? "Alice" : "Bob") << '\n';
	}

	return 0;
}