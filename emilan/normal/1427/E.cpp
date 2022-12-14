#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

vt<string> ans;
ll pl(ll x, ll y) {
    ans.push_back(to_string(x) + " + " + to_string(y));
    return x + y;
}
ll xo(ll x, ll y) {
    ans.push_back(to_string(x) + " ^ " + to_string(y));
    return x ^ y;
}
ll f(ll x) { 
    ll x2 = pl(x, x),
       x3 = pl(x, x2);
    return pl(x3, xo(x, x2));
}
ll g(ll x) {
    ll xf = f(x),
       x4 = pl(x, x * 3);
    return xo(x4, xf);
}
int pcnt(ll x) { return __builtin_popcountll(x); }
int lsb(ll x) { return __builtin_ctzll(x); }

void solve() {
    ll x;
    cin >> x;
    ll y = x, z = x;
    for (int i = 0; i < 19 && x != 1; i++) {
        z = g(y);
        y = f(y);
        if (lsb(x ^ 1) == lsb(z)) x = xo(x, z);
    }

    while (x != 1) {
        if (x & z) x = xo(x, z);
        z = pl(z, z);
    }

    cout << sz(ans) << '\n';
    for (auto s : ans) cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}