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
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}
	for (int i = 0; i < n; ++i) {
		b[i] = nxt() - 1;
	}
	for (int i = 0; i < n; ++i) {
		p[a[i]] = b[i];
	}
	vector<char> used(n, false);
	const int mod = 1'000'000'007;
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		ans = ans * 2 % mod;
		for (int x = i; !used[x]; x = p[x]) {
			used[x] = 1;
		}
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