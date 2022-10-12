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

using mod = modint<998244353>;
const int N = 1005;
mod dp[N][N][2];
int l[N], r[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string x, y; cin >> x >> y;
    int n = x.size(), m = y.size();
    x = "$"+x+"$", y = "$"+y+"$";
    mod ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j][0] = dp[i][j][1] = 1;
    for (int i = n+1; i > 0; i--)
        for (int j = m+1; j > 0; j--) {
            if (i <= n && x[i-1] != x[i]) dp[i][j][0] += dp[i+1][j][0];
            if (j <= m && x[i-1] != y[j]) dp[i][j][0] += dp[i][j+1][1];
            if (i <= n && y[j-1] != x[i]) dp[i][j][1] += dp[i+1][j][0];
            if (j <= m && y[j-1] != y[j]) dp[i][j][1] += dp[i][j+1][1];
            if (i <= n && j <= m) {
                l[i] = x[i] == x[i+1] ? 1 : l[i+1]+1;
                r[j] = y[j] == y[j+1] ? 1 : r[j+1]+1;
                ans += dp[i+1][j][0]+dp[i][j+1][1];
                ans -= l[i]+r[j];
            }
        }
    cout << ans << "\n";
}