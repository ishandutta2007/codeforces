#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

struct Segtree {
	int n;
	vector<vector<int>> a;

	Segtree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = {ar[i]};
		}
		for (int i = n - 1; i > 0; --i) {
			int l = 0, r = 0;
			a[i].reserve(a[i + i].size() + a[i + i + 1].size());
			while (l < (int)a[i + i].size() && r < (int)a[i + i + 1].size()) {
				if (a[i + i][l] < a[i + i + 1][r]) {
					a[i].push_back(a[i + i][l++]);
				} else {
					a[i].push_back(a[i + i + 1][r++]);
				}
			}
			while (l < (int)a[i + i].size()) {
				a[i].push_back(a[i + i][l++]);
			}
			while (r < (int)a[i + i + 1].size()) {
				a[i].push_back(a[i + i + 1][r++]);
			}
		}
	}

	int _get_le(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return 0;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			return upper_bound(all(a[v]), x) - a[v].begin();
		}
		int mid = (l1 + r1) / 2;
		return _get_le(v + v, l1, mid, l, r, x) + _get_le(v + v + 1, mid, r1, l, r, x);
	}

	int get_le(int l, int r, int x) {
		return _get_le(1, 0, n, l, r, x);
	}
};

inline long long binom(int n) {
	return 1ll * n * (n - 1) / 2;
}

int main() {
	int n = nxt(), q = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}

	Segtree tree(a);

	while (q--) {
		int l = nxt() - 1, d = nxt() - 1, r = nxt(), u = nxt();
		// cerr << l << " " << d << " " << r << " " << u << "\n";
		int lcnt = l;
		int rcnt = n - r;
		int dcnt = d;
		int ucnt = n - u;
		int ldcnt = tree.get_le(0, l, d - 1);
		int rdcnt = tree.get_le(r, n, d - 1);
		int lucnt = l - tree.get_le(0, l, u - 1);
		int rucnt = n - r - tree.get_le(r, n, u - 1);

		// cerr << "lcnt = " << lcnt << "\n";
		// cerr << "rcnt = " << rcnt << "\n";
		// cerr << "dcnt = " << dcnt << "\n";
		// cerr << "ucnt = " << ucnt << "\n";
		// cerr << "ldcnt = " << ldcnt << "\n";
		// cerr << "rdcnt = " << rdcnt << "\n";
		// cerr << "lucnt = " << lucnt << "\n";
		// cerr << "rucnt = " << rucnt << "\n";

		long long ans = binom(lcnt)  + binom(rcnt)  + binom(dcnt)  + binom(ucnt) -
						binom(ldcnt) - binom(rdcnt) - binom(lucnt) - binom(rucnt);

		printf("%lld\n", binom(n) - ans);
	}

	return 0;
}