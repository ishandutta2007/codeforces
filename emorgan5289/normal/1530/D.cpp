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
        vector<ll> a(n), v(n, 0), b(n, -1);
        for (int i = 0; i < n; i++)
            cin >> a[i], a[i]--;
        for (int i = 0; i < n; i++) {
            if (!v[a[i]]) {
                v[a[i]] = 1;
                b[i] = a[i];
            }
        }
        debug(b);
        vector<ll> c(n, -1);
        for (int i = 0; i < n; i++)
            if (b[i] == -1 && !v[i])
                c[i] = i, v[i] = 1;
        debug(c);
        ll p = -1;
        for (int i = 0; i < n; i++)
            if (c[i] != -1) {
                if (p != -1) swap(p, c[i]);
                else p = c[i];
            }
        debug(c);
        debug(p);
        for (int i = 0; i < n; i++)
            if (c[i] != -1) {
                c[i] = p;
                break;
            }
        debug(c);
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1 && c[i] != -1) {
                b[i] = c[i];
                // one loop
                if (b[i] == i) {
                    debug("bad");
                    bool ok = 0;
                    for (int j = 0; j < n; j++)
                        if (a[j] == a[i] && j != i) {
                            swap(b[i], b[j]);
                            break;
                        }
                }
            }
            if (b[i] == -1) {
                while (v[x]) x++;
                b[i] = x;
                v[x] = 1;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == b[i]) ans++;
        cout << ans << "\n";
        for (int i = 0; i < n; i++)
            cout << b[i]+1 << " \n"[i == n-1];
    }
}