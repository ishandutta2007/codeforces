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
    vt<ll> a(n);
    for (ll &x : a) cin >> x;

    vt<vt<ll>> b(60);
    for (ll x : a) {
        int e = 0;
        for (ll i = x; ~i & 1; i >>= 1, e++);
        b[e].push_back(x);
    }

    int mx = max_element(all(b), [](vt<ll> &x, vt<ll> &y) {
        return sz(x) < sz(y);
    }) - b.begin();

    vt<ll> ans;
    for (int i = 0; i < 60; i++) {
        if (i == mx) continue;

        ans.insert(ans.end(), all(b[i]));
    }

    cout << sz(ans) << '\n';
    for (ll x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}