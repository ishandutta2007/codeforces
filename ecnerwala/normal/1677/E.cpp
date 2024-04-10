#include <bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

namespace seg_tree {

// Floor of log_2(a); index of highest 1-bit
inline int log_2(int a) {
	return a ? (8 * sizeof(a)) - 1 - __builtin_clz(a) : -1;
}

inline int next_pow_2(int a) {
	assert(a > 0);
	return 1 << log_2(2*a-1);
}

struct point {
	int a;
	point() : a(0) {}
	explicit point(int a_) : a(a_) { assert(a >= -1); }

	explicit operator bool () { return bool(a); }

	// This is useful so you can directly do array indices
	/* implicit */ operator int() const { return a; }

	point c(bool z) const {
		return point((a<<1)|z);
	}

	point operator [] (bool z) const {
		return c(z);
	}

	point p() const {
		return point(a>>1);
	}

	friend std::ostream& operator << (std::ostream& o, const point& p) { return o << int(p); }

	template <typename F> void for_each(F f) const {
		for (int v = a; v > 0; v >>= 1) {
			f(point(v));
		}
	}

	template <typename F> void for_parents_down(F f) const {
		// strictly greater than 0
		for (int L = log_2(a); L > 0; L--) {
			f(point(a >> L));
		}
	}

	template <typename F> void for_parents_up(F f) const {
		for (int v = a >> 1; v > 0; v >>= 1) {
			f(point(v));
		}
	}

	point& operator ++ () { ++a; return *this; }
	point operator ++ (int) { return point(a++); }
	point& operator -- () { --a; return *this; }
	point operator -- (int) { return point(a--); }
};

struct range {
	int a, b;
	range() : a(1), b(1) {}
	range(int a_, int b_) : a(a_), b(b_) {
		assert(1 <= a && a <= b && b <= 2 * a);
	}
	explicit range(std::array<int, 2> r) : range(r[0], r[1]) {}

	explicit operator std::array<int, 2>() const {
		return {a,b};
	}

	const int& operator[] (bool z) const {
		return z ? b : a;
	}

	friend std::ostream& operator << (std::ostream& o, const range& r) { return o << "[" << r.a << ".." << r.b << ")"; }

	// Iterate over the range from outside-in.
	//   Calls f(point a)
	template <typename F> void for_each(F f) const {
		for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
			if (x & 1) f(point(x++));
			if (y & 1) f(point(--y));
		}
	}

	// Iterate over the range from outside-in.
	//   Calls f(point a, bool is_right)
	template <typename F> void for_each_with_side(F f) const {
		for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
			if (x & 1) f(point(x++), false);
			if (y & 1) f(point(--y), true);
		}
	}

	// Iterate over the range from left to right.
	//    Calls f(point)
	template <typename F> void for_each_l_to_r(F f) const {
		int anc_depth = log_2((a-1) ^ b);
		int anc_msk = (1 << anc_depth) - 1;
		for (int v = (-a) & anc_msk; v; v &= v-1) {
			int i = __builtin_ctz(v);
			f(point(((a-1) >> i) + 1));
		}
		for (int v = b & anc_msk; v; ) {
			int i = log_2(v);
			f(point((b >> i) - 1));
			v ^= (1 << i);
		}
	}

	// Iterate over the range from right to left.
	//    Calls f(point)
	template <typename F> void for_each_r_to_l(F f) const {
		int anc_depth = log_2((a-1) ^ b);
		int anc_msk = (1 << anc_depth) - 1;
		for (int v = b & anc_msk; v; v &= v-1) {
			int i = __builtin_ctz(v);
			f(point((b >> i) - 1));
		}
		for (int v = (-a) & anc_msk; v; ) {
			int i = log_2(v);
			f(point(((a-1) >> i) + 1));
			v ^= (1 << i);
		}
	}

	template <typename F> void for_parents_down(F f) const {
		int x = a, y = b;
		if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
		int dx = __builtin_ctz(x);
		int dy = __builtin_ctz(y);
		int anc_depth = log_2((x-1) ^ y);
		for (int i = log_2(x); i > dx; i--) {
			f(point(x >> i));
		}
		for (int i = anc_depth; i > dy; i--) {
			f(point(y >> i));
		}
	}

	template <typename F> void for_parents_up(F f) const {
		int x = a, y = b;
		if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
		int dx = __builtin_ctz(x);
		int dy = __builtin_ctz(y);
		int anc_depth = log_2((x-1) ^ y);
		for (int i = dx+1; i <= anc_depth; i++) {
			f(point(x >> i));
		}
		for (int v = y >> (dy+1); v; v >>= 1) {
			f(point(v));
		}
	}
};

