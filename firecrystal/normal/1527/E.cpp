// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 35005, S = 105;

int n, k, f[N], g[N], pre[N], cnt[N];

int tag[N << 2], v[N << 2];

void inline add(int p, int k) {
	tag[p] += k;
	v[p] += k;
}

#define ls (p << 1)
#define rs (p << 1 | 1)
void inline pushdown(int p) {
	if (tag[p]) {
		add(ls, tag[p]);
		add(rs, tag[p]);
		tag[p] = 0;
	}
}

void inline pushup(int p) {
	v[p] = min(v[ls], v[rs]);
}

void inline build(int p, int l, int r) {
	tag[p] = 0;
	if (l == r) {
		v[p] = g[r];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

void change(int p, int l, int r, int x, int y, int k) {
	if (x <= l && r <= y) {
		add(p, k);
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, y, k);
	if (mid < y) change(rs, mid + 1, r, x, y, k);
	pushup(p);
}

int inline query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return v[p];
	pushdown(p);
	int mid = (l + r) >> 1;
	int res = 2e9;
	if (x <= mid) res = min(res, query(ls, l, mid, x, y));
	if (mid < y) res = min(res, query(rs, mid + 1, r, x, y));
	return res;
}

int main() {
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	read(n); read(k);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		pre[i] = cnt[x];
		cnt[x] = i;
	}
	for (int j = 1; j <= k; j++) {
		memcpy(g, f, sizeof g);
		memset(f, 0x3f, sizeof f);
		build(1, 0, n);
		for (int i = 1; i <= n; i++) {
			if (pre[i]) change(1, 0, n, 0, pre[i] - 1, i - pre[i]);
			f[i] = query(1, 0, n, 0, i);
		}
	}
	printf("%d\n", f[n]);
	return 0;
}