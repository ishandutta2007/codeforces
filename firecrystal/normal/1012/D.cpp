#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


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

const int N = 5e5 + 5, M = 1e6;

typedef pair<int, int> PII;

int n, m, f[N << 1], sz[N << 1], len, c[N << 1];

PII ans[N];

char a[N], b[N];

int q1[N << 2], q2[N << 2], hh = 1 + M, tt = M, h = 1 + M, t = M;

int A[N << 2], B[N << 2], t1, t2;

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x, y);
	f[x] = y, sz[y] += sz[x];
}

int sz1, sz2;

int inline calc1(int t) {
	return abs((sz1 + t - 2 + (sz1 == 0)) - (sz2 - t + ((sz2 - t) == 0))); 
}

int inline calc2(int t) {
	return abs((sz2 + t - 2 + (sz2 == 0)) - (sz1 - t + ((sz1 - t) == 0))); 
}

int inline calc3(int t) {
	return abs((sz1 + t - 1 + (sz1 == 0)) - (sz2 - t)); 
}

int inline calc4(int t) {
	return abs((sz2 + t - 1 + (sz2 == 0)) - (sz1 - t)); 
}

int main() {
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	for (int i = 1; i <= n + m; i++) {
		f[i] = i, sz[i] = 1;
		if (i <= n) {
			if (a[i] == 'b') c[i] = 1;
		} else {
			if (b[i - n] == 'b') c[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j < n && a[j + 1] == a[i]) j++, merge(j, i);
		q1[++tt] = i;
		i = j;
	}
	for (int i = 1; i <= m; i++) {
		int j = i;
		while (j < m && b[j + 1] == b[i]) j++, merge(n + j, n + i);
		q2[++t] = i + n;
		i = j;
	}
	
	
	int pok = 0;
	
	
	while (1) {
		sz1 = tt - hh + 1, sz2 = t - h + 1;
		if (sz1 == 1 && sz2 == 1) break;
		int cA = c[q1[hh]], cB = c[q2[h]];
		int u, v, o;
		if (cA == cB) {
			if (sz1 == 1) {
				u = 0, v = 1, o = calc3(v);
				while (v + 2 < sz2 && calc3(v + 2) < o)
					o = calc3(v + 2), v += 2;
			} else if (sz2 == 1) {
				u = 1, v = 0, o = calc4(u);
				while (u + 2 < sz1 && calc4(u + 2) < o)
					o = calc4(u + 2), u += 2;
			}
			else if (sz1 < sz2) {
				u = 1, v = 0, o = calc1(v);
				while (v + 2 < sz2 && calc1(v + 2) < o)
					o = calc1(v + 2), v += 2;
			} else {
				u = 0, v = 1, o = calc2(u);
				while (u + 2 < sz1 && calc2(u + 2) < o)
					o = calc2(u + 2), u += 2;
			}
		} else {
			if (sz1 < sz2) {
				u = 1, v = 1, o = calc1(v);
				while (v + 2 < sz2 && calc1(v + 2) < o)
					o = calc1(v + 2), v += 2;
			} else {
				u = 1, v = 1, o = calc2(u);
				while (u + 2 < sz1 && calc2(u + 2) < o)
					o = calc2(u + 2), u += 2;
			}
		}
	
		++len;
		for (int i = hh; i < hh + u; i++) ans[len].fi += sz[find(q1[i])];
		for (int i = h; i < h + v; i++) ans[len].se += sz[find(q2[i])];
		
//		puts("1___");
//		for (int i = hh; i <= tt; i++) cout << c[q1[i]] << " " << sz[find(q1[i])] << endl;
//		puts("\n2___-");
//		for (int i = h; i <= t; i++) cout << c[q2[i]] << " " << sz[find(q2[i])] << endl;
//		puts("");
//		
//		cout << hh << " " << tt << " " << h << " " << t << " !!!!" << u << " " << v << " " << ans[len].fi << " " << ans[len].se << endl;
//		
		t1 = t2 = 0;
		for (int i = hh; i < hh + u; i++) A[++t1] = q1[i];
		for (int i = h; i < h + v; i++) B[++t2] = q2[i];
		hh += u, h += v;
		if (t2 && hh <= tt && c[q1[hh]] == c[B[t2]]) {
			merge(q1[hh], B[t2--]);
		}
		if (t1 && h <= t && c[q2[h]] == c[A[t1]]) {
			merge(q2[h], A[t1--]);
		}
		for (int i = t2; i; i--) q1[--hh] = B[i];
		for (int i = t1; i; i--) q2[--h] = A[i];
		
//		++pok;
//		cout << pok <<"???\n";
//		if (pok == 20) return 0;
	}
	printf("%d\n", len);
	for (int i = 1; i <= len; i++) printf("%d %d\n", ans[i].fi, ans[i].se);
}