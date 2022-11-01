#pragma GCC optimize("O3")

#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {
	int n;
	vector<int> t;

	explicit SegmentTree(int size) {
		n = size;
		t.resize(4 * n);
	}

	void Push(int v) {
		t[v * 2] += t[v];
		t[v * 2 + 1] += t[v];
		t[v] = 0;
	}

	int Get(int v, int tl, int tr, int pos) {
		if (tl == tr) {
			return t[v];
		}
		Push(v);
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			return Get(v * 2, tl, tm, pos);
		} else {
			return Get(v * 2 + 1, tm + 1, tr, pos);
		}
	}

	void Update(int v, int tl, int tr, int l, int r, int val) {
		if (l > r) {
			return;
		}
		if (l == tl && r == tr) {
			t[v] += val;
			return;
		}
		int tm = (tl + tr) / 2;
		Update(v * 2, tl, tm, l, min(r, tm), val);
		Update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}

	void Update(int l, int r, int val) {
		// cout << "UPD: " << l << ' ' << r << ' ' << val << '\n';
		Update(1, 0, n - 1, l, r, val);
	}

	int Get(int pos) {
		return Get(1, 0, n - 1, pos);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n * m);
		for (int i = 0; i < n * m; ++i) {
			char ch;
			cin >> ch;
			a[i] = ch - '0';
		}
		SegmentTree segment_tree(m);
		vector<int> cols(m);
		int dist = n * m + 1;
		int good = 0;
		for (int i = 0; i < n * m; ++i) {
			if (a[i] == 0) {
				++dist;
			} else {
				if (dist >= m) {
					segment_tree.Update(0, m - 1, 1);
				} else {
					int L = (i + m - dist - 1) % m;
					int R = (i + m - 1) % m;
					if (L <= R) {
						segment_tree.Update(L, R, 1);
					} else {
						segment_tree.Update(0, R, 1);
						segment_tree.Update(L, m - 1, 1);
					}
				}
				dist = 0;
			}
			cols[i % m] += a[i];
			if (cols[i % m] == 1 && a[i] == 1) {
				++good;
			}
			cout << good + segment_tree.Get(i % m) << ' ';
		}
		cout << '\n';
	}
	return 0;
}