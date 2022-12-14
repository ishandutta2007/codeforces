#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<int> m(n + 1);
    for (int i = 0; i < n; i++) {
        m[i + 1] = max(m[i], a[i] + 1);
    }

    for (int i = n; i > 0; i--) {
        m[i - 1] = max(m[i - 1], m[i] - 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += m[i + 1] - a[i] - 1;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}