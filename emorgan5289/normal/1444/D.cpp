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

const int N = 5e5+5;

vector<ll> partition(vector<ll> a) {
    int n = a.size();
    int m = accumulate(all(a), 0);
    if (m%2) return {};
    m /= 2;
    vector<bitset<N>> dp(1);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        dp.pb((dp[i]<<a[i])|dp[i]);
    vector<ll> r;
    if (!dp[n][m]) return r;
    int x = m;
    for (int i = n-1; i >= 0; i--) {
        if (x >= a[i] && dp[i][x-a[i]])
            x -= a[i], r.pb(a[i]);
        else
            r.pb(-a[i]);
    }
    return r;
}

// #include "../../../geodeb/lib/geodeb.h"

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // GD_INIT("../../output.html");
    int t; cin >> t;
    while (t--) {
        // GD_LAYER();
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll m; cin >> m;
        vector<ll> b(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];
        a = partition(a);
        b = partition(b);
        debug(a, b);
        if (a.empty() || b.empty() || n != m) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            vector<ll> la, ra, lb, rb;
            for (ll x : a) {
                if (x > 0) ra.pb(x);
                else la.pb(-x);
            }
            for (ll x : b) {
                if (x > 0) rb.pb(x);
                else lb.pb(-x);
            }
            vector<array<ll, 2>> l, r;
            if (la.size() < ra.size()) swap(la, ra);
            if (lb.size() > rb.size()) swap(lb, rb);
            for (int i = 0; i < lb.size(); i++)
                l.pb({la[i], lb[i]});
            for (int i = 0; i < ra.size(); i++)
                r.pb({ra[i], rb[i]});
            a.clear(), b.clear();
            sort(all(l), [&](auto x, auto y){
                return atan2(x[0], x[1]) < atan2(y[0], y[1]);
            });
            sort(all(r), [&](auto x, auto y){
                return atan2(x[0], x[1]) < atan2(y[0], y[1]);
            });
            for (auto& [x, y] : l)
                a.pb(x), b.pb(y);
            for (int i = 0; i < la.size()-lb.size(); i++) {
                a.pb(la[la.size()-i-1]);
                b.pb(-rb[rb.size()-i-1]);
            }
            for (auto& [x, y] : r)
                a.pb(-x), b.pb(-y);
            int x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                // GD_SEGMENT(x, y, x, y+b[i], "red");
                y += b[i];
                cout << x << " " << y << "\n";
                // GD_SEGMENT(x, y, x+a[i], y, "black");
                x += a[i];
                cout << x << " " << y << "\n";
            }
        }
        // GD_SEGMENT(-4625, 6156, -3625, 6156, "blue");
        // GD_SEGMENT(-4609, 6100, -4609, 6250, "blue");
        // GD_PAUSE();
    }
}