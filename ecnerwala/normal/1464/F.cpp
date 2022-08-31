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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> depth(N);
	vector<int> preorder_idx(N);
	vector<pair<int, int>> preorder_lcas(N-1);
	int cur_idx = 0;
	std::y_combinator([&](auto self, int cur, int prv = -1) -> void {
		depth[cur] = (prv == -1 ? 0 : depth[prv] + 1);
		preorder_idx[cur] = cur_idx;
		cur_idx++;
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			preorder_lcas[cur_idx-1] = max(preorder_lcas[cur_idx-1], {depth[cur], cur});
			self(nxt, cur);
		}
	})(0);

	RangeMinQuery<pair<int, int>> lca_rmq(preorder_lcas);

	auto lca = [&](int a, int b) {
		if (a == b) return a;
		a = preorder_idx[a];
		b = preorder_idx[b];
		if (a > b) swap(a, b);
		return lca_rmq.query(a, b-1).second;
	};

	auto dist = [&](int a, int b) {
		return depth[a] + depth[b] - 2 * depth[lca(a,b)];
	};

	using path_t = pair<int, int>;

	auto closest_pt = [&](int a, path_t p) {
		int c = lca(p.first, p.second);
		int x = lca(a, p.first);
		int y = lca(a, p.second);
		return max({c,x,y}, [&](int u, int v) { return depth[u] < depth[v]; });
	};

	// If radius = 0, the path represents the set of centers; otherwise, it represents some diameter
	using diam_t = pair<int, path_t>;
	diam_t NO_DIAM{int(1e9), path_t{-1, -1}};

	auto build_diam = [&](int a, int b) -> diam_t {
		return {dist(a,b), {a,b}};
	};

	auto update_diam = [&](diam_t d, path_t a) -> diam_t {
		if (d == NO_DIAM) return {0, a};
		int x = closest_pt(d.second.first, a);
		int y = closest_pt(d.second.second, a);
		if (x != y) {
			if (d.first == 0) {
				return {0, {x, y}};
			} else {
				return d;
			}
		}
		assert(x == y);
		if (d.first == 0) {
			int z = closest_pt(x, d.second);
			return build_diam(x, z);
		} else {
			return max({d, build_diam(d.second.first, x), build_diam(d.second.second, x)});
		}
	};

	set<pair<path_t, int>> alive;
	vector<vector<path_t>> ops(2*Q);
	vector<int> queries(Q, -1);

	for (int q = 0; q < Q; q++) {
		int op; cin >> op;
		if (op == 1 || op == 2) {
			int u, v; cin >> u >> v; u--, v--;
			if (u > v) swap(u, v);
			path_t path(u, v);
			if (op == 1) {
				alive.insert({path, q});
			} else {
				auto it = alive.lower_bound({path, -1});
				assert(it != alive.end() && it->first == path);
				int t0 = it->second;
				alive.erase(it);

				for (int a = Q+t0, b = Q+q; a < b; a >>= 1, b >>= 1) {
					if (a & 1) ops[a++].push_back(path);
					if (b & 1) ops[--b].push_back(path);
				}
			}
		} else if (op == 3) {
			int d; cin >> d;
			queries[q] = d * 2;
		} else assert(false);
	}
	for (auto it : alive) {
		int t0 = it.second;
		path_t path = it.first;
		for (int a = Q+t0, b = Q+Q; a < b; a >>= 1, b >>= 1) {
			if (a & 1) ops[a++].push_back(path);
			if (b & 1) ops[--b].push_back(path);
		}
	}

	vector<int> actual_diam(Q);
	std::y_combinator([&](auto self, int a, diam_t d) -> void {
		for (path_t p : ops[a]) {
			d = update_diam(d, p);
		}
		if (a >= Q) {
			actual_diam[a-Q] = d.first;
		} else {
			self(2*a, d);
			self(2*a+1, d);
		}
	})(1, NO_DIAM);

	for (int q = 0; q < Q; q++) {
		if (queries[q] == -1) continue;
		cout << (actual_diam[q] <= queries[q] ? "Yes" : "No") << '\n';
	}

	return 0;
}