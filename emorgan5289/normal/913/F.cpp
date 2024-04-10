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

    ll v; modint(ll n = 0) : v(_reduce(n)) { v += (M&(0-(v<0))); }
    
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
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};

using mod = modint<998244353>;
// using mod = long double;
const int N = 2005;

mod ppow[N*N], p1pow[N*N];
mod rpow[N*N];
mod f[N*N];

mod psum_dp[N][N];
// [i][j] = sum of (p/(1-p))^sum(x) for all subsets x of the first i nonnegative integers, having size j

mod scc_dp[N];
// [i] = probability of a random graph with n nodes being strongly connected

mod dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, a, b; cin >> n >> a >> b;
    mod p = mod(a)/b, r = p/(1-p);
    ppow[0] = p1pow[0] = 1;
    rpow[0] = 1;
    f[0] = 1;
    for (int i = 1; i <= n*n; i++) {
        ppow[i] = ppow[i-1]*p;
        p1pow[i] = p1pow[i-1]*(1-p);
        rpow[i] = rpow[i-1]*r;
        f[i] = f[i-1]*i;
    }
    psum_dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        psum_dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            psum_dp[i][j] = rpow[i-j]*psum_dp[i-1][j-1]+psum_dp[i-1][j];
            debug(i, j, psum_dp[i][j]);
        }
    }
    scc_dp[0] = scc_dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        scc_dp[i] = 1;
        for (int j = 1; j < i; j++) {
            scc_dp[i] -= scc_dp[j]*p1pow[j*(i-j)]*psum_dp[i][j];
        }
    }
    debug(vector(scc_dp, scc_dp+n));
    for (int i = 2; i <= n; i++) {
        mod y = 0, z = 0;
        for (int j = 1; j <= i; j++) {
            debug(scc_dp[j], p1pow[j*(i-j)], psum_dp[i][j], rpow[j*(j-1)/2]);
            mod prob = scc_dp[j]*p1pow[j*(i-j)]*psum_dp[i][j];
            if (i == j) z = prob;
            mod cont = (j == i ? 0 : dp[j])+dp[i-j]+j*(i-j)+j*(j-1)/2;
            debug(i, j, prob, cont, prob*cont);
            y += prob*cont;
        }
        debug(y, z);
        dp[i] = y/(1-z);
    }
    debug(vector(dp, dp+n+1));
    cout << dp[n] << "\n";
}