#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	if (n % 2 == 0) {
		for (int i = n; i > 0; --i) {
			cout << i << " ";
		}
		cout << "\n";
	} else if (n == 3) {
		cout << "-1\n";
	} else {
		cout << n - 1 << " " << n;
		for (int i = 1; i < n - 1; ++i) {
			cout << " " << i;
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}