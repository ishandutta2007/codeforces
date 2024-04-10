#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
ll read() {
	ll ans = 0;
	int c;
	for (c = getchar(); !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) ans = ans * 10 + c - '0';
	return ans;
}
void out(ll x) {
	if (x >= 10) out(x / 10);
	putchar(x % 10 + '0');
}
int T;
int n, m;
ll a[1010], b[1010];
struct segtree {
	ll t[2100];
	void up(int x) {
		t[x] = __gcd(t[x << 1], t[x << 1 | 1]);
	}
	void build(int x, int l, int r, ll *a, ll v) {
		if (l == r) t[x] = v / __gcd(v, a[l]);
		else {
			int mid = l + r >> 1;
			build(x << 1, l, mid, a, v);
			build(x << 1 | 1, mid + 1, r, a, v);
			up(x);
		}
	}
	void remove(int x, int l, int r, int k) {
		if (l == r) t[x] = 0;
		else {
			int mid = l + r >> 1;
			if (k <= mid) remove(x << 1, l, mid, k);
			else remove(x << 1 | 1, mid + 1, r, k);
			up(x);
		}
	}
} ta[1010], tb[1010];
int taga[1010], tagb[1010];
void rmain() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) b[i] = read();
	for (int i = 1; i <= n; i++) {
		ta[i].build(1, 1, m, b, a[i]);
	}
	for (int i = 1; i <= m; i++) {
		tb[i].build(1, 1, n, a, b[i]);
	}
	memset(taga, 0, sizeof taga);
	memset(tagb, 0, sizeof tagb);
	int restn = n, restm = m;
	while (1) {
		if (restn == 0 || restm == 0) return puts("NO"), void();
		int tag = 0;
		for (int i = 1; i <= n; i++) if (taga[i] == 0 && ta[i].t[1] != 1) {
			tag = 1;
			taga[i] = 1;
			restn--;
			for (int j = 1; j <= m; j++) if (tagb[j] == 0) tb[j].remove(1, 1, n, i);
		}
		for (int i = 1; i <= m; i++) if (tagb[i] == 0 && tb[i].t[1] != 1) {
			tag = 1;
			tagb[i] = 1;
			restm--;
			for (int j = 1; j <= n; j++) if (taga[j] == 0) ta[j].remove(1, 1, m, i);
		}
		if (tag == 0) break;
	}
	printf("YES\n%d %d\n", restn, restm);
	for (int i = 1; i <= n; i++) if (!taga[i]) out(a[i]), putchar(' ');
	puts("");
	for (int i = 1; i <= m; i++) if (!tagb[i]) out(b[i]), putchar(' ');
	puts("");
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}