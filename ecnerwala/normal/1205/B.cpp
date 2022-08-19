#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
ll A[MAXN];

const int L = 60;
const int MAXL = 80;
vector<int> pts[MAXL];

vector<int> adj[MAXN];

int dist[MAXN];
int prv[MAXN];

int go() {
	sort(A, A + N);
	reverse(A, A + N);
	while (N > 0 && A[N-1] == 0) --N;
	if (N == 0) return -1;

	for (int i = 0; i < N; i++) {
		assert(A[i]);
		for (int l = 0; l < L; l++) {
			if (A[i] & (1ll << l)) {
				pts[l].push_back(i);
				if (pts[l].size() >= 3) {
					return 3;
				}
			}
		}
	}

	assert(N <= 3 * L);

	set<pair<int, int>> edges;
	for (int l = 0; l < L; l++) {
		if (pts[l].size() == 2) {
			assert(pts[l][0] < pts[l][1]);
			edges.emplace(pts[l][0], pts[l][1]);
		}
	}

	for (auto e : edges) {
		cerr << e.first << ' ' << e.second << '\n';
		adj[e.first].push_back(e.second);
		adj[e.second].push_back(e.first);
	}

	int ans = N+1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dist[j] = N+1, prv[j] = -1;
		queue<int> q;
		q.push(i);
		prv[i] = i;
		dist[i] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int nxt : adj[cur]) {
				if (nxt == prv[cur]) continue;
				if (prv[nxt] == -1) {
					prv[nxt] = cur;
					dist[nxt] = dist[cur] + 1;
					q.push(nxt);
				} else {
					ans = min(ans, dist[nxt] + dist[cur] + 1);
				}
			}
		}
	}

	if (ans > N) return -1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << go() << '\n';

	return 0;
}