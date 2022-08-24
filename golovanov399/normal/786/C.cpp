#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct SegmentTree {
	int n;
	vector<int> tree, ad;

	SegmentTree() {
		n = 0;
	}

	SegmentTree(int nn) {
		n = 1;
		while (n < nn) {
			n *= 2;
		}
		tree.resize(n + n);
		ad.resize(n + n);
	}

	SegmentTree(const vector<int>& a) {
		n = 1;
		while (n < (int)a.size()) {
			n *= 2;
		}
		tree.resize(n + n);
		ad.resize(n + n);

		for (int i = 0; i < (int)a.size(); ++i) {
			tree[n + i] = a[i];
		}
		for (int i = n - 1; i > 0; --i) {
			tree[i] = tree[i + i] + tree[i + i + 1];
		}
	}

	void relax(int v, int len) {
		tree[v] += len * ad[v];
		if (v < n) {
			ad[v + v] += ad[v];
			ad[v + v + 1] += ad[v];
		}
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
			return;
		}

		relax(v, r1 - l1);
		tree[v] += (r - l) * x;
		int mid = (l1 + r1) / 2;
		_add(v + v, l1, mid, l, r, x);
		_add(v + v + 1, mid, r1, l, r, x);
	}

	void add(int l, int r, int x) {
		_add(1, 0, n, l, r, x);
	}

	int _get(int v, int l1, int r1, int l, int r) {
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
			return tree[v] + (r1 - l1) * ad[v];
		}

		int mid = (l1 + r1) / 2;
		return ad[v] * (r - l) + _get(v + v, l1, mid, l, r) + _get(v + v + 1, mid, r1, l, r);
	}

	int get(int l, int r) {
		return _get(1, 0, n, l, r);
	}

	void show() {
		for (int i = 0; i < n; ++i) {
			cerr << get(i, i + 1) << " ";
		}
		cerr << "\n";
	}

	int get_kth(int k) {
		int v = 1;
		int l = 0, r = n;
		int cur = 0;
		int curad = ad[v];
		while (v < n) {
			if (cur + tree[v + v + 1] + (r - l) / 2 * (curad + ad[v + v + 1]) < k) {
				cur = cur + tree[v + v + 1] + (r - l) / 2 * (curad + ad[v + v + 1]);
				r = (l + r) / 2;
				v = v + v;
			} else {
				cur = cur + (r - l) / 2 * ad[v + v + 1];
				l = (l + r) / 2;
				v = v + v + 1;
			}
			curad += ad[v];
		}
		return v - n;
	}
};

int main() {

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> b = a;
	sort(all(b));
	b.resize(unique(all(b)) - b.begin());
	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(all(b), a[i]) - b.begin();
	}

	int cnt = b.size();
	vector<vector<pair<int, int>>> color_events(cnt);
	vector<int> lst(cnt);
	for (int i = 0; i < n; ++i) {
		color_events[a[i]].push_back({lst[a[i]], i});
		lst[a[i]] = i + 1;
	}
	for (int i = 0; i < cnt; ++i) {
		color_events[i].push_back({lst[i], n});
	}

	vector<vector<int>> events(n + 1);
	vector<int> pop(n + 1);
	for (int i = 0; i < cnt; ++i) {
		for (auto p : color_events[i]) {
			if (p.first == p.second) {
				continue;
			}
			events[p.first].push_back(p.second);
			pop[p.second] += 1;
		}
	}

	vector<int> ans(n);
	set<pair<int, int>> nx;
	for (int i = 0; i < cnt; ++i) {
		nx.insert({0, i + 1});
	}

	// for (int i = 0; i < n; ++i) {
	// 	for (int j : events[i]) {
	// 		cerr << i << ", " << j << "\n";
	// 	}
	// }

	SegmentTree tree(n + 1);
	int curcnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int x : events[i]) {
			tree.add(x, x + 1, 1);
			// tree.add(0, x + 1, 1);
			// tree.add(x, n + 1, 1);
			++curcnt;
		}
		tree.add(i, i + 1, -pop[i]);
		// tree.add(0, i + 1, -pop[i]);
		// tree.add(i, n + 1, -pop[i]);
		curcnt -= pop[i];

		while (!nx.empty() && nx.begin()->first == i) {
			int k = nx.begin()->second;
			nx.erase(nx.begin());

			// cerr << i << " " << k << "\n";
			// max {j : #{(i, j) \subset ...} >= cnt - k}
			if (cnt - k == 0) {
				ans[k - 1] += 1;
				continue;
			}
			// cerr << i << " " << req << " " << k << "\n";
			// tree.show();
			// cerr << tree.get_kth(req + 1) << "\n";
			// assert(req >= 0);

			ans[k - 1] += 1;
			nx.insert({tree.get_kth(cnt - k), k});
		}

	}

	for (int i = cnt; i < n; ++i) {
		ans[i] = ans[i - 1];
	}

	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}