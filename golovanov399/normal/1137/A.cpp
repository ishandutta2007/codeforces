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
	vector<vector<int>> rows(n, vector<int>(m, 0));
	vector<vector<int>> cols(m, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = rows[i][j] = cols[j][i] = nxt();
		}
	}
	for (int i = 0; i < n; ++i) {
		make_unique(rows[i]);
	}
	for (int i = 0; i < m; ++i) {
		make_unique(cols[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int r_i = lower_bound(all(rows[i]), a[i][j]) - rows[i].begin();
			int c_i = lower_bound(all(cols[j]), a[i][j]) - cols[j].begin();
			printf("%d ", max((int)rows[i].size() - r_i + max(r_i, c_i),
							  (int)cols[j].size() - c_i + max(r_i, c_i)));
		}
		printf("\n");
	}

	return 0;
}