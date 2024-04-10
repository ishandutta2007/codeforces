#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
   	sort(a.rbegin(), a.rend());
   	ll ans = 0;
   	int cyc = k + 1;
   	ans += (ll)(m / cyc) * ((ll)k * a[0] + a[1]);
   	ans += (ll)(m % cyc) * a[0];
   	cout << ans << '\n';		
}