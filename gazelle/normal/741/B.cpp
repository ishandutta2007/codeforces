#include <bits/stdc++.h>
#define FOR(i, n, m) for(ll i = (n); i < (ll)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-6;
 
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    REP(i, v.size()) {
        if(i) os << " ";
        os << v[i];
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

using mi = modint;

ll mod_pow(ll a, ll n, ll m = mod) {
    ll ret = 1;
    ll tmp = a;
    while(n > 0) {
        if(n % 2) ret *= tmp;
        ret %= m;
        tmp = tmp * tmp;
        tmp %= m;
        n /= 2;
    }
    return ret % m;
}

constexpr int MAX_N = 1000000;
mi mod_fact  [MAX_N + 1];
mi mod_fact_i[MAX_N + 1];
mi mod_comb(long long n, long long k) {
    static bool initialized = false;
    if(n < 0 || k < 0 || n < k) return 0;
    if(not initialized) {
        mod_fact[0] = 1;
        for(int i = 1; i <= MAX_N; ++i) {
            mod_fact[i] = i * mod_fact[i - 1];
        }
        mod_fact_i[MAX_N] = mod_pow(mod_fact[MAX_N].n, mod - 2);
        for(int i = MAX_N - 1; i >= 0; --i) {
            mod_fact_i[i] = mod_fact_i[i + 1] * (i + 1);
        }
        initialized = true;
    }
    return mod_fact[n] * mod_fact_i[n - k] * mod_fact_i[k];
}

struct union_find {
    union_find(int n) : par_(n, -1) {}
    void init(int n) { par_.assign(n, -1); }
    int root(int x) { return par_[x] < 0 ? x : par_[x] = root(par_[x]); }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par_[x] < par_[y]) {
            par_[x] += par_[y];
            par_[y] = x;
        } else {
            par_[y] += par_[x];
            par_[x] = y;
        }
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par_[root(x)]; }
    vector<int> par_;
};
 
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, w;
    cin >> n >> m >> w;

    vector<int> ws_(n), bs_(n);
    REP(i, n) cin >> ws_[i];
    REP(i, n) cin >> bs_[i];

    int con = 0;

    union_find uf(n);

    REP(i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        uf.unite(x, y);
    }
    
    vector<vector<int>> hs__(n);
    vector<int> ws__(n, 0), bs__(n, 0);
    REP(i, n) {
        ws__[uf.root(i)] += ws_[i];
        bs__[uf.root(i)] += bs_[i];
        hs__[uf.root(i)].pb(i);
    }

    vector<int> ws, bs;
    vector<vector<int>> hs;

    REP(i, n) {
        if(ws__[i] == 0) continue;
        ws.pb(ws__[i]);
        bs.pb(bs__[i]);
        hs.pb(hs__[i]);
    }

    vector<int> dp(w + 1, 0);

    REP(i, bs.size()) {
        vector<int> ndp = dp;
        REP(j, w + 1) {
            if(j >= ws[i]) {
                ndp[j] = max(ndp[j], dp[j - ws[i]] + bs[i]);
            }
            for(auto elm: hs[i]) {
                if(j >= ws_[elm]) {
                    ndp[j] = max(ndp[j], dp[j - ws_[elm]] + bs_[elm]);
                }
            }
        }
        dp = ndp;
    }

    int ans = 0;

    REP(i, w + 1) ans = max(ans, dp[i]);

    cout << ans << endl;

    return 0;
}