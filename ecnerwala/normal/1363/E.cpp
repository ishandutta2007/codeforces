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
	int N; cin >> N;
	vector<int64_t> A(N);
	vector<array<int, 2>> cnt(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		bool b, c; cin >> b >> c;
		cnt[i][0] = (b < c);
		cnt[i][1] = (b > c);
	}

	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int64_t ans = 0;
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			A[nxt] = min(A[nxt], A[cur]);
			self(nxt, cur);
			cnt[cur][0] += cnt[nxt][0];
			cnt[cur][1] += cnt[nxt][1];
		}
		int v = min(cnt[cur][0], cnt[cur][1]);
		ans += A[cur] * 2 * v;

		cnt[cur][0] -= v;
		cnt[cur][1] -= v;
	})(0, -1);
	if (cnt[0][0] || cnt[0][1]) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}