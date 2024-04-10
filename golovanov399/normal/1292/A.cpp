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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), q = nxt();
	vector<vector<char>> used(2, vector<char>(n, 0));
	int cnt = 0;
	while (q--) {
		int x = nxt() - 1, y = nxt() - 1;
		if (used[x][y]) {
			if (y && used[x ^ 1][y - 1]) {
				--cnt;
			}
			if (y < n - 1 && used[x ^ 1][y + 1]) {
				--cnt;
			}
			if (used[x ^ 1][y]) {
				--cnt;
			}
		}
		used[x][y] ^= 1;
		if (used[x][y]) {
			if (y && used[x ^ 1][y - 1]) {
				++cnt;
			}
			if (y < n - 1 && used[x ^ 1][y + 1]) {
				++cnt;
			}
			if (used[x ^ 1][y]) {
				++cnt;
			}
		}
		puts(cnt ? "No" : "Yes");
	}

	return 0;
}