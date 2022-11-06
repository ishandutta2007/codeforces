#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, c0 = 0;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c0 += (1 - a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		c0 -= (1 - b[i]);
		ans += abs(a[i] - b[i]);
	}
	ans = min(ans, abs(c0) + 1);
	printf("%d\n", ans);
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