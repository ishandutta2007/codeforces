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
        vector<array<ll, 2>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i][0] >> a[i][1];
        map<ll, ll> ev;
        for (auto& [x, p] : a) {
            ev[x-p]++;
            ev[x+p]++;
            ev[x] -= 2;
        }
        ll y = 0, dy = 0, px = -inf_ll;
        ll l = inf_ll, r = -inf_ll;
        for (auto& [x, v] : ev) {
            y += dy*(x-px);
            px = x;
            dy += v;
            if (y > m) {
                cmin(l, x-(y-m));
                cmax(r, x+(y-m));
            }
        }
        debug(l, r);
        for (auto& [x, p] : a) {
            cout << (x-p <= l && x+p >= r ? "1" : "0");
        }
        cout << "\n";
    }
}