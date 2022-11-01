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
constexpr ll mod = 1000000007;
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
 
#define MAX_N 1010101
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
 
mi mod_pow(mi a, ll n) {
    mi ret = 1;
    mi tmp = a;
    while(n > 0) {
        if(n % 2) ret *= tmp;
        tmp = tmp * tmp;
        n /= 2;
    }
    return ret;
}
 
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n);
        vector<unordered_set<int>> a(n);
        REP(i, m) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].pb(v);
            a[u].insert(v);
            g[v].pb(u);
            a[v].insert(u);
        }
        vector<bool> used(n, false);
        vector<int> deg(n, 0);
        REP(i, n) {
            if((int)g[i].size() >= k - 1) {
                used[i] = true;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        REP(i, n) {
            if(!used[i]) continue;
            for(auto adj: g[i]) if(used[adj]) deg[i]++;
            q.push({deg[i], i});
        }

        REP(i, n) a[i].insert(i);

        vector<int> clq;
        while(!q.empty()) {
            int d = q.top().first;
            int p = q.top().second;
            q.pop();
            if(!used[p]) continue;
            if(d >= k) break;

            if(d == k - 1 && k * (k - 1) <= 2 * m) {
                bool ok = true;
                vector<int> v;
                for(auto adj: g[p]) {
                    if(used[adj]) v.pb(adj);
                }
                for(auto adj1: v) if(ok) for(auto adj2: v) {
                    if(a[adj1].count(adj2) == 0) {
                        ok = false;
                        break;
                    }
                }  
                if(ok) {
                    if(clq.empty()) {
                        clq.pb(p + 1);
                        for(auto adj: v) {
                            clq.pb(adj + 1);
                        }
                    }
                }
            }
            used[p] = false;
            for(auto adj: g[p]) {
                deg[adj]--;
                if(deg[adj] == k - 1 || deg[adj] == k - 2) q.push({deg[adj], adj});
            }
        }
        vector<int> ans;
        REP(i, n) if(used[i]) ans.pb(i + 1);
        if(clq.empty() && !ans.empty()) {
            cout << 1 << " " << (int)ans.size() << "\n";
            cout << ans << "\n";
        } else if(!clq.empty()) {
            cout << 2 << "\n";
            cout << clq << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}