// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e6 + 5;

int n, m, l, g[N], q[N];
 
LL c[N];

void inline add(int l, int r, LL k) {
	c[l] += k;
	c[r + 1] -= k;
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &l);
		int s = 0;
		for (int j = 1; j <= l; j++) read(g[j]), chkMax(s, g[j]);
		int hh = 1, tt = 0;
		for (int j = 1, k = 1; j <= l; j++) {
			int R = min(l, j), L = max(1, l - (m - j));
			while (k <= R) {
				while (hh <= tt && g[q[tt]] <= g[k]) tt--;
				q[++tt] = k;
				++k;
			}
			while (hh <= tt && q[hh] < L) hh++;
			int v = g[q[hh]];
			if (j - 1 >= l || (m - j) >= l) chkMax(v, 0);
			//cout << v << " !!" << j << endl;
			add(j, j, v);
		}
		hh = 1, tt = 0;
		for (int j = max(m - l + 1, l + 1), k = 1; j <= m; j++) {
			int R = min(l, j), L = max(1, l - (m - j));
			while (k <= R) {
				while (hh <= tt && g[q[tt]] <= g[k]) tt--;
				q[++tt] = k;
				++k;
			}
			while (hh <= tt && q[hh] < L) hh++;
			int v = g[q[hh]];
			if (j - 1 >= l || (m - j) >= l) chkMax(v, 0);
			//cout << v << " 222 " << j << endl;
			add(j, j, v);
		}
		if (l + 1 <= m - l) {
			add(l + 1, m - l, s);
		}
	}
	for (int i = 1; i <= m; i++) c[i] += c[i - 1];
	for (int i = 1; i <= m; i++) printf("%lld ", c[i]);
	return 0;
}