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
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> p(n), q(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        for (int i = 0; i < n; i++)
            cin >> q[i];
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            a[p[i]-1] = q[i]-1;
        debug(p);
        debug(q);
        debug(a);debug();

        vector<ll> cyc;
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cyc.pb(0);
                for (int j = i; !vis[j]; j = a[j]) {
                    cyc.back()++;
                    vis[j] = 1;
                }
            }
        }

        debug(cyc);
        ll odd = 0;
        for (auto& x : cyc)
            if (x%2 == 1) odd++;

        ll ans = 0;

        for (int i = 0; i < (n-odd)/2; i++) {
            ans -= i+1;
            ans += n-i;
            debug(i+1, n-i);
        }
        cout << 2*ans << "\n";
    }
}