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

using ld = long double;

int n, m;
vector<vector<char>> g;
vector<vector<bool>> used;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int i, int j) {
    used[i][j] = true;
    REP(r, 4) {
        int ni = i + dx[r], nj = j + dy[r];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m
           && !used[ni][nj] && g[ni][nj] == '#') dfs(ni, nj);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    g.assign(n, vector<char>(m));
    used.assign(n, vector<bool>(m, false));
    REP(i, n) REP(j, m) cin >> g[i][j];
    int ans = 0;
    REP(i, n) REP(j, m) {
        if(!used[i][j] && g[i][j] == '#') {
            ans++;
            dfs(i, j);
        }
    }
    vector<bool> rw(n, true), cw(m, true);
    REP(i, n) REP(j, m) if(g[i][j] == '#') {
        rw[i] = false;
        cw[j] = false;
    }
    REP(i, n) {
        int l = -1, r = -1, sum = 0;
        REP(j, m) {
            if(g[i][j] == '.') continue;
            if(l == -1) l = j;
            r = j;
            sum++;
        }
        if(sum == 0) continue;
        if(r - l + 1 != sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    REP(i, m) {
        int l = -1, r = -1, sum = 0;
        REP(j, n) {
            if(g[j][i] == '.') continue;
            if(l == -1) l = j;
            r = j;
            sum++;
        }
        if(sum == 0) continue;
        if(r - l + 1 != sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    REP(i, n) {
        bool ok = false;
        REP(j, m) {
            if(g[i][j] == '#') ok = true;
            else if(rw[i] && cw[j]) ok = true;
        }
        if(!ok) {
            cout << -1 << endl;
            return 0;
        }
    }
    REP(i, m) {
        bool ok = false;
        REP(j, n) {
            if(g[j][i] == '#') ok = true;
            else if(rw[j] && cw[i]) ok = true;
        }
        if(!ok) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}