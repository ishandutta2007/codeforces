#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e5;
const int MAXM = 4e5;
int N, M;
int K;
vector<int> adj[MAXN];
int A[MAXM][2];
ll W[MAXM];

ll dist[MAXN];
int prv[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int e = 1; e <= M; e++) {
		cin >> A[e][0] >> A[e][1] >> W[e];
		adj[A[e][0]].push_back(e);
		adj[A[e][1]].push_back(e);
	}
	K = min(K, N-1);
	cout << K << '\n';
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[1] = 0;
	prv[1] = -1;
	pq.emplace(dist[1], 1);
	for (int t = 0; t <= K; t++) {
		assert(!pq.empty());
		int cur = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		assert(prv[cur]);
		assert(d >= dist[cur]);
		if (d > dist[cur]) {
			t--;
			continue;
		}
		assert(d == dist[cur]);
		if (prv[cur] == -1) {
			assert(cur == 1);
			assert(t == 0);
		} else {
			cout << prv[cur];
			if (t < K) cout << ' ';
		}
		for (int e : adj[cur]) {
			assert(cur == A[e][0] || cur == A[e][1]);
			int nxt = A[e][0] ^ A[e][1] ^ cur;
			ll nd = d + W[e];
			if (prv[nxt] == 0 || nd < dist[nxt]) {
				dist[nxt] = nd;
				prv[nxt] = e;
				pq.emplace(dist[nxt], nxt);
			}
		}
	}
	cout << '\n';

	return 0;
}