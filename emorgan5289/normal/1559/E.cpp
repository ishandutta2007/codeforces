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

// computes mobius(i) for i from 0 to n in O(nlogn) time
vector<int> mobiussieve(int n) {
    vector<int> m(n+1, -1), p(n+1, 1);
    m[0] = 0, m[1] = 1;
    for (int i = 2; i <= n; i++)
        if (p[i]) for (int j = 2; j*i <= n; j++) {
            if (j%i) m[i*j] = m[i]*m[j];
            else m[i*j] = 0;
            p[i*j] = 0;
        }
    return m;
}

// given an array a of length n, returns an array b of length n-k+1
// such that b[i] = op(a[i], a[i+1], ..., a[i+k-1])
template<typename it1, typename it2, typename bin_op>
void sliding_window_fold(it1 first, it1 last, it2 result, int width, bin_op op) {
    int n = distance(first, last);
    vector p(first, last), s(first, last);
    for (int i = n-1; i >= 0; i--)
        if (i%width != width-1 && i != n-1) s[i] = op(s[i], s[i+1]);
    for (int i = 0; i < n; i++)
        if (i%width) p[i] = op(p[i], p[i-1]);
    for (int i = 0; i <= n-width; i++, result++)
        *result = i%width ? op(s[i], p[i+width-1]) : s[i];
}

// given an array a of length n, returns an array b of length n+k-1
// such that b[i] = op(a[i-k+1], a[i-k+2], ..., a[i]), not including invalid indices
template<typename it1, typename it2, typename bin_op>
void sliding_window_fold2(it1 first, it1 last, it2 result, int width, bin_op op) {
    int n = distance(first, last);
    vector p(first, last), s(first, last);
    for (int i = n-1; i >= 0; i--)
        if (i%width != width-1 && i != n-1) s[i] = op(s[i], s[i+1]);
    for (int i = 0; i < n; i++)
        if (i%width) p[i] = op(p[i], p[i-1]);
    for (int i = 0; i < width-1; i++, result++)
        *result = p[i];
    for (int i = 0; i <= n-width; i++, result++)
        *result = i%width ? op(s[i], p[i+width-1]) : s[i];
    int b = (n/width)*width;
    for (int i = n-width+1; i < n; i++, result++)
        *result = n%width && i < b ? op(s[i], p[n-1]) : s[i];
}

auto mu = mobiussieve(1e6+5);

mod solve(vector<ll> c, ll x) {
    if (x < 0) return 0;
    vector<mod> dp(x+1), tmp;
    dp[0] = 1;
    for (int i = 0; i < c.size(); i++) {
        tmp.clear();
        sliding_window_fold2(all(dp), back_inserter(tmp), min(x+1, c[i]+1), plus<mod>());
        tmp.resize(x+1);
        swap(dp, tmp);
    }
    return accumulate(all(dp), mod(0));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    mod ans = 0;
    for (int i = 1; i <= m; i++) {
        vector<ll> c(n);
        ll x = m/i;
        for (int j = 0; j < n; j++) {
            x -= (l[j]+i-1)/i;
            c[j] = r[j]/i-(l[j]+i-1)/i;
        }
        ans += mu[i]*solve(c, x);
    }
    cout << ans << "\n";
}