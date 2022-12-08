#include <iostream>
#include <cstdio>

#include <array>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 1e5 + 100;
const int MM = 1e5 + 100;
const int MX = 1<<20;
const int MB = 21;

int N, M, X, a[MN];

using i2 = array<int, 2>;

struct ND {
public:
	i2 l[MB], r[MB];
	int s, L, R;
	ll c;
	ND() {
		for(int i = 0;i < MB;i++) l[i] = r[i] = {0, 0};
		L = R = 1;
		c = 0LL;
		s = 0;
	}
	ND(int x) {
		L = R = 1;
		c = x >= X;
		s = 1;
		l[0] = r[0] = {0, x};
		l[1] = r[1] = {1, 0};
		for(int i = 2;i < MB;i++) l[i] = r[i] = {0, 0};
	}
	ND operator + (const ND& o) {
		ND f;
		f.s = s + o.s, f.c = c + o.c;
		
		int i, j;
		for(i = 0;i < L;i++) f.l[i] = l[i];
		for(int j = 0;j < o.L;j++)
			if((o.l[j][1]&f.l[i-1][1]) != o.l[j][1]) {
				f.l[i][1] = f.l[i-1][1]|o.l[j][1];
				f.l[i][0] = s + o.l[j][0];
				i++;
			}
		f.l[f.L = i] = {f.s, 0};
		
		for(i = 0;i < o.R;i++) f.r[i] = o.r[i];
		for(int j = 0;j < R;j++)
			if((r[j][1]&f.r[i-1][1]) != r[j][1]) {
				f.r[i][1] = f.r[i-1][1]|r[j][1];
				f.r[i][0] = o.s + r[j][0];
				i++;
			}
		f.r[f.R = i] = {f.s, 0};
		
		for(i = R-1, j = 0;i >= 0;i--) {
			for(;j < o.L;j++)
				if((r[i][1]|o.l[j][1]) >= X) break;
			if(j == o.L) break;
			f.c += tl(r[i+1][0]-r[i][0]) * (o.s-o.l[j][0]);
		}
		
		return f;
	}
};
template<int MS = MN << 2> struct ST {
public:
	int s;
	ND v[MS];
	void up(int n) {
		v[n] = v[n<<1] + v[n<<1|1];
	}
	void init(int n, int l, int r) {
		if(r-l>1) {
			int m = l + ((r-l)>>1);
			init(n<<1, l, m), init(n<<1|1, m, r);
			up(n);
		} else
			v[n] = ND(a[l]);
	}
	void init(int S) {
		s = S;
		init(1, 0, s);
	}
	void upd(int n, int l, int r, int q, int x) {
		if(r-l>1) {
			int m = l + ((r-l)>>1);
			if(q < m) upd(n<<1, l, m, q, x);
			else upd(n<<1|1, m, r, q, x);
			up(n);
		} else
			v[n] = ND(x);
	}
	void upd(int q, int x) {upd(1, 0, s, q, x);}
	ND qry(int n, int l, int r, int ql, int qr) {
		if(ql <= l and r <= qr) return v[n];
		int m = l + ((r-l)>>1);
		if(ql < m) {
			if(m < qr) return qry(n<<1, l, m, ql, qr) + qry(n<<1|1, m, r, ql, qr);
			else return qry(n<<1, l, m, ql, qr);
		} else return qry(n<<1|1, m, r, ql, qr);
	}
	ll qry(int ql, int qr) {return qry(1, 0, s, ql, qr).c;}
};
ST<> st;

int main() {
	scanf("%d%d%d", &N, &M, &X);
	for(int i = 0;i < N;i++) scanf("%d", a + i);
	
	st.init(N);
	
	for(int i = 0, a, b, c;i < M;i++) {
		scanf("%d%d%d", &a, &b, &c);
		if(a == 1) st.upd(--b, c);
		else printf("%lld\n", st.qry(--b, c));
	}
	
	return 0;
}