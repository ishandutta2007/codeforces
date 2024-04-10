#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll k, x;
inline ll check(int x) {
    if (x <= k) return 1ll * x * (x + 1) / 2;
    else {
        ll ans = k * k;
        x = 2 * k - 1 - x;
        return ans - 1ll * x * (x + 1) / 2;
    }
}
inline void rmain() {
    cin >> k >> x;
    ll l = 1, r = 2 * k - 2, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid) < x) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans + 1 << endl;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) rmain();
}