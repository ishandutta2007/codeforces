#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 0, sgn = 1; i < n; i++, sgn = -sgn) {
		sum += sgn * a[i];
	}
	if (sum == 0) {
		printf("%d\n%d %d\n", 1, 1, n);
		return;
	}
	if (sum < 0) {
		for (int i = 0; i < n; i++) {
			a[i] = -a[i];
		}
		sum = -sum;
	}
	if (n % 2) {
		puts("-1");
		return;
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i += 2) {
		if (a[i] == a[i + 1]) {
			ans.emplace_back(i, i + 1);
		} else {
			ans.emplace_back(i, i);
			ans.emplace_back(i + 1, i + 1);
		}
	}
	printf("%ld\n", ans.size());
	for (auto [l, r] : ans) {
		printf("%d %d\n", l + 1, r + 1);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}