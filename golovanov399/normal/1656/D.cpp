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
	long long n;
	cin >> n;

	long long p2 = 2ll << __builtin_ctzll(n);
	n >>= __builtin_ctzll(n);
	long long ans = n == 1 ? p2 : min(p2, n);
	if (ans <= (1ll << 31) && ans * (ans + 1) <= n * p2) {
		cout << ans << "\n";
	} else {
		cout << "-1\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}