#include <bits/stdc++.h>

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
			adj[v].push_back(u);
		}
		vector<int> dist(N, -1);
		vector<int> q; q.reserve(N);
		dist[0] = 1;
		q.push_back(0);
		vector<int> ans; ans.reserve(N);
		for (int z = 0; z < int(q.size()); z++) {
			int cur = q[z];
			if (dist[cur]) ans.push_back(cur);
			for (int nxt : adj[cur]) {
				if (dist[nxt] == -1) {
					dist[nxt] = 1;
					q.push_back(nxt);
				}
				dist[nxt] = dist[nxt] && !dist[cur];
			}
		}
		if (int(q.size()) == N) {
			cout << "YES" << '\n';
			cout << ans.size() << '\n';
			for (int v : ans) cout << v+1 << ' ';
			cout << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}