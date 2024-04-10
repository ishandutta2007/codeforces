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
	int n = nxt(), k = nxt();
	int x = nxt() - 1, y = nxt() - 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % k == (x + y) % k) {
				cout << "X";
			} else {
				cout << ".";
			}
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