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
#define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)
#define REP3(i, m, n) for (i32 i = (i32) (m); i < (i32) (n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)
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

    constexpr ModInt pow(unsigned long long x) const {
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

using Mint = ModInt<mod998244353>;

Mint solve(i32 n, Vec<i32> s, Vec<i32> t, Vec<i32> x, Vec<i32> y) {
    Vec<i32> lpf(n + 1, 0);
    iota(ALL(lpf), 0);
    Vec<i32> primes;
    REP(i, 2, n + 1) {
        if (lpf[i] == i) {
            primes.push_back(i);
        }
        for (i32 p : primes) {
            if ((i64) p * i > n || p > lpf[i]) {
                break;
            }
            lpf[p * i] = p;
        }
    }
    
    Vec<Vec<pair<i32, i32>>> fact(n + 1);
    REP(i, 2, n + 1) {
        i32 num = i;
        i32 prv = -1, cnt = 0;
        while (num > 1) {
            if (lpf[num] != prv) {
                if (prv != -1) {
                    fact[i].emplace_back(prv, cnt);
                }
                prv = lpf[num];
                cnt = 0;
            }
            ++cnt;
            num /= lpf[num];
        }
        fact[i].emplace_back(prv, cnt);
    }
    
    Vec<Vec<tuple<i32, i32, i32>>> g(n);
    REP(i, n - 1) {
        g[s[i]].emplace_back(t[i], x[i], y[i]);
        g[t[i]].emplace_back(s[i], y[i], x[i]);
    }
    
    Vec<i32> ep(n + 1, 0);
    const auto dfs1 = [&](const auto &dfs, i32 v, i32 par) -> void {
        for (auto [u, x, y] : g[v]) {
            if (u == par) {
                continue;
            }
            for (auto [p, e] : fact[x]) {
                chmax(ep[p], e);
                ep[p] -= e;
            }
            for (auto [p, e] : fact[y]) {
                ep[p] += e;
            }
            dfs(dfs, u, v);
            for (auto [p, e] : fact[y]) {
                ep[p] -= e;
            }
            for (auto [p, e] : fact[x]) {
                ep[p] += e;
            }
        }
    };
    dfs1(dfs1, 0, -1);
    
    Mint pr(1);
    REP(i, 2, n + 1) {
        pr *= Mint::raw(i).pow(ep[i]);
    }
    
    const auto dfs2 = [&](const auto &dfs, i32 v, i32 par, Mint val) -> Mint {
        Mint ans = val;
        for (auto [u, x, y] : g[v]) {
            if (u == par) {
                continue;
            }
            ans += dfs(dfs, u, v, val / Mint::raw(x) * Mint::raw(y));
        }
        return ans;
    };
    return dfs2(dfs2, 0, -1, pr);
}

int main() {
    i32 t;
    cin >> t;
    while (t--) {
        i32 n;
        cin >> n;
        Vec<i32> s(n - 1), t(n - 1), x(n - 1), y(n - 1);
        REP(i, n - 1) {
            cin >> s[i] >> t[i] >> x[i] >> y[i];
            --s[i];
            --t[i];
            i32 g = gcd(x[i], y[i]);
            x[i] /= g;
            y[i] /= g;
        }
        cout << solve(n, move(s), move(t), move(x), move(y)) << '\n';
    }
}