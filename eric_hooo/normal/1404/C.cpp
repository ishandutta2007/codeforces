#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

int a[300010];
vector <pii> all[300010];
int dp[300010], ans[300010];

struct Segment_tree {
	pii T[1200010]; int lazy[1200010];
	int S[1200010];
	void pushup(int now) {
		T[now] = max(T[now << 1], T[now << 1 | 1]);
	}
	void Build(int now, int l, int r) {
		lazy[now] = 0;
		if (l == r) {
			T[now] = mp((l - dp[l - 1] <= a[l] && a[l] <= l) ? l - dp[l - 1] - a[l] : -INF, l);
			S[now] = -dp[l];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void pushdown(int now) {
		T[now << 1].fi += lazy[now], T[now << 1 | 1].fi += lazy[now];
		lazy[now << 1] += lazy[now], lazy[now << 1 | 1] += lazy[now];
		S[now << 1] += lazy[now], S[now << 1 | 1] += lazy[now];
		lazy[now] = 0;
	}
	void Update(int now, int l, int r, int L, int R, int delta) {
		if (L > R) return ;
		if (l == L && r == R) {
			T[now].fi += delta, lazy[now] += delta, S[now] += delta;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, delta);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, delta);
		else Update(now << 1, l, mid, L, mid, delta), Update(now << 1 | 1, mid + 1, r, mid + 1, R, delta);
		pushup(now);
	}
	void Set(int now, int l, int r, int pos) {
		if (l == r) {
			T[now] = mp(-INF, -INF);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (pos <= mid) Set(now << 1, l, mid, pos);
		else Set(now << 1 | 1, mid + 1, r, pos);
		pushup(now);
	}
	int Query(int now, int l, int r, int pos) {
		if (l == r) return T[now].fi;
		pushdown(now);
		int mid = l + r >> 1;
		if (pos <= mid) return Query(now << 1, l, mid, pos);
		return Query(now << 1 | 1, mid + 1, r, pos);
	}
	int QueryS(int now, int l, int r, int pos) {
		if (l == r) return S[now];
		pushdown(now);
		int mid = l + r >> 1;
		if (pos <= mid) return QueryS(now << 1, l, mid, pos);
		return QueryS(now << 1 | 1, mid + 1, r, pos);
	}
}seg;

int main () {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < q; i++) {
		int x, y; scanf("%d%d", &x, &y);
		all[x].push_back(mp(n - y, i));
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + (i - dp[i - 1] <= a[i] && a[i] <= i);
	}
	seg.Build(1, 1, n);
	for (int i = 0; i < all[0].size(); i++) {
		int x = all[0][i].fi, id = all[0][i].se;
		ans[id] = dp[x];
	}
	for (int i = 1; i < n; i++) {
		if (seg.QueryS(1, 1, n, i)) {
			seg.Set(1, 1, n, i);
			seg.Update(1, 1, n, i, n, 1);
			while (seg.T[1].fi > 0) {
				int p = seg.T[1].se;
				seg.Set(1, 1, n, p);
				seg.Update(1, 1, n, p, n, 1);
			}
		}
		for (int j = 0; j < all[i].size(); j++) {
			int x = all[i][j].fi, id = all[i][j].se;
			ans[id] = -seg.QueryS(1, 1, n, x);
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}