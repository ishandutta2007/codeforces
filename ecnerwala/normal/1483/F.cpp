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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<string> W(N);
	int totL = 0;
	for (auto& w : W) {
		cin >> w;
		totL += int(w.size());
	}

	vector<array<int, 26>> ch; ch.reserve(totL+1);
	vector<int> is_end; is_end.reserve(totL+1);
	ch.emplace_back(); ch.back().fill(0); is_end.push_back(-1);
	for (int i = 0; i < N; i++) {
		int cur = 0;
		for (char c : W[i]) {
			if (!ch[cur][c-'a']) {
				ch[cur][c-'a'] = int(ch.size());
				ch.emplace_back(); ch.back().fill(0); is_end.push_back(-1);
			}
			cur = ch[cur][c-'a'];
		}
		is_end[cur] = i;
	}

	int V = int(ch.size());
	vector<int> fail(V);
	fail[0] = -1;
	vector<int> fail_end(V);

	vector<int> fail_par(N);
	vector<vector<int>> fail_ch(N+1);

	vector<int> q; q.reserve(V);
	q.push_back(0);
	for (int z = 0; z < V; z++) {
		assert(z < int(q.size()));
		int cur = q[z];
		for (int c = 0; c < 26; c++) {
			int fail_val = cur == 0 ? 0 : ch[fail[cur]][c];
			if (ch[cur][c]) {
				fail[ch[cur][c]] = fail_val;
				q.push_back(ch[cur][c]);
			} else {
				ch[cur][c] = fail_val;
			}
		}

		if (is_end[cur] != -1) {
			fail_end[cur] = is_end[cur];

			int p = fail_end[fail[cur]];
			fail_par[is_end[cur]] = p;
			fail_ch[p].push_back(is_end[cur]);
			//cerr << "parent of " << is_end[cur] << " " << W[is_end[cur]] << " is " << p << '\n';
		} else if (cur == 0) {
			fail_end[cur] = N;
		} else {
			fail_end[cur] = fail_end[fail[cur]];
		}
	}

	vector<array<int, 2>> bounds(N+1);
	{
		int cur_idx = 0;
		std::y_combinator([&](auto self, int cur) -> void {
			bounds[cur][0] = cur_idx;
			cur_idx++;
			for (int nxt : fail_ch[cur]) {
				self(nxt);
			}
			bounds[cur][1] = cur_idx;
		})(N);
	}

	binary_indexed_tree<int> bit(N+1);

	int ans = 0;

	for (int i = 0; i < N; i++) {
		//cerr << "running word " << i << ' ' << W[i] << '\n';

		int L = int(W[i].size());
		vector<int> states(L+1);
		states[0] = 0;
		for (int z = 0; z < L; z++) {
			states[z+1] = ch[states[z]][W[i][z]-'a'];
		}
		vector<int> bads; bads.reserve(L);
		vector<int> cnds; cnds.reserve(L);
		int best_start = L;
		for (int z = L; z >= 0; z--) {
			int m = fail_end[states[z]];
			if (z == L) {
				assert(m == i);
				m = fail_par[m];
			}
			if (m == N) continue;
			int start = z - int(W[m].size());
			if (start < best_start) {
				best_start = start;
				cnds.push_back(m);
				m = fail_par[m];
			}
			if (m == N) continue;
			bads.push_back(m);
		}

		//for (int v : bads) { cerr << "bad " << v << ' ' << W[v] << '\n'; }
		//for (int v : cnds) { cerr << "cnd " << v << ' ' << W[v] << '\n'; }

		for (int v : bads) {
			for (auto& a : bit.suffix(bounds[v][0])) a++;
		}
		for (int v : cnds) {
			int cnt = 0;
			for (auto a : bit.prefix(bounds[v][0])) cnt -= a;
			for (auto a : bit.prefix(bounds[v][1])) cnt += a;
			if (!cnt) {
				ans++;
			}
			for (auto& a : bit.suffix(bounds[v][0])) a++;
		}

		for (int v : bads) {
			for (auto& a : bit.suffix(bounds[v][0])) a--;
		}
		for (int v : cnds) {
			for (auto& a : bit.suffix(bounds[v][0])) a--;
		}
	}

	cout << ans << '\n';

	return 0;
}