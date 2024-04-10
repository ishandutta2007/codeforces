#ifndef LOCAL
#define FAST_IO
#endif

// ============
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
// ============

#ifdef DEBUGF
#else
#define DBG(x) (void) 0
#endif

// ============

#include <cassert>
#include <iostream>
#include <type_traits>

// ============

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
            ret = (unsigned) ((unsigned long long) ret * self % mod);
        }
        self = (unsigned) ((unsigned long long) self * self % mod);
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
// ============

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

// ============
// ============

#include <vector>
#include <cassert>

template <typename T>
class FactorialTable {
    std::vector<T> fac;
    std::vector<T> ifac;
    
public:
    FactorialTable() : fac(1, T(1)), ifac(1, T(1)) {}
    
    FactorialTable(int n) : fac(n + 1), ifac(n + 1) {
        assert(n >= 0);
        fac[0] = T(1);
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * T(i);
        }
        ifac[n] = T(1) / T(fac[n]);
        for (int i = n; i > 0; --i) {
            ifac[i - 1] = ifac[i] * T(i);
        }
    }
    
    void resize(int n) {
        int old = n_max();
        if (n <= old) {
            return;
        }
        fac.resize(n + 1);
        for (int i = old + 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * T(i);
        }
        ifac.resize(n + 1);
        ifac[n] = T(1) / T(fac[n]);
        for (int i = n; i > old; --i) {
            ifac[i - 1] = ifac[i] * T(i);
        }
    }
    
    inline int n_max() const {
        return (int) fac.size() - 1;
    }
    
    inline T fact(int n) const {
        assert(n >= 0 && n <= n_max());
        return fac[n];
    }
    
    inline T inv_fact(int n) const {
        assert(n >= 0 && n <= n_max());
        return ifac[n];
    }
    
    inline T choose(int n, int k) const {
        assert(k <= n_max() && n <= n_max());
        if (k > n || k < 0) {
            return T(0);
        }
        return fac[n] * ifac[k] * ifac[n - k];
    }
    
    inline T multi_choose(int n, int k) const {
        assert(n >= 1 && k >= 0 && k + n - 1 <= n_max());
        return choose(k + n - 1, k);
    }
    
    inline T n_terms_sum_k(int n, int k) const {
        assert(n >= 0);
        if (k < 0) {
            return T(0);
        }
        if (n == 0) {
            return k == 0 ? T(1) : T(0);
        }
        return choose(n + k - 1, n - 1);
    }
};
// ============

using Mint = ModInt<998244353>;

FactorialTable<Mint> f_gen;

void solve() {
    i32 n;
    cin >> n;
    Vec<i64> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    
    f_gen.resize(n);
    
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    
    Vec<i64> fwd(n - 1), bwd(n - 1);
    fwd[0] = a[0];
    REP(i, 1, n - 1) {
        fwd[i] = fwd[i - 1] + a[i];
    }
    reverse(ALL(a));
    bwd[0] = a[0];
    REP(i, 1, n - 1) {
        bwd[i] = bwd[i - 1] + a[i];
    }
    reverse(ALL(bwd));
    
    DBG(fwd);
    DBG(bwd);
    
    Mint ans(1);
    i32 l = 0, r = n - 1;
    while (l < r) {
        if (fwd[l] < bwd[r - 1]) {
            ++l;
        } else if (fwd[l] > bwd[r - 1]) {
            --r;
        } else {
            i64 ele = fwd[l];
            i32 nl = l;
            while (nl < r && fwd[nl] == ele) {
                ++nl;
            }
            i32 nr = r;
            while (nr > l && bwd[nr - 1] == ele) {
                --nr;
            }
            DBG(nl);
            DBG(nr);
            if (nl > nr) {
                Mint w(1);
                REP(i, nr, nl) {
                    w += f_gen.choose(i - l + r - (i + 1), i - l);
                }
                REP(i, nr, nl) {
                    w += f_gen.choose(i - l + r - (i + 1), i - l + 1);
                }
                ans *= w;
                break;
            } else {
                Mint w = f_gen.choose(nl - l + r - nr, nl - l);
                ans *= w;
                l = nl;
                r = nr;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    i32 t;
    cin >> t;
    REP(ti, t) {
        solve();
    }
}