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
constexpr ll mod = 1000000007;
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

mi inc_sum(mi l, mi r) { return (l + r) * (r - l + 1) / 2; }

constexpr int OFFSET = 1e6 + 12;
ll w_num[2020202];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    mod_comb(1, 1);

    int m;
    cin >> m;

    vector<int> c(m);
    REP(i, m) cin >> c[i];

    // ap<int, int> w_num;

    REP(i, m) {
        int least = -(c[i] - 1), most = c[i] - 1;
        w_num[OFFSET + least] += 1;
        w_num[OFFSET + most + 2] -= 1;
    }

    mi val_ans = 0, cnt_ans = 1;
    ll sum = 0;

    for(ll i = -(1e6 + 10); i <= 1e6 + 10; i += 1) {
        w_num[OFFSET + i] += w_num[OFFSET + i - 2];
        val_ans += i * inc_sum(sum + 1, sum + w_num[OFFSET + i]);
        sum += w_num[OFFSET + i];
        cnt_ans *= mod_fact[w_num[OFFSET + i]];
    }

    cout << val_ans << " " << cnt_ans << endl;

    return 0;
}