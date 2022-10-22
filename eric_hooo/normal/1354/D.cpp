#include <bits/stdc++.h>
using namespace std;

struct Segment_tree {
	int T[4000010];
	Segment_tree() {memset(T, 0, sizeof(T));}
	void Update(int now, int l, int r, int pos) {
		if (l == r) {
			T[now]++;
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos);
		else Update(now << 1 | 1, mid + 1, r, pos);
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	void Erase(int now, int l, int r, int k) {
		if (l == r) {
			T[now]--;
			return ;
		}
		int mid = l + r >> 1;
		if (k <= T[now << 1]) Erase(now << 1, l, mid, k);
		else Erase(now << 1 | 1, mid + 1, r, k - T[now << 1]);
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	int Query(int now, int l, int r) {
		if (!T[now]) return 0;
		if (l == r) return l;
		int mid = l + r >> 1;
		if (T[now << 1]) return Query(now << 1, l, mid);
		return Query(now << 1 | 1, mid + 1, r);
	}
}seg;

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		seg.Update(1, 1, n, x);
	}
	for (int i = 1; i <= m; i++) {
		int x; scanf("%d", &x);
		if (x >= 1) seg.Update(1, 1, n, x);
		else seg.Erase(1, 1, n, -x);
	}
	printf("%d\n", seg.Query(1, 1, n));
	return 0;
}