#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
#include <chrono>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

template<typename float_t>
struct complex {
    float_t x, y;

    complex<float_t>(float_t _x = 0, float_t _y = 0) : x(_x), y(_y) {}

    float_t real() const {
        return x;
    }

    void real(float_t _x) {
        x = _x;
    }

    float_t imag() const {
        return y;
    }

    void imag(float_t _y) {
        y = _y;
    }

    complex<float_t>& operator+=(const complex<float_t> &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    complex<float_t>& operator-=(const complex<float_t> &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    complex<float_t> operator+(const complex<float_t> &other) const {
        return complex<float_t>(*this) += other;
    }

    complex<float_t> operator-(const complex<float_t> &other) const {
        return complex<float_t>(*this) -= other;
    }

    complex<float_t> operator*(const complex<float_t> &other) const {
        return {x * other.x - y * other.y, x * other.y + other.x * y};
    }

    complex<float_t> operator*(float_t mult) const {
        return {x * mult, y * mult};
    }
};

template<typename float_t>
complex<float_t> conj(const complex<float_t> &c) {
    return {c.x, -c.y};
}

template<typename float_t>
complex<float_t> polar(float_t magnitude, float_t angle) {
    return {magnitude * cos(angle), magnitude * sin(angle)};
}

template<typename float_t>
ostream& operator<<(ostream &stream, const complex<float_t> &c) {
    return stream << '(' << c.x << ", " << c.y << ')';
}

namespace FFT {
    using float_t = double;

    const float_t ONE = 1;
    const float_t PI = acos(-ONE);

    vector<complex<float_t>> roots = {{0, 0}, {1, 0}};
    vector<int> bit_reverse;

    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    int round_up_power_two(int n) {
        assert(n > 0);

        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return n;
    }

    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }

    template<typename complex_array>
    void bit_reorder(int n, complex_array &&values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);

            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }

        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }

    void prepare_roots(int n) {
        if ((int) roots.size() >= n)
            return;

        int length = get_length(roots.size());
        roots.resize(n);

        while (1 << length < n) {
            float_t min_angle = 2 * PI / (1 << (length + 1));

            for (int i = 0; i < 1 << (length - 1); i++) {
                int index = (1 << (length - 1)) + i;
                roots[2 * index] = roots[index];
                roots[2 * index + 1] = polar(ONE, min_angle * (2 * i + 1));
            }

            length++;
        }
    }

    template<typename complex_array>
    void fft_iterative(int N, complex_array &&values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);

        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    const complex<float_t> &even = values[start + i];
                    complex<float_t> odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    inline complex<float_t> extract(int N, const vector<complex<float_t>> &values, int index, int side) {
        if (side == -1) {
            int other = (N - index) & (N - 1);
            return (conj(values[other] * values[other]) - values[index] * values[index]) * complex<float_t>(0, 0.25);
        }

        int other = (N - index) & (N - 1);
        int sign = side == 0 ? +1 : -1;
        complex<float_t> multiplier = side == 0 ? complex<float_t>(0.5, 0) : complex<float_t>(0, -0.5);
        return multiplier * complex<float_t>(values[index].real() + values[other].real() * sign,
                                             values[index].imag() - values[other].imag() * sign);
    }

    void invert_fft(int N, vector<complex<float_t>> &values) {
        assert(N >= 2);

        for (int i = 0; i < N; i++)
            values[i] = conj(values[i]) * (ONE / N);

        for (int i = 0; i < N / 2; i++) {
            complex<float_t> first = values[i] + values[N / 2 + i];
            complex<float_t> second = (values[i] - values[N / 2 + i]) * roots[N / 2 + i];
            values[i] = first + second * complex<float_t>(0, 1);
        }

        fft_iterative(N / 2, values);

        for (int i = N - 1; i >= 0; i--)
            values[i] = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
    }

    const int FFT_CUTOFF = 150;
    const double SPLIT_CUTOFF = 2e15;
    const int SPLIT_BASE = 1 << 15;

    template<typename T_out, typename T_in>
    vector<T_out> square(const vector<T_in> &input) {
        int n = input.size();


        if (n < 1.5 * FFT_CUTOFF) {
            vector<T_out> result(2 * n - 1);

            for (int i = 0; i < n; i++) {
                result[2 * i] += (T_out) input[i] * input[i];

                for (int j = i + 1; j < n; j++)
                    result[i + j] += (T_out) 2 * input[i] * input[j];
            }

            return result;
        }

        int N = round_up_power_two(n);
        assert(N >= 2);
        prepare_roots(2 * N);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i += 2)
            values[i / 2] = complex<float_t>(input[i], i + 1 < n ? input[i + 1] : 0);

        fft_iterative(N, values);

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            complex<float_t> even = extract(N, values, i, 0);
            complex<float_t> odd = extract(N, values, i, 1);
            complex<float_t> aux = even * even + odd * odd * roots[N + i] * roots[N + i];
            complex<float_t> tmp = even * odd;
            values[i] = aux - complex<float_t>(0, 2) * tmp;
            values[j] = conj(aux) - complex<float_t>(0, 2) * conj(tmp);
        }

        for (int i = 0; i < N; i++)
            values[i] = conj(values[i]) * (ONE / N);

        fft_iterative(N, values);
        vector<T_out> result(2 * n - 1);

        for (int i = 0; i < (int) result.size(); i++) {
            float_t value = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
            result[i] = is_integral<T_out>::value ? round(value) : value;
        }

        return result;
    }

    template<typename T_out, typename T_in>
    vector<T_out> multiply(const vector<T_in> &left, const vector<T_in> &right) {
        if (left == right)
            return square<T_out>(left);

        int n = left.size();
        int m = right.size();


        if (min(n, m) < FFT_CUTOFF) {
            vector<T_out> result(n + m - 1);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    result[i + j] += (T_out) left[i] * right[j];

            return result;
        }

        int N = round_up_power_two(n + m - 1);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i++)
            values[i].real(left[i]);

        for (int i = 0; i < m; i++)
            values[i].imag(right[i]);

        fft_iterative(N, values);

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            complex<float_t> product_i = extract(N, values, i, -1);
            values[i] = product_i;
            values[j] = conj(product_i);
        }

        invert_fft(N, values);
        vector<T_out> result(n + m - 1);

        for (int i = 0; i < (int) result.size(); i++)
            result[i] = is_integral<T_out>::value ? round(values[i].real()) : values[i].real();

        return result;
    }

    template<typename T>
    vector<T> mod_multiply(const vector<T> &left, const vector<T> &right, T mod, bool split) {
        int n = left.size();
        int m = right.size();

        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] < mod);

        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] < mod);

        if (min(n, m) < (split ? 2 : 1) * FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) mod * mod;
            vector<uint64_t> result(n + m - 1);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) left[i] * right[j];

                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= mod;
                }

            for (uint64_t &x : result)
                if (x >= (uint64_t) mod)
                    x %= mod;

            return vector<T>(result.begin(), result.end());
        }

        if (!split) {
            const vector<uint64_t> &product = multiply<uint64_t>(left, right);
            vector<T> result(n + m - 1);

            for (int i = 0; i < (int) result.size(); i++)
                result[i] = product[i] % mod;

            return result;
        }

        int N = round_up_power_two(n + m - 1);
        vector<complex<float_t>> left_fft(N, 0), right_fft(N, 0);

        for (int i = 0; i < n; i++) {
            left_fft[i].real(left[i] % SPLIT_BASE);
            left_fft[i].imag(left[i] / SPLIT_BASE);
        }

        fft_iterative(N, left_fft);

        if (left == right) {
            copy(left_fft.begin(), left_fft.end(), right_fft.begin());
        } else {
            for (int i = 0; i < m; i++) {
                right_fft[i].real(right[i] % SPLIT_BASE);
                right_fft[i].imag(right[i] / SPLIT_BASE);
            }

            fft_iterative(N, right_fft);
        }

        vector<complex<float_t>> product(N);
        vector<T> result(n + m - 1);

        for (int exponent = 0; exponent <= 2; exponent++) {
            uint64_t multiplier = 1;

            for (int k = 0; k < exponent; k++)
                multiplier = multiplier * SPLIT_BASE % mod;

            fill(product.begin(), product.end(), 0);

            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    if (x + y == exponent)
                        for (int i = 0; i < N; i++)
                            product[i] += extract(N, left_fft, i, x) * extract(N, right_fft, i, y);

            invert_fft(N, product);

            for (int i = 0; i < (int) result.size(); i++) {
                uint64_t value = round(product[i].real());
                result[i] = (result[i] + value % mod * multiplier) % mod;
            }
        }

        return result;
    }

    template<typename T>
    vector<T> mod_power(const vector<T> &v, int exponent, T mod, bool split) {
        assert(exponent >= 0);
        vector<T> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result, mod, split);

            if (exponent >> k & 1)
                result = mod_multiply(result, v, mod, split);
        }

        return result;
    }

    template<typename T>
    vector<T> power(const vector<T> &v, int exponent)
    {
        assert(exponent >= 0);
        vector<T> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--)
        {
            result = multiply<T>(result, result);
            for(auto &x:result)
            {
                x=!!x;
            }
            if (exponent >> k & 1)
            {
                result = multiply<T>(result, v);
                for(auto &x:result)
                {
                    x=!!x;
                }
            }
        }

        return result;
    }
}
using namespace FFT;

void norm(vi& x) {for(int it: x) it=!!it;}

constexpr int MX=1e6+1;
vi poly(1001, 0);

int32_t main() {
    fastio;
    int n, k; cin>>n>>k; rep(i, n) {int x; cin>>x; poly[x]=1;}
    poly=power(poly, k);
    rep(i, poly.size()) if(poly[i]) cout<<i<<' '; cout<<endl;
}