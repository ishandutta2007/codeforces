#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

const int base = 2000000;

vector <piii> all[4000010];
pii a[300010];

struct Segment_tree {
	int maxj[16000010], lazy[16000010];
	void pushup(int now) {
		maxj[now] = max(maxj[now << 1], maxj[now << 1 | 1]);
	}
	void pushdown(int now) {
		if (!lazy[now]) return ;
		int v = lazy[now]; lazy[now] = 0;
		maxj[now << 1] += v, maxj[now << 1 | 1] += v;
		lazy[now << 1] += v, lazy[now << 1 | 1] += v; 
	}
	void Build(int now, int l, int r) {
		maxj[now] = lazy[now] = 0;
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Update(int now, int l, int r, int L, int R, int val) {
		if (l == L && r == R) {
			maxj[now] += val, lazy[now] += val;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, val);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, val);
		else Update(now << 1, l, mid, L, mid, val), Update(now << 1 | 1, mid + 1, r, mid + 1, R, val);
		pushup(now);
	}
	int Query() {return maxj[1];}
}seg;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].fi, &a[i].se);
		int x = a[i].fi + a[i].se, y = a[i].fi - a[i].se;
		a[i].fi = x + base, a[i].se = y + base;
		all[max(a[i].fi - k, 0)].push_back(mp(mp(a[i].se - k, a[i].se + k), 1));
		all[min(a[i].fi + k, 2 * base) + 1].push_back(mp(mp(a[i].se - k, a[i].se + k), -1));
	}
	seg.Build(1, 0, 2 * base);
	int ans = 0;
	for (int i = 0; i <= 2 * base; i++) {
		for (int j = 0; j < all[i].size(); j++) {
			int l = all[i][j].fi.fi, r = all[i][j].fi.se, val = all[i][j].se;
			l = max(0, l), r = min(2 * base, r);
			seg.Update(1, 0, 2 * base, l, r, val);
		}
		ans = max(ans, seg.Query());
	}
	printf("%d\n", ans);
	return 0;
}