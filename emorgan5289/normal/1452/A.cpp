#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;
const ll inf_ll = 1e18;
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
        ll x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        cout << 2*x+(y-x)+max(0ll, y-x-1) << "\n";
    }
}