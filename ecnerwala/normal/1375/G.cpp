#include<bits/stdc++.h>

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
	vector<int> dist(N, -1);
	vector<int> q; q.reserve(N);
	dist[0] = 0;
	q.push_back(0);
	for (int z = 0; z < N; z++) {
		int cur = q[z];
		for (int nxt : adj[cur]) {
			if (nxt == par[cur]) continue;
			dist[nxt] = dist[cur]+1;
			par[nxt] = cur;
			q.push_back(nxt);
		}
	}
	array<int, 2> cnt{0,0};
	for (int i = 0; i < N; i++) {
		cnt[dist[i]&1]++;
	}
	cout << min(cnt[0], cnt[1]) - 1 << '\n';

	return 0;
}