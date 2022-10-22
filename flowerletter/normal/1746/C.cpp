#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), p(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		p[a[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		int x = p[i] + 1;
		if (p[i] == n - 1) {
			x = 0;
		}
		cout << x + 1 << " \n"[i == n - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}