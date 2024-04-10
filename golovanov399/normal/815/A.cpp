#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

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
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = nxt();
		}
	}

	vector<int> r(n), c(m);
	for (int i = 0; i < n; ++i) {
		r[i] = a[i][0];
	}
	for (int j = 0; j < m; ++j) {
		c[j] = a[0][j] - r[0];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != r[i] + c[j]) {
				puts("-1");
				return 0;
			}
		}
	}

	int mr = *min_element(all(r));
	int mc = *min_element(all(c));

	// mc <= 0
	// mr >= 0

	int offset = 0;
	if (n <= m) {
		// r += max
		// c -= max
		offset = mc;
	} else {
		offset = -mr;
	}

	for (int& x : r) {
		x += offset;
	}
	for (int& x : c) {
		x -= offset;
	}

	for (int x : r) {
		if (x < 0) {
			puts("-1");
			return 0;
		}
	}
	for (int x : c) {
		if (x < 0) {
			puts("-1");
			return 0;
		}
	}

	cout << accumulate(all(r), 0) + accumulate(all(c), 0) << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < r[i]; ++j) {
			printf("row %d\n", i + 1);
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < c[i]; ++j) {
			printf("col %d\n", i + 1);
		}
	}

	return 0;
}