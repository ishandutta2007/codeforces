// ===== template.hpp =====
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (n); ++i)
#define REP3(i, m, n) for (i32 i = (m); i < (n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (n) - 1; i >= 0; --i)
#define ALL(x) begin(x), end(x)

using namespace std;

using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = __uint128_t;
using i32 = signed int;
using i64 = signed long long;
using i128 = __int128_t;

template <typename T>
using Vec = vector<T>;

template <typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

[[maybe_unused]] constexpr i32 inf = 1000000100;
[[maybe_unused]] constexpr i64 inf64 = 3000000000000000100;

struct SetIO {
    SetIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
    }
} set_io;
// ===== template.hpp =====

#ifdef DEBUGF
#include  "../new_library/other/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

// ===== mod_int.hpp =====
#ifndef MOD_INT_HPP
#define MOD_INT_HPP

#include <cassert>
#include <iostream>
#include <type_traits>

// ===== utils.hpp =====
#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>

constexpr bool is_prime(unsigned n) {
    if (n == 0 || n == 1)
        return false;
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

constexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {
    unsigned ret = 1, self = x;
    while (y != 0) {
        if (y & 1)
            ret = (unsigned long long)ret * self % mod;
        self = (unsigned long long)self * self % mod;
        y >>= 1;
    }
    return ret;
}

template <unsigned mod>
constexpr unsigned primitive_root() {
    static_assert(is_prime(mod), "`mod` must be a prime number.");
    if (mod == 2)
        return 1;

    unsigned primes[32] = {};
    std::size_t it = 0;
    {
        unsigned m = mod - 1;
        for (unsigned i = 2; i * i <= m; ++i) {
            if (m % i == 0) {
                primes[it++] = i;
                while (m % i == 0)
                    m /= i;
            }
        }
        if (m != 1)
            primes[it++] = m;
    }
    for (unsigned i = 2; i < mod; ++i) {
        bool ok = true;
        for (std::size_t j = 0; j < it; ++j) {
            if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {
                ok = false;
                break;
            }
        }
        if (ok)
            return i;
    }
    return 0;
}

#endif
// ===== utils.hpp =====

template <typename T, std::enable_if_t<std::is_signed_v<T>> * = nullptr>
constexpr unsigned safe_mod(T x, unsigned mod) {
    if (x < 0) {
        return (unsigned)(x % (T)mod + mod);
    } else {
        return (unsigned)(x % (T)mod);
    }
}

template <typename T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>
constexpr unsigned safe_mod(T x, unsigned mod) {
    return (unsigned)(x % mod);
}

template <unsigned mod>
class ModInt {
    static_assert(mod != 0, "`mod` must not be equal to 0.");
    static_assert(
        mod < (1u << 31),
        "`mod` must be less than (1u << 31) = 2147483648.");

    unsigned val;

public:
    constexpr ModInt() : val(0) {}
    template <typename T>
    constexpr ModInt(T x) : val(safe_mod(x, mod)) {}

    static constexpr ModInt raw(unsigned x) {
        ModInt<mod> ret;
        ret.val = x;
        return ret;
    }

    constexpr unsigned get_val() const {
        return val;
    }

    constexpr ModInt operator+() const {
        return *this;
    }
    constexpr ModInt operator-() const {
        return ModInt<mod>(0u) - *this;
    }

    constexpr ModInt &operator+=(const ModInt &rhs) {
        val += rhs.val;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) {
        if (val < rhs.val)
            val += mod;
        val -= rhs.val;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) {
        val = (unsigned long long)val * rhs.val % mod;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) {
        val = (unsigned long long)val * rhs.inv().val % mod;
        return *this;
    }

    friend constexpr ModInt operator+(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) += rhs;
    }
    friend constexpr ModInt operator-(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) -= rhs;
    }
    friend constexpr ModInt operator*(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) *= rhs;
    }
    friend constexpr ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) /= rhs;
    }

    constexpr ModInt pow(unsigned x) const {
        ModInt<mod> ret = ModInt<mod>::raw(1);
        ModInt<mod> self = *this;
        while (x != 0) {
            if (x & 1)
                ret *= self;
            self *= self;
            x >>= 1;
        }
        return ret;
    }
    constexpr ModInt inv() const {
        static_assert(is_prime(mod), "`mod` must be a prime number.");
        assert(val != 0);
        return this->pow(mod - 2);
    }

    friend std::istream &operator>>(std::istream &is, ModInt<mod> &x) {
        is >> x.val;
        // x.val %= mod;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt<mod> &x) {
        os << x.val;
        return os;
    }

    friend bool operator==(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val == rhs.val;
    }
    
    friend bool operator!=(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val != rhs.val;
    }
};

