#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    int t; cin >> t;
    for (int z = 0; z < t; ++z) {
        int n; cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        ll ans = 0;
        for (int z = 0; z < 2; ++z) {
            ll g = 0;
            for (int i = z; i < n; i += 2)
                g = gcd(g, v[i]);
            for (int i = !z; g && i < n; i += 2)
                if (v[i] % g == 0)
                    g = 0;
            if (g)
                ans = g;
        }
        cout << ans << '\n';
    }
}