struct in_order_layout {
	// Alias them in for convenience
	using point = seg_tree::point;
	using range = seg_tree::range;

	int N, S;
	in_order_layout() : N(0), S(0) {}
	in_order_layout(int N_) : N(N_), S(N ? next_pow_2(N) : 0) {}

	point get_point(int a) const {
		assert(0 <= a && a < N);
		a += S;
		return point(a >= 2 * N ? a - N : a);
	}

	range get_range(int a, int b) const {
		assert(0 <= a && a <= b && b <= N);
		if (N == 0) return range();
		a += S, b += S;
		return range((a >= 2 * N ? 2*(a-N) : a), (b >= 2 * N ? 2*(b-N) : b));
	}

	range get_range(std::array<int, 2> p) const {
		return get_range(p[0], p[1]);
	}

	int get_leaf_index(point pt) const {
		int a = int(pt);
		assert(N <= a && a < 2 * N);
		return (a < S ? a + N : a) - S;
	}

	std::array<int, 2> get_node_bounds(point pt) const {
		int a = int(pt);
		assert(1 <= a && a < 2 * N);
		int l = __builtin_clz(a) - __builtin_clz(2*N-1);
		int x = a << l, y = (a+1) << l;
		assert(S <= x && x < y && y <= 2*S);
		return {(x >= 2 * N ? (x>>1) + N : x) - S, (y >= 2 * N ? (y>>1) + N : y) - S};
	}

	int get_node_split(point pt) const {
		int a = int(pt);
		assert(1 <= a && a < N);
		int l = __builtin_clz(2*a+1) - __builtin_clz(2*N-1);
		int x = (2*a+1) << l;
		assert(S <= x && x < 2*S);
		return (x >= 2 * N ? (x>>1) + N : x) - S;
	}

	int get_node_size(point pt) const {
		auto bounds = get_node_bounds(pt);
		return bounds[1] - bounds[0];
	}
};

struct circular_layout {
	// Alias them in for convenience
	using point = seg_tree::point;
	using range = seg_tree::range;

	int N;
	circular_layout() : N(0) {}
	circular_layout(int N_) : N(N_) {}

	point get_point(int a) const {
		assert(0 <= a && a < N);
		return point(N + a);
	}

	range get_range(int a, int b) const {
		assert(0 <= a && a <= b && b <= N);
		if (N == 0) return range();
		return range(N + a, N + b);
	}

	range get_range(std::array<int, 2> p) const {
		return get_range(p[0], p[1]);
	}

	int get_leaf_index(point pt) const {
		int a = int(pt);
		assert(N <= a && a < 2 * N);
		return a - N;
	}

	// Returns {x,y} so that 0 <= x < N and 1 <= y <= N
	// If the point is non-wrapping, then 0 <= x < y <= N
	std::array<int, 2> get_node_bounds(point pt) const {
		int a = int(pt);
		assert(1 <= a && a < 2 * N);
		int l = __builtin_clz(a) - __builtin_clz(2*N-1);
		int S = next_pow_2(N);
		int x = a << l, y = (a+1) << l;
		assert(S <= x && x < y && y <= 2*S);
		return {(x >= 2 * N ? x >> 1 : x) - N, (y > 2 * N ? y >> 1 : y) - N};
	}

	// Returns the split point of the node, such that 1 <= s <= N.
	int get_node_split(point pt) const {
		int a = int(pt);
		assert(1 <= a && a < N);
		return get_node_bounds(pt.c(0))[1];
	}

	int get_node_size(point pt) const {
		auto bounds = get_node_bounds(pt);
		int r = bounds[1] - bounds[0];
		return r > 0 ? r : r + N;
	}
};

} // namespace seg_tree

struct cnt_min {
	int val = 0;
	int64_t cnt = 0;

	explicit operator int64_t() {
		assert(val >= 0);
		return val == 0 ? cnt : 0;
	}

	cnt_min& operator += (cnt_min o) {
		if (o.cnt == 0) {
			// no-op
		} else if (!cnt || o.val < val) {
			val = o.val;
			cnt = o.cnt;
		} else if (o.val == val) {
			cnt += o.cnt;
		}
		return *this;
	}
	friend cnt_min operator + (cnt_min a, cnt_min b) {
		return a += b;
	}
	cnt_min& operator *= (cnt_min o) {
		val += o.val;
		cnt *= o.cnt;
		return *this;
	}
	friend cnt_min operator * (cnt_min a, cnt_min b) {
		return a *= b;
	}
};


