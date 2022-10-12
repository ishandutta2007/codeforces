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
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        debug(a);
        bool ok = 0;
        for (int i = 0; i < 1<<n; i++)
            for (int j = 0; j < 1<<n; j++) {
                if ((j&i) != j) continue;
                ll x = 0;
                for (int k = 0; k < n; k++) {
                    if (j&(1<<k)) {
                        x -= a[k];
                    } else if (i&(1<<k)) {
                        x += a[k];
                    }
                }
                // debug(i, j, x);
                for (int k = 0; k < n; k++)
                    if (!(i&(1<<k)) && abs(x) == abs(a[k]))
                        ok = 1;
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}