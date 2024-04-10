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
        ll n, m; cin >> n >> m;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
            if (i > 0) cmin(b[i], b[i-1]);
        }
        set<array<ll, 3>> s;
        for (int i = 0; i < n; i++) {
            if (i == 0 || b[i] != b[i-1]) {
                int j = i;
                while (j != n-1 && b[j] == b[j+1])
                    j++;
                s.insert({i, j, b[i]});
            }
        }
        debug(a);
        debug(s);
        while (m--) {
            ll k, d; cin >> k >> d; k--;
            debug(k, d);
            a[k] -= d;
            auto [l, r, x] = *--s.upper_bound({k, inf_ll, inf_ll});
            if (x > a[k]) {
                s.erase({l, r, x});
                if (l != k) s.insert({l, k-1, x});
                auto it = s.upper_bound({k, inf_ll, inf_ll});
                while (it != s.end() && (*it)[2] >= a[k]) {
                    r = (*it)[1];
                    s.erase(it);
                    it = s.upper_bound({k, inf_ll, inf_ll});
                }
                s.insert({k, r, a[k]});
            }
            debug(s);
            cout << s.size() << " \n"[m == 0];
        }
    }
}