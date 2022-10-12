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

using mod = modint<int(1e9+7)>;
const int K = 10, N = 1<<K;
mod a[2*N], p[K];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    p[0] = 65535;
    for (int i = 1; i < K; i++)
        p[i] = p[i-1]*p[i-1];

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        fill(a+N, a+2*N, 0);
        while (n--) {
            int x; cin >> x;
            a[N+x] = 1;
        }
        for (int i = K-1; i >= 0; i--)
            for (int j = 1<<i; j < 1<<(i+1); j++)
                a[j] = a[2*j]+p[K-1-i]*a[2*j+1];

        int ans = N;
        mod v = a[1];
        for (int x = 1; x < N; x++) {
            for (int i = 31-__builtin_clz(x^(x-1)); i >= 0; i--)
                for (int j = 1<<i; j < 1<<(i+1); j++)
                    a[j] = x&(1<<i) ? a[2*j+1]+p[K-1-i]*a[2*j] : a[2*j]+p[K-1-i]*a[2*j+1];
            if (a[1] == v) {
                int y = 0;
                for (int i = 0; i < K; i++)
                    if (x&(1<<i)) y |= N>>(i+1);
                cmin(ans, y);
            }
        }
        
        cout << (ans == N ? -1 : ans) << "\n";
    }
}