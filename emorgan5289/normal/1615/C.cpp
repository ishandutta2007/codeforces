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
        string a, b; cin >> a >> b;
        ll ans = inf_ll;

        ll x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1' && b[i] == '0')
                x++;
            if (a[i] == '0' && b[i] == '1')
                y++;
        }
        if (x == y) cmin(ans, x+y);

        x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '0' && b[i] == '0')
                x++;
            if (a[i] == '1' && b[i] == '1')
                y++;
        }
        if (y == 1+x) cmin(ans, x+y);

        cout << (ans == inf_ll ? -1 : ans) << "\n";
    }
}