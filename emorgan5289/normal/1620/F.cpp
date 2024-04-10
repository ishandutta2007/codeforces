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
        vector<ll> a(n);
        vector<vector<array<ll, 4>>> p(n+1);
        p[0].pb({-inf, -inf, -inf, -inf});
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            vector<array<ll, 4>> q;
            for (auto& [l, r, pl, pr] : p[i]) {
                if (a[i] > r) q.pb({l, a[i], l, r});
                else if (a[i] > l) q.pb({a[i], r, l, r});
                if (-a[i] > r) q.pb({l, -a[i], l, r});
                else if (-a[i] > l) q.pb({-a[i], r, l, r});
            }
            sort(all(q));
            for (auto& [l, r, pl, pr] : q)
                if (p[i+1].empty() || r < p[i+1].back()[1])
                    p[i+1].pb({l, r, pl, pr});
            debug(p[i+1]);
        }
        if (p[n].empty())
            cout << "NO\n";
        else {
            cout << "YES\n";
            auto [l, r, pl, pr] = p[n][0];
            vector<ll> ans(n);
            for (int i = n-1; i >= 0; i--) {
                if (l != pl) ans[i] = l;
                if (r != pr) ans[i] = r;
                for (int j = 0; j < p[i].size(); j++) {
                    if (p[i][j][0] == pl && p[i][j][1] == pr) {
                        l = p[i][j][0];
                        r = p[i][j][1];
                        pl = p[i][j][2];
                        pr = p[i][j][3];
                        break;
                    }
                }
            }
            for (int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i == n-1];
        }
    }
}