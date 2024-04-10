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
        ll n, c, q; cin >> n >> c >> q;
        string s; cin >> s;
        vector<ll> l(c), r(c), p(c+1);
        p[0] = s.size();
        for (int i = 0; i < c; i++) {
            cin >> l[i] >> r[i];
            l[i]--, r[i]--;
            p[i+1] = p[i] + (r[i]-l[i]+1);
        }
        while (q--) {
            ll k; cin >> k; k--;
            for (int i = c; i > 0; i--) {
                if (k >= p[i-1]) {
                    k = l[i-1]+k-p[i-1];
                }
            }
            debug(k, s);
            cout << s[k] << "\n";
        }
    }
}