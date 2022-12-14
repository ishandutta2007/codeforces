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

const ll mod = 1e9 + 7;

void solve() {
    int n, x, pos;
    cin >> n >> x >> pos;

    vt<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }

    ll ans = 1;
    int l = 0, r = n, li = 0, ri = 0;
    while (l < r) {
        int mi = (l + r) / 2;

        if (mi <= pos) {
            if (mi != pos) {
                ans = ans * (x - li - 1) % mod;
                li++;
            }
            l = mi + 1;
        } else if (mi > pos) {
            ans = ans * ((n - x) - ri) % mod;
            ri++;
            r = mi;
        }
    }

    cout << ans * fact[n - li - ri - 1] % mod;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}