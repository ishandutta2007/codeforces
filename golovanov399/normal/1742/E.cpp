#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), q = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<long long> s(n + 1);
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i - 1];
	}
	for (int i = 1; i < n; ++i) {
		a[i] = max(a[i], a[i - 1]);
	}
	while (q--) {
		int k = nxt();
		auto it = upper_bound(all(a), k);
		cout << s[it - a.begin()] << " ";
	}
	cout << "\n";
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