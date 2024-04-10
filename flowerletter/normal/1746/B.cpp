#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> b(2);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[a[i]].push_back(i);
	}
	int cost = 0, ones = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			if (!b[0].empty() && b[0].back() > i) {
				b[0].pop_back();
				++cost;
			}
		}
	}
	cout << cost << '\n';
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