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

const int N = 1e5+5;
ll a[N], b[N], w[N], t[70][70], tt[70], ans[N];
set<int> ps;
vector<int> p;

string bin(ll x) {
    string s = "";
    for (ll i = 1ll<<12; i > 0; i >>= 1)
        s += x&i ? '1' : '0';
    return s;
}
 
ll f(ll x, ll k) {
    ll i = 1, r = 0;
    for (ll j = 1; j < 1ll<<62; j <<= 1)
        if (k&j) r |= ((j&x) ? i : 0), i <<= 1;
    for (ll j = 1; j < 1ll<<62; j <<= 1)
        if ((~k)&j) r |= ((j&x) ? i : 0), i <<= 1;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll m = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], m ^= a[i];
    for (int i = 0; i < n; i++)
        b[i] = f(a[i], m);
    ll s = (1ll<<__builtin_popcountll(m))-1;
    for (ll k = 1ll<<62; k > 0; k /= 2) {
        ll i = max_element(b, b+n)-b;
        ll x = b[i];
        ps.insert(i);
        if ((s^x) > s) s = s^x;
        for (int j = 0; j < n; j++)
            if (b[j]&k) b[j] ^= x;
    }
    debug(s);
    for (auto& x : ps) p.pb(x);
    debug(p);
    for (int i = 0; i < p.size(); i++)
        b[i] = f(a[p[i]], m);
    s = (1ll<<__builtin_popcountll(m))-1;
    for (int i = 0; i < p.size(); i++)
        t[i][i] = 1;
    debug(vector(b, b+p.size()));
    for (ll k = 1ll<<62; k > 0; k /= 2) {
        ll i = max_element(b, b+p.size())-b;
        ll x = b[i];
        if ((s^x) > s) {
            s = s^x;
            debug(vector(b, b+p.size()), x);
            debug(i, vector(t[i], t[i]+p.size()));
            for (int l = 0; l < p.size(); l++)
                tt[l] ^= t[i][l];
        }
        for (int j = 0; j < p.size(); j++)
            if (b[j]&k) {
                debug(i, j);
                if (i != j) {
                    debug(vector(t[j], t[j]+p.size()));
                    debug(vector(t[i], t[i]+p.size()));
                    for (int l = 0; l < p.size(); l++)
                        t[j][l] ^= t[i][l];
                    debug(vector(t[j], t[j]+p.size()));
                }
                b[j] ^= x;
            }
        if (b[i]&k)
            for (int l = 0; l < p.size(); l++)
                t[i][l] = 0;
    }
    debug(s);
    ll x1 = 0, x2 = 0;
    debug(1^145, 145^245^666);
    for (int i = 0; i < p.size(); i++)
        if (tt[i]) ans[p[i]] = 1;
    for (int i = 0; i < n; i++) {
        if (ans[i]) x1 ^= a[i];
        else x2 ^= a[i];
    }
    debug(x1, x2, x1+x2);
    for (int i = 0; i < n; i++)
        cout << (ans[i] ? 1 : 2) << " \n"[i == n-1];
}