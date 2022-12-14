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
    ll u, v;
    cin >> u >> v;

    if (u > v || (u ^ v) & 1) return void(cout << -1);

    vt<int> bits(60);
    v -= u;
    for (int i = 0; i < 60; i++) {
        bits[i] = u >> i & 1 | v >> i & 2;
    }

    vt<ll> ans;
    for (int i = 0; i < 3; i++) {
        ll cur = 0;
        for (int j = 0; j < 60; j++) {
            if (bits[j]) {
                bits[j]--;
                cur |= 1ll << j;
            }
        }
        if (!cur) break;
        ans.push_back(cur);
    }

    cout << sz(ans) << '\n';
    for (ll i : ans) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}