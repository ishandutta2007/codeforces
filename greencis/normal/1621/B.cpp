//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        ll mx = -2e9, mn = 2e9;
        set<pair<ll, int>> mxv, mnv;
        ll bothMinAndMax = 1e10;
        for (int i = 0; i < n; ++i) {
            ll l, r, c;
            cin >> l >> r >> c;
            if (r > mx) {
                mx = r;
                mxv = {};
                bothMinAndMax = 1e10;
            }
            if (r == mx && mxv.size() <= 2) {
                mxv.emplace(c, i);
                while (mxv.size() > 2)
                    mxv.erase(--mxv.end());
            }
            if (l < mn) {
                mn = l;
                mnv = {};
                bothMinAndMax = 1e10;
            }
            if (l == mn && r == mx) {
                bothMinAndMax = min(bothMinAndMax, c);
            }
            if (l == mn && mnv.size() <= 2) {
                mnv.emplace(c, i);
                while (mnv.size() > 2)
                    mnv.erase(--mnv.end());
            }
            ll ans = bothMinAndMax;
            for (auto [cmax, imax] : mxv) {
                for (auto [cmin, imin] : mnv) {
                    ll cur = cmin + cmax;
                    if (imin == imax)
                        cur -= cmax;
                    ans = min(ans, cur);
                }
            }
            cout << ans << '\n';
        }
    }
}