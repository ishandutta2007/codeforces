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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while (q--) {
        ll x, y; cin >> x >> y;
        bool ok = x <= y && __builtin_popcountll(x) >= __builtin_popcountll(y);
        if (ok)
            for (ll i = 1, j = 1; i < 1ll<<35; i *= 2) {
                if (y&i) {
                    while (!(x&j)) j *= 2;
                    ok = ok && j <= i;
                    j *= 2;
                }
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}