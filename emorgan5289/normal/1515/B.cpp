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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        bool ok = 0;
        if (n%2 == 0) {
            n /= 2;
            for (ll x = 1; x*x <= n; x++)
                if (x*x == n) ok = 1;
        }
        if (n%2 == 0) {
            n /= 2;
            for (ll x = 1; x*x <= n; x++)
                if (x*x == n) ok = 1;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}