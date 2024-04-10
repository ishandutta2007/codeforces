#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> C(N); for (int& c : C) { cin >> c; c--; if (c == -1) c = 2; }
		vector<vector<int>> adj(N);
		for (int e = 0; e < N-1; e++) {
			int u, v; cin >> u >> v; u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans = N+1;
		for (int z = 0; z < 2; z++) {
			vector<int> deg(N);
			array<vector<int>, 3> queue; queue[0].reserve(N), queue[1].reserve(N), queue[2].reserve(N);
			for (int i = 0; i < N; i++) {
				deg[i] = int(adj[i].size());
				if (deg[i] <= 1) {
					queue[C[i]].push_back(i);
				}
			}

			int t = 0;
			int num_processed = 0;
			for (; num_processed < N; t++) {
				while (true) {
					int d = 2;
					if (queue[d].empty()) d = (t+z)&1;
					if (queue[d].empty()) break;
					int i = queue[d].back(); queue[d].pop_back();
					num_processed++;
					for (int j : adj[i]) {
						if (--deg[j] == 1) {
							queue[C[j]].push_back(j);
						}
					}
				}
			}
			ans = min(ans, t);
		}
		cout << ans << '\n';
	}

	return 0;
}