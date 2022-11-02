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

const int maxN = 100000 + 5;
int n, m, a[maxN];
LL C[maxN];
void add(int p, int x) {
	for(; p <= n; p += p & -p) C[p] += x;
}
LL sum(int p) {
	LL r = 0;
	for(; p > 0; p -= p & -p) r += C[p];
	return r;
}

void segadd(int l, int r, int t) {
	if(!(l <= r)) return;
	add(l, t);
	add(r + 1, -t);
}
LL query(int p) {
	return sum(p);
}
int l[maxN], r[maxN];
//int tl[maxN], tr[maxN];

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m;
//	for(int i = 1; i <= m; ++i) a[i] = rand() % 2 + 977;
	for(int i = 1; i <= m; ++i) cin >> a[i];

	memset(C, 0, sizeof(C));
	for(int i = 1; i <= n; ++i) segadd(i, i, i);
	for(int i = 1; i <= m; ++i) {
		int L = 1, R = n + 1, val = a[i] - i, sl, sr;
		
		while(L < R) {
			int M = (L + R) >> 1;
			if(query(M) < val) L = M + 1;
			else R = M;
		}
		sl = L;
		L = 1, R = n + 1;
		while(L < R) {
			int M = (L + R) >> 1;
			if(query(M) <= val) L = M + 1;
			else R = M;
		}
		sr = L;
		segadd(sl, sr - 1, -1);
	}
	for(int i = 1; i <= n; ++i) r[i] = query(i) + m + 1, chmin(r[i], n);
	memset(C, 0, sizeof(C));
	for(int i = 1; i <= n; ++i) segadd(i, i, i);
	for(int i = 1; i <= m; ++i) {
		int L = 1, R = n + 1, val = a[i] + i, sl, sr;
		
		while(L < R) {
			int M = (L + R) >> 1;
			if(query(M) < val) L = M + 1;
			else R = M;
		}
		sl = L;
		L = 1, R = n + 1;
		while(L < R) {
			int M = (L + R) >> 1;
			if(query(M) <= val) L = M + 1;
			else R = M;
		}
		sr = L;
//		eprintf("round %d: modify [%d, %d)\n", i, sl, sr);
		segadd(sl, sr - 1, +1);
	}
	for(int i = 1; i <= n; ++i) l[i] = query(i) - m - 1, chmax(l[i], 1);
//	for(int i = 1; i <= n; ++i) tl[i] = tr[i] = i;
//	for(int i = 1; i <= m; ++i) {
//		for(int j = 1; j <= n; ++j) if(tl[j] - 1 == a[i]) ++tl[j];
//		for(int j = 1; j <= n; ++j) if(tr[j] + 1 == a[i]) --tr[j];
//		for(int j = 1; j <= n; ++j) tl[j]--, tr[j]++;
//	}
//	for(int i = 1; i <= n; ++i) tl[i]--, chmax(tl[i], 1), tr[i]++, chmin(tr[i], n);
//	for(int i = 1; i <= n; ++i) assert(l[i] == tl[i]), assert(r[i] == tr[i]); 
//	displaya(l, 1, n);
//	displaya(r, 1, n);
	LL ans = 0;
	for(int i = 1; i <= n; ++i) ans += r[i] - l[i] + 1;
	if(n == 1) ans = 0;
	cout << ans << endl;
	return 0;
}