#include <cstdio>
#include <algorithm>

using namespace std;

const int MN = 3e5 + 100;

template<int MS> struct segtree
{
public:
	int v[MS], z[MS];
	void upd(int n, int x)
	{
		v[n] += x, z[n] += x;
	}
	void down(int n, int l, int r)
	{
		if(!z[n]) return;
		if(r-l>1)
			upd(n<<1, z[n]), upd(n<<1|1, z[n]);
		z[n] = 0;
	}
	void upd(int n, int l, int r, int qr, int x)
	{
		if(n == 1) qr++;
		if(r <= qr) upd(n, x);
		else
		{
			int m = l + (r-l>>1);
			down(n, l, r);
			upd(n<<1, l, m, qr, x);
			if(m < qr) upd(n<<1|1, m, r, qr, x);
			v[n] = min(v[n<<1|1], v[n<<1]);
		}
	}
	int qry(int n, int l, int r)
	{
		//printf("%d %d %d %d %d\n", n, l, r, v[n], z[n]);
		if(v[n] >= 0) return -1;
		if(r-l>1)
		{
			int m = l + (r-l>>1), t = -1;
			down(n, l, r);
			t = qry(n<<1|1, m, r);
			if(!~t) t = qry(n<<1, l, m);
			return t;
		}
		else
			return l;
	}
};
int a[MN], b[MN], N, M, Q;
int v[MN<<3], V;
segtree<MN*3*4> st;
struct QR
{
	int t, i, x;
	void in(void)
	{
		scanf("%d%d%d", &t, &i, &x), --i;
		v[V++] = x;
	}
	void fix(void) {x = lower_bound(v, v + V, x) - v;}
	void wk(void)
	{
		if(t==1)
			st.upd(1, 0, V, a[i], 1), st.upd(1, 0, V, a[i]=x, -1);
		if(t==2)
			st.upd(1, 0, V, b[i], -1), st.upd(1, 0, V, b[i]=x, 1);
	}
};
QR q[MN];
int get(int n) {return ~n?v[n]:-1;}

int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 0;i < N;i++) scanf("%d", a + i), v[V++] = a[i];
	for(int i = 0;i < M;i++) scanf("%d", b + i), v[V++] = b[i];
	scanf("%d", &Q);
	for(int i = 0;i < Q;i++) q[i].in();
	sort(v, v + V);
	V = unique(v, v + V) - v;
	for(int i = 0;i < N;i++) a[i] = lower_bound(v, v + V, a[i]) - v, st.upd(1, 0, V, a[i], -1);
	for(int i = 0;i < M;i++) b[i] = lower_bound(v, v + V, b[i]) - v, st.upd(1, 0, V, b[i], 1);
	for(int i = 0;i < Q;i++) q[i].fix();
	for(int i = 0;i < Q;i++)
	{
		q[i].wk();
		printf("%d\n", get(st.qry(1, 0, V)));
	}
	return 0;
}