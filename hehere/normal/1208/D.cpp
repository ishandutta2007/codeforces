#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

const int maxN = 200000 + 5;
int n;
LL s[maxN];
LL mn[maxN * 4], tg[maxN * 4];

#define lson (o << 1)
#define rson (lson | 1)
void maintain(int o) {
	mn[o] = min(mn[lson], mn[rson]);
}

void pushdown(int o) {
	if(tg[o]) {
		mn[lson] += tg[o]; tg[lson] += tg[o];
		mn[rson] += tg[o]; tg[rson] += tg[o];
		tg[o] = 0;
	}
}

void build(int o, int L, int R) {
	if(L == R) {
		mn[o] = s[L];
	} else {
		int M = (L + R) >> 1;
		build(lson, L, M);
		build(rson, M + 1, R);
		maintain(o);
	}
}

int seek(int o, int L, int R) {
	eprintf("min [%d, %d] = %lld\n", L, R, mn[o]);
	if(L == R) {
		return L;
	} else {
		int M = (L + R) >> 1;
		pushdown(o);
		if(mn[rson] == 0) return seek(rson, M + 1, R);
		else return seek(lson, L, M);
	}
}

int ql, qr;
LL qv;
void modify(int o, int L, int R) {
	if(ql <= L && R <= qr) {
		tg[o] += qv; mn[o] += qv;
	} else {
		int M = (L + R) >> 1;
		pushdown(o);
		if(ql <= M) modify(lson, L, M);
		if(qr > M) modify(rson, M + 1, R);
		maintain(o);
	}
}

int p[maxN];
int main() {
#ifndef LOCAL 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> s[i];
	build(1, 1, n);
	for(int i = 1; i <= n; ++i) {
		int u = seek(1, 1, n);
		display(u);
		p[u] = i;
		ql = u; qr = u; qv = (LL)n * (n - 1) / 2 + 5;
		modify(1, 1, n);
		ql = u + 1; qr = n; qv = -i;
		if(ql <= qr) modify(1, 1, n);
	}
	for(int i = 1; i <= n; ++i) cout << p[i] << ' ';
	cout << endl;
	return 0;
}