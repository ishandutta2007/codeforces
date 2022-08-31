#include <bits/stdc++.h>

#include <cassert>
#include <vector>

#include <algorithm>

using std::min, std::max;

#define CREATE_FUNCTOR(name, expr) \
template <typename T>\
struct name {\
	constexpr T operator ()(const T& x, const T& y) const { return expr; }\
}

CREATE_FUNCTOR(Min, std::min(x, y));
CREATE_FUNCTOR(Max, std::max(x, y));
CREATE_FUNCTOR(Sum, x + y);	// there already is std::plus
CREATE_FUNCTOR(Prod, x * y);	// there already is std::multiplies
// for more refer to https://en.cppreference.com/w/cpp/header/functional

using std::vector;

template <typename T, class Op = Min<T>>
struct Sparse {
	Op op;
	vector<vector<T>> table;

	template <typename U = T>
	void build(const vector<U>& a) {
		table.assign(a.size(), {});
		for (int i = 0; i < (int)a.size(); ++i) {
			table[i] = {a[i]};
		}
		for (int l = 1, j = 0; 2 * l <= (int)a.size(); ++j, l <<= 1) {
			for (int i = 0; i + 2 * l <= (int)a.size(); ++i) {
				table[i].push_back(op(table[i][j], table[i + l][j]));
			}
		}
	}

	Sparse() {}

	template <typename U = T>
	explicit Sparse(const vector<U>& a) {
		build(a);
	}

	template <typename U = T>
	Sparse(const vector<U>& a, Op&& _op): op(_op) {
		build(a);
	}

	T get(int l, int r) const {
		assert(r > l);
		const int b = 31 - __builtin_clz(r - l);
		return op(table[l][b], table[r - (1 << b)][b]);
	}
};


template <typename T, class Op = Min<T>>
struct NonIdempotentSparse {
	Op op;
	vector<vector<T>> left, right;

	template <typename U = T>
	void build(const vector<U>& a) {
		left.assign(a.size(), {});
		right.assign(a.size(), {});
		for (int i = 0; i < (int)a.size(); ++i) {
			left[i] = {a[i]};
		}
		for (int i = 0; i < (int)a.size() - 1; ++i) {
			const int ctz = __builtin_ctz(i + 1);
			T cur = a[i];
			for (int j = i; j > 0 && __builtin_ctz(j) < ctz; --j) {
				cur = op(a[j - 1], cur);
				left[i].push_back(cur);
			}
		}
		for (int i = 1; i < (int)a.size(); ++i) {
			const int ctz = __builtin_ctz(i);
			T cur = a[i];
			right[i] = {cur};
			for (int j = i + 1; j < (int)a.size() && __builtin_ctz(j) < ctz; ++j) {
				cur = op(cur, a[j]);
				right[i].push_back(cur);
			}
		}
	}

	NonIdempotentSparse() {}

	template <typename U = T>
	explicit NonIdempotentSparse(const vector<U>& a) {
		build(a);
	}

	template <typename U = T>
	NonIdempotentSparse(const vector<U>& a, Op&& _op): op(_op) {
		build(a);
	}

	T get(int l, int r) const {
		assert(r > l);
		if (r == l + 1) {
			return left[l][0];
		}
		if (r == l + 2) {
			return op(left[l][0], right[r - 1][0]);
		}
		const int tmp = l ^ (r - 1);
		const int pos = (r - 1) & ~((1 << (31 - __builtin_clz(tmp))) - 1);
		return op(left[pos - 1][pos - l - 1], right[pos][r - pos - 1]);
	}
};

#include <tuple>

template <typename T>
struct IndexedValue {
	int index;
	T value;

	bool operator <(const IndexedValue<T>& ot) const {
		return std::tie(value, index) < std::tie(ot.value, ot.index);
	}
};

template <typename T>
std::ostream& operator <<(std::ostream& ostr, const IndexedValue<T>& x) {
	return ostr << "(index=" << x.index << ", value=" << x.value << ")";
}