[[maybe_unused]] constexpr unsigned mod998244353 = 998244353;
[[maybe_unused]] constexpr unsigned mod1000000007 = 1000000007;

#endif
// ===== mod_int.hpp =====
// ===== linear_equations.hpp =====
#ifndef LINEAR_EQUATIONS_HPP
#define LINEAR_EQUATIONS_HPP

// ===== gaussian_elimination.hpp =====
#ifndef GAUSSIAN_ELIMINATION_HPP
#define GAUSSIAN_ELIMINATION_HPP

// ===== matrix.hpp =====
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <cassert>
#include <utility>

template <typename T>
class Matrix {
    std::vector<std::vector<T>> val;
    
public:
    Matrix() : val() {}
    Matrix(std::size_t h, std::size_t w) : val(h, std::vector<T>(w)) {}
    Matrix(std::size_t h, std::size_t w, const T &ele) : val(h, std::vector<T>(w, ele)) {}
    Matrix(std::vector<std::vector<T>> _val) : val(std::move(_val)) {}
    
    std::size_t row() const {
        return val.size();
    }
    
    std::size_t column() const {
        return val[0].size();
    }
    
    T &operator()(std::size_t i, std::size_t j) {
        return val[i][j];
    }
    const T &operator()(std::size_t i, std::size_t j) const {
        return val[i][j];
    }
    
    Matrix<T> operator+() const {
        return *this;
    }
    Matrix<T> operator-() const {
        Matrix<T> ret(row(), column());
        for (std::size_t i = 0; i < row(); ++i) {
            for (std::size_t j = 0; j < column(); ++j) {
                ret.val[i][j] = -val[i][j];
            }
        }
        return ret;
    }
    
    Matrix<T> &operator+=(const Matrix &rhs) {
        assert(row() == rhs.row() && column() == rhs.column());
        for (std::size_t i = 0; i < row(); ++i) {
            for (std::size_t j = 0; j < column(); ++j) {
                val[i][j] += rhs.val[i][j];
            }
        }
        return *this;
    }
    friend Matrix<T> operator+(Matrix<T> lhs, const Matrix<T> &rhs) {
        return lhs += rhs;
    }
    
    Matrix<T> &operator-=(const Matrix &rhs) {
        assert(row() == rhs.row() && column() == rhs.column());
        for (std::size_t i = 0; i < row(); ++i) {
            for (std::size_t j = 0; j < column(); ++j) {
                val[i][j] -= rhs.val[i][j];
            }
        }
        return *this;
    }
    friend Matrix<T> operator-(Matrix<T> lhs, const Matrix<T> &rhs) {
        return lhs += rhs;
    }
    
    Matrix<T> &operator*=(const Matrix<T> &rhs) {
        *this = *this * rhs;
        return *this;
    }
    friend Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs) {
        assert(lhs.column() == rhs.row());
        Matrix<T> ret(lhs.row(), rhs.column());
        for (std::size_t i = 0; i < lhs.row(); ++i) {
            for (std::size_t j = 0; j < rhs.column(); ++j) {
                for (std::size_t k = 0; k < lhs.column(); ++k) {
                    ret[i][j] += lhs.val[i][k] * rhs.val[k][j];
                }
            }
        }
        return ret;
    }
    
    static Matrix<T> ident(std::size_t n) {
        Matrix<T> ret(n, n, T(0));
        for (std::size_t i = 0; i < n; ++i) {
            ret.val[i][i] = T(1);
        }
        return ret;
    }
    
    void swap_rows(std::size_t i, std::size_t j) {
        std::swap(val[i], val[j]);
    }
    void swap_columns(std::size_t i, std::size_t j) {
        for (std::vector<T> &row : val) {
            std::swap(row[i], row[j]);
        }
    }
};

