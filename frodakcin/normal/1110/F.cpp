#include <iostream>
#include <cstdio>

#include <vector>
#include <array>

using namespace std;

const int MN = 5e5 + 100;
const int MQ = 5e5 + 100;

template<class T> bool mn(T& a, const T& b) {return b < a ? a = b, true : false;}

using ll = long long;
#define tl(X) static_cast<ll>(X)
const ll INF = 1e18;

int o[MN][2], N, Q;
using i2 = array<int, 2>;
using i3 = array<int, 3>;
using vi2 = vector<i2>;
using vi3 = vector<i3>;
vi2 a[MN];
#define pb push_back


template<int MS> struct ST {
public:
	int s;
	ll v[MS], z[MS];
	ll b[MS];
	void up(int n) {
		v[n] = min(v[n<<1], v[n<<1|1]);
	}
	void addz(int n, ll x) {z[n] += x;}
	void down(int n, int l, int r) {
		if(not z[n]) return;
		if(v[n] != INF) v[n] += z[n];
		if(r-l>1) addz(n<<1, z[n]), addz(n<<1|1, z[n]);
		z[n] = 0;
	}
	void init(int n, int l, int r) {
		if(r-l>1) {
			int m = l + ((r-l)>>1);
			init(n<<1, l, m), init(n<<1|1, m, r);
			up(n);
		} else v[n] = b[l];
	}
	void init(int S) {s = S, init(1, 0, s);}
	void upd(int n, int l, int r, int ql, int qr, ll q) {
		if(ql <= l and r <= qr) {
			addz(n, q);
			down(n, l, r);
		} else {
			down(n, l, r);
			int m = l + ((r-l)>>1);
			if(ql < m) upd(n<<1, l, m, ql, qr, q); else down(n<<1, l, m);
			if(m < qr) upd(n<<1|1, m, r, ql, qr, q); else down(n<<1|1, m, r);
			up(n);
		}
	}
	void upd(int ql, int qr, ll q) {if(ql < qr) upd(1, 0, s, ql, qr, q);}
	ll qry(int n, int l, int r, int ql, int qr) {
		down(n, l, r);
		if(ql <= l and r <= qr) return v[n];
		ll f = INF;
		int m = l + ((r-l)>>1);
		if(ql < m) mn(f, qry(n<<1, l, m, ql, qr));
		if(m < qr) mn(f, qry(n<<1|1, m, r, ql, qr));
		return f;
	}
	ll qry(int ql, int qr) {return qry(1, 0, s, ql, qr);}
};
ST<MN<<2> st;

vi3 q[MN];
ll f[MQ];

void dfs(int n = 1, ll d = 0LL, int * c = new int(0)) {
	o[n][0] = (*c)++;
	for(i2& x : a[n]) dfs(x[1], d + x[0], c);
	if(a[n].empty()) st.b[o[n][0]] = d; else st.b[o[n][0]] = INF;
	o[n][1] = *c;
}
void upd(int w, int v) {
	st.upd(o[w][0], o[w][1], -tl(v));
	st.upd(0, o[w][0], tl(v));
	st.upd(o[w][1], N, tl(v));
}
void dfs2(int n = 1) {
	for(i3& x : q[n]) f[x[2]] = st.qry(x[0], x[1]);
	for(i2& x : a[n]) upd(x[1], x[0]), dfs2(x[1]), upd(x[1], -x[0]);
}

int main() {
	scanf("%d%d", &N, &Q);
	
	for(int i = 2, j, w;i <= N;i++) scanf("%d%d", &j, &w), a[j].pb({w, i});
	for(int i = 0, j, k, l;i < Q;i++) scanf("%d%d%d", &j, &k, &l), q[j].pb({--k, l, i});
	
	dfs();
	st.init(N);
	dfs2();
	
	for(int i = 0;i < Q;i++) printf("%lld\n", f[i]);
	
	return 0;
}