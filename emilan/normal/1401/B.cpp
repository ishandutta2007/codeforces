#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int _t;
    cin >> _t;
    while (_t--) {
        vt<int> a(3), b(3);
        for (int& i : a) cin >> i;
        for (int& i : b) cin >> i;

        int ans = 0;

        int x = min(a[2], b[1]);
        a[2] -= x, b[1] -= x;
        ans += x * 2;

        b[2] -= a[0] + a[2];
        ans -= max(0, b[2]) * 2;

        cout << ans << '\n';
    }
}