#endif
// ===== matrix.hpp =====

template <typename T>
std::size_t gaussian_elimination(Matrix<T> &mat) {
    if (mat.row() == 0 || mat.column() == 0) {
        return 0;
    }
    std::size_t r = 0;
    for (std::size_t i = 0; i < mat.column(); ++i) {
        std::size_t idx = mat.row();
        for (std::size_t j = r; j < mat.row(); ++j) {
            if (mat(j, i) != T(0)) {
                idx = j;
                break;
            }
        }
        if (idx == mat.row()) {
            continue;
        }
        mat.swap_rows(r, idx);
        std::vector<std::size_t> nonzero;
        T p = mat(r, i);
        for (std::size_t k = 0; k < mat.column(); ++k) {
            mat(r, k) /= p;
            if (mat(r, k) != T(0)) {
                nonzero.push_back(k);
            }
        }
        for (std::size_t j = 0; j < mat.row(); ++j) {
            if (j == r) {
                continue;
            }
            T q = mat(j, i);
            for (std::size_t k : nonzero) {
                mat(j, k) -= q * mat(r, k);
            }
        }
        ++r;
    }
    return r;
}

#endif
// ===== gaussian_elimination.hpp =====

#include <optional>

template <typename T>
std::optional<std::vector<T>> solve_linear_equations(std::vector<std::vector<T>> a, std::vector<T> b) {
    assert(a.size() == b.size());
    assert(!a.empty());
    assert(!a[0].empty());
    for (std::size_t i = 0; i < a.size(); ++i) {
        assert(a[i].size() == a[0].size());
    }
    for (std::size_t i = 0; i < b.size(); ++i) {
        a[i].emplace_back(std::move(b[i]));
    }
    Matrix<T> mat(std::move(a));
    std::size_t r = gaussian_elimination(mat);
    if (r == mat.column()) {
        return std::nullopt;
    }
    std::vector<std::size_t> idx(r);
    std::size_t cur = 0;
    for (std::size_t i = 0; i < r; ++i) {
        while (mat(i, cur) == T(0)) {
            ++cur;
        }
        idx[i] = cur++;
    }
    std::vector<T> ans(mat.column() - 1);
    for (std::size_t i = r - 1; i < r; --i) {
        T sum(0);
        for (std::size_t j = idx[i] + 1; j < mat.column() - 1; ++j) {
            sum += ans[j] * mat(i, j);
        }
        ans[idx[i]] = (mat(i, mat.column() - 1) - sum) / (mat(i, idx[i]));
    }
    return ans;
}

#endif
// ===== linear_equations.hpp =====

using Mint = ModInt<3>;

void solve() {
    i32 n, m;
    cin >> n >> m;
    Vec<Vec<i32>> eid(n, Vec<i32>(n, -1));
    Vec<i32> color(m, -1);
    REP(e, m) {
        i32 a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        if (c != -1) {
            --c;
        }
        eid[a][b] = eid[b][a] = e;
        color[e] = c;
    }
    
    Vec<Vec<Mint>> am;
    Vec<Mint> bm;
    REP(a, n) REP(b, a + 1, n) REP(c, b + 1, n) {
        i32 ab = eid[a][b], bc = eid[b][c], ca = eid[c][a];
        if (ab != -1 && bc != -1 && ca != -1) {
            Vec<Mint> row(m);
            row[ab] = row[bc] = row[ca] = Mint::raw(1);
            am.emplace_back(move(row));
            bm.push_back(Mint::raw(0));
        }
    }
    REP(i, m) {
        if (color[i] != -1) {
            Vec<Mint> row(m);
            row[i] = Mint::raw(1);
            am.push_back(move(row));
            bm.push_back(Mint::raw(color[i]));
        }
    }
    
    if (am.empty()) {
        REP(i, m) {
            cout << 1 << " \n"[i + 1 == m];
        }
        return;
    }
    optional<Vec<Mint>> ans = solve_linear_equations(move(am), move(bm));
    if (ans) {
        REP(i, m) {
            cout << (*ans)[i].get_val() + 1 << " \n"[i + 1 == m];
        }
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}