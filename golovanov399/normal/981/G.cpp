#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;

void merge(long long& a, long long& b, long long& c, long long& d) {
	b = (b * c + d) % mod;
	a = (a * c) % mod;
}

struct Node {
	int l, r;
	int id;
	long long a, b;
	long long sum;

	Node() {
		l = r = -1;
		id = 0;
		a = 1;
		b = 0;
		sum = 0;
	}

	inline long long eval() const {
		return (sum * a + b * (r - l)) % mod;
	}
};

struct Segtree {
	int n;
	vector<Node> a;

	Segtree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		for (int start = 1; start <= n; start *= 2) {
			int step = n / start;
			for (int i = 0; i * step < n; ++i) {
				a[start + i].l = i * step;
				a[start + i].r = (i + 1) * step;
				a[start + i].id = start + i;
			}
		}
	}

	void relax(int v) {
		if (v >= n) {
			return;
		}
		merge(a[2 * v].a, a[2 * v].b, a[v].a, a[v].b);
		merge(a[2 * v + 1].a, a[2 * v + 1].b, a[v].a, a[v].b);
		a[v].sum = a[v].eval();
		a[v].a = 1, a[v].b = 0;
	}

	long long add(int v, int l, int r, long long x) {
		if (l >= a[v].r || a[v].l >= r) {
			return 0;
		}
		if (l <= a[v].l && r >= a[v].r) {
			long long to_ret = x * (a[v].r - a[v].l) % mod;
			a[v].b = (a[v].b + x) % mod;
			return to_ret;
		}
		relax(v);
		long long to_ret = 0;
		to_ret += add(v + v, l, r, x);
		to_ret += add(v + v + 1, l, r, x);
		to_ret %= mod;
		a[v].sum += to_ret;
		a[v].sum %= mod;
		return to_ret;
	}

	void add(int l, int r, int x = 1) {
		add(1, l, r, x);
	}

	long long mul(int v, int l, int r, long long x) {
		if (l >= a[v].r || a[v].l >= r) {
			// cerr << "// at " << v << " is 0\n";
			return 0;
		}
		if (l <= a[v].l && r >= a[v].r) {
			// cerr << "// v: " << a[v].sum << ", " << a[v].a << ", " << a[v].b << "\n";
			long long to_ret = a[v].eval();
			to_ret = to_ret * (x - 1) % mod;
			a[v].a = (a[v].a * x) % mod;
			a[v].b = (a[v].b * x) % mod;
			// cerr << "// at " << v << " is " << to_ret << "\n";
			return to_ret;
		}
		relax(v);
		// cerr << "// relaxed at " << v << "\n";
		long long to_ret = 0;
		to_ret += mul(v + v, l, r, x);
		to_ret += mul(v + v + 1, l, r, x);
		to_ret %= mod;
		a[v].sum += to_ret;
		a[v].sum %= mod;
		return to_ret;
	}

	void mul(int l, int r, int x = 2) {
		mul(1, l, r, x);
	}

	long long get(int v, int l, int r) {
		if (l >= a[v].r || a[v].l >= r) {
			return 0;
		}
		if (l <= a[v].l && r >= a[v].r) {
			return a[v].eval();
		}
		relax(v);
		return (get(v + v, l, r) + get(v + v + 1, l, r)) % mod;
	}

	long long get(int l, int r) {
		return get(1, l, r);
	}
};

bool inter(const pair<int, int>& p, const pair<int, int>& q, int strict = 0) {
	return max(p.first, q.first) < min(p.second, q.second) + 1 - strict;
}

ostream& operator <<(ostream& ostr, const pair<auto, auto>& p) {
	ostr << "[" << p.first << ", " << p.second << ")";
	return ostr;
}

