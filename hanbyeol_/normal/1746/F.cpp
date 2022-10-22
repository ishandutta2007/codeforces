
#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
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


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


#include <cassert>
#include <vector>


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

// Reference: https://en.wikipedia.org/wiki/Fenwick_tree
template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  // namespace atcoder


#include <bits/stdc++.h>
using namespace std;

using S = uint64_t;
S op(S a, S b) { return a ^ b; }
S e() { return 0; }
using Xor2Seg = atcoder::segtree<S, op, e>;

auto upper = UINT64_C(0xAAAAAAAAAAAAAAAA);
S op3(S a, S b)
{
	//cout << bitset<64>(a) << endl;
	//cout << bitset<64>(b) << endl;

	S g = a & b & upper;
	a -= g, b -= g;
	S t = g >> 1;
	//cout << bitset<64>(g) << endl;
	S r = a + b + t;
	//cout << bitset<64>(r) << endl;
	S c = r & (r >> 1) & (~upper);
	//cout << bitset<64>(r - (3 * c)) << endl;
	//cout << "++" << endl;
	return r - (3 * c);
}
using Xor3Seg = atcoder::segtree<S, op3, e>;

auto B3 = UINT64_C(0x9249249249249249);
S op4(S a, S b)
{
	return (a + b) & ~B3;
}

using Xor4Seg = atcoder::segtree<S, op4, e>;

using fw = atcoder::fenwick_tree<uint64_t>;
const int FW = 15;

int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int &x : A)
		cin >> x;
	vector<tuple<int, int, int, int>> Qry(Q);

	vector<int> B = A;
	for (auto &[t, a, b, c] : Qry)
	{
		cin >> t;
		if (t == 1)
			cin >> a >> b, --a, B.push_back(b);
		else
			cin >> a >> b >> c, --a;
	}
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	for (int &x : A)
		x = lower_bound(B.begin(), B.end(), x) - B.begin();

	int K = B.size();
	{
		vector<uint64_t> Hr2(K), Hr3(K), Hr4(K);
		vector<vector<uint64_t>> Hrg(K, vector<uint64_t>(FW));
		for (int i = 0; i < K; i++)
			Hr2[i] = rng();
		for (int i = 0; i < K; i++)
		{
			uniform_int_distribution<uint64_t> dis(0, 2);
			for (int j = 0; j < 32; j++)
				Hr3[i] =  (Hr3[i]<<2) + dis(rng);
		}
		for (int i = 0; i < K; i++)
			Hr4[i] = rng() & ~B3;

		uniform_int_distribution<uint64_t> dis(1, (long long)1e12);
		for (int i = 0; i < K; i++)
			for (int j = 0; j < FW; j++)
				Hrg[i][j] = dis(rng);

		vector<S> X2(N), X3(N), X4(N);
		vector<fw> F(FW, fw(N));
		for (int i = 0; i < N; i++)
		{
			X2[i] = Hr2[A[i]];
			X3[i] = Hr3[A[i]];
			X4[i] = Hr4[A[i]];
			for (int j = 0; j < FW; j++)
				F[j].add(i, Hrg[A[i]][j]);
		}
		Xor2Seg X2S = Xor2Seg(X2);
		Xor3Seg X3S = Xor3Seg(X3);
		Xor4Seg X4S = Xor4Seg(X4);
		for (auto [t, a, b, c] : Qry)
		{
			if (t == 1)
			{
				b = lower_bound(B.begin(), B.end(), b) - B.begin();
				for (int j = 0; j < FW; j++)
				{
					F[j].add(a, -Hrg[A[a]][j]);
					assert(F[j].sum(a, a + 1) == 0);
				}
				A[a] = b;
				X2S.set(a, Hr2[b]);
				X3S.set(a, Hr3[b]);
				X4S.set(a, Hr4[b]);
				for (int j = 0; j < FW; j++)
					F[j].add(a, +Hrg[b][j]);
			}
			else
			{
				auto check = [&](int l, int r, int k)
				{
					if (k == 1)
						return true;
					if ((r - l) % k != 0)
						return false;
					if (k == 2 && X2S.prod(l, r))
						return false;
					if (k == 3 && X3S.prod(l, r))
						return false;
					if (k == 4 && X4S.prod(l, r))
						return false;
					for (int j = 0; j < FW; j++)
					{
						auto sum = F[j].sum(l, r);
						if (sum % k != 0)
							return false;
					}
					return true;
				};
				cout << (check(a, b, c) ? "YES\n" : "NO\n");
			}
		}
	}
}