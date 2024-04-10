#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int xork(int a, int b, int k) {
	int res = 0;
	int c = 1;
	while (a || b) {
		res += ((a + b) % k) * c;
		a /= k;
		b /= k;
		c *= k;
	}
	return res;
}

int xorinv(int a, int k) {
	int res = 0;
	int c = 1;
	while (a) {
		res += ((k - a % k) % k) * c;
		a /= k;
		c *= k;
	}
	return res;
}

void solve() {
	[[maybe_unused]] int n = nxt(), k = nxt();
	int sign = 1;
	int c = 0;
	for (int i = 0; i < n; ++i) {
		int r = xork((sign == 1 ? i : xorinv(i, k)), c, k);
		cout << r << endl;
		if (nxt() == 1) {
			return;
		}
		sign *= -1;
		c = xork(r, xorinv(c, k), k);
	}
	assert(false);
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}