#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N, M, K;
vector<int> adj[MAXN];
int dist[MAXN][2];

int A[MAXN];
pair<int, int> val[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> A[i]; A[i]--;
	}
	for (int e = 0; e < M; e++) {
		int x, y; cin >> x >> y; x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < N; i++) dist[i][z] = -1;

		int st = z ? N-1 : 0;
		vector<int> q; q.reserve(N);

		dist[st][z] = 0; q.push_back(st);

		for (int t = 0; t < int(q.size()); t++) {
			int cur = q[t];
			for (int nxt : adj[cur]) {
				if (dist[nxt][z] != -1) continue;
				dist[nxt][z] = dist[cur][z]+1;
				q.push_back(nxt);
			}
		}
	}

	for (int i = 0; i < K; i++) {
		val[i] = pair<int, int>(dist[A[i]][0] - dist[A[i]][1], dist[A[i]][1]);
	}
	sort(val, val + K);
	for (int i = 0; i < K; i++) {
		val[i].first += val[i].second;
	}

	// want to maximize val[i].first + val[j].second + 1

	int ans = 0;
	int bestFirst = -1;
	for (int i = 0; i < K; i++) {
		if (i) {
			ans = max(ans, min(dist[N-1][0], bestFirst + val[i].second + 1));
		}
		bestFirst = max(bestFirst, val[i].first);
	}
	cout << ans << '\n';

	return 0;
}