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
#include <random>
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

[[maybe_unused]] constexpr i32 INF = 1000000100;
[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;

struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
    }
} fast_io;
// ===== template.hpp =====

#ifdef DEBUGF
#include "new_library/other/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

// ===== sequence_hash.hpp =====
#ifndef SEQUENCE_HASH_HPP
#define SEQUENCE_HASH_HPP

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
        return (unsigned)(x % mod + mod);
    } else {
        return (unsigned)(x % mod);
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

template <unsigned mod>
struct SequenceHash {
    ModInt<mod> sum;
    ModInt<mod> base_pow;
    
    SequenceHash() : sum(0), base_pow(1) {}
    template <typename T>
    SequenceHash(T val, ModInt<mod> base) : sum(val), base_pow(base) {}
    
    SequenceHash<mod> concat(const SequenceHash<mod> &rhs) const {
        return SequenceHash<mod>(sum + base_pow * rhs.sum, base_pow * rhs.base_pow);
    }
    
    friend bool operator==(const SequenceHash<mod> &lhs, const SequenceHash<mod> &rhs) {
        // return lhs.sum == rhs.sum && lhs.base_pow == rhs.base_pow;
        return lhs.sum == rhs.sum;
    }
    friend bool operator!=(const SequenceHash<mod> &lhs, const SequenceHash<mod> &rhs) {
        // return lhs.sum != rhs.sum || lhs.base_pow != rhs.base_pow;
        return lhs.sum != rhs.sum;
    }
};

template <unsigned mod>
struct HashOp {
    using Value = SequenceHash<mod>;
    static Value id() {
        return Value();
    }
    static Value op(const Value &lhs, const Value &rhs) {
        return lhs.concat(rhs);
    }
};

#endif
// ===== sequence_hash.hpp =====

// ===== segment_tree_xor_range.hpp =====
#ifndef SEGMENT_TREE_XOR_RANGE_HPP
#define SEGMENT_TREE_XOR_RANGE_HPP

#include <vector>
#include <cassert>

template <typename Monoid>
class SegmentTreeXorRange {
public:
    using Value = typename Monoid::Value;
    
private:
    static std::size_t floor_log2(std::size_t n) {
        return 63 - __builtin_clzl(n);
    }
    
    std::size_t depth;
    std::vector<std::vector<Value>> node;
    
public:
    SegmentTreeXorRange(const std::vector<Value> &a) : depth(floor_log2(a.size())), node(2 * a.size()) {
        assert(!a.empty());
        assert(a.size() == (1ul << depth));
        for (std::size_t i = 0; i < a.size(); ++i) {
            node[a.size() + i] = {a[i]};
        }
        for (std::size_t i = a.size() - 1; i > 0; --i) {
            std::size_t k = node[2 * i].size();
            node[i].resize(2 * k);
            for (std::size_t j = 0; j < k; ++j) {
                node[i][j] = Monoid::op(node[2 * i][j], node[2 * i + 1][j]);
                node[i][j + k] = Monoid::op(node[2 * i + 1][j], node[2 * i][j]);
            }
        }
    }
    
    Value prod(std::size_t l, std::size_t r, std::size_t x) const {
        std::size_t d = depth;
        std::size_t nodel_prefix = l;
        std::size_t noder_prefix = r;
        l += 1ul << depth;
        r += 1ul << depth;
        Value lp = Monoid::id();
        Value rp = Monoid::id();
        while (l < r) {
            std::size_t x_upper = x >> (depth - d);
            std::size_t x_lower = x ^ (x_upper << (depth - d));
            if (l % 2 == 1) {
                std::size_t nodei = (x_upper ^ nodel_prefix) + (1ul << d);
                lp = Monoid::op(lp, node[nodei][x_lower]);
                ++l;
                ++nodel_prefix;
            }
            if (r % 2 == 1) {
                --r;
                --noder_prefix;
                std::size_t nodei = (x_upper ^ noder_prefix) + (1ul << d);
                rp = Monoid::op(node[nodei][x_lower], rp);
            }
            --d;
            l /= 2;
            nodel_prefix /= 2;
            r /= 2;
            noder_prefix /= 2;
        }
        return Monoid::op(lp, rp);
    }
};

#endif
// ===== segment_tree_xor_range.hpp =====

constexpr unsigned MOD = 998244353;

using Mint = ModInt<MOD>;

int main() {
    i32 n;
    cin >> n;
    string s;
    cin >> s;
    
    Mint base;
    {
        random_device rd;
        uniform_int_distribution<unsigned> dist(2, MOD - 2);
        base = Mint::raw(dist(rd));
    }
    
    Vec<SequenceHash<MOD>> hs(1 << n);
    REP(i, 1 << n) {
        hs[i] = SequenceHash<MOD>(s[i], base);
    }
    SegmentTreeXorRange<HashOp<MOD>> segtree(hs);
    
    i32 min_index = 0;
    REP(i, 1, 1 << n) {
        i32 ok = 0, ng = 1 << n;
        while (ng - ok > 1) {
            i32 mid = (ok + ng) / 2;
            if (segtree.prod(0, mid, min_index) == segtree.prod(0, mid, i)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (s[ok ^ i] < s[ok ^ min_index]) {
            min_index = i;
        }
    }
    
    cerr << min_index << '\n';
    
    string ans;
    ans.reserve(1 << n);
    REP(i, 1 << n) {
        ans.push_back(s[i ^ min_index]);
    }
    cout << ans << '\n';
}