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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll r = 0;
        vector<ll> w(n), f(n), a;
        for (auto& x : w) cin >> x, r += x;
        for (int i = 0; i < n-1; i++) {
            int x, y; cin >> x >> y;
            f[x-1]++, f[y-1]++;
        }
        for (int i = 0; i < n; i++)
            while (f[i]-- > 1) a.pb(w[i]);
        sort(all(a), greater<>());
        cout << r;
        for (auto& x : a)
            r += x, cout << " " << r;
        cout << "\n";
    }
}