#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <set>
#include <random>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cassert>
#include <bits/stdc++.h>
#define FOR(i, n, m) for(ll i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = std::int_fast64_t;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
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

#define MAX_N 3030303
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

template< typename T >
struct edge {
    int src, to;
    T cost;
    
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
    
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    
    operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename G >
struct LowLink {
    const G &g;
    vector< int > used, ord, low;
    vector< int > articulation;
    vector< pair< int, int > > bridge;
    
    LowLink(const G &g) : g(g) {}
    
    int dfs(int idx, int k, int par) {
        used[idx] = true;
        ord[idx] = k++;
        low[idx] = ord[idx];
        bool is_articulation = false;
        int cnt = 0;
        for(auto &to : g[idx]) {
            if(!used[to]) {
                ++cnt;
                k = dfs(to, k, idx);
                low[idx] = min(low[idx], low[to]);
                is_articulation |= ~par && low[to] >= ord[idx];
                if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
            } else if(to != par) {
                low[idx] = min(low[idx], ord[to]);
            }
        }
        is_articulation |= par == -1 && cnt > 1;
        if(is_articulation) articulation.push_back(idx);
        return k;
    }
    
    virtual void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for(int i = 0; i < g.size(); i++) {
            if(!used[i]) k = dfs(i, k, -1);
        }
    }
};

template< typename G >
struct TwoEdgeConnectedComponents : LowLink< G > {
    using LL = LowLink< G >;
    vector< int > comp;
    
    TwoEdgeConnectedComponents(const G &g) : LL(g) {}
    
    int operator[](const int &k) {
        return comp[k];
    }
    
    void dfs(int idx, int par, int &k) {
        if(~par && this->ord[par] >= this->low[idx]) comp[idx] = comp[par];
        else comp[idx] = k++;
        for(auto &to : this->g[idx]) {
            if(comp[to] == -1) dfs(to, idx, k);
        }
    }
    
    void build(UnWeightedGraph &t) {
        LL::build();
        comp.assign(this->g.size(), -1);
        int k = 0;
        for(int i = 0; i < comp.size(); i++) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for(auto &e : this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
        }
    }
};

int n, m, s;
int nn, ss;
vector<int> sz;
vector<ll> sum;
vector<bool> ok;

bool dfs1(int v, int p, UnWeightedGraph& t) {
    if(sz[v] > 1) ok[v] = true;
    REP(i, t[v].size()) {
        if(t[v][i] == p) continue;
        ok[v] = ok[v] | dfs1(t[v][i], v, t);
    }
    return ok[v];
}

ll dfs2(int v, int p, UnWeightedGraph& t) {
    ll ret = 0;
    REP(i, t[v].size()) {
        if(t[v][i] == p) continue;
        ret = max(ret, dfs2(t[v][i], v, t));
    }
    if(!ok[v]) ret += sum[v];
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<ll> w(n);
    REP(i, n) cin >> w[i];
    UnWeightedGraph g(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    cin >> s;
    s--;
    TwoEdgeConnectedComponents<UnWeightedGraph> bcc(g);
    UnWeightedGraph t;
    bcc.build(t);
    nn = (int)t.size();
    ss = bcc[s];
    sz.assign(nn, 0);
    sum.assign(nn, 0);
    ok.resize(nn, false);
    REP(i, n) {
        sum[bcc[i]] += w[i];
        sz[bcc[i]]++;
    }
    dfs1(ss, -1, t);
    ll ans = 0;
    REP(i, nn) if(ok[i]) ans += sum[i];
    ans += dfs2(ss, -1, t);
    cout << ans << endl;
    return 0;
}