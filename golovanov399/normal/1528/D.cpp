#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 606;
constexpr int inf = 2e9;
int a[N][N];

int ans[N][N];
int d[N];
char used[N];

void remin(int& x, int y) {
	x = min(x, y);
}

// #define TEST

void solve() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a[i][j] = inf;
		}
	}
#ifdef TEST
	int n = 600;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = rand() % 1'000'000'000 + 1;
		}
	}
#else
	int n = nxt();
	int m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt(), v = nxt();
		a[u][v] = nxt();
	}
#endif
	for (int i = 0; i < n; ++i) {
		int cur = inf;
		for ([[maybe_unused]] int c : ")") {
			for (int j = 0; j < n; ++j) {
				cur = min(cur + 1, a[i][j]);
				a[i][j] = cur;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		memcpy(d, a[i], sizeof(int) * n);
		d[i] = 0;
		memset(used, 0, sizeof(used));
		for (int it = 0; it < n; ++it) {
			pair<int, int> opt = {inf, -1};
			for (int j = 0; j < n; ++j) {
				if (!used[j] && d[j] < opt.first) {
					opt = {d[j], j};
				}
			}
			int v = opt.second;
			used[v] = 1;
			for (int j = 0; j < n; ++j) {
				remin(d[(d[v] + j) % n], d[v] + a[v][j]);
			}
		}
		memcpy(ans[i], d, sizeof(int) * n);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}