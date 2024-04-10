#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    int ost = 0;
    for (int i = 0; i < n; ++i) {
        int cur = min(ost, a[i] / 2);
        ans += cur;
        a[i] -= 2 * cur;
        ost -= cur;
        ans += a[i] / 3;
        a[i] %= 3;
        ost += a[i];
    }
    cout << ans << '\n';
}