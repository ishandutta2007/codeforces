// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, q, L[N], R[N], c[N << 2];

int tag[N << 2], v[N << 2];

char s[N], t[N];

void inline cover(int p, int k, int l, int r) {
	tag[p] = k, c[p] = k;
	if (k == 1) v[p] = r - l + 1;
	else v[p] = 0;
}

void inline pushup(int p) {
	v[p] = v[p << 1] + v[p << 1 | 1];
}

void inline pushdown(int p, int l, int mid, int r) {
	if (tag[p] != -1) {
		cover(p << 1, tag[p], l, mid);
		cover(p << 1 | 1, tag[p], mid + 1, r);
		tag[p] = -1;
	}
}

void build(int p, int l, int r) {
	tag[p] = -1;
	if (l == r) {
		c[p] = t[r] == '1';
		v[p] = c[p];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

int inline query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return v[p];
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	int res = 0;
	if (x <= mid) res += query(p << 1, l, mid, x, y);
	if (mid < y) res += query(p << 1 | 1, mid + 1, r, x, y);
	return res;
}

void inline change(int p, int l, int r, int x, int y, int k) {
	if (x <= l && r <= y) {
		cover(p, k, l, r); 
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	if (x <= mid) change(p << 1, l, mid, x, y, k);
	if (mid < y) change(p << 1 | 1, mid + 1, r, x, y, k);
	pushup(p);
}

bool ok;

void work(int p, int l, int r) {
	if (l == r) {
		int ch = s[r] - '0';
		if (c[p] != ch) {
			ok = false;
		}
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	work(p << 1, l, mid);
	work(p << 1 | 1, mid + 1, r);
	pushup(p);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s%s", &n, &q, s + 1, t + 1);
		for (int i = 1; i <= q; i++) scanf("%d%d", L + i, R + i);
		build(1, 1, n);
		ok = true;
		for (int i = q; i; i--) {
			int a = query(1, 1, n, L[i], R[i]);
			int b = R[i] - L[i] + 1 - a;
			if (a == b) {
				ok = false;
				break;
			}

			change(1, 1, n, L[i], R[i], a < b ? 0 : 1);
		}
		work(1, 1, n);
		puts(ok ? "YES" : "NO");
	}
	return 0;
}