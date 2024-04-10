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
using pll = pair<ll, ll>;

const double sqrt2 = sqrt(2);

void solve() {
    ll d, k;
    cin >> d >> k;

    pll mx;
    for (ll x = 0; x <= d; x += k) {
        ll y = x < d / sqrt2 ? x : ll(sqrt(d * d - x * x) / k) * k;
        pll cur = {y, x};
        mx = max(mx, cur);
    }

    cout << (((mx.fi + mx.se) / k) & 1 ? "Ashish\n" : "Utkarsh\n");
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