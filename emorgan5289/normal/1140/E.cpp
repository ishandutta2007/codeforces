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

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
    modint& operator*=(const modint n) { v = reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = reduce(v*inv(n.v)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
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

using mod = modint<998244353>;

const int N = 2e5+5;
int a[N], b[N];
mod dp[N][2];

mod solve(int n, int k) {
    debug(vector(a, a+n));
    if (*max_element(a, a+n) == -1)
        return k*mod(k-1).pow(n-1);
    mod ans = 1;
    int r = 0, s = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) r++;
        else {
            if (s == -1) ans *= mod(k-1).pow(r);
            else ans *= dp[r][a[i] == s ? 1 : 0];
            s = a[i], r = 0;
        }
    }
    return ans*mod(k-1).pow(r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        if (i&1) cin >> a[i/2];
        else cin >> b[i/2];
    }
    dp[0][0] = 1, dp[0][1] = 0;
    for (int i = 1; i < N; i++) {
        dp[i][0] = (k-2)*dp[i-1][0]+dp[i-1][1];
        dp[i][1] = (k-1)*dp[i-1][0];
    }
    mod ans = solve(n/2, k);
    copy(b, b+N, a);
    cout << ans*solve(n/2+(n&1), k) << "\n";
}