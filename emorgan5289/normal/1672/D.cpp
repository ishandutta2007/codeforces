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
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        reverse(all(a)), reverse(all(b));
        map<ll, ll> sto;
        while(!a.empty()) {
            while (sto[a.back()] > 0) {
                a.pb(a.back());
                sto[a.back()]--;
            }
            if (a.back() == b.back()) {
                a.pop_back();
                b.pop_back();
            } else {
                ll x = a.back();
                while (a.back() == x)
                    sto[x]++, a.pop_back();
            }
            debug(a, b, sto);
        }
        cout << (b.empty() ? "YES" : "NO") << "\n";
    }
}