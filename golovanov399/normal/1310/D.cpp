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

const int N = 88;
int a[N][N];
int b[N][N];
char mark[N];
int dist[2][N];

void remin(int& x, int y) {
	x = min(x, y);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = nxt();
		}
	}

	int ans = 2e9;
	for (int it = 0; it < 5000; ++it) {
		vector<int> good;
		for (int i = 1; i < n; ++i) {
			mark[i] = rand() % 2;
		}
		for (int i = 0; i < n; ++i) {
			if (!mark[i]) {
				good.push_back(i);
			}
		}
		if (good.empty() || (int)good.size() == n) {
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				b[i][j] = 2e8;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!mark[i]) {
				continue;
			}
			for (int x : good) {
				for (int y : good) {
					remin(b[x][y], a[x][i] + a[i][y]);
				}
			}
		}
		fill(dist[0], dist[0] + n, 3e8);
		dist[0][0] = 0;
		for (int t = 0; t * 2 < k; ++t) {
			fill(dist[(t + 1) & 1], dist[(t + 1) & 1] + n, 3e8);
			for (int i : good) {
				for (int j : good) {
					remin(dist[(t + 1) & 1][j], dist[t & 1][i] + b[i][j]);
				}
			}
		}
		remin(ans, dist[(k / 2) & 1][0]);
	}
	cout << ans << "\n";

	return 0;
}