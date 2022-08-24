#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 3033;
int dist[N][N];
long long dp[N][N];
vector<int> a[N];
int sz[N];
int tin[N], tout[N];
int timer = 0;

vector<pair<int, int>> by_dist[N];

void dfsDist(int root, int p, int v) {
	for (int u : a[v]) {
		if (u == p) {
			continue;
		}
		dist[root][u] = dist[root][v] + 1;
		dfsDist(root, v, u);
	}
}

void dfsSz(int v, int p) {
	tin[v] = timer++;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfsSz(x, v);
		sz[v] += sz[x];
	}
	++sz[v];
	tout[v] = timer;
}

bool isPar(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void remax(long long& x, long long y) {
	x = max(x, y);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		dfsDist(i, i, i);
	}
	dfsSz(0, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			by_dist[dist[i][j]].push_back({i, j});
		}
	}

	for (int d = n - 1; d >= 0; --d) {
		for (auto [u, v] : by_dist[d]) {
			int sz_u = sz[u], sz_v = sz[v];
			if (isPar(u, v)) {
				for (int x : a[u]) {
					if (isPar(u, x) && isPar(x, v)) {
						sz_u = n - sz[x];
						break;
					}
				}
			} else if (isPar(v, u)) {
				for (int x : a[v]) {
					if (isPar(v, x) && isPar(x, u)) {
						sz_v = n - sz[x];
						break;
					}
				}
			}
			for (int x : a[u]) {
				if (dist[u][v] < dist[x][v]) {
					remax(dp[u][v], dp[x][v]);
				}
			}
			for (int x : a[v]) {
				if (dist[u][v] < dist[u][x]) {
					remax(dp[u][v], dp[u][x]);
				}
			}
			dp[u][v] += sz_u * sz_v;
			dp[v][u] = dp[u][v];
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";

	return 0;
}