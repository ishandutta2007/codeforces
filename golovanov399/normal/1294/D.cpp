#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct SegTree {
	int n;
	vector<int> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
	}

	void inc(int pos) {
		pos += n;
		a[pos] += 1;
		pos /= 2;
		while (pos) {
			a[pos] = min(a[2 * pos], a[2 * pos + 1]);
			pos /= 2;
		}
	}

	int get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return 1e9;
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		return min(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r);
	}

	int getmin(int c) {
		int v = 1;
		int l = 0, r = n;
		if (a[1] >= c) {
			return n;
		}
		while (r - l > 1) {
			if (a[2 * v] >= c) {
				v = 2 * v + 1;
				l = (l + r) / 2;
			} else {
				v = 2 * v;
				r = (l + r) / 2;
			}
		}
		return l;
	}
};

int main() {
	int q = nxt(), n = nxt();
	SegTree f(n);
	while (q--) {
		f.inc(nxt() % n);
		int c = f.get(0, n);
		cout << c * n + f.getmin(c + 1) << "\n";
	}

	return 0;
}