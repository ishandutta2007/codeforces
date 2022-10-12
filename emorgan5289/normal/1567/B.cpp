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
        ll a, b; cin >> a >> b;
        ll x = 0;
        if (a%4 == 2 || a%4 == 3)
            x |= 1;
        for (ll j = 2; j <= 1ll<<40; j *= 2) {
            ll y = a%(2*j);
            if (y > j && y%2 == 1) {
                x |= j;
            }
        }
        // ll y = 0;
        // for (int i = 0; i < a; i++)
        //     y ^= i;
        // debug(a, b, x, y);
        if (x == b) {
            cout << a << "\n";
        } else if ((x^b) != a) {
            cout << a+1 << "\n";
        } else {
            cout << a+2 << "\n";
        }
    }
}