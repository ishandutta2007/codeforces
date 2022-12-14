#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    ll ori = 0;
    for (int i = 0; i < n; i++) {
        ori += a[i] * b[i];
    }

    ll ans = ori;

    // solid
    for (int i = 1; i < n - 1; i++) {
        ll cur = ori;
        for (int l = i - 1, r = i + 1; l >= 0 && r < n; l--, r++) {
            cur -= a[l] * b[l] + a[r] * b[r];
            cur += a[l] * b[r] + a[r] * b[l];
            ans = max(cur, ans);
        }
    }

    // middle
    for (int i = 1; i < n; i++) {
        ll cur = ori;
        for (int l = i - 1, r = i; l >= 0 && r < n; l--, r++) {
            cur -= a[l] * b[l] + a[r] * b[r];
            cur += a[l] * b[r] + a[r] * b[l];
            ans = max(cur, ans);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}