#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, N = 100000;

struct Segment_tree1 {
	int T[400010];
	void Build(int now, int l, int r) {
		T[now] = INF;
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {T[now] = min(T[now], x); return ;}
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
	}
	int Query(int now, int l, int r, int pos) {
		if (l == r) return T[now];
		int mid = l + r >> 1;
		if (pos <= mid) return min(T[now], Query(now << 1, l, mid, pos));
		return min(T[now], Query(now << 1 | 1, mid + 1, r, pos));
	}
}R[2];

struct Segment_tree2 {
	int mx1[400010], cnt[400010], mx2[400010];
	long long sum[400010];
	void pushup(int now) {
		mx1[now] = max(mx1[now << 1], mx1[now << 1 | 1]);
		cnt[now] = (mx1[now] == mx1[now << 1] ? cnt[now << 1] : 0)
				 + (mx1[now] == mx1[now << 1 | 1] ? cnt[now << 1 | 1] : 0);
		mx2[now] = max(mx1[now] == mx1[now << 1] ? mx2[now << 1] : mx1[now << 1],
					   mx1[now] == mx1[now << 1 | 1] ? mx2[now << 1 | 1] : mx1[now << 1 | 1]);
		sum[now] = sum[now << 1] + sum[now << 1 | 1];
	}
	void Build(int now, int l, int r) {
		if (l == r) {mx1[now] = 0, cnt[now] = 1, mx2[now] = -1, sum[now] = 0; return ;}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void pushdown(int now) {
		if (mx1[now << 1] > mx1[now]) {
			sum[now << 1] -= 1ll * (mx1[now << 1] - mx1[now]) * cnt[now << 1];
			mx1[now << 1] = mx1[now];
		}
		if (mx1[now << 1 | 1] > mx1[now]) {
			sum[now << 1 | 1] -= 1ll * (mx1[now << 1 | 1] - mx1[now]) * cnt[now << 1 | 1];
			mx1[now << 1 | 1] = mx1[now];
		}
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {
			if (x >= mx1[now]) return ;
			if (x > mx2[now]) {
				sum[now] -= 1ll * (mx1[now] - x) * cnt[now];
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
	void Modify(int now, int l, int r, int pos, int x) {
		if (l == r) {mx1[now] = x, cnt[now] = 1, mx2[now] = -1, sum[now] = x; return ;}
		pushdown(now);
		int mid = l + r >> 1;
		if (pos <= mid) Modify(now << 1, l, mid, pos, x);
		else Modify(now << 1 | 1, mid + 1, r, pos, x);
		pushup(now);
	}
	long long Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return sum[now];
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) + Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
}seg[2];

set <int> S[4];

int main() {
	R[0].Build(1, 1, N), R[1].Build(1, 1, N), seg[0].Build(1, 1, N), seg[1].Build(1, 1, N);
	for (int i = 1; i <= N; i++) S[3].insert(i);
	int q; scanf("%d", &q);
	while (q--) {
		int op, l, r, x; scanf("%d%d%d", &op, &l, &r), r--;
		if (op == 2) printf("%lld\n", seg[0].Query(1, 1, N, l, r) + seg[1].Query(1, 1, N, l, r));
		else {
			scanf("%d", &x); int d = 0;
			if (x < 0) x = -x, d = 1;
			seg[d].Update(1, 1, N, l, r, x), R[d].Update(1, 1, N, l, r, x);
			for (int i = 0; i < 4; i++) {
				if (i >> d & 1) {
					set <int> :: iterator it = S[i].lower_bound(l);
					while (it != S[i].end() && *it <= r) {
						S[i ^ 1 << d].insert(*it);
						if ((i ^ 1 << d) == 0) {
							seg[0].Modify(1, 1, N, *it, R[0].Query(1, 1, N, *it));
							seg[1].Modify(1, 1, N, *it, R[1].Query(1, 1, N, *it)); 
						}
						it = S[i].erase(it);
					}
				}
			}
		}
	}
	return 0;
}