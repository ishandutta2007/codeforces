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

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

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

	vector<int> dist(N, -1);
	{
		int K; cin >> K;
		vector<int> q; q.reserve(N);
		while (K--) {
			int v; cin >> v; v--;
			dist[v] = 0, q.push_back(v);
		}
		for (int z = 0; z < int(q.size()); z++) {
			int cur = q[z];
			for (int nxt : adj[cur]) {
				if (dist[nxt] == -1) dist[nxt] = dist[cur]+1, q.push_back(nxt);
			}
		}
		assert(int(q.size()) == N);
	}

	vector<int> ans(N, 0);

	{
		vector<bool> alive(N, true);
		vector<int> sz(N);
		vector<int> lims(N);
		std::y_combinator([&](auto run_centroid, int root) -> void {
			std::y_combinator([&](auto self, int cur, int prv) -> int {
				int s = 1;
				for (int nxt : adj[cur]) {
					if (!alive[nxt]) continue;
					if (nxt == prv) continue;
					s += self(nxt, cur);
				}
				return sz[cur] = s;
			})(root, -1);

			int tot_sz = sz[root];
			root = std::y_combinator([&](auto self, int cur, int prv) -> int {
				for (int nxt : adj[cur]) {
					if (!alive[nxt]) continue;
					if (nxt == prv) continue;
					if (sz[nxt] * 2 > tot_sz) return self(nxt, cur);
				}
				return cur;
			})(root, -1);

			fill(lims.begin(), lims.begin()+tot_sz, 0);
			std::y_combinator([&](auto self, int cur, int prv, int depth) -> void {
				if (dist[cur]-1 >= depth) setmax(lims[min(tot_sz-1, dist[cur]-1-depth)], dist[cur]);
				for (int nxt : adj[cur]) {
					if (!alive[nxt]) continue;
					if (nxt == prv) continue;
					self(nxt, cur, depth+1);
				}
			})(root, -1, 0);

			for (int i = tot_sz-1; i > 0; i--) {
				setmax(lims[i-1], lims[i]);
			}
			std::y_combinator([&](auto self, int cur, int prv, int depth) -> void {
				setmax(ans[cur], lims[depth]);
				for (int nxt : adj[cur]) {
					if (!alive[nxt]) continue;
					if (nxt == prv) continue;
					self(nxt, cur, depth+1);
				}
			})(root, -1, 0);

			alive[root] = false;
			for (int nxt : adj[root]) {
				if (!alive[nxt]) continue;
				run_centroid(nxt);
			}
		})(0);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " \n"[i+1==N];
	}

	return 0;
}