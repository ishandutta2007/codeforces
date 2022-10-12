#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e14+10;
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
        ll n, m; cin >> n >> m;
        set<ll> s;
        multiset<array<ll, 2>> ev;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            s.insert(x);
            ev.insert({x, -inf_ll});
        }
        for (int i = 0; i < m; i++) {
            ll l, r; cin >> l >> r;
            if (s.lower_bound(l) != s.end() && *s.lower_bound(l) <= r)
                continue;
            ev.insert({l, r});
        }
        ev.insert({inf_ll, -inf_ll});
        vector<array<ll, 2>> a;
        vector<ll> dp = {0};
        vector<array<ll, 2>> stk;
        ll x = -inf_ll;
        ll pc = 0;
        debug(ev);
        for (auto& [l, r] : ev) {
            if (r == -inf_ll) {
                debug(x, stk);
                ll m1 = dp.back(), m2 = dp.back();
                for (int j = dp.size()-1; j > dp.size()-1-pc; j--) {
                    cmin(m1, x-a[j-1][1]+dp[j-1]);
                    cmin(m2, 2*(x-a[j-1][1])+dp[j-1]);
                }
                cmin(dp.back(), m1);
                for (auto& [w, z] : stk) {
                    a.pb({w, z});
                    dp.pb(min(m1+2*(w-x), m2+w-x));
                }
                pc = stk.size();
                stk.clear();
                x = l;
            } else {
                while (!stk.empty() && stk.back()[1] >= r)
                    stk.pop_back();
                stk.pb({l, r});
            }
        }
        debug(dp);
        cout << dp.back() << "\n";
    }
}