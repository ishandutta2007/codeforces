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

void solve() {
	int n = nxt(), k = nxt();
	if (k == 1) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << i + 1 << "\n";
		}
	} else if (n % 2) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < k; ++j) {
				cout << i * 2 * k + 1 + 2 * j << " ";
			}
			cout << "\n";
			for (int j = 0; j < k; ++j) {
				cout << i * 2 * k + 2 + 2 * j << " ";
			}
			cout << "\n";
		}
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}