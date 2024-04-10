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
    vector<int> a(n);
    vector<int> l(n, inf), r(n, -inf), c(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        cmin(l[a[i]], i);
        cmax(r[a[i]], i);
        c[a[i]]++;
    }

    int ans = 0;
    vector<array<int, 2>> e, g;
    for (int i = 0; i < n; i++) {
        if (c[i] > 2)
            ans += c[i]-2;
        if (l[i] < r[i])
            e.pb({l[i], r[i]});
    }
    sort(all(e));

    vector<int> d(n+1);
    for (auto& [x, y] : e)
        d[x]++, d[y+1]--;
    for (int i = 0; i < n; i++)
        d[i+1] += d[i];

    for (int i = 0; i < n; i++)
        if (l[i] == r[i] && d[l[i]] > 0)
            ans++;

    debug(ans);
    debug(e);

    int py = -1;
    for (auto& [x, y] : e) {
        if (y < py) {
            ans += 2;
        } else {
            py = y;
            g.pb({x, y});
        }
    }
    e = g;
    g.clear();

    debug(ans);
    debug(e);

    for (int i = 0; i < e.size(); i++) {
        if (i != 0 && i+1 != e.size() && g.back()[1] > e[i+1][0])
            ans += 2;
        else
            g.pb(e[i]);
    }
    e = g;

    debug(ans);
    debug(e);

    for (int i = 0; i+1 < e.size(); i++)
        if (e[i][1] > e[i+1][0])
            ans++;

    cout << ans << "\n";
}