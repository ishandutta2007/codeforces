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
	vector<int64_t> A(N);
	for (auto& a : A) cin >> a;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	const int64_t INF = 1e18;
	// it can be up to first, any multiple of second
	int64_t ans = std::y_combinator([&](auto self, int cur, int prv) -> pair<int64_t, int64_t> {
		int num_ch = 0;
		pair<int64_t, int64_t> res{INF,1};
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			num_ch++;
			auto ch = self(nxt, cur);
			if (ch.first < res.first) swap(ch, res);
			assert(res.first <= ch.first);
			int64_t g = gcd(res.second, ch.second);
			res.first = (res.first / res.second) / (ch.second / g) * (ch.second / g) * res.second;
			if (res.first == 0) {
				res.second = 1;
			} else {
				res.second *= ch.second / g;
			}
		}

		if (num_ch == 0) {
			return {A[cur], 1};
		} else {
			assert(A[cur] == 0);
		}

		res.first *= num_ch;
		res.second *= num_ch;
		return res;
	})(0, -1).first;

	cout << std::accumulate(A.begin(), A.end(), int64_t(0)) - ans << '\n';

	return 0;
}