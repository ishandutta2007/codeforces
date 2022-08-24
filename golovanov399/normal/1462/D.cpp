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
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> p(n + 1);
	for (int i = 0; i < n; ++i) {
		p[i + 1] = p[i] + a[i];
	}
	for (int d : p) {
		if (d == 0) {
			continue;
		}
		int cur = 0;
		for (int i = 0; i <= n; ++i) {
			if (p[i] == cur) {
				cur += d;
			}
		}
		if (cur == p[n] + d) {
			cout << n - p[n] / d << "\n";
			return;
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