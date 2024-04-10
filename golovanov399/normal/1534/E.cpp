#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	if (n % 2 == 1 && k % 2 == 0) {
		cout << "-1" << endl;
		return;
	}
	int ans = 0;

	int d = (n + k - 1) / k;
	if ((d * k - n) % 2) {
		++d;
	}

	if (k == n) {
		cout << "? ";
		for (int i = 1; i <= n; ++i) {
			cout << i << " ";
		}
		cout << endl;
		ans = nxt();
	} else if (n % k == 0) {
		for (int i = 0; i < n / k; ++i) {
			cout << "? ";
			for (int j = 1; j <= k; ++j) {
				cout << i * k + j << " ";
			}
			cout << endl;
			ans ^= nxt();
		}
	} else if (d != 2) {
		int extra = (d * k - n) / 2;
		int cur = extra;
		for (int i = 0; i < d; ++i) {
			cout << "? ";
			if (i < 3) {
				for (int j = 0; j < extra; ++j) {
					cout << j + 1 << " ";
				}
				for (int j = 0; j < k - extra; ++j) {
					cout << ++cur << " ";
				}
				cout << endl;
			} else {
				for (int j = 0; j < k; ++j) {
					cout << ++cur << " ";
				}
				cout << endl;
			}
			ans ^= nxt();
		}
	} else if ((n - k) % 2 == 0) {
		int len = (n - k) / 2;
		for (int i = 0; i < 3; ++i) {
			cout << "? ";
			for (int ii = 0; ii < len; ++ii) {
				cout << i * len + ii + 1 << " ";
			}
			for (int ii = 3 * len; ii < n; ++ii) {
				cout << ii + 1 << " ";
			}
			cout << endl;
			ans ^= nxt();
		}
	} else {
		// n is even, k is odd, so we need an even number of, but odd number of times covered by inverse
		k = n - k;

		int d = (n + k - 1) / k;
		if ((d * k - n) % 2) {
			d += 1;
		}

		if (2 * k > n && k < n && d == 2) {
			d += 1;
			if ((d * k - n) % 2) {
				++d;
			}
		}

		int extra = (d * k - n) / 2;
		int cur = extra;
		for (int i = 0; i < d; ++i) {
			cout << "? ";
			if (i < 3) {
				for (int j = extra; j < n; ++j) {
					if (j < cur || j >= cur + (k - extra)) {
						cout << j + 1 << " ";
					}
				}
				cur += k - extra;
				cout << endl;
			} else {
				for (int j = 0; j < n; ++j) {
					if (j < cur || j >= cur + k) {
						cout << j + 1 << " ";
					}
				}
				cur += k;
				cout << endl;
			}
			ans ^= nxt();
		}
	}
	cout << "! " << ans << endl;
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}