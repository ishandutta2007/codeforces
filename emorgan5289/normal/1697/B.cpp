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
    ll n, q; cin >> n >> q;
    vector<ll> p(n+1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    sort(all(p));
    for (int i = 1; i <= n; i++)
        p[i] += p[i-1];
    while (q--) {
        ll x, y; cin >> x >> y;
        cout << p[n-x+y]-p[n-x] << "\n";
    }
}