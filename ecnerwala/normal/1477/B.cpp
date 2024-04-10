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
	explicit point(int a_) : a(a_) { assert(a >= 0); }

	explicit operator bool () { return bool(a); }

	// This is useful so you can directly do array indices
	/* implicit */ operator int() const { return a; }

	point c(bool z) const {
		return point((a<<1)|z);
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
};

struct range {
	int a, b;
	range() : a(0), b(0) {}
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

	template <typename F> void for_each(F f) const {
		for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
			if (x & 1) f(point(x++), false);
			if (y & 1) f(point(--y), true);
		}
	}

	template <typename F> void for_parents_down(F f) const {
		int x = a >> __builtin_ctz(a);
		int y = b >> __builtin_ctz(b);

		// TODO: dedup
		point(x).for_parents_down(f);
		point(y).for_parents_down(f);
	}

	template <typename F> void for_parents_up(F f) const {
		int x = a >> __builtin_ctz(a);
		int y = b >> __builtin_ctz(b);

		// TODO: dedup
		point(x).for_parents_up(f);
		point(y).for_parents_up(f);
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

	int get_node_size(point pt) const {
		auto [x, y] = get_node_bounds(pt);
		return y - x;
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

	int get_node_size(point pt) const {
		auto [x, y] = get_node_bounds(pt);
		int r = y - x;
		return r > 0 ? r : r + N;
	}
};

} // namespace seg_tree

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, Q; cin >> N >> Q;
		string S, F; cin >> S >> F;
		vector<array<int, 2>> updates(Q);
		for (auto& v : updates) { cin >> v[0] >> v[1], v[0]--; }
		reverse(updates.begin(), updates.end());

		seg_tree::circular_layout seg(N);
		struct seg_data {
			bool lazy = false;
			int cnt[2] = {0,0};
		};
		vector<seg_data> dat(2*N);
		auto update_node = [&](seg_tree::point a) {
			assert(a < N);
			assert(!dat[a].lazy);
			dat[a].cnt[0] = dat[2*a].cnt[0] + dat[2*a+1].cnt[0];
			dat[a].cnt[1] = dat[2*a].cnt[1] + dat[2*a+1].cnt[1];
		};
		auto do_set = [&](seg_tree::point a, bool v) {
			dat[a].lazy = true;
			dat[a].cnt[v] += std::exchange(dat[a].cnt[!v], 0);
		};
		auto downdate_node = [&](seg_tree::point a) {
			assert(a < N);
			if (dat[a].lazy) {
				bool dir = bool(dat[a].cnt[1]);
				do_set(a.c(0), dir);
				do_set(a.c(1), dir);
				dat[a].lazy = false;
			}
		};
		for (int i = 0; i < N; i++) {
			dat[N+i].lazy = false;
			dat[N+i].cnt[F[i]-'0'] = 1;
		}
		for (int a = N-1; a; a--) {
			dat[a].lazy = false;
			update_node(seg_tree::point(a));
		}
		for (auto [l, r] : updates) {
			auto rng = seg.get_range(l, r);
			rng.for_parents_down(downdate_node);
			int cnt[2] = {0,0};
			rng.for_each([&](seg_tree::point a, bool) {
				cnt[0] += dat[a].cnt[0];
				cnt[1] += dat[a].cnt[1];
			});
			if (cnt[0] == cnt[1]) {
				cout << "NO" << '\n';
				goto done;
			}
			bool dir = cnt[1] > cnt[0];
			rng.for_each([&](seg_tree::point a, bool) {
				do_set(a, dir);
			});
			rng.for_parents_up(update_node);
		}
		for (int a = 1; a < N; a++) {
			downdate_node(seg_tree::point(a));
		}
		for (int i = 0; i < N; i++) {
			if (!dat[N+i].cnt[S[i]-'0']) {
				cout << "NO" << '\n';
				goto done;
			}
		}
		cout << "YES" << '\n';
		done:;
	}

	return 0;
}