// Template
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <tuple>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <cassert>
#include <cmath>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll infll = 3003003003003003003LL;
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
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &element : vec) is >> element;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (int i = 0, vec_len = (int)vec.size(); i < vec_len; ++i) {
        os << vec[i] << (i + 1 == vec_len ? "" : " ");
    }
    return os;
}
struct IOSET {
    IOSET() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} ioset;

// Mod-Int
#include <iostream>

template <unsigned int mod>
struct ModInt {
    static_assert(mod >= 1 && mod < (1u << 31));
    
    unsigned int val;
    
    ModInt() : val(0) {}
    
    ModInt(long long x) : val(x < 0 ? x % mod + mod : (unsigned long long)x % mod) {}
    
    ModInt<mod> &operator+=(const ModInt<mod> &x) {
        val += x.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    
    ModInt<mod> &operator-=(const ModInt<mod> &x) {
        if (val < x.val) val += mod;
        val -= x.val;
        return *this;
    }
    
    ModInt<mod> &operator*=(const ModInt<mod> &x) {
        unsigned long long s = (unsigned long long)val * x.val;
        val = (unsigned int)(s % mod);
        return *this;
    }
    
    ModInt<mod> operator+() const {
        return *this;
    }
    
    ModInt<mod> operator-() const {
        return ModInt<mod>(0u) - *this;
    }
    
    friend ModInt<mod> operator+(const ModInt<mod> &x, const ModInt<mod> &y) {
        return ModInt<mod>(x) += y;
    }
    
    friend ModInt<mod> operator-(const ModInt<mod> &x, const ModInt<mod> &y) {
        return ModInt<mod>(x) -= y;
    }
    
    friend ModInt<mod> operator*(const ModInt<mod> &x, const ModInt<mod> &y) {
        return ModInt<mod>(x) *= y;
    }
    
    friend std::istream &operator>>(std::istream &is, ModInt<mod> &x) {
        is >> x.val;
        // x.value %= mod;
        return is;
    }
    
    friend std::ostream &operator<<(std::ostream &os, const ModInt<mod> &x) {
        os << x.val;
        return os;
    }
    
    ModInt<mod> pow(unsigned long long x) const {
        ModInt<mod> res(1), s(*this);
        while (x) {
            if (x & 1) res *= s;
            s *= s;
            x >>= 1;
        }
        return res;
    }
    
    // --- prime number ---
    ModInt<mod> &operator/=(const ModInt<mod> &x) {
        *this *= x.pow(mod - 2);
        return *this;
    }
    
    friend ModInt<mod> operator/(const ModInt<mod> &x, const ModInt<mod> &y) {
        return ModInt<mod>(x) /= y;
    }
};

// Main
int main() {
    constexpr unsigned mod = 998244353;
    using Mint = ModInt<mod>;
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m));
    cin >> d;
    
    Mint perm(1);
    rep(i, 1, n + 1) perm *= Mint(i);
    
    Mint ans(0);
    rep(i, m) {
        vector<int> cnt(n + 1, 0);
        rep(j, n) {
            ++cnt[n + 1 - d[j][i]];
        }
        Mint p(1);
        int now = cnt[0];
        rep(j, n) {
            p *= Mint(now--);
            now += cnt[j + 1];
        }
        ans += perm - p;
        //cout << p << '\n';
    }
    //cout << ans << '\n';
    cout << ans / perm << '\n';
}