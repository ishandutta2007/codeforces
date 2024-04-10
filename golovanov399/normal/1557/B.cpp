#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = i;
	}
	sort(all(a));
	int bad = 0;
	for (int i = 0; i < n - 1; ++i) {
		bad += a[i + 1].second - a[i].second != 1;
	}
	puts(bad <= k - 1 ? "Yes" : "No");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << setprecision(10) << fixed;
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}