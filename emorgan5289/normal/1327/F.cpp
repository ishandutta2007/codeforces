#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

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
    template<typename T> operator T() { return T(v); }

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
        if (k < 1) return k == 0 ? 1 : modint(inv(this->v)).pow(-k);
        return k&1 ? *this*(this->pow(k-1)) : (*this**this).pow(k>>1);
    }
};

using mod = modint<998244353>;

const int N = 5e5+5;
vector<array<int, 3>> q;
vector<array<int, 2>> a;
int n, k, m, f[N], p[N];
mod s[N], c;

mod solve() {
    fill(s, s+n+1, 0);
    c = s[0] = 1;
    fill(p, p+n, -1);
    for (auto& [l, r] : a)
        p[r] = max(p[r], l);
    for (int i = 1; i < n; i++)
        f[i] += f[i-1];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (!f[i]) s[i+1] += c, c *= 2;
        while (j <= p[i]) c -= s[j], s[j++] = 0;
        debug(vector(s, s+5), c);
    }
    debug(c);
    return c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int l, r, x; cin >> l >> r >> x;
        q.pb({l-1, r-1, x});
    }
    sort(all(q));
    mod ans = 1;
    for (int i = 0; i < k; i++) {
        a.clear();
        fill(f, f+n, 0);
        for (auto& [l, r, x] : q) {
            if (x&(1<<i)) f[l]++, f[r+1]--;
            else a.pb({l, r});
        }
        ans *= solve();
    }
    cout << ans << "\n";
}

// !f[i] -> (0) dp[i][j] -> dp[i+1][i+1]
// p[i+1] <= j -> (1) dp[i][j] -> dp[i+1][j]