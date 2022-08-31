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

int n, m;
const int N = 2111111;
int p[N];
int r[N];

inline int get(int i, int j) {
	return i * (m + 1) + j;
}

int tmp[N];

int sumRect(int x1, int y1, int x2, int y2) {
	return p[get(x2, y2)] - p[get(x1, y2)] - p[get(x2, y1)] + p[get(x1, y1)];
}

int sumRectTmp(int x1, int y1, int x2, int y2) {
	return tmp[get(x2, y2)] - tmp[get(x1, y2)] - tmp[get(x2, y1)] + tmp[get(x1, y1)];
}

bool check(int k) {
	if (k > n || k > m) {
		return false;
	}
	memset(tmp, 0, sizeof(int) * (n + 1) * (m + 1));
	for (int i = 0; i + k <= n; ++i) {
		for (int j = 0; j + k <= m; ++j) {
			if (sumRect(i, j, i + k, j + k) == k * k) {
				tmp[get(i + k, j + k)] += 1;
			}
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			tmp[get(i, j)] += tmp[get(i, j - 1)];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			tmp[get(i, j)] += tmp[get(i - 1, j)];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (r[get(i + 1, j + 1)] != !!sumRectTmp(i, j, min(i + k, n), min(j + k, m))) {
				return false;
			}
		}
	}
	return true;
}

void prepare(int k) {
	if (k > n || k > m) {
		return;
	}
	memset(tmp, 0, sizeof(int) * (n + 1) * (m + 1));
	for (int i = 0; i + k <= n; ++i) {
		for (int j = 0; j + k <= m; ++j) {
			if (sumRect(i, j, i + k, j + k) == k * k) {
				tmp[get(i + k, j + k)] += 1;
			}
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'X') {
				p[get(i + 1, j + 1)] += 1;
				r[get(i + 1, j + 1)] = 1;
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			p[get(i, j)] += p[get(i, j - 1)];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			p[get(i, j)] += p[get(i - 1, j)];
		}
	}

	int le = 0, ri = n * m + 1;
	while (ri > le + 1) {
		int mid = (le + ri) / 2;
		if (check(2 * mid + 1)) {
			le = mid;
		} else {
			ri = mid;
		}
	}
	int k = 2 * le + 1;
	prepare(k);
	memset(r, 0, sizeof(r));
	for (int i = 0; i + k <= n; ++i) {
		for (int j = 0; j + k <= m; ++j) {
			if (tmp[get(i + k, j + k)]) {
				r[get(i + k / 2, j + k / 2)] = 1;
			}
		}
	}
	cout << le << "\n";
	for (int i = 0; i < n; ++i) {
		string s(m, '.');
		for (int j = 0; j < m; ++j) {
			if (r[get(i, j)]) {
				s[j] = 'X';
			}
		}
		cout << s << "\n";
	}

	return 0;
}