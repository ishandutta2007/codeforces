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

int res;

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, -1));
    ans[0][0] = 1;
    ans[0][1] = 1;
    ans[n - 1][n - 1] = 0;
    if(query(0, 0, 1, 1)) ans[1][1] = 1;
    else ans[1][1] = 0;
    if(query(0, 1, 1, 2)) ans[1][2] = 1;
    else ans[1][2] = 0;
    if(query(1, 0, 1, 2)) ans[1][0] = ans[1][2];
    else ans[1][0] = !ans[1][2];
    REP(i, n) REP(j, n) {
        if(ans[i][j] != -1) continue;
        if(j == 0 || j == 1) {
            if(query(i - 2, j, i, j)) ans[i][j] = ans[i - 2][j];
            else ans[i][j] = !ans[i - 2][j];
        } else {
            if(query(i, j - 2, i, j)) ans[i][j] = ans[i][j - 2];
            else ans[i][j] = !ans[i][j - 2];
        }
    }
    bool neg = false;
    REP(i, n - 2) {
        if(ans[i][i] == 1 && ans[i + 1][i + 1] == 1 && ans[i + 2][i + 2] == 0) {
            if(ans[i][i + 1] == ans[i + 1][i + 2]) {
                if(query(i, i, i + 1, i + 2) != ans[i + 1][i + 2]) neg = true;
            } else if(ans[i + 1][i] == ans[i + 2][i + 1]) {
                if(query(i, i, i + 2, i + 1) != ans[i + 2][i + 1]) neg = true;
            } else if(ans[i][i + 1] != ans[i + 1][i]) {
                if(query(i, i, i + 1, i + 2) != ans[i + 1][i + 2]) neg = true;
            } else {
                if(query(i, i + 1, i + 2, i + 2) == ans[i][i + 1]) neg = true;
            }
            break;
        }
        if(ans[i][i] == 1 && ans[i + 1][i + 1] == 0 && ans[i + 2][i + 2] == 0) {
            if(ans[i][i + 1] == ans[i + 1][i + 2]) {
                if(query(i, i + 1, i + 2, i + 2) == ans[i][i + 1]) neg = true;
            } else if(ans[i + 1][i] == ans[i + 2][i + 1]) {
                if(query(i + 1, i, i + 2, i + 2) == ans[i + 1][i]) neg = true;
            } else if(ans[i][i + 1] != ans[i + 1][i]) {
                if(query(i, i + 1, i + 2, i + 2) == ans[i][i + 1]) neg = true;
            } else {
                if(query(i, i, i + 2, i + 1) != ans[i + 2][i + 1]) neg = true;
            }
            break;
        }
    }
    if(neg) {
        REP(i, n) REP(j, n) {
            if((i + j) % 2) ans[i][j] = !ans[i][j];
        }
    }
    cout << "!" << endl;
    REP(i, n) {
        REP(j, n) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}