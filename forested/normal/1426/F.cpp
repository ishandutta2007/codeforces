// Template
#include "bits/stdc++.h"
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T>
inline bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T> 
inline bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
struct IOSET {
    IOSET() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} ioset;

// Mod-Int
template <int MOD> // MOD > 1
struct ModInt {
    long long val;
    ModInt() = default;
    ModInt(long long x) : val(x % MOD + (x < 0 ? MOD : 0)) {}
    ModInt<MOD> &operator+= (const ModInt<MOD> &x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt<MOD> &operator-= (const ModInt<MOD> &x) {
        if ((val -= x.val) < 0) val += MOD; 
        return *this;
    }
    ModInt<MOD> &operator*= (const ModInt<MOD> &x) {
        (val *= x.val) %= MOD; return *this;
    }
    ModInt<MOD> operator+ (const ModInt<MOD> &x) const {
        return ModInt(*this) += x;
    }
    ModInt<MOD> operator- (const ModInt<MOD> &x) const {
        return ModInt(*this) -= x;
    }
    ModInt<MOD> operator* (const ModInt<MOD> &x) const {
        return ModInt(*this) *= x;
    }
    ModInt<MOD> pow(long long t) const {
        assert(t >= 0);
        ModInt<MOD> res(1), now(*this);
        while (t) {
            if (t & 1) res *= now;
            now *= now;
            t >>= 1;
        }
        return res;
    }
    ModInt<MOD> inv() const {
        return pow(MOD - 2);
    }
    ModInt<MOD> &operator/= (const ModInt<MOD> &x) {
        return *this *= x.pow(MOD - 2);
    }
    ModInt<MOD> operator/ (const ModInt<MOD> &x) const {
        return ModInt(*this) /= x;
    }
    friend std::istream &operator>> (std::istream &is, ModInt<MOD> &x) {
        long long a;
        is >> a;
        x = ModInt<MOD>(a);
        return is;
    }
    friend std::ostream &operator<< (std::ostream &os, const ModInt<MOD> &x) {
        os << x.val;
        return os;
    }
};

constexpr int mod = 1000000007;
using mint = ModInt<mod>;

// Main
int main() {
    int n;
    cin >> n;
    vector<char> s(n);
    rep(i, n) cin >> s[i];

    mint a(0), b(0), c(0), ab(0), abc(0);
    rep(i, n) {
        if (s[i] == 'a') {
            a += mint(1);
        }
        if (s[i] == 'b') {
            b += mint(1);
            ab += a;
        }
        if (s[i] == 'c') {
            c += mint(1);
            abc += ab;
        }
        if (s[i] == '?') {
            ab += a / mint(3);
            abc += (ab - a / mint(3)) / mint(3);
            a += mint(1) / mint(3);
            b += mint(1) / mint(3);
            c += mint(1) / mint(3);
        }
    }

    int k = 0;
    rep(i, n) {
        if (s[i] == '?') ++k;
    }
    cout << abc * mint(3).pow(k) << "\n";
}