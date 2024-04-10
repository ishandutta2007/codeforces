#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int ans = 0;
    int la = 0, lb = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        int nd = max(la, lb);
        int hv = min(a, b);
        if (a != b) ans += max((int)0, hv - nd + 1);
        else ans += max((int)0, hv - nd);
        la = a;
        lb = b;
    }
    if (la == lb) ++ans;
    cout << ans << '\n';
}