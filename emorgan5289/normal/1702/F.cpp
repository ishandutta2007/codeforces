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
        multiset<ll, greater<>> a, b;
        for (int i = 0; i < 2*n; i++) {
            ll x; cin >> x;
            x >>= __builtin_ctz(x);
            (i < n ? a : b).insert(x);
        }
        debug(a, b);
        while (!b.empty()) {
            ll x = *b.begin(); b.erase(b.begin());
            if (a.find(x) != a.end())
                a.erase(a.find(x));
            else if (x > 1)
                b.insert(x >> __builtin_ctz(x^1));
        }
        debug(a, b);
        cout << (a.empty() ? "YES" : "NO") << "\n";
    }
}