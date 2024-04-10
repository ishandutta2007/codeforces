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
        int n; cin >> n;
        vector<ll> f(n+1);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            f[x]++;
        }
        vector<int> p;
        ll c = 0;
        bool ok = 1;
        for (int i = 0; i <= n; i++) {
            cout << (ok ? c+f[i] : -1) << " \n"[i == n];
            if (f[i] == 0) {
                if (p.empty())
                    ok = 0;
                else {
                    c += i-p.back();
                    p.pop_back();
                }
            } else {
                f[i]--;
                while (f[i]--)
                    p.pb(i);
            }
        }
    }
}