#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<vector<int>> a(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = nxt();
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] ^= nxt();
		}
	}
	for (int i = 0; i < n; ++i) {
		int x = 0;
		for (int j = 0; j < m; ++j) {
			x ^= a[i][j];
		}
		if (x) {
			cout << "No\n";
			return 0;
		}
	}
	for (int j = 0; j < m; ++j) {
		int x = 0;
		for (int i = 0; i < n; ++i) {
			x ^= a[i][j];
		}
		if (x) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";

	return 0;
}