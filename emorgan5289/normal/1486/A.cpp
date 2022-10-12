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
        ll x = 0, y = 0;
        bool ans = 1;
        for (int i = 0; i < n; i++) {
            ll z; cin >> z;
            x += z, y += i;
            ans = ans && x >= y;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
}