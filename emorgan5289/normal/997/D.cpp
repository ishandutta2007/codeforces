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

vector<mod> solve(vector<vector<int>> a, int n, int k) {
    debug(a, n, k);
    vector<mod> out(k+1, 0);
    vector<vector<mod>> dp(n, vector<mod>(k+1, 0));
    vector<vector<mod>> tmp(n, vector<mod>(k+1, 0));
    function<void(int, int)> dfs1, dfs2, shift;
    auto redo = [&](int i) {
        fill(all(dp[i]), 0);
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            for (int l = 0; l < j; l++)
                dp[i][j] += dp[i][l]*tmp[i][j-l];
        }
    };
    dfs1 = [&](int i, int p) {
        tmp[i][0] = 1;
        for (int j : a[i])
            if (j != p) {
                dfs1(j, i);
                for (int l = 2; l <= k; l++)
                    tmp[i][l] += dp[j][l-2];
            }
        redo(i);
    };
    shift = [&](int x, int y) {
        for (int l = 2; l <= k; l++)
             tmp[x][l] -= dp[y][l-2];
        redo(x);
        for (int l = 2; l <= k; l++)
             tmp[y][l] += dp[x][l-2];
        redo(y);
    };
    dfs2 = [&](int i, int p) {
        debug(i, dp[i]);
        for (int j = 0; j <= k; j++)
            out[j] += dp[i][j];
        for (int j : a[i])
            if (j != p) {
                shift(i, j);
                dfs2(j, i);
                shift(j, i);
            }
    };
    dfs1(0, 0), dfs2(0, 0);
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<int>> a(n), b(m);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        a[x].pb(y), a[y].pb(x);
    }
    for (int i = 0; i < m-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        b[x].pb(y), b[y].pb(x);
    }
    auto p = solve(a, n, k), q = solve(b, m, k);
    mod ans = 0;
    vector<mod> f(k+1); f[0] = 1;
    for (int i = 1; i <= k; i++)
        f[i] = f[i-1]*i;
    for (int i = 0; i <= k; i++)
        ans += f[k]/f[i]/f[k-i]*p[i]*q[k-i];
    cout << ans << "\n";
}