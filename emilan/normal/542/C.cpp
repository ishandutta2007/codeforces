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
    vt<int> f(n);
    for (int &x : f) cin >> x, x--;

    ll max_mu = 1, cycle_lcm = 1;
    for (int s = 0; s < n; s++) {
        int t, h;
        for (t = f[s], h = f[t]; t != h; t = f[t], h = f[f[h]]);

        ll mu;
        for (t = s, mu = 0; t != h; t = f[t], h = f[h], mu++);
        max_mu = max(max_mu, mu);

        ll len;
        for (len = 1, t = f[t]; t != h; len++, t = f[t]);
        cycle_lcm = lcm(cycle_lcm, len);
    }
    
    cout << (max_mu + cycle_lcm - 1) / cycle_lcm * cycle_lcm;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}