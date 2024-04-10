#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppp;

int a[500010];
vector <int> all[500010];
vector <ppp> op[500010];
pii rng[500010];

void add_op(int l, int r, int L, int R) {
	if (l > r || L > R) return ;
	op[l].push_back(mp(mp(L, R), 1));
	op[r + 1].push_back(mp(mp(L, R), -1));
}

pii merge(pii a, pii b) {
	return a.fi == b.fi ? mp(a.fi, a.se + b.se) : a.fi < b.fi ? b : a;
}

struct Segment_tree {
	pii T[2000010]; int lazy[2000010];
	void pushup(int now) {
		T[now] = merge(T[now << 1], T[now << 1 | 1]);
	}
	void pushdown(int now) {
		if (!lazy[now]) return ;
		lazy[now << 1] += lazy[now], lazy[now << 1 | 1] += lazy[now];
		T[now << 1].fi += lazy[now], T[now << 1 | 1].fi += lazy[now];
		lazy[now] = 0;
	}
	void Build(int now, int l, int r) {
		lazy[now] = 0;
		if (l == r) {
			T[now] = mp(0, 1);
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int delta) {
		if (l == L && r == R) {
			lazy[now] += delta;
			T[now].fi += delta;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, delta);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, delta);
		else Update(now << 1, l, mid, L, mid, delta), Update(now << 1 | 1, mid + 1, r, mid + 1, R, delta);
		pushup(now);
	}
	pii Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return merge(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		all[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= all[i].size(); j++) {
			int pre = j == 0 ? 0 : all[i][j - 1], suc = j == all[i].size() ? n + 1 : all[i][j];
			rng[j] = mp(pre + 1, suc - 1);
		}
		for (int j = 0; j <= all[i].size(); j++) {
			add_op(rng[j].fi, rng[j].se, rng[j].fi, rng[j].se);
			if (j + 3 <= all[i].size()) {
				add_op(rng[j].fi, rng[j].se + 1, rng[j + 3].fi - 1, rng[j + 3].se);
			}
		}
	}
	seg.Build(1, 1, n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < op[i].size(); j++) {
			int l = op[i][j].fi.fi, r = op[i][j].fi.se, delta = op[i][j].se;
			seg.Update(1, 1, n, l, r, delta);
		}
		pii tmp = seg.Query(1, 1, n, i, n);
		if (tmp.fi == n) ans += tmp.se;
	}
	printf("%lld\n", ans);
	return 0;
}