#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int l = -1;
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		l = max(l, i - a[i]);
		ans += i - l;
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