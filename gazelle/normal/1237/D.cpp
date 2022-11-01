#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <math.h>
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

template <typename T> struct segment_tree {
private:
    int n;
    const function<T(T, T)> op;
    const T ie;
    vector<T> seq;
    
public:
    segment_tree(int _n, function<T(T, T)> op, const T ie) : op(op), ie(ie) {
        n = 1;
        while(n < _n) n *= 2;
        seq.resize(2 * n - 1);
        for(int i = 0; i < 2 * n - 1; i++) seq[i] = ie;
    }
    
    void update(int k, const T e) {
        k += n - 1;
        seq[k] = e;
        while(k > 0) {
            k = (k - 1) / 2;
            seq[k] = op(seq[k * 2 + 1], seq[k * 2 + 2]);
        }
    }
    
    T get(int k) {
        k += n - 1;
        return seq[k];
    }
    
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r == -1) r = n;
        if(r <= a || b <= l) return ie;
        if(a <= l && r <= b) return seq[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return op(vl, vr);
    }
};
// segment_tree<ll> rsq(n, [] (ll a, ll b) { return a + b; }, 0)
// segment_tree<ll> rMq(n, [] (ll a, ll b) { return max(a, b); }, -1e18)
// segment_tree<ll> rmq(n, [] (ll a, ll b) { return min(a, b); }, 1e18)


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    REP(i, n) a[i] *= 2;
    set<ll> s;
    map<ll, int> m;
    ll mx = a[0], mn = a[0];
    REP(i, n) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        s.insert(a[i]);
        m[a[i]] = -1;
    }
    if(mx / 2 <= mn) {
        REP(i, n) {
            if(i) cout << " ";
            cout << -1;
        }
        cout << endl;
        return 0;
    }
    int c = 0;
    for(auto elm: s) {
        m[elm] = c;
        c++;
    }
    segment_tree<ll> rmq(n, [] (ll a, ll b) { return min(a, b); }, inf);
    vector<int> dp(3 * n);
    dp[3 * n - 1] = 3 * n;
    rmq.update(m[a[n - 1]], 3 * n - 1);
    for(int i = 3 * n - 2; i >= 0; i--) {
        auto ite = s.lower_bound(a[i % n] / 2);
        int th = m[*ite];
        dp[i] = min(dp[i + 1], (int)rmq.query(0, th));
        rmq.update(m[a[i % n]], i);
    }
    REP(i, n) {
        if(i) cout << " ";
        cout << dp[i] - i;
    }
    cout << endl;
    return 0;
}