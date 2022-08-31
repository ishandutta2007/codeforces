#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		bool res = []() -> bool {
			int N, M; cin >> N >> M;
			vector<int> P(N); for (auto& v : P) cin >> v;
			vector<int> H(N); for (auto& v : H) cin >> v;
			vector<vector<int>> adj(N);
			for (int e = 0; e < N-1; e++) {
				int u, v; cin >> u >> v; u--, v--;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			vector<int> par(N);
			vector<int> q; q.reserve(N);
			par[0] = -1; q.push_back(0);
			for (int z = 0; z < N; z++) {
				int cur = q[z];
				int64_t v = P[cur] + H[cur];
				for (int nxt : adj[cur]) {
					if (nxt == par[cur]) continue;
					par[nxt] = cur;
					q.push_back(nxt);
					v -= H[nxt];
				}
				if (v & 1) return false;
				if (v < 0) return false;
			}
			for (int z = N-1; z >= 0; z--) {
				int cur = q[z];
				if (H[cur] > P[cur]) return false;
				if (cur) P[par[cur]] += P[cur];
			}
			return true;
		}();
		cout << (res ? "YES" : "NO") << '\n';
	}

	return 0;
}