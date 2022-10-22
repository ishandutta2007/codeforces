#include <bits/stdc++.h>
using namespace std;

int p[200010], fa[200010], dep[200010], a[200010];
int id[200010], num[200010], tot;
vector <int> son[200010];

struct Node {
	int x;
	Node operator = (const int &X) {
		x = X;
		return *this;
	}
	bool operator < (const Node &X) const {
		return dep[x] < dep[X.x];
	}
}f[400010][19];

int lg[400010], L[200010], R[200010];

void dfs(int x) {
	L[x] = id[x] = ++tot, f[tot][0] = x;
	for (int i = 0; i < son[x].size(); i++) {
		int v = son[x][i];
		dfs(v);
		f[++tot][0] = x;
	}
	R[x] = tot;
}

void get_f(int n) {
	n *= 2;
	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= n; i++) {
			if (i + (1 << j) - 1 > n) break;
			f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
		}
	}
	for (int i = 2; i <= n; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
}

int get_min(int l, int r) {
	if (l > r) swap(l, r);
	int k = lg[r - l + 1];
	return min(f[l][k], f[r - (1 << k) + 1][k]).x;
}

int get_lca(int x, int y) {
	return get_min(id[x], id[y]);
}

bool is_anc(int x, int y) {
	return L[x] < id[y] && id[y] < R[x];
}

int down(int x, int y) {
	return x == -1 || y == -1 ? x == -1 ? y : x : dep[x] > dep[y] ? x : y;
}

bool is_sub(int x, int y) {
	return is_anc(x, y) || is_anc(y, x);
}

struct Chain {
	int empty, alive;
	int lca, x, y;
	Chain() {empty = 1, alive = 1, lca = -1, x = y = -1;}
	Chain(const int &X) {*this = X;}
	Chain operator = (const int &X) {
		lca = X, empty = 0, alive = 1, x = y = -1;
		return *this;
	}
	Chain operator + (const Chain &A) const {
		if (empty || A.empty) return empty ? A : *this;
		Chain res; res.empty = 0;
		if (!alive || !A.alive || (lca != A.lca && y != -1 && A.y != -1)) {
			res.alive = 0;
			return res;
		}
		res.lca = get_lca(lca, A.lca);
		if (res.lca != lca && res.lca != A.lca) {
			if (y != -1 || A.y != -1) {
				res.alive = 0;
				return res;
			}
			res.x = x == -1 ? lca : x;
			res.y = A.x == -1 ? A.lca : A.x;
			return res;
		}
		if (y == -1 && A.y == -1) {
			if (lca != res.lca) {
				res.x = x == -1 ? lca : x;
				if (A.x == -1) return res;
				int tmp = get_lca(res.x, A.x);
				if (tmp == res.lca) res.y = A.x;
				else if (tmp == res.x || tmp == A.x) res.x = down(res.x, A.x);
				else {
					res.alive = 0;
					return res;
				}
				return res;
			}
			if (A.lca != res.lca) {
				res.x = A.x == -1 ? A.lca : A.x;
				if (x == -1) return res;
				int tmp = get_lca(res.x, x);
				if (tmp == res.lca) res.y = x;
				else if (tmp == res.x || tmp == x) res.x = down(res.x, x);
				else {
					res.alive = 0;
					return res;
				}
				return res;
			}
			if (x != -1 && A.x != -1) {
				if (is_sub(x, A.x)) res.x = down(x, A.x);
				else res.x = x, res.y = A.x;
			} else if (x != -1) res.x = x;
			else if (A.x != -1) res.x = A.x;
			return res;
		}
		if (res.lca == lca && lca == A.lca) {
			res.x = x, res.y = y;
			if (A.x != -1) {
				if (res.x == -1 || is_sub(res.x, A.x)) res.x = down(res.x, A.x);
				else if (res.y == -1 || is_sub(res.y, A.x)) res.y = down(res.y, A.x);
				else {
					res.alive = 0;
					return res;
				}
			}
			if (A.y != -1) {
				if (res.x == -1 || is_sub(res.x, A.y)) res.x = down(res.x, A.y);
				else if (res.y == -1 || is_sub(res.y, A.y)) res.y = down(res.y, A.y);
				else {
					res.alive = 0;
					return res;
				}
			}
			return res;
		}
		if ((res.lca == lca && y == -1) || (res.lca == A.lca && A.y == -1)) {
			res.alive = 0;
			return res;
		}
		if (y == -1) {
			res.x = A.x, res.y = A.y;
			int tmp = x == -1 ? lca : x;
			if (is_sub(tmp, res.x)) res.x = down(res.x, tmp);
			else if (is_sub(tmp, res.y)) res.y = down(res.y, tmp);
			else {
				res.alive = 0;
				return res;
			}
			return res;
		}
		assert(A.y == -1);
		res.x = x, res.y = y;
		int tmp = A.x == -1 ? A.lca : A.x;
		if (is_sub(tmp, res.x)) res.x = down(res.x, tmp);
		else if (is_sub(tmp, res.y)) res.y = down(res.y, tmp);
		else {
			res.alive = 0;
			return res;
		}
		return res;
	}
};

struct Segment_tree {
	Chain T[800010];
	void Build(int now, int l, int r) {
		if (l == r) {
			T[now] = a[l];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	void Update(int now, int l, int r, int pos, int x) {
		if (l == r) {
			T[now] = x;
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, x);
		else Update(now << 1 | 1, mid + 1, r, pos, x);
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	int Query(int now, int l, int r, Chain tmp) {
		if (l == r) return (tmp + T[now]).alive ? l : -1;
		int mid = l + r >> 1;
		if ((tmp + T[now << 1]).alive) return max(mid, Query(now << 1 | 1, mid + 1, r, tmp + T[now << 1]));
		return Query(now << 1, l, mid, tmp);
	}
}seg;

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		a[p[i]] = i;
	}
	for (int i = 2; i <= n; i++) {
		scanf("%d", &fa[i]);
		son[fa[i]].push_back(i);
		dep[i] = dep[fa[i]] + 1;
	}
	dfs(1), get_f(n), seg.Build(1, 0, n - 1);
	int q; scanf("%d", &q);
	while (q--) {
		int op, x, y; scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &x, &y);
			swap(p[x], p[y]);
			a[p[x]] = x, a[p[y]] = y;
			seg.Update(1, 0, n - 1, p[x], x);
			seg.Update(1, 0, n - 1, p[y], y);
		} else printf("%d\n", seg.Query(1, 0, n - 1, Chain()) + 1);
	}
	return 0;
}