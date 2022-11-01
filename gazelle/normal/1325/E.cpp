#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
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
constexpr ll mod = 1000000007;
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

ll tonum(vector<int>& v, int l = 0, int r = 31) {
    ll ret = 0, tmp = 1;
    for(int i = l; i < r; i++) {
        ret += tmp * v[i];
        tmp *= 3;
    }
    return ret;
}

vector<bool> bl;
vector<vector<int>> g;
int n, m;

int solve1(int s) {
    vector<int> dist(m, inf);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(auto adj: g[p]) {
            if(dist[adj] == inf) {
                dist[adj] = dist[p] + 1;
                q.push(adj);
            }
        }
    }
    vector<int> v;
    REP(i, m) {
        if(bl[i] && dist[i] != inf) {
            v.pb(dist[i]);
        }
    }
    if((int)v.size() <= 1) return inf;
    sort(ALL(v));
    return v[0] + v[1] + 2;
}

int solve2(int s) {
    vector<vector<int>> dist(2, vector<int>(m, inf));
    dist[0][s] = 0;
    queue<pair<int, int>> q;
    q.push({s, 0});
    while(!q.empty()) {
        int p = q.front().first, t = q.front().second;
        q.pop();
        for(auto adj: g[p]) {
            if(dist[0][adj] < dist[0][p]) continue;
            if(dist[t][p] + 1 <= dist[0][adj] && dist[t][p] + 1 < dist[1][adj]) {
                bool b = dist[t][p] + 1 < dist[0][adj];
                dist[1][adj] = dist[0][adj];
                dist[0][adj] = dist[t][p] + 1;
                if(b) q.push({adj, 0});
                q.push({adj, 1});
            } else if(dist[t][p] + 1 < dist[1][adj]) {
                dist[1][adj] = dist[t][p] + 1;
                q.push({adj, 1});
            }
        }
    }
    int ret = inf;
    REP(i, m) {
        ret = min(ret, dist[0][i] + dist[1][i]);
    }
    return ret;
}

bool used[1000001];
int dict[1000001];
vector<int> prim;
int main() {
    for(int i = 2; i <= 1000000; i++) {
        if(!used[i]) {
            prim.pb(i);
            for(int j = 1; i * j <= 1000000; j++) {
                used[i * j] = true;
            }
        }
    }
    m = (int)prim.size();
    REP(i, m) {
        dict[prim[i]] = i;
    }
    set<pair<int, int>> edge;
    bl.assign(m, 0);
    cin >> n;
    int ans = inf;
    REP(i, n) {
        int a;
        cin >> a;
        int x = -1, y = -1;
        for(int j = 2; j * j <= a; j++) {
            int c = 0;
            while(a % j == 0) {
                c++;
                a /= j;
            }
            if(c % 2) {
                if(x == -1) x = j;
                else y = j;
            }
        }
        if(a != 1) {
            if(x == -1) x = a;
            else y = a;
        }
        if(x == -1) {
            ans = min(ans, 1);
            continue;
        }
        if(y == -1) {
            if(bl[dict[x]]) {
                ans = min(ans, 2);
            } else {
                bl[dict[x]] = 1;
            }
        } else {
            if(x > y) swap(x, y);
            if(edge.count({dict[x], dict[y]})) {
                ans = min(ans, 2);
            } else {
                edge.insert({dict[x], dict[y]});
            }
        }
    }
    g.resize(m);
    for(auto elm: edge) {
        g[elm.first].pb(elm.second);
        g[elm.second].pb(elm.first);
    }
    REP(i, m) {
        if(prim[i] > 1000) continue;
        ans = min(ans, solve1(i));
        ans = min(ans, solve2(i));
    }
    if(ans != inf) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}