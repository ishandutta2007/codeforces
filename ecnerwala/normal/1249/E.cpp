#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N;

vector<pair<int, int>> adj[MAXN*2];

int dist[MAXN*2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	int C; cin >> C;
	for (int i = 0; i < N; i++) {
		adj[i].emplace_back(i+N, C);
		adj[i+N].emplace_back(i, 0);
	}

	for (int i = 0; i < N-1; i++) {
		int a; cin >> a;
		adj[i].emplace_back(i+1, a);
		adj[i+1].emplace_back(i, a);
	}
	for (int i = 0; i < N-1; i++) {
		int b; cin >> b;
		adj[i+N].emplace_back(i+N+1, b);
		adj[i+N+1].emplace_back(i+N, b);
	}

	memset(dist, -1, sizeof(dist));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[0] = 0;
	pq.emplace(dist[0], 0);

	while (!pq.empty()) {
		int d = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		assert(d >= dist[cur]);
		if (d != dist[cur]) continue;

		for (auto e : adj[cur]) {
			int nxt = e.first;
			int nd = e.second + d;
			if (dist[nxt] == -1 || nd < dist[nxt]) {
				dist[nxt] = nd;
				pq.emplace(dist[nxt], nxt);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << dist[i] << " \n"[i+1==N];
	}

	return 0;
}