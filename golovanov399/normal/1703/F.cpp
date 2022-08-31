#include <bits/stdc++.h>

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
#include <vector>

using std::vector;

template <typename V = int>
struct Fenwick {
	int n;
	vector<V> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, const V& x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	V get(int pos) const {
		V res = V{};
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	V get(int l, int r) const {
		return get(r - 1) - get(l - 1);
	}

	int get_min_atleast(V x) const {
		int res = 0;
		for (int i = 1 << (31 - __builtin_clz(n)); i; i >>= 1) {
			if (res + i > n) {
				continue;
			}
			if (a[res + i - 1] < x) {
				res += i;
				x -= a[res - 1];
			}
		}
		return res;
	}

	int get_max_atmost(V x) const {
		int res = 0;
		for (int i = 1 << (31 - __builtin_clz(n)); i; i >>= 1) {
			if (res + i > n) {
				continue;
			}
			if (a[res + i - 1] <= x) {
				res += i;
				x -= a[res - 1];
			}
		}
		return res - 1;
	}
};

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	for (auto& x : a) {
		x -= 1;
	}
	auto ar = with_index(a);
	sort(all(ar));
	Fenwick<int> f(n);
	long long ans = 0;
	for (auto [i, x] : ar) {
		if (x >= i) {
			continue;
		}
		ans += f.get(x - 1);
		f.add(i, 1);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}