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

const int L = 21;
const int N = 1 << L;
constexpr int mod = 31607;

int a[N];
int b[N];

void normalize(int& x) {
	x %= mod;
	if (x < 0) {
		x += mod;
	}
}

template <bool inv>
void wh(int* b, int* e) {
	if (b + 1 == e) {
		return;
	}
	int *m = b + (e - b) / 2;
	wh<inv>(b, m);
	wh<inv>(m, e);
	while (m != e) {
		if constexpr (inv) {
			*m -= *b;
		} else {
			*m += *b;
		}
		normalize(*m);
		++m, ++b;
	}
}

int table[L][L];
int n;

void rec(int row, int col, int mask, int prob, bool can_main, bool can_other) {
	if (col == n) {
		b[mask] = prob;
		return;
	}
	rec(row, col + 1, mask, prob * table[row][col] % mod, can_main, can_other);
	if ((can_main || col != row) && (can_other || col + row != n - 1)) {
		rec(row, col + 1, mask | (1 << col), prob * (mod + 1 - table[row][col]) % mod, can_main, can_other);
	}
};


void solve() {
	n = nxt();
	// vector<vector<int>> table(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			table[i][j] = nxt() * 3973 % mod;
			// table[i][j] = rand() % (mod - 1) + 1;
		}
	}

	const int nn = 1 << n;

	int ans = 1;
	for (bool off_main : {false, true}) {
		for (bool off_other : {false, true}) {
			fill(a, a + nn, 1);
			for (int i = 0; i < n; ++i) {
				memset(b, 0, sizeof(int) * nn);
				rec(i, 0, 0, 1, !off_main, !off_other);
				b[0] = 0;
				wh<false>(b, b + nn);
				for (int j = 0; j < nn; ++j) {
					a[j] = a[j] * b[j] % mod;
				}
			}
			long long res = 0;
			for (int i = 0; i < nn; ++i) {
				if (__builtin_parity(i) == n % 2) {
					res += a[i];
				} else {
					res += mod - a[i];
				}
			}
			res %= mod;
			if (off_main == off_other) {
				ans -= res;
			} else {
				ans += res;
			}
		}
	}
	normalize(ans);
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}