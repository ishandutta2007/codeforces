#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> outEdges(N);
	vector<vector<int>> inEdges(N);
	for (int e = 0; e < M; e++) {
		int u, v; cin >> u >> v; u--, v--;
		outEdges[u].push_back(v);
		inEdges[v].push_back(u);
	}

	int K; cin >> K; K--;
	vector<int> P(K+1);
	for (int& p : P) { cin >> p; p--; }

	const int S = P[0], T = P[K];

	vector<int> dist(N, -1);
	vector<int> q; q.reserve(N);
	dist[T] = 0;
	q.push_back(T);
	for (int z = 0; z < int(q.size()); z++) {
		int cur = q[z];
		for (int nxt : inEdges[cur]) {
			if (dist[nxt] == -1) {
				dist[nxt] = dist[cur]+1;
				q.push_back(nxt);
			}
		}
	}

	int minRebuild = 0;
	int maxRebuild = 0;
	for (int i = 0; i < K; i++) {
		int a = P[i], b = P[i+1];
		assert(dist[a] <= dist[b]+1);
		if (dist[b] > dist[a]-1) {
			minRebuild++;
			maxRebuild++;
		} else {
			bool hasOther = false;
			for (auto cnd : outEdges[a]) {
				if (cnd == b) continue;
				if (dist[cnd] == dist[a] - 1) {
					hasOther = true;
					break;
				}
			}
			if (hasOther) {
				maxRebuild++;
			}
		}
	}
	cout << minRebuild << ' ' << maxRebuild << '\n';

	return 0;
}