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
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};

using mod = modint<int(1e9+7)>;

const int N = 1e6;
vector<vector<int>> digit(N, vector<int>(6));

template<typename T>
void transform(vector<T>& a) {
    for (int k = 0, x = 1; k < 6; k++, x *= 10)
        for (int i = N-1; i >= 0; i--)
            if (digit[i][k] != 0)
                a[i-x] += a[i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++) {
        string x = to_string(i);
        for (int j = 0; j < x.size(); j++)
            digit[i][x.size()-1-j] = x[j]-'0';
    }
    vector<ll> sum_0(N);
    vector<mod> sum_1(N), sum_2(N);
    for (int i = 0; i < n; i++) {
        sum_0[a[i]] += 1;
        sum_1[a[i]] += a[i];
        sum_2[a[i]] += a[i]*a[i];
    }
    transform(sum_0);
    transform(sum_1);
    transform(sum_2);
    vector<mod> g(N);
    for (int i = 0; i < N; i++) {
        g[i] = sum_2[i]+sum_1[i]*sum_1[i];
        g[i] *= mod(2).pow(sum_0[i]-2);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < (1<<6); j++) {
            bool ok = 1;
            int x = 1, y = 0, z = 1;
            for (int k = 0; k < 6; k++, x *= 10)
                if (j&(1<<k)) {
                    ok = ok && digit[i][k] != 9;
                    y += x, z *= -1;
                }
            if (ok)
                g[i] += g[i+y]*z;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++)
        ans ^= i*ll(g[i]);
    cout << ans << "\n";
}