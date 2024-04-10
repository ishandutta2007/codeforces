#include<bits/stdc++.h>

template <typename T, class Compare = std::less<T>> class RangeMinQuery : private Compare {
	static const int BUCKET_SIZE = 16;
	static const int BUCKET_SIZE_LOG = 4;
	static_assert((BUCKET_SIZE & (BUCKET_SIZE-1)) == 0);
	static const int CACHE_LINE_ALIGNMENT = 64;
	int n = 0;
	std::vector<T> data;
	std::vector<T> pref_data;
	std::vector<T> suff_data;
	std::vector<T> sparse_table;

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
	{
		for (int i = 0; i < n; i++) data[i] = data_[i];
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
			T ans = data[l];
			for (int i = l+1; i <= r; i++) setmin(ans, data[i]);
			return ans;
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

std::mt19937 mt(48);

struct treap {
	treap* c[2] = {nullptr, nullptr};
	int64_t numInv[2] = {0,0};
	std::mt19937::result_type pri = mt();
	int cnt[2] = {0,0};
	int val = -1;
	bool color = 0;

	~treap() {
		delete c[0];
		delete c[1];
	}

	void update() {
		cnt[0] = cnt[1] = 0;
		cnt[color]++;
		numInv[0] = numInv[1] = 0;
		if (c[0]) {
			numInv[0] += c[0]->numInv[0] + int64_t(c[0]->cnt[0]) * cnt[1];
			numInv[1] += c[0]->numInv[1] + int64_t(c[0]->cnt[1]) * cnt[0];
			cnt[0] += c[0]->cnt[0];
			cnt[1] += c[0]->cnt[1];
		}
		if (c[1]) {
			numInv[0] += c[1]->numInv[0] + int64_t(cnt[0]) * c[1]->cnt[1];
			numInv[1] += c[1]->numInv[1] + int64_t(cnt[1]) * c[1]->cnt[0];
			cnt[0] += c[1]->cnt[0];
			cnt[1] += c[1]->cnt[1];
		}
	}

	int64_t get_ans() {
		return std::min(numInv[0], numInv[1]);
	}
	void print_tree(std::string pref = "") {
		if (c[0]) c[0]->print_tree(pref + ' ');
		std::cerr << pref << val << ',' << color << ' ' << cnt[0] << ' ' << cnt[1] << ' ' << numInv[0] << ' ' << numInv[1] << '\n';
		if (c[1]) c[1]->print_tree(pref + ' ');
	}
};

treap* merge(treap* a, treap* b) {
	if (!a) return b;
	if (!b) return a;

	if (a->pri < b->pri) {
		a->c[1] = merge(a->c[1], b);
		a->update();
		return a;
	} else {
		b->c[0] = merge(a, b->c[0]);
		b->update();
		return b;
	}
}

std::array<treap*, 2> split(treap* a, int k) {
	if (!a) return {nullptr, nullptr};
	std::array<treap*, 2> res;
	if (k <= a->val) {
		res[1] = a;
		auto n = split(a->c[0], k);
		res[0] = n[0], a->c[0] = n[1];
	} else {
		res[0] = a;
		auto n = split(a->c[1], k);
		a->c[1] = n[0], res[1] = n[1];
	}
	a->update();
	return res;
}

std::pair<treap*, treap*> del(treap* r, int k) {
	auto [lo, midhi] = split(r, k);
	auto [mid, hi] = split(midhi, k+1);
	return {merge(lo, hi), mid};
}

treap* ins(treap* r, treap* n) {
	n->update();
	auto [lo, hi] = split(r, n->val);
	return merge(merge(lo, n), hi);
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; i++) cin >> P[i];

	vector<pair<int, int>> W(N+1);
	for (int i = 1; i <= N-1; i++) cin >> W[i].first;
	for (int i = 0; i <= N; i++) W[i].second = i;
	RangeMinQuery<pair<int, int>> rmq(W);

	const int V = 2 * N - 1;
	vector<array<int, 2>> bounds(V);
	vector<int> mid(V);

	vector<int> par(V);
	par[0] = -1;

	vector<int> leafs(N);

	int cur_ind = 0;
	std::y_combinator([&](auto self, int l, int r) -> void {
		int v = cur_ind++;
		bounds[v] = {l, r};
		if (r - l == 1) {
			leafs[l] = v;
			return;
		}
		int m = rmq.query(l+1, r-1).second;
		mid[v] = m;

		par[cur_ind] = v;
		self(l, m);

		par[cur_ind] = v;
		self(m, r);
	})(0, N);

	vector<treap*> treaps(V, nullptr);
	int64_t ans = 0;
	auto insert_ind = [&](int i) {
		for (int cur = par[leafs[i]]; cur != -1; cur = par[cur]) {
			treap* node = new treap;
			assert(bounds[cur][0] <= i && i < bounds[cur][1]);
			node->val = P[i], node->color = (i >= mid[cur]);
			node->update();
			if (treaps[cur]) ans -= treaps[cur]->get_ans();
			treaps[cur] = ins(treaps[cur], node);
			if (treaps[cur]) ans += treaps[cur]->get_ans();
		}
	};
	auto delete_ind = [&](int i) {
		for (int cur = par[leafs[i]]; cur != -1; cur = par[cur]) {
			if (treaps[cur]) ans -= treaps[cur]->get_ans();
			treap* node;
			tie(treaps[cur], node) = del(treaps[cur], P[i]);
			assert(node->val == P[i]);
			assert(node->color == (i >= mid[cur]));
			delete node;
			if (treaps[cur]) ans += treaps[cur]->get_ans();
		}
	};

	for (int i = 0; i < N; i++) {
		insert_ind(i);
	}

	//cerr << ans << '\n';

	int Q; cin >> Q;
	while (Q--) {
		int X, Y; cin >> X >> Y; X--, Y--;
		if (X != Y) {
			delete_ind(X);
			delete_ind(Y);
			swap(P[X], P[Y]);
			insert_ind(X);
			insert_ind(Y);
		}
		/*
		for (treap* t : treaps) {
			if (!t) continue;
			cerr << t->cnt[0] << ' ' << t->cnt[1] << ' ' << t->numInv[0] << ' ' << t->numInv[1] << '\n';
			t->print_tree(); cerr << '\n';
		}
		cerr << '\n';
		*/
		cout << ans << '\n';
	}

	for (treap* t : treaps) {
		delete t;
	}

	return 0;
}