int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	std::vector<int> P(N);
	for (auto& a : P) { cin >> a; }

	std::vector<int> invP(N+1);
	for (int i = 0; i < N; i++) invP[P[i]] = i;

	std::vector<int> prvBigger(N);
	std::vector<int> nxtBigger(N);
	{
		std::vector<std::pair<int, int>> stk; stk.reserve(N+1);
		stk.push_back({N+1, -1});
		for (int i = 0; i < N; i++) {
			while (P[i] > stk.back().first) {
				nxtBigger[stk.back().second] = i;
				stk.pop_back();
			}
			prvBigger[i] = stk.back().second;
			stk.push_back({P[i], i});
		}
		while (stk.size() > 1) {
			nxtBigger[stk.back().second] = N;
			stk.pop_back();
		}
	}

	std::vector<std::vector<std::pair<int, int>>> inserts(N);
	std::vector<std::vector<std::pair<int, int>>> deletes(N);

	for (int i = 1; i <= N; i++) {
		for (int j = i+1; int64_t(i)*j <= N; j++) {
			int x = invP[i], y = invP[j];
			int z = invP[i*j];

			int l_lo = prvBigger[z] + 1, r_hi = nxtBigger[z] - 1;
			int l_hi = std::min({x, y, z});
			int r_lo = std::max({x, y, z});
			if (l_lo > l_hi || r_lo > r_hi) continue;
			// l_lo <= l <= l_hi <= r_lo <= r <= r_hi
			//cerr << l_lo << "-" << l_hi << ' ' << r_lo << '-' << r_hi << '\n';
			inserts[r_lo].push_back({l_lo, l_hi});
			deletes[r_hi].push_back({l_lo, l_hi});
		}
	}

	seg_tree::in_order_layout layout(N);
	struct seg_t {
		cnt_min val;
		cnt_min sum;
		int lazy_incr = 0;
		cnt_min lazy_coeff;
	};
	std::vector<seg_t> seg(N*2);
	auto update_node = [&](seg_tree::point a) -> void {
		seg[a].val = seg[a[0]].val + seg[a[1]].val;
	};
	for (int i = 0; i < N; i++) { seg[N+i].val = cnt_min{0, 1}; }
	for (seg_tree::point a(N-1); a > 0; a--) update_node(a);
	auto apply_lazy = [&](seg_tree::point a, cnt_min lazy_coeff, int lazy_incr) -> void {
		seg[a].sum += seg[a].val * lazy_coeff;
		seg[a].val.val += lazy_incr;
		lazy_coeff.val += seg[a].lazy_incr;
		seg[a].lazy_coeff += lazy_coeff;
		seg[a].lazy_incr += lazy_incr;
	};
	auto downdate_node = [&](seg_tree::point a) -> void {
		apply_lazy(a[0], seg[a].lazy_coeff, seg[a].lazy_incr);
		apply_lazy(a[1], seg[a].lazy_coeff, seg[a].lazy_incr);
		seg[a].lazy_incr = 0;
		seg[a].lazy_coeff = {0, 0};
	};

	auto update_range = [&](std::pair<int, int> interval, int v) -> void {
		auto [l, r] = interval;
		assert(l <= r);
		auto rng = layout.get_range(l, r+1);
		rng.for_parents_down(downdate_node);
		rng.for_each([&](auto a) -> void {
			apply_lazy(a, cnt_min{0, 0}, v);
		});
		rng.for_parents_up(update_node);
	};
	auto do_sum = [&]() -> void {
		apply_lazy(seg_tree::point(1), cnt_min{0, 1}, 0);
	};

	for (int i = 0; i < N; i++) update_range({i, i}, +1);

	std::vector<std::vector<std::pair<int, int>>> queries(N);
	std::vector<int64_t> ans(Q);
	for (int q = 0; q < Q; q++) {
		int l, r; cin >> l >> r; l--, r--;
		queries[r].push_back({l, q});
	}
	for (int i = 0; i < N; i++) {
		update_range({i, i}, -1);
		for (auto ls : inserts[i]) update_range(ls, +1);
		do_sum();

		for (auto [l, q] : queries[i]) {
			auto rng = layout.get_range(l, N);
			rng.for_parents_down(downdate_node);
			cnt_min res;
			rng.for_each([&](auto a) -> void {
				res += seg[a].sum;
			});
			int len = i+1 - l;
			int64_t tot = int64_t(len) * int64_t(len + 1) / 2;
			ans[q] = tot - int64_t(res);
		}
		for (auto ls : deletes[i]) update_range(ls, -1);
	}

	for (int q = 0; q < Q; q++) {
		cout << ans[q] << '\n';
	}

	return 0;
}