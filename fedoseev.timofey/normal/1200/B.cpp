#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int long long
 
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i + 1 < n; ++i) {
		int nd = max(0LL, a[i + 1] - a[i] - k);
		int tk = max(0LL, a[i] - max(0LL, (a[i + 1] - k)));
		if (m < nd) {
			cout << "NO\n";
			return;
		}
		m -= nd;
		m += tk;
	}
	cout << "YES\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}