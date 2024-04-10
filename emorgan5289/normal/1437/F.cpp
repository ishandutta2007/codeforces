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

const int N = 5555;
ll a[N], p[N];
mod dp[N][N], f[N], pre[N][2*N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i-1]*i;
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    p[0] = -1;
    fill(p+1, p+N, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[j]*2 <= a[i]) p[i] = j;
    if (p[n] < n-1) cout << "0\n", exit(0);
    pre[0][N+1] = dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int x = n; x >= 0; x--) {
            dp[i][x] = x <= p[i] ? pre[p[i]][x-p[i]+1+N]*f[x] + dp[i][x+1] : mod(0);
            pre[i][x-p[i]+N] = pre[i-1][x-p[i]+N] + dp[i][x]/f[x];
        }
    }
    cout << dp[n][0] << "\n";
}