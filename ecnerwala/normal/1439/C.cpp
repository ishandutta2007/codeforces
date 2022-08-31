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
int log_2(int a) {
	return a ? (8 * sizeof(a)) - 1 - __builtin_clz(a) : -1;
}

int next_pow_2(int a) {
	assert(a > 0);
	return 1 << log_2(2*a-1);
}

template <typename F> void for_parents_up(int a, F f) {
	a >>= 1;
	for (; a > 0; a >>= 1) {
		f(a);
	}
}

template <typename F> void for_parents_down(int a, F f) {
	a >>= 1;
	for (int L = log_2(a); L >= 0; L--) {
		f(a >> L);
	}
}

template <typename F> void for_range_parents_up(std::array<int, 2> r, F f) {
	auto [a, b] = r;
	assert(a && b);
	a >>= __builtin_ctz(a);
	b >>= __builtin_ctz(b);

	// TODO: dedup
	for_parents_up(a, f);
	for_parents_up(b, f);
}

template <typename F> void for_range_parents_down(std::array<int, 2> r, F f) {
	auto [a, b] = r;
	assert(a && b);
	a >>= __builtin_ctz(a);
	b >>= __builtin_ctz(b);

	// TODO: dedup
	for_parents_down(a, f);
	for_parents_down(b, f);
}

template <typename F> void for_point(int a, F f) {
	for (; a > 0; a >>= 1) {
		f(a);
	}
}

template <typename F> void for_range(std::array<int, 2> r, F f) {
	auto [a, b] = r;
	assert(a <= b && b <= 2*a);
	for (; a < b; a >>= 1, b >>= 1) {
		if (a & 1) f(a++, false);
		if (b & 1) f(--b, true);
	}
}

namespace in_order {

int get_point(int N, int a) {
	assert(0 <= a && a < N);
	int S = next_pow_2(N);
	a += S;
	return a >= 2 * N ? a - N : a;
}

std::array<int, 2> get_range(int N, std::array<int, 2> p) {
	auto [a, b] = p;
	assert(0 <= a && a <= b && b <= N);
	int S = next_pow_2(N);
	a += S, b += S;
	return { (a >= 2 * N ? 2*(a-N) : a), (b >= 2 * N ? 2*(b-N) : b) };
}

int get_node_index(int N, int a) {
	assert(N <= a && a < 2 * N);
	int S = next_pow_2(N);
	return (a < S ? a + N : a) - S;
}

std::array<int, 2> get_node_bounds(int N, int a) {
	assert(1 <= a && a < 2 * N);
	int l = __builtin_clz(a) - __builtin_clz(2*N-1);
	int S = next_pow_2(N);
	int x = a << l, y = (a+1) << l;
	assert(S <= x && x < y && y <= 2*S);
	return {(x >= 2 * N ? (x>>1) + N : x) - S, (y >= 2 * N ? (y>>1) + N : y) - S};
}

int get_node_size(int N, int a) {
	assert(1 <= a && a < 2 * N);
	auto [x, y] = get_node_bounds(N, a);
	return y - x;
}

} // namespace in_order

namespace circular {

int get_point(int N, int a) {
	assert(0 <= a && a < N);
	return N + a;
}

std::array<int, 2> get_range(int N, std::array<int, 2> p) {
	auto [a, b] = p;
	assert(0 <= a && a <= b && b <= N);
	return { N + a, N + b };
}

int get_node_index(int N, int a) {
	assert(N <= a && a < 2 * N);
	return a - N;
}

std::array<int, 2> get_node_bounds(int N, int a) {
	assert(1 <= a && a < 2 * N);
	int l = __builtin_clz(a) - __builtin_clz(2*N-1);
	int S = next_pow_2(N);
	int x = a << l, y = (a+1) << l;
	assert(S <= x && x < y && y <= 2*S);
	return {(x >= 2 * N ? x >> 1 : x) - N, (y >= 2 * N ? y >> 1 : y) - N};
}

int get_node_size(int N, int a) {
	assert(1 <= a && a < 2 * N);
	return in_order::get_node_size(N, a);
}

} // namespace circular

} // namespace seg_tree

namespace seg_tree { using namespace in_order; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;

	// 0 is unset
	vector<int> lazy_set(2*N);
	vector<int64_t> sum(2*N);
	vector<int> min_val(2*N);
	vector<int> max_val(2*N);

