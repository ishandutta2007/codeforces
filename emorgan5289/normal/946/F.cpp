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

    static ll reduce(ll n) {
        constexpr static ll b = -1ull/M;
        ll r = n-(ll)(__uint128_t(b)*n>>64)*M; return r >= M ? r-M : r;
    }

    static ll inv(ll n) {
        ll r = 1;
        for (ll k = M-2; k > 0; k >>= 1, n = reduce(n*n))
            if (k&1) r = reduce(r*n);
        return r;
    }

    ll v; modint(ll n = 0) : v(reduce(n)) { v += (M&0-(v<0)); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
    modint& operator*=(const modint n) { v = reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = reduce(v*inv(n.v)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        if (k < 1) return k == 0 ? modint(1) : modint(inv(this->v)).pow(-k);
        return k&1 ? *this*(this->pow(k-1)) : (*this**this).pow(k>>1);
    }
};

using mod = modint<int(1e9+7)>;
const int N = 105;
mod dp[N][N][N][4], f[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    string s; cin >> s; reverse(all(s));
    f[0] = f[1] = 2;
    for (int i = 2; i <= x; i++)
        f[i] = f[i-1]*f[i-2];
    for (int i = 0; i <= x; i++)
        for (int len = 1; len <= n; len++)
            for (int l = 0; l < n-len+1; l++) {
                int r = l+len-1;
                for (int b = 0; b < 4; b++) {
                    if (i < 2) dp[i][l][r][b] = (l == r && s[l]-'0' == i) ? 1 : 0;
                    else {
                        for (int k = l; k < r; k++) {
                            dp[i][l][r][b] += dp[i-2][l][k][b&2]*dp[i-1][k+1][r][b&1];
                            // debug(i, l, r, b);
                            // debug(i-2, l, l+k-1, b&2);
                            // debug(i-1, l+k, r, b&1);
                        }
                        dp[i][l][r][b] += dp[i-2][l][r][b]*((b&1) ? f[i-1] : 1);
                        dp[i][l][r][b] += dp[i-1][l][r][b]*((b&2) ? f[i-2] : 1);
                    }
                    // debug(i, l, r, b, dp[i][l][r][b]);
                }
            }
    cout << dp[x][0][n-1][3] << "\n";
}

// 0110

// 0
// 1
// 01
// 101
// 01101
// 10101101
// 0110110101101

// 13+10+3