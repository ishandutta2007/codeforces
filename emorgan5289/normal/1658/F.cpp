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

ll solve_one(string s, ll m) {
    ll n = s.size();
    ll c = 0;
    for (char x : s)
        if (x == '1') c++;
    c = (c*m)/n;
    for (int i = 0; i < m; i++)
        if (s[i] == '1') c--;
    for (int i = 0; i < n-m+1; i++) {
        if (c == 0)
            return i;
        if (i < n-m) {
            if (s[i] == '1') c++;
            if (s[i+m] == '1') c--;
        }
    }
    return -1;
}

bool solve_depth(string s, ll m, ll depth) {
    ll n = s.size();

    vector<ll> a = {m}, x;
    while (n%a.back() != 0)
        a.pb({n%a.back()});
    while (a.size() > depth) a.pop_back();

    reverse(all(a));
    for (ll w : a) {
        ll i = solve_one(s, w);
        if (i == -1)
            return 0;
        x.pb(i);
        if (w != s.size())
            s = s.substr(0, i) + s.substr(i+w);
    }
    reverse(all(x));

    ll sw = accumulate(all(a), 0ll);
    cout << "2\n" << x[0]+1 << " " << x[1] << "\n" << x[1]+sw-m+1 << " " << x[0]+sw << "\n";
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        string s; cin >> s;
        ll c = 0;
        for (char x : s)
            if (x == '1') c++;
        if ((c*m)%n != 0) {
            cout << "-1\n";
            continue;
        }

        ll ans = solve_one(s, m);
        if (ans != -1) {
            cout << "1\n" << ans+1 << " " << ans+m << "\n";
            continue;
        }

        for (int i = 2; i < 9999; i++)
            if (solve_depth(s, m, i)) break;
    }
}