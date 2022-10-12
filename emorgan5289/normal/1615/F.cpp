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

using mod = modint<int(1e9+7)>;

auto get_dp(string a, string b, ll n) {
    vector<vector<mod>> p(n+1, vector<mod>(2*n+3, 0));
    p[0][n+1] = 1;
    for (int i = 0; i < n; i++) {
        vector<mod> x(3);
        if (a[i] == '1' && b[i] == '1')
            x = {0, 1, 0};
        if (a[i] == '0' && b[i] == '0')
            x = {0, 1, 0};
        if (a[i] == '1' && b[i] == '0')
            x = {1, 0, 0};
        if (a[i] == '0' && b[i] == '1')
            x = {0, 0, 1};
        if (a[i] == '?' && b[i] == '1')
            x = {0, 1, 1};
        if (a[i] == '?' && b[i] == '0')
            x = {1, 1, 0};
        if (a[i] == '0' && b[i] == '?')
            x = {0, 1, 1};
        if (a[i] == '1' && b[i] == '?')
            x = {1, 1, 0};
        if (a[i] == '?' && b[i] == '?')
            x = {1, 2, 1};
        for (int j = 1; j <= 2*n+1; j++)
            p[i+1][j] = x[0]*p[i][j-1] + x[1]*p[i][j] + x[2]*p[i][j+1];
    }
    for (int i = 0; i <= n; i++) {
        p[i].erase(p[i].begin());
        p[i].pop_back();
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;
        for (int i = 0; i < n; i += 2) {
            if (a[i] != '?') a[i] ^= 1;
            if (b[i] != '?') b[i] ^= 1;
        }
        debug(a);
        debug(b);
        auto p = get_dp(a, b, n);
        reverse(all(a)), reverse(all(b));
        auto s = get_dp(a, b, n);
        reverse(all(a)), reverse(all(b));
        reverse(all(s));
        debug(p.size(), s.size());
        mod ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 2*n; j++) {
                debug(i, j-n, p[i][j], s[i][2*n-j]);
                ans += abs(j-n)*p[i][j]*s[i][2*n-j];
            }
        }
        cout << ans << "\n";
    }
}

// dp[i][j] = sum over all ways, on prefix of length i, with j stored up on the left (-n <= j <= n)