#include <bits/stdc++.h>

inline int readint() {
	int a = 0; char c = getchar(), po = 1;
	while(isspace(c)) c = getchar();
	if(c == '-') c = getchar(), po = 0;
	while(isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return po ? a : -a;
}

const int maxN = 100000 + 233;
const int maxM = 100000 + 233;
int n, m;
int a[maxN], b[maxN];

inline bool chmax(int &a, const int &b) { return a < b ? a = b, true : false; }

#define lson (o << 1)
#define rson (o << 1 | 1)
int t[maxN << 2], d[maxN << 2];
int ql, qr, ba, bb, now = 0;
void cover(int o, int L, int R) {
	if(ql <= L && R <= qr) {
		t[o] = now;
		d[o] = L - bb + ba;
	} else {
		int M = (L + R) >> 1;
		if(ql <= M) cover(lson, L, M);
		if(qr > M) cover(rson, M + 1, R);
	}
}
int pos, maxt, id;
void query(int o, int L, int R) {
	if(L == R) {
		if(chmax(maxt, t[o])) id = d[o];
	} else {
		int M = (L + R) >> 1;
		if(chmax(maxt, t[o])) id = d[o] + pos - L;
		if(pos <= M) query(lson, L, M);
		else query(rson, M + 1, R);
	}
}
#undef lson
#undef rson

int main() {
	n = readint(); m = readint();
	for(int i = 1; i <= n; ++i) a[i] = readint();
	for(int i = 1; i <= n; ++i) b[i] = readint();
	memset(t, 0, sizeof(t));
	for(int kase = 1; kase <= m; ++kase) {
		++now;
		int op = readint();
		if(op == 1) {
			ba = readint(); bb = readint();
			int len = readint();
			ql = bb; qr = bb + len - 1;
			cover(1, 1, n);
		} else if(op == 2) {
			maxt = 0; pos = readint();
			query(1, 1, n);
			if(maxt == 0) printf("%d\n", b[pos]);
			else printf("%d\n", a[id]);
		} else {
			assert(false);
		}
	}
	return 0;
}