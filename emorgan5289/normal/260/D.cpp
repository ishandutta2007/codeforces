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
    ll n; cin >> n;
    vector<array<ll, 2>> a, b;
    for (int i = 0; i < n; i++) {
        ll c, s; cin >> c >> s;
        if (c) a.pb({i+1, s});
        else b.pb({i+1, s});
    }
    int i = 0, j = 0;
    while (i < a.size()) {
        ll x = min(a[i][1], b[j][1]);
        cout << a[i][0] << " " << b[j][0] << " " << x << "\n";
        a[i][1] -= x, b[j][1] -= x;
        if (a[i][1] == 0 && (i < a.size()-1 || j == b.size()-1)) i++;
        else j++;
    }
}