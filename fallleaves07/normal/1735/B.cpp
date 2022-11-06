#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, mn;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) {
			mn = a[i];
		} else {
			mn = min(mn, a[i]);
		}
	}
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		LL p = a[i] / (mn * 2 - 1);
		if (a[i] > p * (mn * 2 - 1ll)) {
			++p;
		}
		ans += p - 1ll;
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