#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

#define CREATE_FUNCTOR(name, expr) \
template <typename T>\
struct name {\
	constexpr T operator ()(const T& x, const T& y) const { return expr; }\
}

CREATE_FUNCTOR(Min, min(x, y));
CREATE_FUNCTOR(Max, max(x, y));

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

void solve() {
	int n = nxt(), q = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] += nxt();
	}
	for (int i = 0; i < n; ++i) {
		a[i] -= nxt();
	}
	vector<long long> p(n + 1);
	partial_sum(all(a), p.begin() + 1);
	Sparse<long long, Min<long long>> mn(p);
	Sparse<long long, Max<long long>> mx(p);

	while (q--) {
		int l = nxt(), r = nxt() + 1;
		// for (int i = l; i < r; ++i) {
		// 	cerr << p[i] - p[l - 1] << " ";
		// }
		// cerr << "\n";
		if (mx.get(l, r) > p[l - 1] || p[r - 1] != p[l - 1]) {
			printf("-1\n");
		} else {
			printf("%lld\n", p[l - 1] - mn.get(l, r));
		}
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}