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
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> par(N, -1);
	vector<int> dp_down(N);
	vector<int> dp_up(N);

	std::y_combinator([&](auto self, int cur, int prv) -> void {
		par[cur] = prv;
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur);
		}
		if (prv == -1) return;
		vector<pair<int, int>> vals; vals.reserve(adj[cur].size());
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			vals.push_back({dp_down[nxt], nxt});
		}
		sort(vals.begin(), vals.end(), std::greater<>());
		vals.push_back({0, cur});
		for (int z = 0; z < int(vals.size()); z++) {
			dp_down[cur] = max(dp_down[cur], vals[z].first + z);
		}
	})(0, -1);

	int ans = 0;
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		{
			vector<pair<int, int>> vals; vals.reserve(adj[cur].size() + 1);
			for (int nxt : adj[cur]) {
				if (nxt == prv) {
					vals.push_back({dp_up[cur], nxt});
				} else {
					vals.push_back({dp_down[nxt], nxt});
				}
			}
			sort(vals.begin(), vals.end(), std::greater<>());
			vals.push_back({0, cur});
			if (vals.size() == 1) {
				assert(N == 1);
				ans = 0;
			}
			for (int z = 1; z < int(vals.size()); z++) {
				ans = max(ans, max(vals[0].first, 1) + vals[z].first + z-1);
			}
			vector<int> pref(vals.size());
			pref[0] = 0;
			for (int z = 0; z+1 < int(vals.size()); z++) {
				pref[z+1] = max(pref[z], vals[z].first + z);
			}
			vector<int> suff(vals.size());
			suff[int(vals.size())-1] = 0;
			for (int z = int(vals.size())-1; z > 0; z--) {
				suff[z-1] = max(suff[z], vals[z].first + (z-1));
			}
			for (int z = 0; z < int(vals.size()); z++) {
				int nxt = vals[z].second;
				if (nxt == prv) continue;
				dp_up[nxt] = max(pref[z], suff[z]);
			}
		}
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur);
		}
	})(0, -1);

	cout << ans << '\n' << flush;

	auto query = [&](int cur) -> int {
		cout << '?' << ' ' << cur+1 << '\n' << flush;
		int resp; cin >> resp; resp--;
		return resp;
	};

	int F; cin >> F; F--;
	auto search = std::y_combinator([&](auto self, int cur, int prv) -> pair<bool, int> {
		vector<pair<int, int>> vals; vals.reserve(adj[cur].size());
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			vals.push_back({nxt == par[cur] ? dp_up[cur] : dp_down[nxt], nxt});
		}
		sort(vals.begin(), vals.end(), std::greater<>());
		bool has_query = false;
		for (auto [_, nxt] : vals) {
			auto [found, resp] = self(nxt, cur);
			if (found) return {found, resp};
			if (resp != cur) {
				return {false, resp};
			} else {
				has_query = true;
			}
		}
		if (!has_query) {
			int resp = query(cur);
			return {resp == cur, resp};
		} else {
			return {true, cur};
		}
	});

	vector<pair<int, int>> vals; vals.reserve(adj[F].size());
	for (int nxt : adj[F]) {
		vals.push_back({nxt == par[F] ? dp_up[F] : dp_down[nxt], nxt});
	}
	sort(vals.begin(), vals.end(), std::greater<>());
	vector<int> path; path.reserve(2);
	for (auto [_, nxt] : vals) {
		auto [found, resp] = search(nxt, F);
		if (found) {
			path.push_back(resp);
			if (path.size() == 2) break;
		}
	}
	while (path.size() < 2) path.push_back(F);
	cout << '!' << ' ' << path[0]+1 << ' ' << path[1]+1 << '\n' << flush;

	return 0;
}