void addSeg(set<pair<int, int>>& S, int l, int r, Segtree& tree) {
	pair<int, int> p = {l, -1};
	auto it = S.lower_bound(p);
	pair<int, int> to_add = {l, r};
	// cerr << "adding " << to_add << ":\n";
	auto beg_inter = it;
	while (beg_inter != S.begin() && inter(*prev(beg_inter), to_add)) {
		--beg_inter;
	}
	auto end_inter = it;
	while (end_inter != S.end() && inter(*end_inter, to_add)) {
		++end_inter;
	}

	int last_r = -1;
	for (it = beg_inter; it != end_inter; ++it) {
		// cerr << " intersects with " << *it << ",\n";
		if (last_r > -1 && it->first >= l) {
			// cerr << "  add one to [" << last_r << ", " << it->first << ")\n";
			tree.add(last_r, it->first);
		} else if (it->first >= l) {
			// cerr << "  add one to [" << l << ", " << it->first << ")\n";
			tree.add(l, it->first);
		}
		last_r = min(r, it->second);
		// cerr << "  multiply by two on [" << max(l, it->first) << ", " << last_r << ")\n";
		tree.mul(max(l, it->first), last_r);
		to_add.first = min(to_add.first, it->first);
		to_add.second = max(to_add.second, it->second);
	}
	if (last_r == -1) {
		// cerr << " add one to [" << l << ", " << r << ")\n";
		tree.add(l, r);
	} else {
		// cerr << " add one to [" << last_r << ", " << r << ")\n";
		tree.add(last_r, r);
	}

	it = beg_inter;
	while (it != end_inter) {
		// cerr << " removing " << *it << "\n";
		++it;
		S.erase(prev(it));
	}
	// cerr << " inserting " << to_add << "\n";
	S.insert(to_add);
}

vector<long long> solve(int n, const vector<vector<int>>& qrs) {
	Segtree tree(n);
	vector<set<pair<int, int>>> a(n);
	vector<long long> ans;

	for (const auto& qr : qrs) {
		int t = qr[0];
		if (t == 1) {
			int l = qr[1] - 1, r = qr[2], x = qr[3] - 1;
			addSeg(a[x], l, r, tree);
		} else {
			int l = qr[1] - 1, r = qr[2];
			// printf("%lld\n", tree.get(l, r));
			ans.push_back(tree.get(l, r));
		}
	}
	return ans;
}

vector<long long> stupid(int n, const vector<vector<int>>& qrs) {
	vector<long long> sz(n);
	vector<set<int>> S(n);
	vector<long long> ans;

	for (const auto& qr : qrs) {
		int t = qr[0];
		if (t == 1) {
			int l = qr[1] - 1, r = qr[2], x = qr[3] - 1;
			for (int i = l; i < r; ++i) {
				if (S[i].count(x)) {
					sz[i] = sz[i] * 2 % mod;
				} else {
					sz[i] += 1;
					S[i].insert(x);
				}
			}
		} else {
			int l = qr[1] - 1, r = qr[2];
			long long s = 0;
			for (int i = l; i < r; ++i) {
				s += sz[i];
			}
			ans.push_back(s % mod);
		}
	}
	return ans;
}

vector<vector<int>> genQrs(int& n, int q) {
	vector<vector<int>> qrs(q);
	n = rand() % 5 + 1;
	for (int i = 0; i < q; ++i) {
		int t = rand() % 2 + 1;
		qrs[i].push_back(t);
		int l = rand() % n, r = rand() % n;
		if (l > r) {
			swap(l, r);
		}
		qrs[i].push_back(l + 1);
		qrs[i].push_back(r + 1);
		if (t == 1) {
			qrs[i].push_back(rand() % n + 1);
		}
	}
	return qrs;
}

ostream& operator <<(ostream& ostr, const vector<auto>& a) {
	ostr << "(";
	for (int i = 0; i < (int)a.size(); ++i) {
		if (i) ostr << ", ";
		ostr << a[i];
	}
	ostr << ")";
	return ostr;
}

int main() {
#if 1
	int n = nxt(), q = nxt();
	vector<vector<int>> qrs(q);
	for (int i = 0; i < q; ++i) {
		int t = nxt();
		qrs[i].push_back(t);
		for (int j = 0; j < 4 - t; ++j) {
			qrs[i].push_back(nxt());
		}
	}

	auto res = solve(n, qrs);
	for (auto x : res) {
		printf("%lld\n", x);
	}
#else
	while (true) {
		int n, q;
		q = 10;
		auto qrs = genQrs(n, q);
		auto ans = stupid(n, qrs);
		auto res = solve(n, qrs);
		if (ans != res) {
			cerr << n << " " << q << "\n" << qrs << "\ncorrect = " << ans << "\nyours = " << res << "\n";
			return 0;
		} else {
			cerr << "ok\n";
		}
	}
#endif

	return 0;
}