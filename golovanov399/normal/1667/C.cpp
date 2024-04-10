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

void solve() {
	int n = nxt();
	if (n == 1) {
		cout << "1\n1 1\n";
		return;
	}
	int m = n;
	while (m % 3 != 2) {
		--m;
	}
	cout << (2 * m - 1) / 3 + (n - m) << "\n";
	int k = (2 * m - 1) / 3;
	for (int i = 0; i < m - k; ++i) {
		cout << m - k - i << " " << i + 1 << "\n";
	}
	for (int i = 0; i < m - k - 1; ++i) {
		cout << m - k + m - k - 1 - i << " " << m - k + i + 1 << "\n";
	}
	for (int i = 0; i < n - m; ++i) {
		cout << m + 1 + i << " " << m + 1 + i << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}