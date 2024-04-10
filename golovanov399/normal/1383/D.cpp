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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 288;
int a[N][N];
int b[N][N];

void solve() {
	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = nxt();
		}
	}

	vector<int> rmx(n), cmx(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			rmx[i] = max(rmx[i], a[i][j]);
			cmx[j] = max(cmx[j], a[i][j]);
		}
	}
	sort(all(rmx));
	sort(all(cmx));
	reverse(all(rmx));
	reverse(all(cmx));
	rmx.push_back(88888888);
	cmx.push_back(88888888);
	int ri = 0;
	int ci = 0;

	int r = -1, c = -1;
	int cr = -1, cc = -1;
	queue<pair<int, int>> what_to_fill;
	for (int val = n * m; val > 0; --val) {
		if (val == rmx[ri] && val == cmx[ci]) {
			++ri, ++ci;
			++r, ++c;
			b[r][c] = val;
			for (int i = r - 1; i >= 0; --i) {
				what_to_fill.push({i, c});
			}
			for (int i = c - 1; i >= 0; --i) {
				what_to_fill.push({r, i});
			}
			cr = r, cc = c;
		} else if (val == rmx[ri]) {
			++ri;
			++r;
			b[r][cc] = val;
			for (int i = cc - 1; i >= 0; --i) {
				what_to_fill.push({r, i});
			}
			for (int i = cc + 1; i <= c; ++i) {
				what_to_fill.push({r, i});
			}
		} else if (val == cmx[ci]) {
			++ci;
			++c;
			b[cr][c] = val;
			for (int i = cr - 1; i >= 0; --i) {
				what_to_fill.push({i, c});
			}
			for (int i = cr + 1; i <= r; ++i) {
				what_to_fill.push({i, c});
			}
		} else {
			b[what_to_fill.front().first][what_to_fill.front().second] = val;
			what_to_fill.pop();
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}