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
        ll x, y; cin >> x >> y;
        // x+y -> y%x, y%(x+y)
        ll n;
        if (x == y) {
            n = x;
        } else if (x > y) {
            n = x+y;
        } else if (y > 2*x) {
            n = y-(y%x)/2;
        } else if (y > x) {
            n = (x+y)/2;
        }
        debug(x, y, n, n%x, y%n);
        cout << n << "\n";
    }
}