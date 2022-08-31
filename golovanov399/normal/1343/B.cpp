#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	if (n / 2 % 2) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 0; i < n / 2; ++i) {
			cout << 2 + 2 * i << " ";
		}
		for (int i = 0; i < n / 4; ++i) {
			cout << 1 + 2 * i << " ";
		}
		for (int i = 0; i < n / 4; ++i) {
			cout << 1 + n / 2 + 2 + 2 * i << " ";
		}
		cout << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}