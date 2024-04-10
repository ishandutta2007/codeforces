#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	int rest = n - m;
	++m;
	cout << 1ll * n * (n + 1) / 2 - 1ll * (rest % m) * (rest / m + 1) * (rest / m + 2) / 2 - 1ll * (m - rest % m) * (rest / m) * (rest / m + 1) / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}