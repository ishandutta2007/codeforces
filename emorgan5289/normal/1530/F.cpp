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

#define ll int

template<ll M>
struct modint {

    static ll _reduce(ll n) {
        return n%M;
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

#undef ll

using mod = modint<31607>;
// using mod = double;
const int N = 21;
int n;
mod a[N][N];
mod row[N][1<<N], dp[N][1<<N];

void dfs(int i, int j, int mask, mod val) {
    if (j == n) {
        row[i][mask] = val;
    } else {
        dfs(i, j+1, mask|(1<<j), val*(a[i][j]));
        dfs(i, j+1, mask, val);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<mod> prow(n, 1), pcol(n, 1), prow0(n, 1), pcol0(n, 1);
    // for (int i = 0; i < n; i++)
    //     fill(row[i], row[i]+(1<<n), 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] /= 10000;
            // a[i][j] *= 2;
            prow[i] *= a[i][j];
            pcol[j] *= a[i][j];
            prow0[i] *= 1-a[i][j];
            pcol0[j] *= 1-a[i][j];
            // row[i][1<<j] = a[i][j];
        }
    for (int x = 0; x < n; x++)
        dfs(x, 0, 0, 1);
    // p(superset of wins) * (-1)^#wins
    mod ans = 0;
    // no diags
    for (int m = 0; m < 1<<n; m++) {
        debug(m);
        mod r = 1;
        for (int j = 0; j < n; j++)
            if (m&(1<<j))
                r *= -pcol[j];

        // no diags
        mod f = 1;
        for (int j = 0; j < n; j++)
            f *= 1-row[j][m^((1<<n)-1)];
        ans += r*f;

        // main diag
        f = 1;
        for (int j = 0; j < n; j++) {
            if (m&(1<<j))
                f *= 1-row[j][m^((1<<n)-1)];
            else
                f *= a[j][j]-row[j][m^((1<<n)-1)];
        }
        ans -= r*f;

        // anti diag
        f = 1;
        for (int j = 0; j < n; j++) {
            if (m&(1<<(n-1-j)))
                f *= 1-row[j][m^((1<<n)-1)];
            else
                f *= a[j][n-1-j]-row[j][m^((1<<n)-1)];
        }
        ans -= r*f;

        // both diags
        f = 1;
        for (int j = 0; j < n; j++) {
            bool x = m&(1<<(j));
            bool y = m&(1<<(n-1-j));
            // debug(row[j][m^((1<<n)-1)]);
            if (x && y)
                f *= 1-row[j][m^((1<<n)-1)];
            else if (x && !y)
                f *= a[j][n-1-j]-row[j][m^((1<<n)-1)];
            else if (y && !x)
                f *= a[j][j]-row[j][m^((1<<n)-1)];
            else
                f *= (j == n-1-j ? a[j][j] : a[j][j]*a[j][n-1-j])-row[j][m^((1<<n)-1)];
        }
        // debug(f);
        ans += r*f;
    }
    cout << 1-ans << "\n";
}