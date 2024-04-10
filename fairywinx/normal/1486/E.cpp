#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

// #define int long long
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1e5 + 228;
const int W = 51;
const int INF = 1e9 + 228;

vector<pair<int, int>> G[N];
int dist[N][2][W];
int used[N][2][W];

struct node {
	int v, t, w;
	node() {}
	node(int a, int b, int c) {v = a, t = b, w = c;}
};

bool operator> (node a, node b) {
	return a.v < b.v;
}

bool operator< (node a, node b) {
	return a.v > b.v;
}

signed main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a - 1].emplace_back(b - 1, c);
		G[b - 1].emplace_back(a - 1, c);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j)
			fill(dist[i][j], dist[i][j] + W, INF);
	}
	priority_queue<pair<int, node>, vector<pair<int, node>>, greater<pair<int, node>>> q;
	q.push({0, {0, 0, 0}});
	dist[0][0][0] = 0;
	vector<int> ans(n, INF);
	while (q.size()) {
		node now = q.top().second;
		q.pop();
		if (used[now.v][now.t][now.w])
			continue;
		if (now.t == 0)
			ans[now.v] = min(ans[now.v], dist[now.v][0][0]);
		used[now.v][now.t][now.w] = 1;
		for (auto i : G[now.v]) {
			if (now.t == 0) {
				if (dist[i.first][1][i.second] > dist[now.v][0][0]) {
					dist[i.first][1][i.second] = dist[now.v][0][0];
					q.push({dist[now.v][0][0], {i.first, 1, i.second}});
				}
			} else if (dist[i.first][0][0] > dist[now.v][1][now.w] + (now.w + i.second) * (now.w + i.second)) {
				dist[i.first][0][0] = dist[now.v][1][now.w] + (now.w + i.second) * (now.w + i.second);
				q.push({dist[i.first][0][0], {i.first, 0, 0}});
			}
		}
	}
	for (int i : ans)
		cout << ((i == INF) ? -1 : i) << ' ';
	cout << '\n';
}