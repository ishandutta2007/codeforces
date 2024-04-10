#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <random>
#include <iomanip>
#include <bitset>
#define FOR(i, n, m) for(ll i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-9;
 
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
    std::vector<int> zero_;
    std::vector<int> goal_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    REP(i, m) cin >> d[i];
    sort(ALL(d));
    if(d.back() != n) {
        d.pb(n);
        m++;
    }
    int g, r;
    cin >> g >> r;
    vector<int> cost(m * (g + 1), inf);
    deque<int> dq;
    if(d.front() > g) {
        cout << -1 << endl;
        return 0;
    }
    dq.pb(g - d[0]);
    cost[g - d[0]] = 0;
    while(!dq.empty()) {
        int pos = dq.front() / (g + 1);
        int rem = dq.front() % (g + 1);
        dq.pop_front();
        if(rem == 0) {
            if(cost[pos * (g + 1) + g] == inf) {
                cost[pos * (g + 1) + g] = cost[pos * (g + 1)] + 1;
                dq.pb(pos * (g + 1) + g);
            }
            continue;
        }
        if(pos) {
            if(d[pos] - d[pos - 1] <= rem && cost[(pos - 1) * (g + 1) + rem - (d[pos] - d[pos - 1])] == inf) {
                cost[(pos - 1) * (g + 1) + rem - (d[pos] - d[pos - 1])] = cost[pos * (g + 1) + rem];
                dq.push_front((pos - 1) * (g + 1) + rem - (d[pos] - d[pos - 1]));
            }
        }
        if(pos < m - 1) {
            if(d[pos + 1] - d[pos] <= rem && cost[(pos + 1) * (g + 1) + rem - (d[pos + 1] - d[pos])] == inf) {
                cost[(pos + 1) * (g + 1) + rem - (d[pos + 1] - d[pos])] = cost[pos * (g + 1) + rem];
                dq.push_front((pos + 1) * (g + 1) + rem - (d[pos + 1] - d[pos]));
            }
        }
    }
    ll ans = inf * inf;
    REP(i, g + 1) {
        if(cost[(m - 1) * (g + 1) + i] == inf) continue;
        else ans = min(ans, (g + r) * cost[(m - 1) * (g + 1) + i] + g - i);
    }
    if(ans == inf * inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}