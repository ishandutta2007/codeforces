
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
const int N = 23;
int tmp[1<<N], a[26][N];
mod f[1<<N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s) a[c-'a'][i]++;
    }
    fill(f, f+(1<<N), 1);

    for (int i = 0; i < 26; i++) {
        fill(tmp, tmp+(1<<N), inf);
        for (int j = 1; j < 1<<n; j++) {
            int x = j & -j;
            tmp[j] = min(tmp[j-x], a[i][__builtin_ctz(x)]+1);
            f[j] *= tmp[j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1<<n; j++)
            if (j&(1<<i)) f[j^(1<<i)] -= f[j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1<<n; j++)
            if (j&(1<<i)) f[j] += f[j^(1<<i)];

    vector<ll> w(1<<n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1<<n; j++)
            if (j&(1<<i)) w[j] += i+1;
    ll ans = 0;
    for (int i = 0; i < 1<<n; i++)
        ans ^= ll(f[(1<<n)-1]-f[(1<<n)-1-i])*__builtin_popcount(i)*w[i];
    cout << ans << "\n";
}