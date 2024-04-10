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
    int n, x;
    cin >> n >> x;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    if (accumulate(all(a), 0) % x) cout << n << '\n';
    else {
        int mx = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] % x) mx = max(mx, n - i - 1);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] % x) mx = max(mx, i);
        }
        cout << mx << '\n';
    }
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