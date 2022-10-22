#include <bits/stdc++.h>
using namespace std;

int n, q;

struct BIT {
	int T[200010];
	long long S[200010];
	void clear() {memset(T, 0, sizeof(T)), memset(S, 0, sizeof(S));}
	void modify(int x, int v) {
		for (int i = x; i <= 200005; i += i & -i) {
			T[i] += v, S[i] += v * x;
		}
	}
	void modify(int l, int r, int x) {
		modify(l, x), modify(r + 1, -x);
	}
	long long query(int x) {
		long long res = 0;
		for (int i = x; i; i -= i & -i) {
			res += 1ll * (x + 1) * T[i] - S[i];
		}
		return res;
	}
	long long query(int l, int r) {return query(r) - query(l - 1);}
}bit;

struct Segment_tree {
	int mx1[800010], mx2[800010], cnt[800010];
	void pushup(int now) {
		mx1[now] = max(mx1[now << 1], mx1[now << 1 | 1]);
		mx2[now] = max(mx2[now << 1], mx2[now << 1 | 1]);
		cnt[now] = 0;
		if (mx1[now] == mx1[now << 1]) cnt[now] += cnt[now << 1];
		else mx2[now] = max(mx2[now], mx1[now << 1]);
		if (mx1[now] == mx1[now << 1 | 1]) cnt[now] += cnt[now << 1 | 1];
		else mx2[now] = max(mx2[now], mx1[now << 1 | 1]);
	}
	void pushdown(int now) {
		mx1[now << 1] = min(mx1[now << 1], mx1[now]);
		mx1[now << 1 | 1] = min(mx1[now << 1 | 1], mx1[now]);
	}
	void Build(int now, int l, int r) {
		if (l == r) {
			mx1[now] = l, cnt[now] = 1, mx2[now] = -1;
			bit.modify(l, l, 1);
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (L > R) return ;
		if (l == L && r == R) {
			if (x >= mx1[now]) return ;
			if (x > mx2[now]) {
				bit.modify(x + 1, mx1[now], -cnt[now]);
				mx1[now] = x;
				return ;
			}
			pushdown(now);
			int mid = l + r >> 1;
			Update(now << 1, l, mid, l, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, r, x);
			pushup(now);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	void Modify(int now, int l, int r, int x, int v) {
		if (l == r) {
			bit.modify(l, mx1[now], -1);
			bit.modify(l, v, 1);
			mx1[now] = v, cnt[now] = 1, mx2[now] = -1;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (x <= mid) Modify(now << 1, l, mid, x, v);
		else Modify(now << 1 | 1, mid + 1, r, x, v);
		pushup(now);
	}
}seg;

int main() {
	scanf("%d%d", &n, &q);
	bit.clear(), seg.Build(1, 1, n);
	while (q--) {
		int op, x, y; scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			seg.Update(1, 1, n, 1, x - 1, x - 1);
			seg.Modify(1, 1, n, x, y);
		} else {
			printf("%lld\n", bit.query(x, y));
		}
	}
	return 0;
}