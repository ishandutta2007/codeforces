#include<bits/stdc++.h>

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

template <typename T, class Compare = std::less<T>> class RangeMinQuery : private Compare {
	static const int BUCKET_SIZE = 32;
	static const int BUCKET_SIZE_LOG = 5;
	static_assert(BUCKET_SIZE == (1 << BUCKET_SIZE_LOG), "BUCKET_SIZE should be a power of 2");
	static const int CACHE_LINE_ALIGNMENT = 64;
	int n = 0;
	std::vector<T> data;
	std::vector<T> pref_data;
	std::vector<T> suff_data;
	std::vector<T> sparse_table;
	std::vector<uint32_t> range_mask;

private:
	int num_buckets() const {
		return n >> BUCKET_SIZE_LOG;
	}
	int num_levels() const {
		return num_buckets() ? 32 - __builtin_clz(num_buckets()) : 0;
	}
	int sparse_table_size() const {
		return num_buckets() * num_levels();
	}
private:
	const T& min(const T& a, const T& b) const {
		return Compare::operator()(a, b) ? a : b;
	}
	void setmin(T& a, const T& b) const {
		if (Compare::operator()(b, a)) a = b;
	}

	template <typename Vec> static int get_size(const Vec& v) { using std::size; return int(size(v)); }

public:
	RangeMinQuery() {}
	template <typename Vec> explicit RangeMinQuery(const Vec& data_, const Compare& comp_ = Compare())
		: Compare(comp_)
		, n(get_size(data_))
		, data(n)
		, pref_data(n)
		, suff_data(n)
		, sparse_table(sparse_table_size())
		, range_mask(n)
	{
		for (int i = 0; i < n; i++) data[i] = data_[i];
		for (int i = 0; i < n; i++) {
			if (i & (BUCKET_SIZE-1)) {
				uint32_t m = range_mask[i-1];
				while (m && !Compare::operator()(data[(i | (BUCKET_SIZE-1)) - __builtin_clz(m)], data[i])) {
					m -= uint32_t(1) << (BUCKET_SIZE - 1 - __builtin_clz(m));
				}
				m |= uint32_t(1) << (i & (BUCKET_SIZE - 1));
				range_mask[i] = m;
			} else {
				range_mask[i] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			pref_data[i] = data[i];
			if (i & (BUCKET_SIZE-1)) {
				setmin(pref_data[i], pref_data[i-1]);
			}
		}
		for (int i = n-1; i >= 0; i--) {
			suff_data[i] = data[i];
			if (i+1 < n && ((i+1) & (BUCKET_SIZE-1))) {
				setmin(suff_data[i], suff_data[i+1]);
			}
		}
		for (int i = 0; i < num_buckets(); i++) {
			sparse_table[i * num_levels()] = data[i * BUCKET_SIZE];
			for (int v = 1; v < BUCKET_SIZE; v++) {
				setmin(sparse_table[i * num_levels()], data[i * BUCKET_SIZE + v]);
			}
		}
		for (int l = 0; l+1 < num_levels(); l++) {
			for (int i = 0; i + (1 << (l+1)) <= num_buckets(); i++) {
				sparse_table[(l+1) + i * num_levels()] = min(sparse_table[l + i * num_levels()], sparse_table[l + (i + (1 << l)) * num_levels()]);
			}
		}
	}

	T query(int l, int r) const {
		assert(l <= r);
		int bucket_l = (l >> BUCKET_SIZE_LOG);
		int bucket_r = (r >> BUCKET_SIZE_LOG);
		if (bucket_l == bucket_r) {
			uint32_t msk = range_mask[r] & ~((uint32_t(1) << (l & (BUCKET_SIZE-1))) - 1);
			int ind = (l & ~(BUCKET_SIZE-1)) + __builtin_ctz(msk);
			return data[ind];
		} else {
			T ans = min(suff_data[l], pref_data[r]);
			bucket_l++;
			if (bucket_l < bucket_r) {
				int level = (32 - __builtin_clz(bucket_r - bucket_l)) - 1;
				setmin(ans, sparse_table[level + bucket_l * num_levels()]);
				setmin(ans, sparse_table[level + (bucket_r - (1 << level)) * num_levels()]);
			}
			return ans;
		}
	}
};

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

	point& operator ++ () { ++a; return *this; }
	point operator ++ (int) { point r = *this; ++*this; return r; }
	point& operator -- () { --a; return *this; }
	point operator -- (int) { point r = *this; --*this; return r; }

	point& operator >>= (int v) { a >>= v; return *this; }
	point& operator <<= (int v) { a <<= v; return *this; }
	point operator >> (int v) const { return point(*this) >>= v; }
	point operator << (int v) const { return point(*this) <<= v; }

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
	point a, b;
	range() : a(0), b(0) {}
	range(int a_, int b_) : a(a_), b(b_) {
		assert(1 <= a && a <= b && b <= 2 * a);
	}
	explicit range(std::array<int, 2> r) : range(r[0], r[1]) {}

	explicit operator std::array<int, 2>() const {
		return {a,b};
	}

	const point& operator[] (bool z) const {
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

template <typename T> class binary_indexed_tree {
private:
	std::vector<T> dat;
public:
	binary_indexed_tree() {}
	explicit binary_indexed_tree(size_t N) : dat(N) {}
	binary_indexed_tree(size_t N, const T& t) : dat(N, t) {}

	size_t size() const { return dat.size(); }
	const std::vector<T>& data() const { return dat; }
	std::vector<T>& data() { return dat; }

private:
	template <typename I, typename S = I> struct iterator_range {
	private:
		I begin_;
		S end_;
	public:
		iterator_range() : begin_(), end_() {}
		iterator_range(const I& begin__, const S& end__) : begin_(begin__), end_(end__) {}
		iterator_range(I&& begin__, S&& end__) : begin_(begin__), end_(end__) {}
		I begin() const { return begin_; }
		S end() const { return end_; }
	};

public:
	class const_suffix_iterator {
	private:
		const T* dat;
		int a;
		const_suffix_iterator(const T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class binary_indexed_tree;
	public:
		friend bool operator != (const const_suffix_iterator& i, const const_suffix_iterator& j) {
			assert(j.dat == nullptr);
			return i.a < j.a;
		}
		const_suffix_iterator& operator ++ () {
			a |= a+1;
			return *this;
		}
		const T& operator * () const {
			return dat[a];
		}
	};
	using const_suffix_range = iterator_range<const_suffix_iterator>;
	const_suffix_range suffix(int a) const {
		assert(0 <= a && a <= int(dat.size()));
		return const_suffix_range{const_suffix_iterator{dat.data(), a}, const_suffix_iterator{nullptr, int(dat.size())}};
	}

	class suffix_iterator {
	private:
		T* dat;
		int a;
		suffix_iterator(T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class binary_indexed_tree;
	public:
		friend bool operator != (const suffix_iterator& i, const suffix_iterator& j) {
			assert(j.dat == nullptr);
			return i.a < j.a;
		}
		suffix_iterator& operator ++ () {
			a |= a+1;
			return *this;
		}
		T& operator * () const {
			return dat[a];
		}
	};
	using suffix_range = iterator_range<suffix_iterator>;
	suffix_range suffix(int a) {
		assert(0 <= a && a <= int(dat.size()));
		return suffix_range{suffix_iterator{dat.data(), a}, suffix_iterator{nullptr, int(dat.size())}};
	}

	class const_prefix_iterator {
	private:
		const T* dat;
		int a;
		const_prefix_iterator(const T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class binary_indexed_tree;
	public:
		friend bool operator != (const const_prefix_iterator& i, const const_prefix_iterator& j) {
			assert(j.dat == nullptr);
			return i.a > 0;
		}
		const_prefix_iterator& operator ++ () {
			a &= a-1;
			return *this;
		}
		const T& operator * () const {
			return dat[a-1];
		}
	};
	using const_prefix_range = iterator_range<const_prefix_iterator>;
	const_prefix_range prefix(int a) const {
		return const_prefix_range{const_prefix_iterator{dat.data(), a}, const_prefix_iterator{nullptr, 0}};
	}

	class prefix_iterator {
	private:
		T* dat;
		int a;
		prefix_iterator(T* dat_, int a_) : dat(dat_), a(a_) {}
		friend class binary_indexed_tree;
	public:
		friend bool operator != (const prefix_iterator& i, const prefix_iterator& j) {
			assert(j.dat == nullptr);
			return i.a > 0;
		}
		prefix_iterator& operator ++ () {
			a &= a-1;
			return *this;
		}
		T& operator * () const {
			return dat[a-1];
		}
	};
	using prefix_range = iterator_range<prefix_iterator>;
	prefix_range prefix(int a) {
		return prefix_range{prefix_iterator{dat.data(), a}, prefix_iterator{nullptr, 0}};
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> depth(N);
	vector<int> preorder_idx(N);
	vector<int> preorder_lcas(N-1);
	int cur_idx = 0;
	std::y_combinator([&](auto self, int cur, int prv = -1) -> void {
		depth[cur] = (prv == -1 ? 0 : depth[prv] + 1);
		preorder_idx[cur] = cur_idx;
		cur_idx++;
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			preorder_lcas[cur_idx-1] = max(preorder_lcas[cur_idx-1], depth[cur]);
			self(nxt, cur);
		}
	})(0);

	RangeMinQuery<int> lca_rmq(preorder_lcas);

	auto dist = [&](int a, int b) {
		if (a == b) return 0;
		int v = depth[a] + depth[b];
		a = preorder_idx[a];
		b = preorder_idx[b];
		if (a > b) swap(a, b);
		return v - 2 * lca_rmq.query(a, b-1);
	};

	using diam_t = pair<int, array<int, 2>>;
	auto build_path = [&](int a, int b) -> diam_t {
		return {dist(a, b), {max(a,b), min(a,b)}};
	};

	auto merge_diams = [&](diam_t a, diam_t b) -> diam_t {
		diam_t r = max(a, b);
		r = max(r, build_path(a.second[0], b.second[0]));
		r = max(r, build_path(a.second[0], b.second[1]));
		r = max(r, build_path(a.second[1], b.second[0]));
		r = max(r, build_path(a.second[1], b.second[1]));
		return r;
	};

	seg_tree::in_order_layout seg(N);
	vector<diam_t> seg_diams(2*N);
	for (int i = 0; i < N; i++) {
		seg_diams[seg.get_point(i)] = build_path(i,i);
	}
	for (int a = N-1; a > 0; a--) {
		seg_diams[a] = merge_diams(seg_diams[2*a], seg_diams[2*a+1]);
	}

	vector<int> pref_best(N);
	{
		int cur = -1;
		int cur_depth = -1;
		for (int i = 0; i < N; i++) {
			if (depth[i] >= cur_depth) {
				cur = i;
				cur_depth = depth[i];
			}
			pref_best[i] = cur;
		}
	}
	vector<int> suff_best(N);
	{
		int cur = -1;
		int cur_depth = -1;
		for (int i = N-1; i >= 0; i--) {
			if (depth[i] > cur_depth) {
				cur = i;
				cur_depth = depth[i];
			}
			suff_best[i] = cur;
		}
	}

	int64_t ans = 0;

	vector<int> pref_lim(N);
	vector<int> pref_weight(N);
	vector<int> suff_lim(N);
	vector<int> suff_weight(N);
	for (int i = 0; i < N; i++) {
		if (pref_best[i] == i) {
			int j = i;
			while (j < N && pref_best[j] == i) j++;
			pref_lim[i] = -1;
			pref_weight[i] = j-i;
		} else {
			diam_t cur_diam = build_path(i, i);
			int lim1;

			{
				seg_tree::point a = seg.get_point(i);
				while (true) {
					a >>= __builtin_ctz(a);
					a--;
					if (!a) break;

					auto cnd = merge_diams(seg_diams[a], cur_diam);
					if (cnd.second[0] == i) {
						cur_diam = cnd;
					} else {
						break;
					}
				}
				if (!a) {
					lim1 = -1;
				} else {
					while (a < N) {
						a = a.c(1);
						auto cnd = merge_diams(seg_diams[a], cur_diam);
						if (cnd.second[0] == i) {
							cur_diam = cnd;
							a--;
						} else {
							// leave it
						}
					}
					lim1 = seg.get_leaf_index(a);
				}
			}

			int lim2;
			{
				seg_tree::point a = ++seg.get_point(i);
				while (true) {
					a >>= __builtin_ctz(a);
					if (a == 1) break;
					auto cnd = merge_diams(seg_diams[a], cur_diam);
					if (cnd == cur_diam) {
						a++;
					} else {
						break;
					}
				}

				if (a == 1) {
					lim2 = N;
				} else {
					while (a < N) {
						a = a.c(0);
						auto cnd = merge_diams(seg_diams[a], cur_diam);
						if (cnd == cur_diam) {
							a++;
						} else {
							// leave it
						}
					}
					lim2 = seg.get_leaf_index(a);
				}
			}

			assert(cur_diam.second[0] == i);
			int j = cur_diam.second[1];

			assert(-1 <= lim1 && lim1 < j && j < i && i < lim2 && lim2 <= N);

			bool is_tip;
			if (lim2 == N) {
				is_tip = suff_best[j] == j;
			} else {
				auto v = merge_diams(cur_diam, build_path(lim2, lim2));
				assert(v.second[0] == lim2);
				is_tip = v.second[1] == j;
			}

			// We'll add it in this case regardless of is_tip or not
			ans += int64_t(cur_diam.first) * int64_t(j - lim1) * int64_t(lim2 - i);

			if (is_tip) {
				pref_lim[i] = j;
				pref_weight[i] = lim2 - i;
			} else {
				pref_lim[i] = i;
				pref_weight[i] = 0;
			}
		}

		if (suff_best[i] == i) {
			int j = i;
			while (j >= 0 && suff_best[j] == i) j--;
			suff_lim[i] = N;
			suff_weight[i] = i-j;
		} else {
			diam_t cur_diam = build_path(i, i);
			int lim1;

			{
				seg_tree::point a = ++seg.get_point(i);
				while (true) {
					a >>= __builtin_ctz(a);
					if (a == 1) break;
					auto cnd = merge_diams(seg_diams[a], cur_diam);
					if (cnd.second[1] == i) {
						cur_diam = cnd;
						a++;
					} else {
						break;
					}
				}
				if (a == 1) {
					lim1 = N;
				} else {
					while (a < N) {
						a = a.c(0);
						auto cnd = merge_diams(seg_diams[a], cur_diam);
						if (cnd.second[1] == i) {
							cur_diam = cnd;
							a++;
						} else {
							// leave it
						}
					}
					lim1 = seg.get_leaf_index(a);
				}
			}

			int lim2;
			{
				seg_tree::point a = seg.get_point(i);
				while (true) {
					a >>= __builtin_ctz(a);
					a--;
					if (a == 0) break;
					auto cnd = merge_diams(seg_diams[a], cur_diam);
					if (cnd == cur_diam) {
						// do nothing
					} else {
						break;
					}
				}
				if (a == 0) {
					lim2 = -1;
				} else {
					while (a < N) {
						a = a.c(1);
						auto cnd = merge_diams(seg_diams[a], cur_diam);
						if (cnd == cur_diam) {
							a--;
						} else {
							// leave it
						}
					}
					lim2 = seg.get_leaf_index(a);
				}
			}

			assert(cur_diam.second[1] == i);
			int j = cur_diam.second[0];

			assert(-1 <= lim2 && lim2 < i && i < j && j < lim1 && lim1 <= N);

			bool is_tip;
			if (lim2 == -1) {
				is_tip = pref_best[j] == j;
			} else {
				auto v = merge_diams(cur_diam, build_path(lim2, lim2));
				assert(v.second[1] == lim2);
				is_tip = v.second[0] == j;
			}

			if (is_tip) {
				ans += int64_t(cur_diam.first) * int64_t(lim1 - j) * int64_t(i - lim2);
			}

			if (is_tip) {
				suff_lim[i] = j;
				suff_weight[i] = i - lim2;
			} else {
				suff_lim[i] = i;
				suff_weight[i] = 0;
			}
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (j < suff_lim[i] && i > pref_lim[j]) {
				ans += int64_t(dist(i, j)) * int64_t(suff_weight[i]) * int64_t(pref_weight[j]);
			}
		}
	}
	*/

	vector<bool> alive(N, true);
	vector<int> sz(N);

	vector<int> val(N, 0);
	vector<int> pts; pts.reserve(N);
	vector<int> cur_pts; cur_pts.reserve(N);
	binary_indexed_tree<pair<int64_t, int64_t>> cnt(N);

	std::y_combinator([&](auto solve_centroid, int root) -> void {
		if (!alive[root]) return;
		pts.clear();
		std::y_combinator([&](auto self, int cur, int prv) -> int {
			if (!alive[cur]) {
				return sz[cur] = 0;
			}
			sz[cur] = 1;
			pts.push_back(cur);
			for (int nxt : adj[cur]) {
				if (nxt == prv) continue;
				sz[cur] += self(nxt, cur);
			}
			return sz[cur];
		})(root, -1);

		int tot_sz = sz[root];
		while (true) {
			for (int nxt : adj[root]) {
				if (sz[nxt] > sz[root]) continue;
				if (sz[nxt] * 2 > tot_sz) {
					root = nxt;
					goto found;
				}
			}
			break;
found:;
		}

		std::y_combinator([&](auto self, int cur, int prv, int d) -> void {
			if (!alive[cur]) return;
			val[cur] += d;
			for (int nxt : adj[cur]) {
				if (nxt == prv) continue;
				self(nxt, cur, d+1);
			}
		})(root, -1, 0);

		sort(pts.begin(), pts.end());
		assert(cur_pts.empty());
		for (int i : pts) {
			while (!cur_pts.empty() && suff_lim[cur_pts.back()] <= i) {
				int j = cur_pts.back(); cur_pts.pop_back();
				for (auto& a : cnt.prefix(j+1)) {
					a.first -= suff_weight[j];
					a.second -= int64_t(suff_weight[j]) * int64_t(val[j]);
				}
			}

			for (const auto& a : cnt.suffix(pref_lim[i] + 1)) {
				ans += (a.first * int64_t(val[i]) + a.second) * pref_weight[i];
			}

			cur_pts.push_back(i);
			for (auto& a : cnt.prefix(i+1)) {
				a.first += suff_weight[i];
				a.second += int64_t(suff_weight[i]) * int64_t(val[i]);
			}
		}

		while (!cur_pts.empty()) {
			int j = cur_pts.back(); cur_pts.pop_back();
			for (auto& a : cnt.prefix(j+1)) {
				a.first -= suff_weight[j];
				a.second -= int64_t(suff_weight[j]) * int64_t(val[j]);
			}
		}

		// finally, set the recursive val to -d
		std::y_combinator([&](auto self, int cur, int prv, int d) -> void {
			if (!alive[cur]) return;
			val[cur] = -d;
			for (int nxt : adj[cur]) {
				if (nxt == prv) continue;
				self(nxt, cur, d+1);
			}
		})(root, -1, 0);

		alive[root] = false;
		for (int nxt : adj[root]) {
			solve_centroid(nxt);
		}
	})(0);

	cout << ans << '\n';
}