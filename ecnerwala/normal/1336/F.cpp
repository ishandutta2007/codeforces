#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;

// Supports
//  auto iterator = order_statistic_set().find_by_order(int); // (0-indexed)
//  int num_strictly_smaller = order_statistic_set().order_of_key(key);

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
	int N, M, K; cin >> N >> M >> K;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<pair<int, int>> paths(M);
	for (int j = 0; j < M; j++) {
		int s, t; cin >> s >> t; s--, t--;
		paths[j] = {s,t};
	}

	int64_t ans = 0;

	vector<int> sz(N, 1);
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur);
			sz[cur] += sz[nxt];
		}
	})(0, -1);

	vector<int> st(N);
	vector<int> en(N);
	vector<int> depth(N);
	vector<int> par(N);
	vector<int> heavyRoot(N);

	vector<int> preorder; preorder.reserve(N);

	preorder.clear();
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		st[cur] = int(preorder.size());
		preorder.push_back(cur);

		par[cur] = prv;
		depth[cur] = prv != -1 ? depth[prv] + 1 : 0;
		heavyRoot[cur] = (prv != -1 && st[cur] == st[prv] + 1) ? heavyRoot[prv] : cur;

		sort(adj[cur].begin(), adj[cur].end(), [&](int a, int b) -> bool { return sz[a] > sz[b]; });

		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur);
		}

		en[cur] = int(preorder.size());
	})(0, -1);

	auto getAnc = [&](int cur, int k) -> int {
		assert(k >= 0);
		int d = depth[cur] - k;
		while (d < depth[heavyRoot[cur]]) {
			cur = par[heavyRoot[cur]];
		}
		return preorder[st[cur] - (depth[cur] - d)];
	};

	auto lca = [&](int a, int b) -> int {
		while (heavyRoot[a] != heavyRoot[b]) {
			if (st[heavyRoot[a]] > st[heavyRoot[b]]) {
				swap(a, b);
			}
			assert(st[heavyRoot[a]] < st[heavyRoot[b]]);
			b = par[heavyRoot[b]];
		}
		return st[a] < st[b] ? a : b;
	};

	vector<vector<pair<pair<int, int>, int>>> pathEnd(N);
	int evtIdx = 0;
	for (auto it : paths) {
		int s, t; tie(s,t) = it;
		if (st[s] > st[t]) swap(s, t);
		int c = lca(s, t);
		assert(t != c);
		pathEnd[t].push_back({{st[s], c}, evtIdx++});
		if (s != c) {
			pathEnd[s].push_back({{st[getAnc(t, depth[t] - depth[c] - 1)], c}, evtIdx++});
		}
	}

	std::y_combinator([&](auto self, int cur, int prv) -> order_statistic_set<pair<pair<int, int>, int>> {
		order_statistic_set<pair<pair<int, int>, int>> res;

		// precompute this cause we'll use it a bunch
		int curPar = depth[cur] >= K ? getAnc(cur, K-1) : -1;

		auto updateFromVal = [&](pair<int, int> it) -> bool {
			auto getSubtree = [&](int node) -> int {
				return int(res.order_of_key({{en[node], -1}, -1})) - int(res.order_of_key({{st[node], -1}, -1}));
			};
			int stDest = it.first, c = it.second;
			assert(!(st[cur] <= stDest && stDest < en[cur]));
			int dest = preorder[stDest];

			int totLen = (depth[cur] - depth[c]) + (depth[dest] - depth[c]);
			if (totLen >= K) {
				if (depth[cur] - depth[c] >= K) {
					ans += int(res.size()) - getSubtree(curPar);
				} else {
					ans += getSubtree(getAnc(dest, totLen - K));
				}

				if (stDest >= en[cur]) {
					assert(par[dest] == c);
					// exclude this subtree to avoid double counting
					ans -= getSubtree(dest);
				}
				return true;
			}
			return false;
		};

		for (auto it : pathEnd[cur]) {
			if (updateFromVal(it.first)) {
				res.insert(it);
			}
		}
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			auto o = self(nxt, cur);

			for (auto lo = o.lower_bound({{st[cur], -1}, -1}); lo != o.end() && lo->first.first < en[cur]; ) {
				lo = o.erase(lo);
			}

			if (o.size() > res.size()) res.swap(o);
			for (auto it = o.begin(); it != o.end(); ) {
				if (updateFromVal(it->first)) {
					++it;
				} else {
					it = o.erase(it);
				}
			}
			for (auto i : o) {
				res.insert(i);
			}
		}

		return res;
	})(0, -1);

	cout << ans << '\n';

	return 0;
}