#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

const int MAXN = 75;
int N, M;
ll A, B;

int compA[MAXN];
vector<int> adjA[MAXN];
vector<int> adjB[MAXN];

const int MAXBIG = 19;
ll dist[1 << MAXBIG][MAXN];

int dfsA(int cur, int root) {
	if (compA[cur] != -1) {
		assert(compA[cur] == root);
		return 0;
	}
	compA[cur] = root;
	int res = 1;
	for (int nxt : adjA[cur]) {
		res += dfsA(nxt, root);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> A >> B;
	for (int i = 0; i < M; i++) {
		int u, v, c; cin >> u >> v >> c;
		u--, v--;
		assert(c == A || c == B);
		if (c == A) {
			adjA[u].push_back(v);
			adjA[v].push_back(u);
		} else if (c == B) {
			adjB[u].push_back(v);
			adjB[v].push_back(u);
		} else assert(false);
	}

	for (int i = 0; i < N; i++) {
		compA[i] = -1;
	}
	int numBig = 0;
	for (int i = 0; i < N; i++) {
		if (compA[i] == -1) {
			int sz = dfsA(i, numBig);
			assert(compA[i] == numBig);

			if (sz <= 3) {
				for (int j = 0; j < N; j++) {
					if (compA[j] == numBig) {
						compA[j] = -2-i; // it's a small component
					}
				}
			} else {
				numBig++;
			}
		}
	}

	assert(numBig <= 19);

	for (int i = 0; i < N; i++) {
		assert(compA[i] != -1);
	}

	for (int m = 0; m < (1 << numBig); m++) {
		for (int i = 0; i < N; i++) {
			dist[m][i] = INF;
		}
	}
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
	auto relax = [&](int m, int i, ll v) {
		if (v < dist[m][i]) {
			dist[m][i] = v;
			pq.emplace(dist[m][i], pair<int, int>(m, i));
		}
	};
	relax(compA[0] >= 0 ? (1 << compA[0]) : 0, 0, 0);

	while (!pq.empty()) {
		ll d = pq.top().first;
		int m = pq.top().second.first;
		int cur = pq.top().second.second;
		pq.pop();

		assert(d >= dist[m][cur]);
		if (d != dist[m][cur]) continue;

		for (int nxt : adjA[cur]) {
			assert(compA[nxt] == compA[cur]);
			relax(m, nxt, d + A);
		}

		for (int nxt : adjB[cur]) {
			if (compA[nxt] == compA[cur]) continue;
			if (m & (compA[nxt] >= 0 ? (1 << compA[nxt]) : 0)) {
				continue;
			}
			relax(m | (compA[nxt] >= 0 ? (1 << compA[nxt]) : 0), nxt, d + B);
		}
	}

	for (int i = 0; i < N; i++) {
		ll res = INF;
		for (int m = 0; m < (1 << numBig); m++) {
			res = min(res, dist[m][i]);
		}
		cout << res << " \n"[i+1==N];
	}
	return 0;
}