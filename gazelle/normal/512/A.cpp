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

ll mod_pow(ll a, ll n, ll m) {
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
 
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<int> min_match(string a, string b) {
    int n = a.length(), m = b.length();

    vector<vector<int>> next(n, vector<int>(26, n));

    for(int i = n - 2; i >= 0; --i) {
        REP(j, 26) next[i][j] = next[i + 1][j];
        next[i][a[i + 1] - 'a'] = i + 1;
    }

    vector<int> match(m, n);
    int pos = 0;
    
    REP(i, m) {
        if(pos == n) break;
        if(a[pos] != b[i]) {
            pos = next[pos][b[i] - 'a'];
            --i;
            continue;
        }
        match[i] = pos;
        ++pos;
    }

    return match;
}

vector<vector<int>> g(26, vector<int>(26, 0));
vector<string> str;
string ans = "";
vector<int> used(26, 0);

void lexify(int l, int r, int d) {
    if(r - l <= 1) return;
    if(str[l].size() < d) {
        lexify(l + 1, r, d);
        return;
    }

    int ll = l;

    for(int i = l + 1; i < r; ++i) {
        if(str[i].size() < d) {
            cout << "Impossible" << endl;
            exit(0);
        }
        if(str[i][d - 1] != str[i - 1][d - 1]) {
            g[str[i][d - 1] - 'a'][str[i - 1][d - 1] - 'a'] = 1;
            lexify(ll, i, d + 1);
            ll = i;
        }
    }

    lexify(ll, r, d + 1);
}

void toposo(int v) {
    if(used[v] == 2) return;
    if(used[v] == 1) {
        cout << "Impossible" << endl;
        exit(0);
    }

    used[v] = 1;

    REP(i, 26) {
        if(g[v][i]) toposo(i);
    }

    ans += 'a' + v;
    used[v] = 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    str.resize(n);
    REP(i, n) cin >> str[i];

    lexify(0, n, 1);
    REP(i, 26) toposo(i);

    cout << ans << endl;

    return 0;
}