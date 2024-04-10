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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll a, b, m; cin >> a >> b >> m;
        ll len = 0;
        if (a == b) {
            cout << "1 " << a << "\n";
            continue;
        }
        while ((1ll<<(len))*(a+m) < b) len++;
        if ((1ll<<len)*(a+1) > b) {
            cout << "-1\n";
            continue;
        }
        vector<ll> r = {a, a+m};
        while (r.size() < len+2) r.pb(2*r.back());
        for (int i = len-1; i >= 0; i--) {
            ll x = min(m-1, (r.back()-b)/(1ll<<i));
            if (x > 0) {
                ll k = 1ll<<i, j = r.size()-1;
                while (k > 0) r[j--] -= k*x, k /= 2;
                r[j] -= x;
            }
        }
        r.back() = b;
        cout << r.size();
        for (auto& x : r) cout << " " << x;
        cout << "\n";
    }
}