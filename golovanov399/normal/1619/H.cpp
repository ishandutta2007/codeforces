#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

mt19937 rr;

struct Node {
	int key, prior;
	int l, r;
	int par;
	int size;

	Node(): key(0), prior(0), l(-1), r(-1), par(-1), size(0) {}
	explicit Node(int x): key(x), prior(rr()), l(-1), r(-1), par(-1), size(1) {}
};

const int N = 1e5 + 100;
Node nodes[N];
int sz = 0;

int getsize(int v) {
	return ~v ? nodes[v].size : 0;
}

void recalc(int v) {
	nodes[v].size = 1 + getsize(nodes[v].l) + getsize(nodes[v].r);
	nodes[v].par = -1;
	if (~nodes[v].l) {
		nodes[nodes[v].l].par = v;
	}
	if (~nodes[v].r) {
		nodes[nodes[v].r].par = v;
	}
}

void split(int v, int sz, int& l, int& r) {
	if (v == -1) {
		l = r = -1;
		return;
	}
	if (int lsz = getsize(nodes[v].l); lsz >= sz) {
		split(nodes[v].l, sz, l, nodes[v].l);
		r = v;
	} else {
		split(nodes[v].r, sz - 1 - lsz, nodes[v].r, r);
		l = v;
	}
	recalc(v);
}

int merge(int l, int r) {
	if (l == -1) {
		return r;
	}
	if (r == -1) {
		return l;
	}
	if (nodes[l].prior > nodes[r].prior) {
		nodes[l].r = merge(nodes[l].r, r);
		recalc(l);
		return l;
	} else {
		nodes[r].l = merge(l, nodes[r].l);
		recalc(r);
		return r;
	}
}

struct PosInfo {
	int root;
	int pos;
};

PosInfo track(int v) {
	int pos = getsize(nodes[v].l);
	while (~nodes[v].par) {
		int p = nodes[v].par;
		if (nodes[p].r == v) {
			pos += getsize(nodes[p].l) + 1;
		}
		v = p;
	}
	return {v, pos};
}

int rotate(int root, int sz) {
	int l, r;
	split(root, sz, l, r);
	return merge(r, l);
}

int get_kth(int v, int k) {
	while (true) {
		if (auto lsz = getsize(nodes[v].l); lsz > k) {
			v = nodes[v].l;
		} else if (lsz == k) {
			return v;
		} else {
			k -= lsz + 1;
			v = nodes[v].r;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = nxt(), q = nxt();
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt() - 1;
	}
	for (int i = 0; i < n; ++i) {
		nodes[i] = Node(i);
	}
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		int root = -1;
		for (int x = i; !used[x]; x = p[x]) {
			used[x] = 1;
			root = merge(root, x);
		}
	}

	while (q--) {
		int t = nxt();
		if (t == 1) {
			int i = nxt() - 1, j = nxt() - 1;
			auto pi = track(i);
			auto pj = track(j);
			if (pi.root == pj.root) {
				if (pi.pos > pj.pos) {
					swap(i, j);
					swap(pi, pj);
				}
				int root = rotate(pi.root, pi.pos + 1);
				pj.pos -= pi.pos;
				int l, r;
				split(root, pj.pos, l, r);
			} else {
				int l = rotate(pi.root, pi.pos + 1);
				int r = rotate(pj.root, pj.pos + 1);
				merge(l, r);
			}
		} else {
			int i = nxt() - 1, k = nxt();
			auto [root, pos] = track(i);
			pos += k;
			pos %= getsize(root);
			cout << get_kth(root, pos) + 1 << "\n";
		}
	}

	return 0;
}