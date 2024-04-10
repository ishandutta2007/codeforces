#ifndef LOCAL
#define FAST_IO
#endif

// ===== template.hpp =====
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
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
using f64 = double;
using f80 = long double;

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

istream &operator>>(istream &is, i128 &x) {
    i64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, i128 x) {
    os << (i64) x;
    return os;
}
istream &operator>>(istream &is, u128 &x) {
    u64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, u128 x) {
    os << (u64) x;
    return os;
}

[[maybe_unused]] constexpr i32 INF = 1000000100;
[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;
struct SetUpIO {
    SetUpIO() {
#ifdef FAST_IO
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
#endif
        cout << fixed << setprecision(15);
    }
} set_up_io;
// ===== template.hpp =====

#ifdef DEBUGF
#include "cpl/template/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

// ===== mod_int.hpp =====

#include <cassert>
#include <iostream>
#include <type_traits>

// ===== utils.hpp =====

constexpr bool is_prime(unsigned n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

constexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {
    unsigned ret = 1, self = x;
    while (y != 0) {
        if (y & 1) {
            ret = static_cast<unsigned>(static_cast<unsigned long long>(ret) * self % mod);
        }
        self = static_cast<unsigned>(static_cast<unsigned long long>(self) * self % mod);
        y /= 2;
    }
    return ret;
}

template <unsigned mod>
constexpr unsigned primitive_root() {
    static_assert(is_prime(mod), "`mod` must be a prime number.");
    if (mod == 2) {
        return 1;
    }

    unsigned primes[32] = {};
    int it = 0;
    {
        unsigned m = mod - 1;
        for (unsigned i = 2; i * i <= m; ++i) {
            if (m % i == 0) {
                primes[it++] = i;
                while (m % i == 0) {
                    m /= i;
                }
            }
        }
        if (m != 1) {
            primes[it++] = m;
        }
    }
    for (unsigned i = 2; i < mod; ++i) {
        bool ok = true;
        for (int j = 0; j < it; ++j) {
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

// y >= 1
template <typename T>
constexpr T safe_mod(T x, T y) {
    x %= y;
    if (x < 0) {
        x += y;
    }
    return x;
}

// y != 0
template <typename T>
constexpr T floor_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return x / y;
    } else {
        return -((-x + y - 1) / y);
    }
}

// y != 0
template <typename T>
constexpr T ceil_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return (x + y - 1) / y;
    } else {
        return -(-x / y);
    }
}
// ===== utils.hpp =====

template <unsigned mod>
class ModInt {
    static_assert(mod != 0, "`mod` must not be equal to 0.");
    static_assert(
        mod < (1u << 31),
        "`mod` must be less than (1u << 31) = 2147483648.");

    unsigned val;

public:
    constexpr ModInt() : val(0) {}
    template <typename T, std::enable_if_t<std::is_signed_v<T>> * = nullptr>
    constexpr ModInt(T x) : val((unsigned) ((long long) x % (long long) mod + (x < 0 ? mod : 0))) {}
    template <typename T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>
    constexpr ModInt(T x) : val((unsigned) (x % mod)) {}

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
        x.val %= mod;
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

// ===== mod_int.hpp =====

using Mint = ModInt<mod998244353>;

int main() {
    string s;
    cin >> s;
    
    array<array<Mint, 8>, 4> dp;
    dp[0][0] = Mint(1);
    for (char d_ : s) {
        i32 d = d_ - '0';
        array<array<Mint, 8>, 4> ndp;
        REP(phase, 4) REP(state, 8) {
            i32 state_a = !!(state & 1);
            i32 state_ax = !!(state & 2);
            i32 state_az = !!(state & 4);
            REP(axz, 8) {
                i32 a = !!(axz & 1);
                i32 x = !!(axz & 2);
                i32 z = !!(axz & 4);
                if (phase == 0) {
                    if (x == 1) {
                        continue;
                    }
                } else if (phase == 1) {
                    if (x == 1 && z == 0) {
                        continue;
                    }
                }
                i32 ax = a ^ x;
                i32 az = a ^ z;
                if (a > d && !state_a) {
                    continue;
                }
                if (ax > d && !state_ax) {
                    continue;
                }
                if (az > d && !state_az) {
                    continue;
                }
                i32 next_phase = phase;
                if (phase == 0 && x == 0 && z == 1) {
                    ++next_phase;
                }
                if (phase == 1 && x == 1 && z == 1) {
                    ++next_phase;
                }
                if (phase == 2 && x == 1 && z == 0) {
                    ++next_phase;
                }
                i32 next_state = state;
                if (a < d) {
                    next_state |= 1;
                }
                if (ax < d) {
                    next_state |= 2;
                }
                if (az < d) {
                    next_state |= 4;
                }
                ndp[next_phase][next_state] += dp[phase][state];
            }
        }
        dp = ndp;
        /*REP(phase, 4) {
            REP(state, 8) {
                cerr << dp[phase][state] << " \n"[state == 7];
            }
        }
        cerr << '\n';*/
    }
    
    Mint ans;
    REP(i, 8) {
        ans += dp[3][i];
    }
    ans *= Mint(6);
    cout << ans << '\n';
}