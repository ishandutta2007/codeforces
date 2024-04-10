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

ll solve(vector<pair<ll, int>>& gems, vector<int>& perm) {
    int n = (int)gems.size();
    vector<ll> lnear(n, -1), rnear(n, -1);
    REP(i, n) {
        if(i) lnear[i] = lnear[i - 1];
        if(gems[i].second == perm[0]) lnear[i] = gems[i].first;
    }
    for(ll i = n - 1; i >= 0; i--) {
        if(i < n - 1) rnear[i] = rnear[i + 1];
        if(gems[i].second == perm[2]) rnear[i] = gems[i].first;
    }
    ll ret = 3LL * inf * inf + 5LL;
    REP(i, n) {
        if(gems[i].second == perm[1] && lnear[i] != -1 && rnear[i] != -1) {
            ll w = gems[i].first;
            ll tmp = (w - lnear[i]) * (w - lnear[i]);
            tmp += (rnear[i] - w) * (rnear[i] - w);
            tmp += (lnear[i] - rnear[i]) * (lnear[i] - rnear[i]);
            ret = min(ret, tmp);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    REP(testcase, t) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        vector<pair<ll, int>> gems;
        REP(i, n0) {
            ll w; cin >> w;
            gems.pb({w, 0});
        }
        REP(i, n1) {
            ll w; cin >> w;
            gems.pb({w, 1});
        }
        REP(i, n2) {
            ll w; cin >> w;
            gems.pb({w, 2});
        }
        sort(ALL(gems));
        vector<int> perm = {0, 1, 2};
        ll ans = 3LL * inf * inf + 5LL;
        do {
            ans = min(ans, solve(gems, perm));
        } while(next_permutation(ALL(perm)));
        cout << ans << "\n";
    }
    return 0;
}