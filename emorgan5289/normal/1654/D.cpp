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
const int N = 2e5+5; // upper bound on x, y
 
vector<vector<array<int, 3>>> adj;
vector<int> d; // d[x] = smallest divisor of x
vector<vector<int>> factors; // factors[x] = prime factors of x, including duplicates
vector<int> f, wf; // from editorial
mod ans = 0;
 
// compute wf
void dfs1(int i, int k) {
    for (auto& [j, x, y] : adj[i])
        if (j != k) {
            for (int p : factors[y]) f[p]--;
            for (int p : factors[x]) f[p]++, cmax(wf[p], f[p]);
            dfs1(j, i);
            for (int p : factors[y]) f[p]++;
            for (int p : factors[x]) f[p]--;
        }
}
 
// compute the amount of every ingredient, where p is the amount of ingredient i
void dfs2(int i, int k, mod p) {
    ans += p;
    mod tmp = p;
    for (auto& [j, x, y] : adj[i]) {
        if (j != k) {
            p = tmp;
            for (int q : factors[y]) p *= q;
            for (int q : factors[x]) p /= q;
            dfs2(j, i, p);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
 
    d.assign(N, 1);
    factors.resize(N);
    for (int i = N-1; i > 1; i--)
        for (int j = i; j < N; j += i)
            d[j] = i;
    for (int i = 1; i < N; i++)
        for (int x = i; x != 1; x /= d[x])
            factors[i].pb(d[x]);
 
    f.assign(N, 0);
    wf.assign(N, 0);
 
    while (t--) {
        int n; cin >> n;
 
        set<int> distinct_primes;
 
        adj.assign(n, {});
        for (int i = 0; i < n-1; i++) {
            int p, q, x, y; cin >> p >> q >> x >> y;
            p--, q--;
            adj[p].pb({q, x, y});
            adj[q].pb({p, y, x});
            for (int z : factors[x])
                distinct_primes.insert(z);
            for (int z : factors[y])
                distinct_primes.insert(z);
        }
 
        dfs1(0, 0);
        mod p = 1;
        for (int x : distinct_primes)
            for (int i = 0; i < wf[x]; i++)
                p *= x;
        ans = 0;
        dfs2(0, 0, p);
        cout << ans << "\n";
 
        for (int x : distinct_primes)
            f[x] = wf[x] = 0;
    }
}