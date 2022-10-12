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

const int N = 2e5+5;
int n, a[N], ld[N];
vector<int> adj[N];
mod ans = 0, dp[N], c[N];
unordered_map<int, mod> u[N];

vector<int> p_out;
vector<int>& unique_prime_factors(int x) {
    p_out.clear();
    while (x > 1) {
        int p = ld[x];
        p_out.push_back(p);
        while (x > 1 && x%p == 0)
            x /= p;
    }
    debug(x, p_out);
    return p_out;
}

void dfs(int i, int k) {
    int b = -1;
    for (int j : adj[i]) {
        if (j == k) continue;
        dfs(j, i);
        if (b == -1 || u[j].size() > u[b].size())
            b = j;
    }
    if (b == -1) {
        for (int p : unique_prime_factors(a[i])) {
            u[i][p] = 1;
            dp[i] += (c[p]-2) * (c[p]-1);
        }
    } else {
        dp[i] = dp[b];
        u[i] = move(u[b]);
        for (int j : adj[i]) {
            if (j == k || j == b) continue;
            for (auto& [p, x] : u[j]) {
                dp[i] -= (c[p]-2) * (c[p]-u[i][p]) * u[i][p];
                u[i][p] += x;
                dp[i] += (c[p]-2) * (c[p]-u[i][p]) * u[i][p];
            }
            u[j].clear();
        }
        for (int p : unique_prime_factors(a[i])) {
            dp[i] -= (c[p]-2) * (c[p]-u[i][p]) * u[i][p];
            u[i][p]++;
            dp[i] += (c[p]-2) * (c[p]-u[i][p]) * u[i][p];
        }
    }
    debug(i, dp[i], u[i]);
    ans += dp[i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; i++)
        if (ld[i] == 0)
            for (int j = i; j < N; j += i)
                ld[j] = i;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int p : unique_prime_factors(a[i]))
            c[p]++;
    }
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(0, 0);
    cout << ans/2 << "\n";
}