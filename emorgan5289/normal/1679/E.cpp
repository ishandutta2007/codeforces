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

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }

    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
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

    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
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
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};

using mod = modint<998244353>;

mod ans[18][1<<17];
mod pw[18][1005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i < n; i++)
        s = s.substr(0, 2*i-1)+'$'+s.substr(2*i-1, s.size());
    n = s.size();

    for (int i = 1; i <= 17; i++) {
        pw[i][0] = 1;
        for (int j = 1; j < 1005; j++)
            pw[i][j] = pw[i][j-1]*i;
    }

    ll mc = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '?') mc++;

    for (int i = 0; i < n; i++) {
        ll c = mc, x = 0;
        for (int j = s[i] == '$' ? 1 : 0; j < n; j += 2) {
            int l = i-j, r = i+j;
            if (l < 0 || r >= n) break;

            if (s[l] == '?') c--;
            if (l != r && s[r] == '?') c--;

            if (s[l] == '?' && s[r] == '?')
                c++;
            else if (s[l] == '?' && s[r] != '?')
                x |= 1ll<<(s[r]-'a');
            else if (s[l] != '?' && s[r] == '?')
                x |= 1ll<<(s[l]-'a');
            else if (s[l] != s[r])
                break;
            for (int k = 1; k <= 17; k++)
                ans[k][x] += pw[k][c];
        }
    }

    for (int i = 1; i <= 17; i++)
        for (int j = 0; j < 17; j++)
            for (int k = 0; k < 1<<17; k++)
                if (k&(1<<j)) ans[i][k] += ans[i][k^(1<<j)];

    ll q; cin >> q;
    while (q--) {
        string t; cin >> t;
        ll x = 0;
        for (auto& c : t)
            x |= 1ll<<(c-'a');
        cout << ans[t.size()][x] << "\n";
    }
}