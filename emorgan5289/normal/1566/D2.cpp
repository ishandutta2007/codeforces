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
        vector<ll> a(n*m), c(n*m, 0);
        for (int i = 0; i < n*m; i++)
            cin >> a[i];
        vector<ll> b(a); sort(all(b));
        auto cmp = [&](ll x, ll y) {
            return x%m < y%m;
        };
        map<ll, vector<ll>> s;
        for (int i = 0; i < n*m; i++)
            s[b[i]].pb(i);
        for (auto& [_, v] : s) {
            vector<ll> head, mid, tail;
            while (!v.empty() && v.back()%m != m-1)
                tail.pb(v.back()), v.pop_back();
            int j = 0;
            while (j < v.size() && v[j]%m != 0)
                head.pb(v[j++]);
            while (j < v.size())
                mid.pb(v[j++]);
            reverse(all(mid));
            reverse(all(head));
            v.clear();
            for (auto& x : head) v.pb(x);
            for (auto& x : mid) v.pb(x);
            for (auto& x : tail) v.pb(x);
            reverse(all(v));
            debug(v);
        }
        ll ans = 0;
        for (int i = 0; i < n*m; i++) {
            debug(i, s[a[i]]);
            int x = s[a[i]].back();
            s[a[i]].pop_back();
            debug(x);
            for (int j = m*(x/m); j < x; j++)
                if (c[j]) ans++;
            c[x] = 1;
        }
        cout << ans << "\n";
    }
}