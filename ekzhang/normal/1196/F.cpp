#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N, M, K;
vector<pair<int, int> > adj[MAXN];
map<int, LL> dist[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		--x, --y;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	set<pair<LL, pair<int, int> > > s;
	for (int i = 0; i < N; i++) {
		dist[i][i] = 0;
		s.insert({0, {i, i}});
		sort(adj[i].begin(), adj[i].end(), [](pair<int, int> a, pair<int, int> b) {
			return a.second < b.second;
		});
	}

	int count = -N;
	while (s.size()) {
		auto it = s.begin();
		auto p = *it;
		s.erase(it);
		LL w = p.first;
		int u = p.second.first;
		int v = p.second.second;
		if (++count == 2 * K) {
			cout << w << endl;
			return 0;
		}

		for (pair<int, int> e : adj[v]) {
			int n = e.first;
			if (s.size() + count == 2 * K && w + e.second >= (--s.end())->first)
				break;
			if (!dist[u].count(n) || dist[u][n] > w + e.second) {
				s.erase({dist[u][n], {u, n}});
				dist[u][n] = w + e.second;
				s.insert({dist[u][n], {u, n}});
				if (s.size() + count > 2 * K)
					s.erase(--s.end());
			}
		}
	}

	cout.flush();
	return 0;
}