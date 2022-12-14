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
    int d, m;
    cin >> d >> m;

    vt<ll> f(__lg(d) + 1, 1 % m);
    ll ans = 0;
    for (int i = 0; i < sz(f); i++) {
        for (int j = 0; j < i; j++) {
            f[i] = (f[i] + f[j]) % m;
        }
        int cnt = 1 << i;
        if (i == sz(f) - 1) cnt = d - (1 << __lg(d)) + 1;
        f[i] = f[i] * cnt % m;
        ans = (ans + f[i]) % m;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}