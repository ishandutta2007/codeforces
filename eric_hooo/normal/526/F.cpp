#include <bits/stdc++.h>
using namespace std;

int a[300010];

struct Segment_tree {
	int minj[1200010], lazy[1200010], cnt[1200010];
	void pushup(int now) {
		if (minj[now << 1] < minj[now << 1 | 1]) {
			minj[now] = minj[now << 1], cnt[now] = cnt[now << 1];
		} else if (minj[now << 1] > minj[now << 1 | 1]) {
			minj[now] = minj[now << 1 | 1], cnt[now] = cnt[now << 1 | 1];
		} else {
			minj[now] = minj[now << 1], cnt[now] = cnt[now << 1] + cnt[now << 1 | 1];
		}
	}
	void pushdown(int now) {
		if (!lazy[now]) return ;
		int v = lazy[now]; lazy[now] = 0;
		minj[now << 1] += v, minj[now << 1 | 1] += v;
		lazy[now << 1] += v, lazy[now << 1 | 1] += v;
	}
	void Build(int now, int l, int r) {
		lazy[now] = 0;
		if (l == r) {
			minj[now] = l, cnt[now] = 1;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int val) {
		if (l == L && r == R) {
			minj[now] += val, lazy[now] += val;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, val);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, val);
		else Update(now << 1, l, mid, L, mid, val), Update(now << 1 | 1, mid + 1, r, mid + 1, R, val);
		pushup(now);
	}
	long long Query() {return cnt[1];}
}seg;

int s1[300010], s2[300010], t1, t2;

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[x] = y;
	}
	seg.Build(1, 1, n);
	t1 = t2 = 0; s1[t1++] = 0, s2[t2++] = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		while (t1 > 1 && a[s1[t1 - 1]] > a[i]) {
			seg.Update(1, 1, n, s1[t1 - 2] + 1, s1[t1 - 1], a[s1[t1 - 1]]);
			t1--;
		}
		s1[t1++] = i;
		seg.Update(1, 1, n, s1[t1 - 2] + 1, s1[t1 - 1], -a[s1[t1 - 1]]);
		while (t2 > 1 && a[s2[t2 - 1]] < a[i]) {
			seg.Update(1, 1, n, s2[t2 - 2] + 1, s2[t2 - 1], -a[s2[t2 - 1]]);
			t2--;
		}
		s2[t2++] = i;
		seg.Update(1, 1, n, s2[t2 - 2] + 1, s2[t2 - 1], a[s2[t2 - 1]]);
		ans += seg.Query();
		assert(seg.minj[1] == i);
	}
	printf("%I64d\n", ans);
	return 0;
}