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

using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ld x = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        ld a; cin >> a;
        ans += 2*a*x-a;
        x = x*a+1;
    }
    cout << setprecision(25) << fixed;
    cout << ans << "\n";
}