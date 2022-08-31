#include <bits/stdc++.h>

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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;

	std::vector<int> P(2*N+1);
	for (auto& p : P) { cin >> p; p--; }

	std::vector<int> pos(2*N+1);
	for (int i = 0; i < 2*N+1; i++) {
		pos[P[i]] = i;
	}

	seg_tree::in_order_layout layout(2*N+1);
	struct seg_node {
		int lazy = 0;
		int val = 0;
	};
	std::vector<seg_node> seg(layout.N * 2);
	auto update_node = [&](seg_tree::point a) {
		seg[a].val = seg[a].lazy + std::min(seg[a[0]].val, seg[a[1]].val);
	};

	auto update_prefs = [&](int i, int delta) {
		auto rng = layout.get_range(i+1, 2*N+1);
		rng.for_each([&](seg_tree::point a) {
			seg[a].lazy += delta;
			seg[a].val += delta;
		});
		rng.for_parents_up(update_node);
	};
	for (int i = 0; i < 2*N+1; i++) {
		update_prefs(i, (P[i] > N) - (P[i] < N));
	}

	int lo_sum = 0;
	for (int i = 0; i+1 <= N; i++) {
		lo_sum += (pos[i+1] - pos[i] + 2*N+1) % (2*N+1);
	}
	lo_sum += (pos[0] - pos[N] + 2*N+1) % (2*N+1);

	int hi_sum = 0;
	for (int i = N; i+1 <= 2*N; i++) {
		hi_sum += (pos[i+1] - pos[i] + 2*N+1) % (2*N+1);
	}
	hi_sum += (pos[N] - pos[2*N] + 2*N+1) % (2*N+1);

	auto solve = [&]() -> int {
		int mid_pref = 0;
		layout.get_point(pos[N]).for_each([&](seg_tree::point a) {
			mid_pref += seg[a].lazy;
		});
		if (mid_pref != seg[1].val) {
			assert(mid_pref > seg[1].val);
			seg_tree::point a(1);
			while (a < layout.N) {
				a = seg[a[0]].val < seg[a[1]].val ? a[0] : a[1];
			}
			return layout.get_leaf_index(a);
		}

		// Otherwise, check the ..pos[N] and pos[N]..
		if (lo_sum != 2*N+1) {
			return (pos[N] + 1) % (2*N+1);
		}
		if (hi_sum != 2*N+1) {
			return pos[N];
		}
		return -1;
	};

	auto do_swap = [&](int u, int v) {
		std::vector<std::array<int, 2>> relevant; relevant.reserve(8);
		for (int a : {P[u], P[v]}) {
			if (a-1 >= 0) {
				relevant.push_back({a-1, a});
			}
			if (a+1 <= 2*N) {
				relevant.push_back({a, a+1});
			}
			if (a == 0 || a == N) {
				relevant.push_back({N, 0});
			}
			if (a == N || a == 2*N) {
				relevant.push_back({2*N, N});
			}
		}
		std::sort(relevant.begin(), relevant.end());
		relevant.resize(std::unique(relevant.begin(), relevant.end()) - relevant.begin());

		for (auto [x, y] : relevant) {
			(x+y < 2*N ? lo_sum : hi_sum) -= (pos[y] - pos[x] + 2*N+1) % (2*N+1);
		}

		std::swap(P[u], P[v]);
		pos[P[u]] = u;
		pos[P[v]] = v;

		for (auto [x, y] : relevant) {
			(x+y < 2*N ? lo_sum : hi_sum) += (pos[y] - pos[x] + 2*N+1) % (2*N+1);
		}

		update_prefs(u, ((P[u] > N) - (P[u] < N)) - ((P[v] > N) - (P[v] < N)));
		update_prefs(v, ((P[v] > N) - (P[v] < N)) - ((P[u] > N) - (P[u] < N)));
	};

	while (Q--) {
		int u, v; cin >> u >> v; u--, v--;
		do_swap(u, v);
		cout << solve() << '\n';
	}

	return 0;
}