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

	int N, Q; cin >> N >> Q;
	std::vector<int> A(N);
	for (auto& a : A) { cin >> a; a--; }

	bool can_go = (*std::min_element(A.begin(), A.end()) == 0) && (*std::max_element(A.begin(), A.end()) == N-1);

	const int L = 40;
	std::vector<std::pair<RangeMinQuery<int>, RangeMaxQuery<int>>> jumps(L);
	{
		std::vector<int> lo(N-1);
		std::vector<int> hi(N-1);
		for (int i = 0; i+1 < N; i++) {
			int x = std::min(A[i], A[i+1]);
			int y = std::max(A[i], A[i+1]) - 1;
			if (x > y) {
				lo[i] = N;
				hi[i] = -1;
			} else {
				lo[i] = x;
				hi[i] = y;
			}
		}
		jumps[0].first = RangeMinQuery<int>(lo);
		jumps[0].second = RangeMaxQuery<int>(hi);
	}
	for (int l = 1; l < L; l++) {
		std::vector<int> lo(N-1);
		std::vector<int> hi(N-1);
		for (int i = 0; i < N-1; i++) {
			int x = jumps[l-1].first.query(i, i);
			int y = jumps[l-1].second.query(i, i);
			if (x > y) {
				lo[i] = N;
				hi[i] = -1;
			} else {
				lo[i] = jumps[l-1].first.query(x, y);
				hi[i] = jumps[l-1].second.query(x, y);
			}
		}
		jumps[l].first = RangeMinQuery<int>(lo);
		jumps[l].second = RangeMaxQuery<int>(hi);
	}

	while (Q--) {
		int l, r; cin >> l >> r; l--, r--;
		if (l == 0 && r == N-1) {
			cout << 0 << '\n';
			continue;
		}
		if (l == r || !can_go) {
			cout << -1 << '\n';
			continue;
		}
		assert(l < r);
		r--;
		assert(l <= r);

		{
			int lo = jumps.back().first.query(l, r);
			int hi = jumps.back().second.query(l, r);
			if (!(lo == 0 && hi == N-2)) {
				cout << -1 << '\n';
				continue;
			}
		}

		int64_t ans = 1;
		for (int j = L-1; j >= 0; j--) {
			int nl = jumps[j].first.query(l, r);
			int nr = jumps[j].second.query(l, r);
			if (!(nl == 0 && nr == N-2)) {
				ans += int64_t(1) << j;
				l = nl, r = nr;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}