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
	int n = nxt(), m = nxt();
	if (m < n) {
		cout << "No\n";
		return;
	}
	if (n == m) {
		cout << "Yes\n";
		for (int i = 0; i < n; ++i) {
			cout << "1 ";
		}
		cout << "\n";
		return;
	}
	if (n % 2) {
		cout << "Yes\n";
		for (int i = 0; i < n - 1; ++i) {
			cout << "1 ";
		}
		cout << m - n + 1 << "\n";
		return;
	}
	if (m % 2) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	for (int i = 0; i < n - 2; ++i) {
		cout << "1 ";
	}
	cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}