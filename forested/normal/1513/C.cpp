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

// Square Matrix
#include <array>

template <typename T, int N>
class SquareMatrix {
    static_assert(N >= 0);
    
    std::array<std::array<T, N>, N> arr;
    
public:
    const std::array<T, N> &operator[](int x) const {
        assert(x >= 0 && x < N);
        return arr.at(x);
    }
    
    std::array<T, N> &operator[](int x) {
        assert(x >= 0 && x < N);
        return arr.at(x);
    }
    
    static SquareMatrix identity() {
        SquareMatrix<T, N> s;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    s.arr[i][j] = T(1);
                } else {
                    s.arr[i][j] = T(0);
                }
            }
        }
        return s;
    }
    
    SquareMatrix &operator+=(const SquareMatrix<T, N> &x) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                arr[i][j] += x.arr[i][j];
            }
        }
        return *this;
    }
    
    SquareMatrix &operator-=(const SquareMatrix<T, N> &x) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                arr[i][j] -= x.arr[i][j];
            }
        }
        return *this;
    }
    
    SquareMatrix &operator*=(const SquareMatrix<T, N> &x) {
        std::array<std::array<T, N>, N> res;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res[i][j] = T(0);
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    res[i][j] += arr[i][k] * x.arr[k][j];
                }
            }
        }
        arr.swap(res);
        return *this;
    }
    
    SquareMatrix operator+(const SquareMatrix<T, N> &x) const {
        return SquareMatrix(*this) += x;
    }
    
    SquareMatrix operator-(const SquareMatrix<T, N> &x) const {
        return SquareMatrix(*this) -= x;
    }
    
    SquareMatrix operator*(const SquareMatrix<T, N> &x) {
        return SquareMatrix(*this) *= x;
    }
    
    SquareMatrix pow(long long x) const {
        assert(x >= 0);
        SquareMatrix<T, N> a(*this);
        SquareMatrix<T, N> b = SquareMatrix<T, N>::identity();
        while (x) {
            if (x & 1) {
                b *= a;
            }
            a *= a;
            x >>= 1;
        }
        return b;
    }
};

// Mod-Int
#include <iostream>

template <unsigned int mod>
class ModInt {
    static_assert(mod >= 1 && mod < (1u << 31));
    
    unsigned int val;
    
public:
    ModInt() : val(0) {}
    
    ModInt(long long x) : val(x < 0 ? x % mod + mod : (unsigned long long)x % mod) {}
    
    unsigned get_val() const {
        return val;
    }
    
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
    constexpr unsigned mod = 1000000007;
    using Mint = ModInt<mod>;
    constexpr int mx = 200000;
    
    array<array<array<Mint, 10>, 10>, mx + 1> calc;
    rep(i, 10) calc[0][i][i] = Mint(1);
    rep(i, mx) {
        rep(j, 9) {
            rep(k, 10) calc[i + 1][j + 1][k] += calc[i][j][k];
        }
        rep(k, 10) {
            calc[i + 1][0][k] += calc[i][9][k];
            calc[i + 1][1][k] += calc[i][9][k];
        }
    }
    
    array<array<Mint, 10>, mx + 1> sum;
    rep(i, mx + 1) rep(j, 10) rep(k, 10) sum[i][k] += calc[i][j][k];
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        array<int, 10> cnt;
        rep(i, 10) cnt[i] = 0;
        while (n) {
            cnt[n % 10] += 1;
            n /= 10;
        }
        Mint ans;
        rep(i, 10) ans += sum[m][i] * cnt[i];
        cout << ans << '\n';
    }
}