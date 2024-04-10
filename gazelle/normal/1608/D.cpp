#include <bits/stdc++.h>
#define FOR(i, n, m) for(long long i = (n); i < (long long)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr ld eps = 1e-6;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
    REP(i, v.size()) {
        if(i)
            os << " ";
        os << v[i];
    }
    return os;
}

struct modint {
    long long n;

  public:
    modint(const long long n = 0) : n((n % mod + mod) % mod) {}
    static modint pow(modint a, int m) {
        modint r = 1;
        while(m > 0) {
            if(m & 1) {
                r *= a;
            }
            a = (a * a);
            m /= 2;
        }
        return r;
    }
    modint &operator++() {
        *this += 1;
        return *this;
    }
    modint &operator--() {
        *this -= 1;
        return *this;
    }
    modint operator++(int) {
        modint ret = *this;
        *this += 1;
        return ret;
    }
    modint operator--(int) {
        modint ret = *this;
        *this -= 1;
        return ret;
    }
    modint operator~() const { return (this->pow(n, mod - 2)); } // inverse
    friend bool operator==(const modint &lhs, const modint &rhs) {
        return lhs.n == rhs.n;
    }
    friend bool operator<(const modint &lhs, const modint &rhs) {
        return lhs.n < rhs.n;
    }
    friend bool operator>(const modint &lhs, const modint &rhs) {
        return lhs.n > rhs.n;
    }
    friend modint &operator+=(modint &lhs, const modint &rhs) {
        lhs.n += rhs.n;
        if(lhs.n >= mod)
            lhs.n -= mod;
        return lhs;
    }
    friend modint &operator-=(modint &lhs, const modint &rhs) {
        lhs.n -= rhs.n;
        if(lhs.n < 0)
            lhs.n += mod;
        return lhs;
    }
    friend modint &operator*=(modint &lhs, const modint &rhs) {
        lhs.n = (lhs.n * rhs.n) % mod;
        return lhs;
    }
    friend modint &operator/=(modint &lhs, const modint &rhs) {
        lhs.n = (lhs.n * (~rhs).n) % mod;
        return lhs;
    }
    friend modint operator+(const modint &lhs, const modint &rhs) {
        return modint(lhs.n + rhs.n);
    }
    friend modint operator-(const modint &lhs, const modint &rhs) {
        return modint(lhs.n - rhs.n);
    }
    friend modint operator*(const modint &lhs, const modint &rhs) {
        return modint(lhs.n * rhs.n);
    }
    friend modint operator/(const modint &lhs, const modint &rhs) {
        return modint(lhs.n * (~rhs).n);
    }
};
istream &operator>>(istream &is, modint m) {
    is >> m.n;
    return is;
}
ostream &operator<<(ostream &os, modint m) {
    os << m.n;
    return os;
}

using mi = modint;

long long mod_pow(__int128 a, __int128 n, __int128 m = mod) {
    __int128 ret = 1;
    __int128 tmp = a;
    while(n > 0) {
        if(n % 2)
            ret *= tmp;
        ret %= m;
        tmp = tmp * tmp;
        tmp %= m;
        n /= 2;
    }
    return ret % m;
}

constexpr int MAX_N = 2020202;
mi mod_fact[MAX_N + 1];
mi mod_fact_i[MAX_N + 1];
mi mod_comb(long long n, long long k) {
    static bool initialized = false;
    if(n < 0 || k < 0 || n < k)
        return 0;
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    pair<int, int> wdeg = {0, 0}, bdeg = {0, 0}, un = {0, 0};
    mi error = 1;
    int w = 0, b = 0;
    cin >> n;
    REP(i, n) {
        string str;
        cin >> str;
        if(str[1] == 'W')
            str[1] = 'B';
        else if(str[1] == 'B')
            str[1] = 'W';
        if(str[0] != '?' && str[1] != '?' && str[0] != str[1])
            error = 0;
        if(str[0] == '?' && str[1] == '?')
            error *= 2;

        if(str[0] == 'W') {
            wdeg.first += 1;
            w += 1;
        }
        if(str[1] == 'W') {
            wdeg.second += 1;
            w += 1;
        }
        if(str[0] == 'B') {
            bdeg.first += 1;
            b += 1;
        }
        if(str[1] == 'B') {
            bdeg.second += 1;
            b += 1;
        }
        if(str[0] == '?')
            un.first += 1;
        if(str[1] == '?')
            un.second += 1;
    }
    if(w == 0 || b == 0)
        error -= 1;
    if(w == 0 && b == 0)
        error -= 1;
    mi ans = 0;
    REP(i, n + 1) {
        mi tmp = mod_comb(un.first, i - bdeg.first) *
                 mod_comb(un.second, i - bdeg.second);
        ans += tmp;
        //cout << i << " " << ans << endl;
    }

    cout << ans - error << endl;

    return 0;
}