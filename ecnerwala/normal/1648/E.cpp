#include <bits/stdc++.h>

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
			sparse_table[i] = data[i * BUCKET_SIZE];
			for (int v = 1; v < BUCKET_SIZE; v++) {
				setmin(sparse_table[i], data[i * BUCKET_SIZE + v]);
			}
		}
		for (int l = 0; l+1 < num_levels(); l++) {
			for (int i = 0; i + (1 << (l+1)) <= num_buckets(); i++) {
				sparse_table[(l+1) * num_buckets() + i] = min(sparse_table[l * num_buckets() + i], sparse_table[l * num_buckets() + i + (1 << l)]);
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
				setmin(ans, sparse_table[level * num_buckets() + bucket_l]);
				setmin(ans, sparse_table[level * num_buckets() + bucket_r - (1 << level)]);
			}
			return ans;
		}
	}
};

template <typename T> using RangeMaxQuery = RangeMinQuery<T, std::greater<T>>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		std::vector<std::pair<std::array<int, 2>, int>> edges(M);
		for (auto& [p, l] : edges) {
			cin >> p[0] >> p[1] >> l; p[0]--, p[1]--;
		}

		std::vector<std::array<int, 2>> berlaflot(M);
		for (int e = 0; e < M; e++) {
			auto [u, v] = edges[e].first;
			if (u > v) std::swap(u, v);
			berlaflot[e] = {u, v};
		}
		std::sort(berlaflot.begin(), berlaflot.end());
		auto is_s8_edge = [&](int u, int v) {
			assert(u != v);
			if (u > v) std::swap(u, v);
			return !std::binary_search(berlaflot.begin(), berlaflot.end(), std::array<int, 2>{u, v});
		};

		std::vector<std::pair<int, std::array<int, 2>>> edge_q(M);
		for (int e = 0; e < M; e++) {
			edge_q[e] = {edges[e].second, edges[e].first};
		}
		std::sort(edge_q.begin(), edge_q.end(), [&](auto a, auto b) { return a.first < b.first; });
		std::vector<int> par(N, -1);
		auto get_par = [&](int a) -> int {
			while (par[a] >= 0) {
				if (par[par[a]] >= 0) par[a] = par[par[a]];
				a = par[a];
			}
			return a;
		};
		std::vector<std::vector<std::list<std::pair<int, int>>>> comps(N);
		for (int i = 0; i < N; i++) {
			comps[i].emplace_back();
			comps[i].back().push_back({i, 0});
		}

		for (auto [_l, e] : edge_q) {
			auto l = _l;
			auto [a, b] = e;
			a = get_par(a);
			b = get_par(b);
			if (a == b) continue;
			// merge a and b into a
			std::vector<std::list<std::pair<int, int>>> ncomps; ncomps.reserve(comps[a].size() + comps[b].size());

			while (!comps[a].empty()) {
				std::list<std::pair<int, int>> cur_a(std::move(comps[a].back()));
				comps[a].pop_back();
				std::list<std::pair<int, int>> cur_b;
				auto extend = [&](std::list<std::pair<int, int>>& cur, std::list<std::pair<int, int>>& o) {
					if (o.empty()) return cur.end();
					if (cur.empty()) {
						cur.splice(cur.end(), o);
						return cur.begin();
					}
					cur.back().second = l;
					auto res = std::prev(cur.end());
					cur.splice(cur.end(), o);
					return res;
				};
				for (auto za = cur_a.begin(), zb = cur_b.begin(); true; ) {
					if (!comps[b].empty() && za != cur_a.end()) {
						int v = za->first;
						za++;
						int op = b;
						int L = 0;
						for (int i = 0; i < int(comps[op].size()); i++) {
							bool link = false;
							for (auto [u, _] : comps[op][i]) {
								if (is_s8_edge(u, v)) {
									link = true;
									break;
								}
							}
							if (!link) {
								if (i > L) {
									std::swap(comps[op][L], comps[op][i]);
								}
								L++;
							} else {
								if (zb == cur_b.end()) zb = extend(cur_b, comps[op][i]);
								else extend(cur_b, comps[op][i]);
							}
						}
						comps[op].resize(L);
					} else if (!comps[a].empty() && zb != cur_b.end()) {
						int v = zb->first;
						zb++;
						int op = a;
						int L = 0;
						for (int i = 0; i < int(comps[op].size()); i++) {
							bool link = false;
							for (auto [u, _] : comps[op][i]) {
								if (is_s8_edge(u, v)) {
									link = true;
									break;
								}
							}
							if (!link) {
								if (i > L) {
									std::swap(comps[op][L], comps[op][i]);
								}
								L++;
							} else {
								if (za == cur_a.end()) za = extend(cur_a, comps[op][i]);
								else extend(cur_a, comps[op][i]);
							}
						}
						comps[op].resize(L);
					} else {
						break;
					}
				}

				extend(cur_a, cur_b);
				ncomps.emplace_back(std::move(cur_a));
			}

			for (auto& c : comps[b]) {
				ncomps.emplace_back(std::move(c));
			}
			comps[b] = {};

			if (par[a] > par[b]) std::swap(a, b);
			comps[a] = std::move(ncomps);

			par[a] += par[b];
			par[b] = a;
		}

		int p = get_par(0);
		assert(comps[p].size() == 1);
		assert(int(comps[p][0].size()) == N);
		std::vector<std::pair<int, int>> vec(comps[p][0].begin(), comps[p][0].end());
		std::vector<int> loc(N);
		for (int i = 0; i < N; i++) {
			loc[vec[i].first] = i;
		}
		std::vector<int> w(N-1);
		for (int i = 0; i < N-1; i++) w[i] = vec[i].second;
		RangeMaxQuery<int> rmq(w);
		for (int e = 0; e < M; e++) {
			int u = loc[edges[e].first[0]], v = loc[edges[e].first[1]];
			if (u > v) std::swap(u, v);
			assert(u != v);
			cout << rmq.query(u, v-1) << " \n"[e+1==M];
		}
	}


	return 0;
}