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
		V res = 0;
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

const int N = 303'000;

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	// fill(all(a), 300'000);

	Fenwick<long long> fsum(N);
	Fenwick<long long> fsmall(N);
	Fenwick<int> fcnt(N);
	long long ans = 0;
	for (int x : a) {
		ans += fsum.get(N - 1) + 1ll * x * fcnt.get(N - 1);
		ans -= fsmall.get(x);
		for (int i = 1; x * i < N; ++i) {
			ans -= 1ll * x * i * fcnt.get(x * i, min(N, x * (i + 1)));
			fsmall.add(x * i, x);
		}

		fsum.add(x, x);
		fcnt.add(x, 1);
		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}