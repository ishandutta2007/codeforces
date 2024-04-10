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

void solve(int tc) {
    int n;
    cin >> n;
    int ans = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            odd++;
            if (~i & 1) ans++;
        }
    }
    if (odd != n / 2) cout << "-1\n";
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case #" << tc << ": ";
        solve(tc);
    }
}