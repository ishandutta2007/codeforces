#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

// struct SegTree {
// 	int n;
// 	vector<int> a;

// 	SegTree(int _n) {
// 		n = 1;
// 		while (n < _n) {
// 			n *= 2;
// 		}
// 		a.resize(n + n);
// 	}

// 	void chg(int pos, int x) {
// 		pos += n;
// 		while (pos > 1) {
// 			a[pos] = max(a[pos], x);
// 			pos /= 2;
// 		}
// 	}

// 	int get(int v, int l1, int r1, int l, int r) {
// 		if (l >= r1 || l1 >= r) {
// 			return 0;
// 		}
// 		if (l <= l1 && r >= r1) {
// 			return a[v];
// 		}
// 		int m = (l1 + r1) / 2;
// 		return max(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
// 	}

// 	int get(int l, int r) {
// 		return get(1, 0, n, l, r);
// 	}
// };

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> last_touched(n, 0);
	int timer = 0;
	vector<int> xs;
	int q = nxt();
	// SegTree tree(q);
	while (q--) {
		int t = nxt();
		if (t == 1) {
			int p = nxt() - 1, bal = nxt();
			if (last_touched[p] < timer) {
				// a[p] = max(a[p], tree.get(last_touched[p], timer));
				last_touched[p] = timer;
			}
			a[p] = bal;
		} else {
			int x = nxt();
			xs.push_back(x);
			++timer;
		}
	}

	for (int i = timer - 2; i >= 0; --i) {
		xs[i] = max(xs[i], xs[i + 1]);
	}
	for (int i = 0; i < n; ++i) {
		if (last_touched[i] < timer) {
			a[i] = max(a[i], xs[last_touched[i]]);
		}
	}
	for (int x : a) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}