template <typename T>
std::vector<IndexedValue<T>> with_index(const std::vector<T>& vec) {
	std::vector<IndexedValue<T>> result(vec.size());
	for (int i = 0; i < (int)vec.size(); ++i) {
		result[i] = {i, vec[i]};
	}
	return result;
}
#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Event {
	int t;
	int x;
	long long val;
};

struct Query {
	int l, r;
	int idx;
};

struct Node {
	int l, r;
	int li, ri;
	long long val;
};

Node nodes[333'333 * 20];
int ncur = 0;

int build(int li, int ri) {
	int res = ncur;
	nodes[ncur++] = {-1, -1, li, ri, 0};
	if (ri > li + 1) {
		int m = (li + ri) / 2;
		nodes[res].l = build(li, m);
		nodes[res].r = build(m, ri);
	}
	return res;
}

int clone(int v) {
	nodes[ncur++] = nodes[v];
	return ncur - 1;
}

int add(int v, int pos, long long x) {
	int res = clone(v);
	nodes[res].val += x;
	if (nodes[v].ri > nodes[v].li + 1) {
		int m = (nodes[v].li + nodes[v].ri) / 2;
		if (pos >= m) {
			nodes[res].r = add(nodes[v].r, pos, x);
		} else {
			nodes[res].l = add(nodes[v].l, pos, x);
		}
	}
	return res;
}

long long get(int v, int pos) {
	if (nodes[v].ri <= pos) {
		return nodes[v].val;
	}
	if (nodes[v].li >= pos) {
		return 0;
	}
	return get(nodes[v].l, pos) + get(nodes[v].r, pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt(), q = nxt();
	string s;
	cin >> s;

	vector<vector<int>> seqs = {{0}};
	vector<int> bal(n + 1);
	vector<int> st = {0};
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			bal[i + 1] = bal[i] + 1;
			st.push_back(seqs.size());
			seqs.push_back({i + 1});
		} else {
			st.pop_back();
			bal[i + 1] = bal[i] - 1;
			if (st.empty()) {
				st.push_back(seqs.size());
				seqs.push_back({});
			}
			seqs[st.back()].push_back(i + 1);
		}
	}
	vector<int> which(n + 1);
	for (int i = 0; i < (int)seqs.size(); ++i) {
		for (int j : seqs[i]) {
			which[j] = i;
		}
	}

	Sparse<IndexedValue<int>> sparse(with_index(bal));
	vector<vector<Event>> events(n);
	vector<int> roots(n + 1);
	roots[n] = build(0, n + 1);
	for (const auto& v : seqs) {
		const int sz = v.size();
		if (sz == 1) {
			continue;
		}
		for (int i = 1; i < sz - 1; ++i) {
			events[v[0]].push_back({v[0], v[i], i});
		}
		for (int i = 1; i < sz - 1; ++i) {
			events[v[i]].push_back({v[i], v[sz - 1], sz - 1 - i});
		}
		events[v[0]].push_back({v[0], v[sz - 1], 1ll * (sz - 1) * (4 - sz) / 2});
	}
	for (int i = n - 1; i >= 0; --i) {
		int root = roots[i + 1];
		for (const auto& e : events[i]) {
			root = add(root, e.x, e.val);
		}
		roots[i] = root;
	}

	for (int i = 0; i < q; ++i) {
		nxt();
		int l = nxt() - 1, r = nxt();
		int pos = sparse.get(l, r + 1).index;
		int idx = which[pos];
		long long ans = get(roots[l], r + 1);
		if (seqs[idx][0] < l && r < seqs[idx].back()) {
			auto lit = lower_bound(all(seqs[idx]), l);
			auto rit = upper_bound(all(seqs[idx]), r);
			ans += 1ll * (rit - lit) * (rit - lit - 1) / 2;
		}
		cout << ans << "\n";
	}

	return 0;
}