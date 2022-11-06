#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int tot = 0, ans = n + 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	int c1 = 0;
	for (int i = 0; i < n; i++) {
		int c0 = (n - i) - (tot - c1);
		ans = min(ans, max(c0, c1));
		c1 += a[i];
	}
	int c0 = 0;
	ans = min(ans, max(c0, c1));
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