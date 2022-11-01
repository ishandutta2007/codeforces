#include <bits/stdc++.h>
#define FOR(i, n, m) for(ll i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = std::int_fast64_t;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-15;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    REP(i, v.size()) {
        if(i) os << " ";
        os << to_string(v[i]);
    }
    return os;
}

struct modint {
    ll n;
public:
    modint(const ll n = 0) : n((n % mod + mod) % mod) {}
    static modint pow(modint a, int m) {
        modint r = 1;
        while(m > 0) {
            if(m & 1) { r *= a; }
            a = (a * a); m /= 2;
        }
        return r;
    }
    modint &operator++() { *this += 1; return *this; }
    modint &operator--() { *this -= 1; return *this; }
    modint operator++(int) { modint ret = *this; *this += 1; return ret; }
    modint operator--(int) { modint ret = *this; *this -= 1; return ret; }
    modint operator~() const { return (this -> pow(n, mod - 2)); } // inverse
    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.n == rhs.n;
    }
    friend bool operator<(const modint& lhs, const modint& rhs) {
        return lhs.n < rhs.n;
    }
    friend bool operator>(const modint& lhs, const modint& rhs) {
        return lhs.n > rhs.n;
    }
    friend modint &operator+=(modint& lhs, const modint& rhs) {
        lhs.n += rhs.n;
        if (lhs.n >= mod) lhs.n -= mod;
        return lhs;
    }
    friend modint &operator-=(modint& lhs, const modint& rhs) {
        lhs.n -= rhs.n;
        if (lhs.n < 0) lhs.n += mod;
        return lhs;
    }
    friend modint &operator*=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * rhs.n) % mod;
        return lhs;
    }
    friend modint &operator/=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * (~rhs).n) % mod;
        return lhs;
    }
    friend modint operator+(const modint& lhs, const modint& rhs) {
        return modint(lhs.n + rhs.n);
    }
    friend modint operator-(const modint& lhs, const modint& rhs) {
        return modint(lhs.n - rhs.n);
    }
    friend modint operator*(const modint& lhs, const modint& rhs) {
        return modint(lhs.n * rhs.n);
    }
    friend modint operator/(const modint& lhs, const modint& rhs) {
        return modint(lhs.n * (~rhs).n);
    }
};
istream& operator>>(istream& is, modint m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, modint m) { os << m.n; return os; }

#define MAX_N 10000001
long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
long long mod_inverse(long long a, long long m) {
    long long x, y;
    if(extgcd(a, m, x, y) == 1) return (m + x % m) % m;
    else return -1;
}
vector<long long> fact(MAX_N+1, inf);
long long mod_fact(long long n, long long& e) {
    if(fact[0] == inf) {
        fact[0]=1;
        if(MAX_N != 0) fact[1]=1;
        for(ll i = 2; i <= MAX_N; ++i) {
            fact[i] = (fact[i-1] * i) % mod;
        }
    }
    e = 0;
    if(n == 0) return 1;
    long long res = mod_fact(n / mod, e);
    e += n / mod;
    if((n / mod) % 2 != 0) return (res * (mod - fact[n % mod])) % mod;
    return (res * fact[n % mod]) % mod;
}
// return nCk
long long mod_comb(long long n, long long k) {
    if(n < 0 || k < 0 || n < k) return 0;
    long long e1, e2, e3;
    long long a1 = mod_fact(n, e1), a2 = mod_fact(k, e2), a3 = mod_fact(n - k, e3);
    if(e1 > e2 + e3) return 0;
    return (a1 * mod_inverse((a2 * a3) % mod, mod)) % mod;
}

using mi = modint;

mi mod_pow(ll a, ll n) {
    mi ret = 1;
    mi tmp = a;
    while(n > 0) {
        if(n % 2) ret *= tmp;
        tmp = tmp * tmp;
        n /= 2;
    }
    return ret;
}

class union_find {
public:
    union_find(int n)
        : par_(n, -1)
    {}
    void init(int n) {
        par_.assign(n, -1);
    }

    int root(int x) {
        return par_[x] < 0 ? x : par_[x] = root(par_[x]);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) {
            return false;
        } else {
            if(par_[x] < par_[y]) {
                par_[x] += par_[y];
                par_[y] = x;
            } else {
                par_[y] += par_[x];
                par_[x] = y;
            }
            return true;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return -par_[root(x)];
    }

private:
    std::vector<int> par_;
};

int mst(vector<vector<int>> g) {
    int n = (int)g.size();
    vector<pair<int, P>> e;
    REP(i, n) FOR(j, i + 1, n) {
        e.pb({g[i][j], {(int)i, (int)j}});
    }
    sort(ALL(e));
    union_find uf(n);
    int ans = 0;
    REP(i, e.size()) {
        int p = e[i].second.first, q = e[i].second.second;
        int c = e[i].first;
        if(!uf.same(p, q)) {
            uf.unite(p, q);
            ans += c;
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int mn = (int)g[0].size(), argmn = 0;
    FOR(i, 1, n) {
        if(mn > (int)g[i].size()) {
            mn = (int)g[i].size();
            argmn = i;
        }
    }
    int nn = n - (n - 1 - mn);
    vector<vector<int>> e(nn, vector<int>(nn, 0));
    set<int> st;
    st.insert(argmn);
    REP(i, n) {
        bool ok = true;
        REP(j, g[i].size()) if(g[i][j] == argmn) ok = false;
        if(ok) st.insert(i);
    }
    vector<int> v(n, -1);
    int c = 0;
    REP(i, n) {
        if(st.count(i)) continue;
        v[i] = c;
        c++;
        int k = 0;
        REP(j, g[i].size()) {
            if(st.count(g[i][j])) k++;
        }
        if(k == (int)st.size()) {
            e[v[i]][nn - 1] = 1;
            e[nn - 1][v[i]] = 1;
        }
    }
    REP(i, n) {
        if(v[i] == -1) continue;
        REP(j, g[i].size()) {
            if(v[g[i][j]] != -1) {
                e[v[i]][v[g[i][j]]] = 1;
                e[v[g[i][j]]][v[i]] = 1;
            }
        }
    }
    cout << mst(e) << endl;
    return 0;
}