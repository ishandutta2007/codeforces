#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
     	if (a[i] == mx) ++cnt;
     	else cnt = 0;
     	ans = max(ans, cnt);
    }
    cout << ans << '\n';
}