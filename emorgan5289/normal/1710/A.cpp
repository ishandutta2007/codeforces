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
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> a(k);
        for (int i = 0; i < k; i++)
            cin >> a[i];
        bool ok = 0;
        {
            ll x = 0, z = 0;
            for (int i = 0; i < k; i++) {
                ll y = a[i]/m;
                if (y >= 2) x += y;
                if (y >= 2) z += 2;
            }
            if ((z <= n || z != x || (z-n)%2 == 0) && x >= n) ok = 1;
        }
        swap(n, m);
        {
            ll x = 0, z = 0;
            for (int i = 0; i < k; i++) {
                ll y = a[i]/m;
                if (y >= 2) x += y;
                if (y >= 2) z += 2;
            }
            if ((z <= n || z != x || (z-n)%2 == 0) && x >= n) ok = 1;
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}