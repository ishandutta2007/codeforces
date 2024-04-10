#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

long long del_vniz(long long a, long long b) {
	if (b < 0)
		a = -a, b = -b;
	if (a >= 0)
		return a / b;
	else
		return (a - b + 1) / b;
}

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(all(a));
	vector<long long> pr(n);
	pr[0] = 0;
	for (int i = 1; i < n; ++i)
		pr[i] = pr[i - 1] + a[i];
	if (pr.back() + a[0] <= k) {
		cout << 0 << '\n';
		return;
	}
	long long ans = 1e18 + 228;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, max(0ll, a[0] - del_vniz((k - pr[i]), (n - i))) + (n - i - 1));
	}
	cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}