	auto update_node = [&](int a) {
		if (lazy_set[a]) {
			min_val[a] = max_val[a] = lazy_set[a];
			sum[a] = int64_t(lazy_set[a]) * seg_tree::get_node_size(N, a);
		} else {
			assert(a < N);
			assert(min_val[2*a] >= max_val[2*a+1]);
			max_val[a] = max_val[2*a];
			min_val[a] = min_val[2*a+1];
			sum[a] = sum[2*a] + sum[2*a+1];
		}
	};

	auto downdate_node = [&](int a) {
		if (a < N && lazy_set[a]) {
			lazy_set[2*a] = lazy_set[a];
			update_node(2*a);
			lazy_set[2*a+1] = lazy_set[a];
			update_node(2*a+1);
			lazy_set[a] = 0;
		}
	};

	auto try_set = std::y_combinator([&](auto self, int a, int v) -> void {
		if (v <= min_val[a]) {
			//cerr << "not setting " << a << ' ' << seg_tree::get_node_bounds(N, a)[0] << ' ' << seg_tree::get_node_bounds(N,a)[1] << '\n';
			//cerr << v << ' ' << max_val[a] << ' ' << min_val[a] << '\n';
			return;
		}
		if (v >= max_val[a]) {
			//cerr << "setting " << a << ' ' << seg_tree::get_node_bounds(N, a)[0] << ' ' << seg_tree::get_node_bounds(N,a)[1] << '\n';
			//cerr << v << ' ' << max_val[a] << ' ' << min_val[a] << '\n';
			lazy_set[a] = v;
			update_node(a);
			return;
		}
		assert(min_val[a] < v && v < max_val[a]);
		assert(!lazy_set[a]);
		self(2*a, v);
		self(2*a+1, v);
		update_node(a);
	});

	for (int i = 0; i < N; i++) {
		int v; cin >> v;
		int a = seg_tree::get_point(N, i);
		lazy_set[a] = v;
	}
	for (int a = 2*N-1; a > 0; a--) update_node(a);

	while (Q--) {
		int t, x, y; cin >> t >> x >> y;
		x--;
		if (t == 1) {
			auto r = seg_tree::get_range(N, {0, x+1});
			seg_tree::for_range_parents_down(r, downdate_node);
			seg_tree::for_range(r, [&](int a, bool) {
				try_set(a, y);
			});
			seg_tree::for_range_parents_up(r, update_node);
		} else if (t == 2) {
			int64_t tot_pref = y;
			{
				auto r = seg_tree::get_range(N, {0, x});
				seg_tree::for_range_parents_down(r, downdate_node);
				seg_tree::for_range(r, [&](int a, bool) {
					tot_pref += sum[a];
				});
			}

			//cerr << tot_pref << '\n';

			int ans = -x;
			std::y_combinator([&](auto self, int a) -> void {
				if (tot_pref >= sum[a]) {
					//cerr << "buying all of " << a << ' ' << seg_tree::get_node_bounds(N, a)[0] << ' ' << seg_tree::get_node_bounds(N,a)[1] << '\n';
					//cerr << tot_pref << ' ' << sum[a] << '\n';
					tot_pref -= sum[a];
					ans += seg_tree::get_node_size(N, a);
					return;
				}
				if (tot_pref < min_val[a]) {
					//cerr << "skipping " << a << ' ' << seg_tree::get_node_bounds(N, a)[0] << ' ' << seg_tree::get_node_bounds(N,a)[1] << '\n';
					//cerr << tot_pref << ' ' << min_val[a] << ' ' << max_val[a] << '\n';
					return;
				}
				if (max_val[a] == min_val[a]) {
					//cerr << "buying some of " << a << ' ' << seg_tree::get_node_bounds(N, a)[0] << ' ' << seg_tree::get_node_bounds(N,a)[1] << '\n';
					//cerr << tot_pref << ' ' << min_val[a] << '\n';
					int64_t num_buy = tot_pref / min_val[a];
					tot_pref -= num_buy * min_val[a];
					ans += int(num_buy);
					return;
				}
				assert(!lazy_set[a]);
				self(2*a);
				self(2*a+1);
			})(1);
			cout << ans << '\n';
		} else assert(false);
	}

	return 0;
}