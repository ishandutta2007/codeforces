#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = nxt();
	}
	sort(all(a));
	for (int i = 1; i < n; ++i) {
		if (a[i].second < a[i - 1].second) {
			cout << "NO\n";
			return;
		}
	}
	a.insert(a.begin(), {0, 0});
	n += 1;
	cout << "YES\n";
	for (int i = 1; i < n; ++i) {
		cout << string(a[i].first - a[i - 1].first, 'R') << string(a[i].second - a[i - 1].second, 'U');
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}