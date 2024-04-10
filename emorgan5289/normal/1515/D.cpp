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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, l, r; cin >> n >> l >> r;
        vector<ll> a(l), b(r);
        for (int i = 0; i < l; i++)
            cin >> a[i];
        for (int i = 0; i < r; i++)
            cin >> b[i];
        if (a.size() > b.size())
            swap(a, b), swap(l, r);
        vector<ll> f(n+1), g(n+1);
        for (auto& x : a)
            f[x]++;
        for (auto& x : b)
            g[x]++;
        ll ans = 0;
        debug(f);
        debug(g);
        for (int i = 0; i <= n; i++) {
            while (l < r && g[i] > f[i]+1) {
                l++, r--;
                f[i]++, g[i]--;
                ans += 2;
            }
        }
        for (int i = 0; i <= n; i++) {
            while (l < r && g[i] > f[i]) {
                l++, r--;
                f[i]++, g[i]--;
                ans += 2;
            }
        }
        debug(f);
        debug(g);
        for (int i = 0; i <= n; i++)
            ans += abs(f[i]-g[i]);
        cout << ans/2 << "\n";
    }
}