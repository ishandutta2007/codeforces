#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	long long b, s;
	cin >> b >> s;
	s -= b * k;
	if (s < 0) {
		cout << "-1\n";
		return;
	}
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = min<long long>(s, k - 1);
		s -= a[i];
	}
	if (s) {
		cout << "-1\n";
		return;
	}
	a[0] += b * k;
	for (auto x : a) {
		cout << x << " ";
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