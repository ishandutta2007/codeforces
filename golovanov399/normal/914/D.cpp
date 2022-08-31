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

struct SegTree {
	int n;
	vector<itn> a;

	SegTree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		n = n;
		a.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = ar[i];
		}

		for (itn i = n - 1; i > 0; --i) {
			if (a[i + i + 1]) {
				a[i] = __gcd(a[i + i], a[i + i + 1]);
			} else {
				a[i] = a[i + i];
			}
		}
	}

	void chg(int pos, itn x) {
		pos += n;
		a[pos] = x;
		pos /= 2;
		while (pos) {
			if (a[pos + pos + 1]) {
				a[pos] = __gcd(a[pos + pos], a[pos + pos + 1]);
			} else {
				a[pos] = a[pos + pos];
			}
			pos /= 2;
		}
	}

	int getMaxDiv(int l, int x) {
		int r = l + 1;
		int v = l + n;

		while (a[v] % x == 0) {
			if (r == n) {
				return n;
			}
			int p = v / 2;
			if (v == p * 2 + 1) {
				int len = r - l;
				l += len;
				r += len;
				v += 1;
			} else {
				r = 2 * r - l;
				v = p;
			}
		}

		while (r > l + 1) {
			if (a[v + v] % x) {
				r = (l + r) / 2;
				v *= 2;
			} else {
				l = (l + r) / 2;
				v = v * 2 + 1;
			}
		}
		return a[v] % x ? l : r;
	}

	int stupidMaxDiv(int l, int x) {
		l += n;
		while (l < n + n && a[l] % x == 0) {
			++l;
		}
		return l - n;
	}
};

void ut() {
	int n = 8;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 100 + 1;
	}
	SegTree tree(a);

	for (int i = 0; i < 100; ++i) {
		{
			int pos = rand() % n, x = rand() % 100 + 1;
			a[pos] = x;
			tree.chg(pos, x);
		}
		int l = rand() % n, x = rand() % 100 + 1;
		if (tree.getMaxDiv(l, x) != tree.stupidMaxDiv(l, x)) {
			cerr << n << "\n";
			for (int i = 0; i < n; ++i) {
				cerr << a[i] << " ";
			}
			cerr << "\n";
			cerr << l << " " << x << "\n";
			cerr << tree.getMaxDiv(l, x) << ", expected " << tree.stupidMaxDiv(l, x) << "\n";
			exit(0);
		}
	}
	cerr << "ok ";
}

int main() {
	// while (true) {
	// 	ut();
	// }

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	SegTree tree(a);

	int q = nxt();
	while (q--) {
		int t = nxt();
		if (t == 1) {
			int l = nxt() - 1, r = nxt(), x = nxt();
			int m = tree.getMaxDiv(l, x) + 1;
			if (m < r) {
				m = tree.getMaxDiv(m, x);
			}

			puts(m >= r ? "YES" : "NO");
		} else {
			int pos = nxt() - 1, x = nxt();
			tree.chg(pos, x);
		}
	}

	return 0;
}