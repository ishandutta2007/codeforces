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

    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;
    sort(all(a));

    if (n == 1 || n > 60) cout << accumulate(all(a), 0ll) - n;
    else if (n == 2) cout << a[0] - 1;
    else {
        ll ans = 1ll << 62;
        for (int i = 1; pow(i, n - 1) < 2e9 * n; i++) {
            ll cur = 1, acc = 0;
            for (int j = 0; j < n; j++, cur *= i) {
                acc += abs(a[j] - cur);
            }
            ans = min(ans, acc);
        }

        cout << ans;
    }
}