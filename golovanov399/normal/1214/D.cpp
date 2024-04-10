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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	cin.sync_with_stdio(0);
	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (n == 1 || m == 1) {
		int cnt = 0;
		for (auto s : a) {
			for (char c : s) {
				if (c == '#') {
					++cnt;
				}
			}
		}
		if (cnt) {
			puts("0");
		} else {
			puts("1");
		}
		return 0;
	}

	vector<vector<char>> can(n, vector<char>(m, 0));
	function<void(int, int)> rec = [&](int x, int y) {
		if (x >= n || y >= m || a[x][y] == '#' || can[x][y]) {
			return;
		}
		can[x][y] = 1;
		rec(x + 1, y);
		rec(x, y + 1);
	};
	rec(0, 0);
	if (!can[n - 1][m - 1]) {
		puts("0");
		return 0;
	}

	int x = n - 1, y = m - 1;
	while (x || y) {
		if (x > 0 && a[x - 1][y] != '#' && can[x - 1][y]) {
			--x;
		} else {
			--y;
		}
		a[x][y] = '#';
	}
	a[0][0] = '.';
	can.assign(n, vector<char>(m, 0));
	rec(0, 0);
	if (!can[n - 1][m - 1]) {
		puts("1");
	} else {
		puts("2");
	}

	return 0;
}