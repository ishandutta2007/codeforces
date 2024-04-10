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
    ll n, m; cin >> n >> m;
    vector<array<ll, 5>> qry(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> qry[i][j];
    reverse(all(qry));
    vector<array<ll, 4>> pos;
    ll lx = -inf_ll, ly = -inf_ll, rx = inf_ll, ry = inf_ll;
    pos.pb({lx, rx, ly, ry});
    for (auto& [k, a, b, c, d] : qry) {

        ll a1, b1, c1, d1;
        if (k < ly || k > ry)
            a1 = lx, b1 = rx;
        else
            a1 = -inf_ll, b1 = inf_ll;
        if (k < lx || k > rx)
            c1 = ly, d1 = ry;
        else
            c1 = -inf_ll, d1 = inf_ll;

        if (k >= c && k <= d)
            cmax(a1, a), cmin(b1, b);
        else
            a1 = 1, b1 = 0;
        if (k >= a && k <= b)
            cmax(c1, c), cmin(d1, d);
        else
            c1 = 1, d1 = 0;

        debug(a1, b1, c1, d1);

        lx = a1;
        rx = b1;
        ly = c1;
        ry = d1;

        pos.pb({lx, rx, ly, ry});
    }

    reverse(all(pos));
    reverse(all(qry));

    auto check = [&](int i, ll x, ll y) {
        if (x < qry[i][1] || x > qry[i][2]) return 0;
        if (y < qry[i][3] || y > qry[i][4]) return 0;
        if (x >= pos[i+1][0] && x <= pos[i+1][1]) return 1;
        if (y >= pos[i+1][2] && y <= pos[i+1][3]) return 1;
        return 0;
    };

    if (lx > 0 && ly > 0)
        cout << "No\n";
    else {
        cout << "Yes\n";
        ll x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (check(i, x, qry[i][0]))
                cout << "1 ", y = qry[i][0];
            else
                cout << "0 ", x = qry[i][0];
        }
    }
}