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
	vector<int> a;
	vector<int> ad;

	Segtree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		ad.resize(n + n);

		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = ar[i];
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = max(a[i + i], a[i + i + 1]);
		}
	}

	void push(int v) {
		a[v + v] += ad[v];
		ad[v + v] += ad[v];
		a[v + v + 1] += ad[v];
		ad[v + v + 1] += ad[v];
		ad[v] = 0;
	}

	void _add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			ad[v] += x;
			a[v] += x;
			return;
		}
		push(v);
		int mid = (l1 + r1) / 2;
		_add(v + v, l1, mid, l, r, x);
		_add(v + v + 1, mid, r1, l, r, x);
		a[v] = max(a[v + v], a[v + v + 1]);
	}

	void add(int l, int r, int x) {
		_add(1, 0, n, l, r, x);
	}

	int _get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return INT_MIN;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			return a[v];
		}
		push(v);
		int mid = (l1 + r1) / 2;
		int result = max(_get(v + v, l1, mid, l, r),
						 _get(v + v + 1, mid, r1, l, r));
		a[v] = max(a[v + v], a[v + v + 1]);
		return result;
	}

	int get(int l, int r) {
		return _get(1, 0, n, l, r);
	}
};

int main() {
	int n = nxt();
	int k = nxt();
	vector<int> a(n, 0);

	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = nxt();
	}

	vector<int> prv(n, -1);
	vector<int> plus(n);
	map<int, int> lol;
	for (int i = 0; i < n; ++i) {
		if (lol.count(ar[i])) {
			prv[i] = lol[ar[i]];
			plus[lol[ar[i]]] -= 1;
		}
		plus[i] += 1;
		lol[ar[i]] = i;
	}
	for (int i = n - 2; i >= 0; --i) {
		plus[i] += plus[i + 1];
	}

	for (int kk = 1; kk <= k; ++kk) {
		vector<int> b(n);
		for (int i = n - 1; i > 0; --i) {
			a[i] = a[i - 1] + plus[i];
		}
		a[0] = plus[0];
		Segtree tree(a);

		for (int i = n; i >= kk; --i) {
			b[i - 1] = tree.get(kk - 1, i);
			tree.add(prv[i - 1] + 1, i, -1);
			// if (prv[i - 1] > -1) {
			// 	tree.add(prv[prv[i - 1]] + 1, prv[i - 1], 1);
			// }
		}

		b.swap(a);
		// for (int x : a) {
		// 	cerr << x << " ";
		// }
		// cerr << "\n";
	}

	cout << a.back() << "\n";

	return 0;
}