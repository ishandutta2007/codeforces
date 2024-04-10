#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector f(2, vector<int>());
	for (int i = 0; i < n; i++) {
		f[a[i]].push_back(b[i]);
	}
	sort(f[0].begin(), f[0].end());
	sort(f[1].begin(), f[1].end());
	LL ans = 0;
	if (f[0].size() == f[1].size()) {
		for (auto v : f[0]) {
			ans += v * 2;
		}
		for (auto v : f[1]) {
			ans += v * 2;
		}
		ans -= min(f[0][0], f[1][0]);
	} else {
		reverse(f[0].begin(), f[0].end());
		reverse(f[1].begin(), f[1].end());
		if (f[0].size() < f[1].size()) {
			swap(f[0], f[1]);
		}
		for (int i = 0; i < (int)f[1].size(); i++) {
			ans += f[1][i] * 2ll + f[0][i] * 2ll;
		}
		for (int i = (int)f[1].size(); i < (int)f[0].size(); i++) {
			ans += f[0][i];
		}
	}
	printf("%lld\n", ans);
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