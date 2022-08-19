#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int64_t N; int M; cin >> N >> M;

	using pt_t = array<int64_t, 2>;
	pt_t S, T; cin >> S[0] >> S[1] >> T[0] >> T[1];
	vector<pt_t> locs(M+1);
	for (int i = 0; i < M; i++) {
		cin >> locs[i][0] >> locs[i][1];
	}
	locs[M] = S;

	vector<vector<pair<int64_t, int>>> adj(M+2);
	for (int i = 0; i <= M; i++) {
		adj[i].push_back({abs(locs[i][0] - T[0]) + abs(locs[i][1] - T[1]), M+1});
	}
	for (int z = 0; z < 2; z++) {
		vector<pair<int64_t, int>> coords(M+1);
		for (int i = 0; i <= M; i++) {
			coords[i] = {locs[i][z], i};
		}
		sort(coords.begin(), coords.end());
		for (int i = 1; i <= M; i++) {
			int64_t d = coords[i].first - coords[i-1].first;
			int x = coords[i-1].second;
			int y = coords[i].second;
			adj[x].push_back({d, y});
			adj[y].push_back({d, x});
		}
	}

	vector<int64_t> dist(M+2, -1);
	priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
	pq.push({dist[M] = 0, M});

	while (!pq.empty()) {
		int64_t d = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (d != dist[cur]) continue;
		for (auto [nd, nxt] : adj[cur]) {
			nd += d;
			if (dist[nxt] == -1 || nd < dist[nxt]) {
				pq.push({dist[nxt] = nd, nxt});
			}
		}
	}
	cout << dist[M+1] << '\n';

	return 0;
}