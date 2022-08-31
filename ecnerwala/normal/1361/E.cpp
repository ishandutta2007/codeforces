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

std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> solve(int N, std::vector<std::vector<int>> adj) {
	using namespace std;
	vector<bool> in_stack(N);
	vector<int> depth(N);
	vector<int> stk; stk.reserve(N);
	vector<int> good_par(N);
	for (int round = 0; round < 100; round++) {
		fill(depth.begin(), depth.end(), -1);
		fill(in_stack.begin(), in_stack.end(), false);
		stk.clear();
		fill(good_par.begin(), good_par.end(), -1);

		int ROOT = int(mt() % N);
		depth[ROOT] = 0;

		const pair<int, int> BAD(-1, -1);
		auto root_res = std::y_combinator([&](auto self, int cur) -> pair<int, int> {
			in_stack[cur] = true;
			stk.push_back(cur);
			pair<int, int> res(depth[cur], depth[cur]);
			for (int nxt : adj[cur]) {
				if (depth[nxt] == -1) {
					depth[nxt] = depth[cur]+1;
					auto ch = self(nxt);
					if (ch == BAD) return BAD;
					// take the smallest 2
					if (ch.first < res.first) {
						swap(res, ch);
					}
					res.second = min(res.second, ch.first);
				} else if (!in_stack[nxt]){
					return BAD;
				} else {
					if (depth[nxt] < res.first) {
						res.second = res.first;
						res.first = depth[nxt];
					} else if (depth[nxt] < res.second) {
						res.second = depth[nxt];
					}
				}
			}

			assert(res.first <= depth[cur]);
			assert(res.first < depth[cur] || depth[cur] == 0);
			if (res.second >= depth[cur]) {
				good_par[cur] = stk[res.first];
			}

			in_stack[cur] = false;
			stk.pop_back();

			return res;
		})(ROOT);
		if (root_res == BAD) {
			continue;
		}
		vector<int> ans; ans.reserve(N);
		vector<bool> is_good(N, false);
		is_good[ROOT] = true;
		std::y_combinator([&](auto self, int cur) -> void {
			in_stack[cur] = true;
			if (good_par[cur] != -1 && is_good[good_par[cur]]) {
				is_good[cur] = true;
				ans.push_back(cur);
			}
			for (int nxt : adj[cur]) {
				if (in_stack[nxt]) continue;
				self(nxt);
			}
			in_stack[cur] = false;
		})(ROOT);
		return ans;
	}
	return {};
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<vector<int>> adj(N);
		for (int e = 0; e < M; e++) {
			int u, v; cin >> u >> v; u--, v--;
			adj[u].push_back(v);
		}
		vector<int> ans = solve(N, std::move(adj));
		if (int(ans.size()) * 5 < N) {
			cout << -1 << '\n';
		} else {
			sort(ans.begin(), ans.end());
			for (int i = 0; i < int(ans.size()); i++) {
				cout << ans[i]+1 << " \n"[i+1==int(ans.size())];
			}
		}
	}

	return 0;
}