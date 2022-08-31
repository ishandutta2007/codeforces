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
	int n = nxt();
	if (n > 45) {
		cout << "-1\n";
		return;
	}
	int cnt = 1;
	while ((9 + 9 - cnt + 1) * cnt / 2 < n) {
		++cnt;
	}
	for (int i = 1; i <= 9; ++i) {
		if (cnt > 0 && (9 + 9 - cnt + 2) * (cnt - 1) / 2 >= n - i) {
			cout << i;
			--cnt;
			n -= i;
		}
	}
	assert(n == 0);
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}