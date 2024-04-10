#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 222222;
int timer;
int tin[N], tout[N];
vector<pair<int, long long>> ed[N];
int val[N];
long long waylen[N];
vector<long long> sums;

void dfs(int v, int pr = -1) {
	tin[v] = timer++;
	sums.push_back(waylen[v] - val[v]);
	for (auto p : ed[v]) {
		if (p.first == pr) {
			continue;
		}
		waylen[p.first] = waylen[v] + p.second;
		dfs(p.first, v);
	}
	tout[v] = timer++;
	sums.push_back(waylen[v] - val[v]);
}

void merge(vector<long long>& to, const vector<long long>& fi, const vector<long long>& se) {
	int l = 0, r = 0;
	while (l < (int)fi.size() && r < (int)se.size()) {
		if (fi[l] < se[r]) {
			to.push_back(fi[l++]);
		} else {
			to.push_back(se[r++]);
		}
	}

	while (l < (int)fi.size()) {
		to.push_back(fi[l++]);
	}
	while (r < (int)se.size()) {
		to.push_back(se[r++]);
	}
}

struct SegmentTree {
	vector<vector<long long>> tree;
	int n;

	SegmentTree(const vector<long long>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		tree.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			tree[n + i].push_back(ar[i]);
		}
		for (int i = n - 1; i > 0; --i) {
			merge(tree[i], tree[i + i], tree[i + i + 1]);
		}
	}

	int get_(int v, int l1, int r1, int l, int r, long long lim) {
		if (l1 >= r || l >= r1) {
			return 0;
		}

		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			return upper_bound(all(tree[v]), lim) - tree[v].begin();
		}

		int m = (l1 + r1) / 2;
		return get_(v + v, l1, m, l, r, lim) + get_(v + v + 1, m, r1, l, r, lim);
	}

	int get(int l, int r, long long lim) {
		return get_(1, 0, n, l, r, lim);
	}
};

int main(){

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		val[i] = nxt();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = i + 1, v = nxt() - 1, w = nxt();
		ed[v].push_back({u, w});
		ed[u].push_back({v, w});
	}

	dfs(0);

	// for (auto x : sums) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";)

	// for (int i = 0; i < n; ++i) {
	// 	cerr << tin[i] << " " << tout[i] << " " << waylen[i] + val[i] << "\n";
	// }

	SegmentTree tree(sums);
	for (int i = 0; i < n; ++i) {
		printf("%d ", (tree.get(tin[i], tout[i], waylen[i]) - 1) / 2);
	}

	puts("");

	return 0;
}