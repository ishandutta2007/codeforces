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

const long long inf = 1e17;

void remax(long long& x, long long y) {
	x = (x > y) ? x : y;
}

struct Fenwick {
	int n;
	vector<long long> a;

	Fenwick(int _n): n(_n), a(_n, -inf) {}

	void remax(int pos, long long x) {
		while (pos < n) {
			::remax(a[pos], x);
			pos |= pos + 1;
		}
	}

	long long get(int pos) {
		long long res = -inf;
		while (pos >= 0) {
			::remax(res, a[pos]);
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<long long> p(n + 1);
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] + a[i - 1];
	}
	auto all_ps = p;
	make_unique(all_ps);
	const int sz = all_ps.size();

	auto get_index = [&](long long x) {
		return lower_bound(all(all_ps), x) - all_ps.begin();
	};

	Fenwick f_m(sz), f_p(sz);
	vector<long long> f_0(sz, -inf);
	f_m.remax(get_index(0), 0);
	f_0[get_index(0)] = 0;
	f_p.remax(sz - get_index(0) - 1, 0);

	long long last = 0;
	for (int i = 1; i <= n; ++i) {
		long long cur = p[i];
		int idx = get_index(cur);
		long long opt = -inf;
		remax(opt, f_0[idx]);
		remax(opt, f_m.get(idx - 1) + i);
		remax(opt, f_p.get(sz - idx - 2) - i);
		remax(f_0[idx], opt);
		f_m.remax(idx, opt - i);
		f_p.remax(sz - idx - 1, opt + i);
		last = opt;
	}

	cout << last << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}