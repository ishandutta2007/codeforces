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
	vector<int> a(n), b(n);
	generate(all(a), nxt);
	generate(all(b), nxt);
	int s = 111 * n + 10;
	vector<char> can(s);
	can[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = s - 1; j >= 0; --j) {
			can[j] = 0;
			if (j >= a[i] && can[j - a[i]]) {
				can[j] = 1;
			}
			if (j >= b[i] && can[j - b[i]]) {
				can[j] = 1;
			}
		}
	}
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		tot += a[i] + b[i];
	}
	int i = tot / 2;
	while (!can[i]) {
		--i;
	}
	long long ans = 1ll * i * i + 1ll * (tot - i) * (tot - i);
	for (int i = 0; i < n; ++i) {
		ans += 1ll * a[i] * a[i] * (n - 2);
		ans += 1ll * b[i] * b[i] * (n - 2);
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}