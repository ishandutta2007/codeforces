#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> a(1<<n), ans(1<<n);
    for (int i = 0; i < 1<<n; i++)
        cin >> a[i];
    ll m = 1<<(n+1);

    // any subarray, prefix, suffix, whole array
    vector<ll> s(m), l(m), r(m), w(m);

    for (int i = 0; i < 1<<n; i++) {
        s[(1<<n)+i] = max(0ll, a[i]);
        l[(1<<n)+i] = max(0ll, a[i]);
        r[(1<<n)+i] = max(0ll, a[i]);
        w[(1<<n)+i] = a[i];
    }

    auto compute_level = [&](ll k, bool flip) {
        for (int i = 1<<k; i < 1<<(k+1); i++) {
            int x = 2*i, y = 2*i+1;
            if (flip) swap(x, y);
            s[i] = max(max(s[x], s[y]), r[x]+l[y]);
            r[i] = max(w[y]+r[x], r[y]);
            l[i] = max(w[x]+l[y], l[x]);
            w[i] = w[x]+w[y];
            debug("c", i, flip, s[i], l[i], r[i], w[i]);
        }
    };

    for (int i = 0; i < 1<<n; i++) {
        for (int k = i == 0 ? n-1 : 31-__builtin_clz(i^(i-1)); k >= 0; k--)
            compute_level(k, (i&(1<<k)) > 0);
        ans[i] = s[1];
    }

    ll q; cin >> q;
    ll x = 0;
    for (int i = 0; i < q; i++) {
        int k; cin >> k;
        x ^= 1<<(n-1-k);
        cout << ans[x] << "\n";
    }
}