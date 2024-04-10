#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

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
	int ans = 0;
	auto b = a;
	sort(all(b));
	vector<int> p(n), q(n);
	for (int i = 0; i < n; ++i) {
		p[i] = lower_bound(all(b), a[i]) - b.begin();
		q[p[i]] = i;
	}
	for (int l = 0; l < n;) {
		int r = l + 1;
		while (r < n && q[r] > q[r - 1]) {
			++r;
		}
		ans = max(ans, r - l);
		l = r;
	}
	cout << n - ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}