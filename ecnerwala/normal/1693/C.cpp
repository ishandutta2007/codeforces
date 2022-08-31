#include <bits/stdc++.h>

template <typename T> using min_pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	std::vector<int> outDeg(N);
	std::vector<std::vector<int>> inEdges(N);
	for (int e = 0; e < M; e++) {
		int u, v; cin >> u >> v; u--, v--;
		outDeg[u]++;
		inEdges[v].push_back(u);
	}

	std::vector<int> dist(N, -1);
	min_pq<std::pair<int, int>> pq;
	pq.push({dist[N-1] = 0, N-1});

	while (!pq.empty()) {
		auto [d, cur] = pq.top(); pq.pop();
		if (d != dist[cur]) continue;
		for (int nxt : inEdges[cur]) {
			outDeg[nxt]--;
			int nd = d + 1 + outDeg[nxt];
			if (dist[nxt] == -1 || nd < dist[nxt]) {
				pq.push({dist[nxt] = nd, nxt});
			}
		}
	}
	cout << dist[0] << '\n';

	return 0;
}