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
        ll n, k; cin >> n >> k;
        map<ll, ll> l, r;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            if (!l.count(x))
                l[x] = i;
            r[x] = i;
        }
        while (k--) {
            int a, b; cin >> a >> b;
            cout << (!l.count(a) || !l.count(b) || l[a] > r[b] ? "NO" : "YES") << "\n";
        }
    }
}