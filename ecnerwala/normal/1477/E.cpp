#include <bits/stdc++.h>

/** Binary-indexed tree
 *
 *  A binary indexed tree with N nodes of type T provides the
 *  following two functions for 0 <= i <= N:
 *
 *      prefix(int i) -> prefix_iterator<T>
 *      suffix(int i) -> suffix_iterator<T>
 *
 *  such that size(suffix(i) intersect prefix(j)) = (1 if i < j else 0).
 *  Furthermore, the resulting lists always have size at most log_2(N).
 *
 *  This can be used to implement either point-update/(prefix|suffix)-query or
 *  (prefix|suffix)-update/point-query over a virtual array of size N of a
 *  commutative monoid. This can be generalized to implement
 *  point-update/range-query or range-update/point-query over a virtual array
 *  of size N of a commutative group.
 *
 *  With 0-indexed data, prefixes are more natural:
 *   * For range update/query, use for_prefix for the ranges and for_suffix for the points.
 *   * For prefix update/query, no change.
 *   * For suffix update/query, use for_prefix(point + 1); 1-index the data.
 */
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

	int N, M, Q; cin >> N >> M >> Q;

	vector<int> A(N); for (auto& a : A) cin >> a;
	vector<int> B(M); for (auto& b : B) cin >> b;
	const int V = int(1.1e6);

	int64_t A_tot = 0;
	set<pair<int, int>> A_set;
	for (int i = 0; i < N; i++) {
		A_tot += A[i];
		A_set.insert({A[i], i});
	}
	int64_t B_tot = 0;
	set<pair<int, int>> B_set;
	binary_indexed_tree<pair<int, int64_t>> B_bit(V);
	for (int j = 0; j < M; j++) {
		B_tot += B[j];
		B_set.insert({B[j], j});
		for (auto& a : B_bit.suffix(B[j])) {
			a.first++;
			a.second += B[j];
		}
	}

	auto get_B_sum = [&](int v0) -> int64_t {
		int64_t res = int64_t(v0) * M;
		for (const auto& a : B_bit.prefix(max(v0, 0))) {
			res -= a.first * int64_t(v0);
			res += a.second;
		}
		return res;
	};

	auto query = [&](int K) -> int64_t {
		int min_all = min(A_set.begin()->first, B_set.begin()->first);

		int64_t res = (N-M) * int64_t(min_all - K);

		{
			int v0 = B_set.rbegin()->first - K;
			res = min(res, N * int64_t(min(v0, min_all)) - get_B_sum(v0));
		}

		// Check choices of A around B_set.rbegin()->first + K
		{
			auto it = A_set.lower_bound({B_set.rbegin()->first + K + 1, -1});
			if (it != A_set.end()) {
				int v0 = it->first - K;
				res = min(res, v0 + (N-1) * int64_t(min_all) - B_tot);
			}
			if (it != A_set.begin()) {
				int v0 = prev(it)->first - K;
				res = min(res, v0 + (N-1) * int64_t(min(v0, min_all)) - get_B_sum(v0));
			}
		}

		return A_tot - B_tot - res;
	};

	for (int q = 0; q < Q; q++) {
		int op; cin >> op;
		if (op == 1) {
			int i; cin >> i; i--;
			A_tot -= A[i];
			A_set.erase({A[i], i});
			cin >> A[i];
			A_tot += A[i];
			A_set.insert({A[i], i});
		} else if (op == 2) {
			int j; cin >> j; j--;
			B_tot -= B[j];
			B_set.erase({B[j], j});
			for (auto& a : B_bit.suffix(B[j])) {
				a.first--;
				a.second -= B[j];
			}
			cin >> B[j];
			B_tot += B[j];
			B_set.insert({B[j], j});
			for (auto& a : B_bit.suffix(B[j])) {
				a.first++;
				a.second += B[j];
			}
		} else if (op == 3) {
			int k; cin >> k;
			cout << query(k) << '\n';
		}
	}

	return 0;
}

// Just add a player of potential P[0] - K at the start; then, player's score is P[i] - min(players before him)
// The main choice is P[0]; then, take all the B's in decreasing order and all the A's in increasing order
// We can simplify down to minimizing
//   sum min(players before A) - sum min(players before B)
// If we move an A to the front,
//   = P[0]-K + (N-1) * min(P[0]-K, min(everything)) - sum min(P[0]-K, B[i])
// If we move a B to the front:
//   = N * min(P[0]-K, min(everything)) - sum min(P[0], B[i]+K)
//
// If P[0] - K <= min(everything), then everything gets P[0] - K, which equals
//
// If P[0]-K >= min(everything), we just want it to be either maximum B, or one of the A's closest to Bmax + K, Bmax2 + K
//
// If we move an A[i] to the start, we lose a flat min(A,B)