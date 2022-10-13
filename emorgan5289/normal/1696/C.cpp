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

vector<array<ll, 2>> f(vector<array<ll, 2>> a, ll n, ll m) {
    for (int i = 0; i < n; i++) {
        while (a[i][0]%m == 0) {
            a[i][1] *= m;
            a[i][0] /= m;
        }
    }
    vector<array<ll, 2>> res;
    for (auto& [x, y] : a) {
        if (res.empty() || x != res.back()[0])
            res.pb({x, y});
        else res.back()[1] += y;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<array<ll, 2>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i][0];
            a[i][1] = 1;
        }
        ll k; cin >> k;
        vector<array<ll, 2>> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i][0];
            b[i][1] = 1;
        }
        debug(a, b);
        a = f(a, n, m);
        b = f(b, k, m);
        debug(a, b);
        cout << (a == b ? "Yes" : "No") << "\n";
    }
}