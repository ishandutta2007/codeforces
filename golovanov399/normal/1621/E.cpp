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

CREATE_FUNCTOR(Min, std::min(x, y));

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
		if (l >= r) {
			return 1e9;
		}
		const int b = 31 - __builtin_clz(r - l);
		return op(table[l][b], table[r - (1 << b)][b]);
	}
};

void solve() {
	int n = nxt(), m = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	vector<int> which_group;
	vector<int> new_value;
	vector<pair<int, int>> need;
	for (int i = 0; i < m; ++i) {
		int k = nxt();
		vector<int> age(k);
		generate(all(age), nxt);
		for (int j = 0; j < k; ++j) {
			which_group.push_back(i);
		}
		long long s = accumulate(all(age), 0ll);
		need.push_back({(s + k - 1) / k, i});
		for (int j = 0; j < k; ++j) {
			new_value.push_back((s - age[j] + k - 2) / (k - 1));
		}
	}
	sort(all(need));
	vector<int> new_place(m);
	for (int i = 0; i < m; ++i) {
		new_place[need[i].second] = i;
	}

	vector<int> values(m);
	for (int i = 0; i < m; ++i) {
		values[i] = need[i].first;
	}
	vector<int> balance(m);
	for (int i = 0; i < m; ++i) {
		balance[i] = (a.end() - lower_bound(all(a), values[i])) - (m - i);
	}

	Sparse<int> st(balance);

	string ans(new_value.size(), '?');
	// for (auto x : a) {
	// 	cerr << x << " ";
	// }
	// cerr << "<-- teachers\n";
	for (int i = 0; i < (int)ans.size(); ++i) {
		int pos = new_place[which_group[i]];
		int npos = lower_bound(all(values), new_value[i]) - values.begin();
		int new_balance = (a.end() - lower_bound(all(a), new_value[i])) - (m - npos) + (pos >= npos) - 1;
		// cerr << new_value[i] << ": " << pos << " " << npos << " " << new_balance << "\n";
		if (npos > pos) {
			ans[i] = (char)('0' + (min({st.get(0, pos), st.get(pos + 1, npos) - 1, st.get(npos, m), new_balance}) >= 0));
		} else {
			ans[i] = (char)('0' + (min({st.get(0, npos), st.get(npos, pos) + 1, st.get(pos + 1, m), new_balance}) >= 0));
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}