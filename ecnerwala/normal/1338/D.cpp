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
	int N; cin >> N;
	vector<vector<int>> adj(N);

	for (int e = 0; e < N-1; e++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	assert(N >= 3);
	int ROOT = 0;
	while (adj[ROOT].size() == 1) ROOT++;
	assert(adj[ROOT].size() >= 2);

	int ans = 0;

	y_combinator([&](auto self, int cur, int prv) -> pair<int, int> {
		if (adj[cur].size() == 1) {
			assert(adj[cur].front() == prv);
			return {0, 1};
		}
		int dontTakeVal = 0;
		int dontTakeSelf = int(adj[cur].size())-2;
		int takeVal = 0;
		int takeSelf = 1;

		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			auto dp = self(nxt, cur);
			dp.second = max(dp.second, dp.first);

			ans = max(ans, dontTakeVal + dontTakeSelf + dp.second);
			dontTakeVal = max(dontTakeVal, dp.second);

			ans = max(ans, takeVal + takeSelf + dp.first);
			takeVal = max(takeVal, dp.first);
		}
		return {dontTakeVal + dontTakeSelf, takeVal + takeSelf};
	})(ROOT, -1);
	cout << ans << '\n';

	return 0;
}