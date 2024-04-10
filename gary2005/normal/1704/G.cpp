/**
 *    author:  gary
 *    created: 10.08.2022 09:45:38
**/
#include<bits/stdc++.h>

#include <algorithm>
#include <array>
#include <cassert>
#include <type_traits>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif


#include <utility>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

struct barrett {
    unsigned int _m;
    unsigned long long im;

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    unsigned int umod() const { return _m; }

    unsigned int mul(unsigned int a, unsigned int b) const {

        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  // namespace internal

}  // namespace atcoder


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

namespace internal {

template <class mint,
          int g = internal::primitive_root<mint::mod()>,
          internal::is_static_modint_t<mint>* = nullptr>
struct fft_info {
    static constexpr int rank2 = bsf_constexpr(mint::mod() - 1);
    std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1
    std::array<mint, rank2 + 1> iroot;  // root[i] * iroot[i] == 1

    std::array<mint, std::max(0, rank2 - 2 + 1)> rate2;
    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;

    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;
    std::array<mint, std::max(0, rank2 - 3 + 1)> irate3;

    fft_info() {
        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
        iroot[rank2] = root[rank2].inv();
        for (int i = rank2 - 1; i >= 0; i--) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }

        {
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 2; i++) {
                rate2[i] = root[i + 2] * prod;
                irate2[i] = iroot[i + 2] * iprod;
                prod *= iroot[i + 2];
                iprod *= root[i + 2];
            }
        }
        {
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 3; i++) {
                rate3[i] = root[i + 3] * prod;
                irate3[i] = iroot[i + 3] * iprod;
                prod *= iroot[i + 3];
                iprod *= root[i + 3];
            }
        }
    }
};

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly(std::vector<mint>& a) {
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static const fft_info<mint> info;

    int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
    while (len < h) {
        if (h - len == 1) {
            int p = 1 << (h - len - 1);
            mint rot = 1;
            for (int s = 0; s < (1 << len); s++) {
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * rot;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                if (s + 1 != (1 << len))
                    rot *= info.rate2[bsf(~(unsigned int)(s))];
            }
            len++;
        } else {
            int p = 1 << (h - len - 2);
            mint rot = 1, imag = info.root[2];
            for (int s = 0; s < (1 << len); s++) {
                mint rot2 = rot * rot;
                mint rot3 = rot2 * rot;
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto mod2 = 1ULL * mint::mod() * mint::mod();
                    auto a0 = 1ULL * a[i + offset].val();
                    auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
                    auto a1na3imag =
                        1ULL * mint(a1 + mod2 - a3).val() * imag.val();
                    auto na2 = mod2 - a2;
                    a[i + offset] = a0 + a2 + a1 + a3;
                    a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
                    a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
                    a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
                }
                if (s + 1 != (1 << len))
                    rot *= info.rate3[bsf(~(unsigned int)(s))];
            }
            len += 2;
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly_inv(std::vector<mint>& a) {
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static const fft_info<mint> info;

    int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
    while (len) {
        if (len == 1) {
            int p = 1 << (h - len);
            mint irot = 1;
            for (int s = 0; s < (1 << (len - 1)); s++) {
                int offset = s << (h - len + 1);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] =
                        (unsigned long long)(mint::mod() + l.val() - r.val()) *
                        irot.val();
                    ;
                }
                if (s + 1 != (1 << (len - 1)))
                    irot *= info.irate2[bsf(~(unsigned int)(s))];
            }
            len--;
        } else {
            int p = 1 << (h - len);
            mint irot = 1, iimag = info.iroot[2];
            for (int s = 0; s < (1 << (len - 2)); s++) {
                mint irot2 = irot * irot;
                mint irot3 = irot2 * irot;
                int offset = s << (h - len + 2);
                for (int i = 0; i < p; i++) {
                    auto a0 = 1ULL * a[i + offset + 0 * p].val();
                    auto a1 = 1ULL * a[i + offset + 1 * p].val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val();

                    auto a2na3iimag =
                        1ULL *
                        mint((mint::mod() + a2 - a3) * iimag.val()).val();

                    a[i + offset] = a0 + a1 + a2 + a3;
                    a[i + offset + 1 * p] =
                        (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();
                    a[i + offset + 2 * p] =
                        (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) *
                        irot2.val();
                    a[i + offset + 3 * p] =
                        (a0 + (mint::mod() - a1) + (mint::mod() - a2na3iimag)) *
                        irot3.val();
                }
                if (s + 1 != (1 << (len - 2)))
                    irot *= info.irate3[bsf(~(unsigned int)(s))];
            }
            len -= 2;
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_naive(const std::vector<mint>& a,
                                    const std::vector<mint>& b) {
    int n = int(a.size()), m = int(b.size());
    std::vector<mint> ans(n + m - 1);
    if (n < m) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                ans[i + j] += a[i] * b[j];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
    }
    return ans;
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_fft(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    int z = 1 << internal::ceil_pow2(n + m - 1);
    a.resize(z);
    internal::butterfly(a);
    b.resize(z);
    internal::butterfly(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::butterfly_inv(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

}  // namespace internal

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(std::vector<mint>&& a, std::vector<mint>&& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) return convolution_naive(a, b);
    return internal::convolution_fft(a, b);
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(const std::vector<mint>& a,
                              const std::vector<mint>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) return convolution_naive(a, b);
    return internal::convolution_fft(a, b);
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    using mint = static_modint<mod>;
    std::vector<mint> a2(n), b2(m);
    for (int i = 0; i < n; i++) {
        a2[i] = mint(a[i]);
    }
    for (int i = 0; i < m; i++) {
        b2[i] = mint(b[i]);
    }
    auto c2 = convolution(move(a2), move(b2));
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        c[i] = c2[i].val();
    }
    return c;
}

std::vector<long long> convolution_ll(const std::vector<long long>& a,
                                      const std::vector<long long>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;  // 2^24
    static constexpr unsigned long long MOD2 = 167772161;  // 2^25
    static constexpr unsigned long long MOD3 = 469762049;  // 2^26
    static constexpr unsigned long long M2M3 = MOD2 * MOD3;
    static constexpr unsigned long long M1M3 = MOD1 * MOD3;
    static constexpr unsigned long long M1M2 = MOD1 * MOD2;
    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::inv_gcd(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::inv_gcd(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::inv_gcd(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * M2M3;
        x += (c2[i] * i2) % MOD2 * M1M3;
        x += (c3[i] * i3) % MOD3 * M1M2;
        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

}  // namespace atcoder

#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
using namespace atcoder;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+20;
int n,m;
bool ok[MAXN];
LL A[MAXN],B[MAXN],a[MAXN],b[MAXN],c[MAXN],e[MAXN],d[MAXN],f[MAXN],g[MAXN];
const int MOD[2]={998244353,1004535809};
vector<int> mul(vector<int> A,vector<int> B,bool f){
    // A[i]*B[j] -> C[i-j]
    reverse(ALL(B));
    auto C=(f==0? convolution<998244353>(A,B):convolution<1004535809>(A,B));
    reverse(ALL(C));
    rb(i,1,B.size()-1) C.pop_back();
    reverse(ALL(C));
    return C;
}
int sumf[MAXN],sumg[MAXN],sumff[MAXN],sumgg[MAXN];
void calc_match(){
    if(m<=2){
        rb(i,1,n-m+1) ok[i]=1;
        return;
    }
    rb(i,1,n-m+1) ok[i]=1;
    rep(flag,2){
        vector<int> F,G,H;
        rb(i,3,n) F.push_back((f[i]%MOD[flag]+MOD[flag])%MOD[flag]);
        rb(i,3,m) G.push_back((g[i]%MOD[flag]+MOD[flag])%MOD[flag]);
        rep(i,F.size()){
            if(i) sumf[i]=sumf[i-1],sumff[i]=sumff[i-1];
            else sumf[i]=sumff[i]=0;
            (sumf[i]+=F[i])%=MOD[flag];
            (sumff[i]+=1ll*F[i]*F[i]%MOD[flag])%=MOD[flag];
        }
        rep(i,G.size()){
            if(i) sumg[i]=sumg[i-1],sumgg[i]=sumgg[i-1];
            else sumg[i]=sumgg[i]=0;
            (sumg[i]+=G[i])%=MOD[flag];
            (sumgg[i]+=1ll*G[i]*G[i]%MOD[flag])%=MOD[flag];
        }
        // for(auto it:F) cout<<it<<',';
        // cout<<endl;
        // for(auto it:G) cout<<it<<",";
        // cout<<endl;
        H=mul(F,G,flag);
        rep(i,H.size()){
            if(i+m<=n){
                // cout<<H[i]<<endl;
                LL val=-2ll*H[i];
                //{i,0} , {i+1,1} ... {}
                int can=min(F.size()-i,G.size());
                // assert(can==G.size());
                if(can){
                    int l,r;
                    l=i,r=can+i-1;
                    val-=sumf[r];
                    if(l) val+=sumf[l-1];
                    val+=sumg[can-1];
                    val+=sumff[r];
                    if(l) val-=sumff[l-1];
                    val+=sumgg[can-1];
                }
                // cout<<val%MOD[flag]<<"___"<<i+1<<endl;
                if(val%MOD[flag]){
                    ok[i+1]=0;
                }
            }
        }
    }
}
LL Fmax(int x){
    // x x-4 ...
    if(x<0) return 0;
    int l=x%4;
    return 1ll*(x+l)*((x-l)/4+1)/2;
}
LL Fmin(int x){
    // x x+4 ...
    if(x>0) return 0;
    int r=x%4;
    return 1ll*(x+r)*((r-x)/4+1)/2;
}
bool check(int x){
    LL F,S;
    F=b[1]-a[x];
    S=b[2]-a[x+1];
    mp addi,minu;
    addi=II(0,x-(x&1));
    minu=II(1,x-!(x&1));
    if(!(x&1)) swap(minu,addi);
    LL l=0,r=0;
    LL pm=0,pa=0;
    if(F<S){
        pa=S-F;
    }
    else{
        pm=F-S;
    }
    if(pm>(minu.second-minu.first)/2+1) return 0;
    if(pa>(addi.second-addi.first)/2+1) return 0;
    {
        mp ta=addi,tm=minu;
        if(pm) tm.second-=2*pm,l-=1ll*(minu.second+minu.second-2*pm+2)*pm/2;
        if(pa) ta.first+=2*pa,l+=1ll*(addi.first+addi.first+2*pa-2)*pa/2;
        l+=Fmin(ta.first-tm.second);
    }
    {
        mp ta=addi,tm=minu;
        if(pm) tm.first+=2*pm,r-=1ll*(minu.first+minu.first+2*pm-2)*pm/2;
        if(pa) ta.second-=2*pa,r+=1ll*(addi.second+addi.second-2*pa+2)*pa/2;
        // cout<<r<<endl;
        r+=Fmax(ta.second-tm.first);
    }
    // if(x==5){
    //     cout<<addi.first<<" "<<addi.second<<" "<<minu.first<<" "<<minu.second<<" "<<l<<" "<<r<<" "<<F<<" "<<S<<endl;
    // }
    return F<=r&&F>=l;
}
void construct(int x){
    vector<int> way;
    rl(j,m,3){
        LL delta=(e[x+j-1]-e[x+j-2])-(e[x+j-2]-e[x+j-3]);
        if(delta!=0){
            way.push_back(x+j-1);
        }
    }
    LL F,S;
    F=b[1]-a[x];
    S=b[2]-a[x+1];
    mp addi,minu;
    addi=II(0,x-(x&1));
    minu=II(1,x-!(x&1));
    if(!(x&1)) swap(minu,addi);
    int MinA=addi.first,MaxM=minu.second;
    int L=addi.first,R=minu.second;
    LL SUM=0;
    set<int> A,M;
    rb(i,1,S-F){
        A.insert(addi.second);
        SUM+=addi.second;
        addi.second-=2;
    }
    rb(i,1,F-S){
        M.insert(minu.first);
        SUM-=minu.first;
        minu.first+=2;
    }
    while (addi.first<=addi.second&&minu.first<=minu.second&&addi.second>=minu.first){
        A.insert(addi.second);
        SUM+=addi.second;
        addi.second-=2;
        M.insert(minu.first);
        SUM-=minu.first;
        minu.first+=2;
    }
    // cerr<<SUM<<" "<<F<<" "<<addi.second<<" "<<minu.first<<endl;
    // exit(0);
    assert(SUM>=F);
    set<int> era;
    if((SUM-F)%2==1){
        if(addi.first<=addi.second&&minu.first<=minu.second&&SUM+addi.second-minu.first>=F){
            A.insert(addi.second);
            SUM+=addi.second;
            addi.second-=2;
            M.insert(minu.first);
            SUM-=minu.first;
            minu.first+=2;
        }
        else{
            A.erase(addi.second+2);
            addi.second+=2;
            SUM-=addi.second;
            M.erase(minu.first-2);
            minu.first-=2;
            SUM+=minu.first;
        }
    }
    while (SUM>F){
        while (!A.empty()&&*A.begin()==MinA){
            way.push_back(x+1-MinA);
            A.erase(A.begin());
            MinA+=2;
        }
        while (!M.empty()&&*prev(M.end())==MaxM){
            way.push_back(x+1-MaxM);
            M.erase(prev(M.end()));
            MaxM-=2;
        }
        if(!A.empty()){
            int x=*A.begin();
            A.erase(A.begin());
            int y=min((LL)(x-MinA),SUM-F);
            A.insert(x-y);
            SUM-=y;
        }
        else{
            // cerr<<M.size()<<endl;
            if(M.empty()){
                assert(MaxM+2<R&&MinA-2>L&&SUM+MaxM+2+MaxM+4-(MinA-2)-(MinA-4)<=F);
                int X1=MaxM+2,X2=MaxM+4;
                int Y1=MinA-4,Y2=MinA-2;
                while(SUM+X1+X2-Y1-Y2<F&&Y1>L) Y1-=2;
                while(SUM+X1+X2-Y1-Y2<F&&Y2-2>Y1) Y2-=2;
                while(SUM+X1+X2-Y1-Y2<F&&X2<R) X2+=2;
                while(SUM+X1+X2-Y1-Y2<F&&X1+2<X2) X1+=2;
                era.insert(x+1-X1);
                era.insert(x+1-X2);
                era.insert(x+1-Y1);
                era.insert(x+1-Y2);
                assert(SUM+X1+X2-Y1-Y2==F);
                break;
            }
            assert(!M.empty());
            int x=*prev(M.end());
            M.erase(prev(M.end()));
            int y=min((LL)(MaxM-x),SUM-F);
            M.insert(x+y);
            SUM-=y;
        }
    }
    // cerr<<SUM<<" "<<F<<endl;
    rep(i,way.size()){
        if(era.count(way[i])){
            // cout<<"!"<<endl;
            swap(way[i],way.back());
            way.pop_back();
            --i;
        }
    }
    for(auto it:A) way.push_back(x+1-it);
    for(auto it:M) way.push_back(x+1-it);
    cout<<way.size()<<'\n';
    // exit(0);
    for(auto it:way) cout<<it<<" ";
    cout<<'\n';
}
bool chk(int flag){
    rb(i,1,n) ok[i]=0;
    rb(i,1,n) {a[i]=A[i];if(i&1) a[i]=-a[i];}
    rb(i,1,m) {b[i]=B[i];if((i&1)==flag) b[i]=-b[i];}
    rb(i,2,n) c[i]=a[i-1]-a[i];
    rb(i,2,m) d[i]=b[i-1]-b[i];
    rb(i,3,n) {f[i]=c[i]-c[i-1];}
    rb(i,3,m) {g[i]=d[i]-d[i-1];if(((i^(!flag))&1)) g[i]--;}
    calc_match();
    // cout<<flag<<endl;
    // rb(i,3,n) cout<<f[i]<<' ';
    // cout<<endl;
    // rb(i,3,m) cout<<g[i]<<" ";
    // cout<<endl;
    // return 0;
    rb(i,1,n-m+1) if((i&1)==flag&&ok[i]){
        // cout<<"____"<<i<<endl;
        // i
        if(!check(i)) continue;
        // cout<<"!"<<endl;
        rep(j,m) e[i+j]=b[j+1]-a[i+j];
        bool can=1;
        rl(j,m,3){
            LL delta=(e[i+j-1]-e[i+j-2])-(e[i+j-2]-e[i+j-3]);
            if(delta!=0){
                if(!((j^(!flag))&1)){
                    if(delta!=1){
                        can=0;
                        break;
                    }
                }
                else{
                    if(delta!=-1){
                        can=0;
                        break;
                    }
                }
            }
        }
        if(!can) continue;
        construct(i);
        return true;
    }
    return false;
}
int TTT=0;
void solve(){
    cin>>n;
    rb(i,1,n) cin>>A[i];
    cin>>m;
    rb(i,1,m) cin>>B[i];
    if(chk(0)) {return ;}
    if(chk(1)) {return ;}
    cout<<"-1\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    // if(T==10000){
    //     rb(i,1,T){
    //         int n,m;
    //         cin>>n;
    //         rb(i,1,n){
    //             cin>>a[i];
    //         }
    //         cin>>m;
    //         rb(i,1,m){
    //             cin>>b[i];
    //         }
    //         if(i==63){
    //             cout<<n<<endl;
    //             rb(i,1,n){
    //                 cout<<a[i]<<" ";
    //             }
    //             cout<<endl;
    //             cout<<m<<endl;
    //             rb(i,1,m){
    //                 cout<<b[i]<<" ";
    //             }
    //             cout<<endl;
    //         }
    //     }
    //     return 0;
    // }
    while (T--){
        ++TTT;
        solve();
    }
    return 0;
}