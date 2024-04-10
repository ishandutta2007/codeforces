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

template<ll M>
struct modint {

    static ll _reduce(ll n) {
        constexpr static ll b = -1ull/M;
        ll r = n-(ll)(__uint128_t(b)*n>>64)*M; return r >= M ? r-M : r;
    }

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = _reduce(n*n))
            if (k&1) r = _reduce(r*n);
        return r;
    }

    ll v; modint(ll n = 0) : v(_reduce(n)) { v += (M&0-(v<0)); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
    modint& operator*=(const modint n) { v = _reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = _reduce(v*_pow(n.v, M-2)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const { return _pow(v, k); }
    modint inv() const { return _pow(v, M-2); }
};

using mod = modint<int(1e9+7)>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<ll> f(m), h(m);
    vector<ll> l(m, -1), r(m, -1);
    for (int i = 0; i < m; i++) {
        cin >> f[i] >> h[i];
        ll x = 0;
        for (int j = 0; j < n; j++)
            if (s[j] == f[i] && ++x == h[i])
                l[i] = j;
        x = 0;
        for (int j = n-1; j >= 0; j--)
            if (s[j] == f[i] && ++x == h[i])
                r[i] = j;
    }
    ll ans = 0;
    mod cnt = 0;
    // at least one comes from left
    for (int i = 0; i < m; i++) {
        if (l[i] == -1) continue;
        ll x = 1;
        mod y = 1;
        vector<ll> frl(n+1), frr(n+1), frb(n+1);
        for (int j = 0; j < m; j++) {
            if (j != i && l[j] != -1) {
                bool ok_l = f[i] != f[j] && l[j] < l[i];
                bool ok_r = r[j] > l[i];
                if (ok_l && ok_r) frb[f[j]]++;
                else if (ok_l) frl[f[j]]++;
                else if (ok_r) frr[f[j]]++;
            }
        }
        for (int j = 0; j <= n; j++) {
            ll z = 0;
            if (frl[j]+frb[j] > 0) z++;
            if (frr[j]+frb[j] > 0) z++;
            if (frb[j] == 1 && frl[j] == 0 && frr[j] == 0) z--;
            x += z;
            if (z == 1)
                y *= frl[j] + frr[j] + 2*frb[j];
            if (z == 2)
                y *= frl[j]*frr[j] + frl[j]*frb[j] + frr[j]*frb[j] + frb[j]*(frb[j]-1);
        }
        debug(i, x, y);
        if (x > ans)
            ans = x, cnt = 0;
        if (x == ans)
            cnt += y;
    }
    // all come from right
    vector<ll> fr(n+1);
    for (int i = 0; i < m; i++)
        if (l[i] != -1) fr[f[i]]++;
    ll x = 0;
    mod y = 1;
    for (int i = 0; i <= n; i++) {
        if (fr[i] > 0) x++, y *= fr[i];
    }
    debug(x, y);
    if (x > ans)
        ans = x, cnt = 0;
    if (x == ans)
        cnt += y;
    cout << ans << " " << cnt << "\n";
}