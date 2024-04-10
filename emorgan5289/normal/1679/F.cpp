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

string bin(unsigned long long x) {
    string s(64, '0');
    for (int i = 63; x > 0; i--, x >>= 1)
        if (x&1) s[i] = '1';
    return s;
}

const int B = 10, N = 50005;
mod dp[2][1<<B];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<array<int, 2>> e(m);
    for (int i = 0; i < m; i++)
        cin >> e[i][0] >> e[i][1];
    array<int, B> u, v;
    for (int i = 0; i < B; i++)
        u[i] = v[i] = (1<<B)-1;
    for (auto& [x, y] : e) {
        u[x] &= ~(1<<y);
        u[y] &= ~(1<<x);
        v[max(x, y)] &= ~(1<<min(x, y));
    }
    array<vector<int>, B> t;
    for (int x = 0; x < 1<<B; x++)
        for (int j = 0; j < B; j++)
            if (x&(1<<j))
                t[j].pb(x);
    dp[0][(1<<B)-1] = 1;
    for (int i = 1; i <= n; i++) {
        fill(dp[1], dp[1]+(1<<B), 0);
        for (int j = 0; j < B; j++)
            for (int x : t[j])
                dp[1][(x|u[j])&v[j]] += dp[0][x];
        swap(dp[0], dp[1]);
    }
    mod ans = 0;
    for (int x = 0; x < 1<<B; x++)
        ans += dp[0][x];
    cout << ans << "\n";
}