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
// #define debug(...) 0
#else
// #include "../../debug.cpp"
#endif

ll qry(vector<ll> a) {
    cout << "?";
    for (ll x : a) cout << " " << x;
    cout << endl;
    ll r; cin >> r;
    return r-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);\
    ll n; cin >> n;
    vector<ll> p(n);
    ll y = n;
    for (int j = n-1; j >= 0; j--) {
        if (p[j]) continue;
        vector<array<ll, 2>> s;
        for (int x = 1; x <= n; x++) {
            vector<ll> a(n, 1);
            for (int i = 0; i < n; i++)
                if (p[i]) a[i] = n;
            a[j] += x;
            int r = x == n ? -1 : qry(a);
            if (r == -1) {
                p[j] = y-x+1;
                break;
            } else {
                s.pb({r, x});
            }
        }
        y -= s.size()+1;
        for (auto& [r, x] : s)
            p[r] = p[j]+x;
    }
    cout << "!";
    for (ll x : p) cout << " " << x;
    cout << endl;
}