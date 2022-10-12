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
        ll n, m; cin >> n >> m;
        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        ll g = 0;
        for (ll y : b)
            g = gcd(g, y);
        vector<vector<ll>> p(g), neg(g);
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0)
                p[i%g].pb(a[i]);
            else
                neg[i%g].pb(-a[i]);
        }

        ll odd = 0, even = 0;

        for (int i = 0; i < g; i++) {
            sort(all(p[i]));
            sort(all(neg[i]));

            debug(p[i], neg[i]);

            for (auto& x : p[i])
                odd += x, even += x;
            for (auto& x : neg[i])
                odd += x, even += x;

            if (neg[i].size()%2 == 0) {
                if (p[i].empty())
                    odd -= 2*neg[i][0];
                else if (neg[i].empty())
                    odd -= 2*p[i][0];
                else
                    odd -= 2*min(p[i][0], neg[i][0]);
            } else {
                if (p[i].empty())
                    even -= 2*neg[i][0];
                else if (neg[i].empty())
                    even -= 2*p[i][0];
                else
                    even -= 2*min(p[i][0], neg[i][0]);
            }
        }

        cout << max(odd, even) << "\n";
    }
}