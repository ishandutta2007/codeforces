#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5+1;
vector<int> adj[N];
int pred[N];
int dist[N];
int root[N];
int weight[N];

void init() {
	memset(pred, 0, sizeof pred);
	memset(dist, INF, sizeof dist);
	memset(root, -1, sizeof root);
	memset(weight, -1, sizeof weight);
}

int find(int i) {
	if (root[i] == -1) return i;
	return root[i] = find(root[i]);
}
void link(int i, int j) {
	if (find(i) != find(j)) {
		weight[find(j)] += weight[find(i)];
		root[find(i)] = find(j);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
	init();

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> bfs;
	bfs.push(1);
	dist[1] = 0;
	while (!bfs.empty()) {
		int cur = bfs.front();
		bfs.pop();

		for (int x : adj[cur]) {
			if (dist[x] == INF) {
				dist[x] = dist[cur]+1;
				pred[x] = cur;
				bfs.push(x);
			}
		}
	}

	if (dist[n] <= 4) {
		cout << dist[n] << nl;
		vector<int> ans;
		for (int i = n; i != 0; i = pred[i]) {
			ans.push_back(i);
		}
		reverse(ans.begin(), ans.end());
		for (int it : ans) cout << it << " ";
		cout << nl;
		return 0;
	}

	else {
		for (int i = 1; i <= n; i++) {
			if (dist[i] == 2) {
				cout << 4 << nl;
				cout << 1 << " " << pred[i] << " " << i << " " << 1 << " " << n << nl;
				return 0;
			}
		}

		if (dist[n] <= 5) {
			cout << dist[n] << nl;
			vector<int> ans;
			for (int i = n; i != 0; i = pred[i]) {
				ans.push_back(i);
			}
			reverse(ans.begin(), ans.end());
			for (int it : ans) cout << it << " ";
			cout << nl;
			return 0;
		}

		for (int u : adj[1]) {
			for (int v : adj[u]) {
				if (v != 1) link(u, v);
			}
		}
		for (int u : adj[1]) {
			if (abs(weight[find(u)]) != adj[u].size()) {
				init();
				dist[1] = -1;

				queue<int> bfs;
				bfs.push(u);
				dist[u] = 0;
				while (!bfs.empty()) {
					int cur = bfs.front();
					bfs.pop();

					for (int x : adj[cur]) {
						if (dist[x] == INF) {
							dist[x] = dist[cur]+1;
							pred[x] = cur;
							bfs.push(x);
						}
					}
				}

				for (int i = 2; i <= n; i++) {
					if (dist[i] == 2) {
						cout << 5 << nl;
						cout << 1 << " " << u << " " << pred[i] << " " << i << " " << u << " " << n << nl;
						return 0;
					}
				}

				assert(false);
				return 0;
			}
		}

		cout << -1 << nl;
		return 0;
	}

	return 0;
}