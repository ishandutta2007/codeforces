#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MN = 1e5 + 100;
using ll = long long;
const ll MV = 1e18 + 1e9;
ll a[MN], k[MN], p[MN], q[MN];
int N, Q;
template<class T> bool mx(T& a, const T& b) {return a<b?a=b,1:0;}
template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}

template<int MS> struct ST
{
	ll v[MS], u[MS], z[MS];
	int s;
	void set(int n, int l, int r, ll q)
	{
		v[n] = q;
		u[n] = q*(r-l);
		z[n] = q;
	}
	void down(int n, int l, int r)
	{
		if(z[n]==MV) return;
		if(r-l>1)
		{
			int m = l + ((r-l)>>1);
			set(n<<1, l, m, z[n]), set(n<<1|1, m, r, z[n]);
		}
		z[n] = MV;
	}
	void up(int n)
	{
		//assert(v[n<<1] <= v[n<<1|1]);
		v[n] = v[n<<1|1];
		u[n] = u[n<<1] + u[n<<1|1];
	}
	void init(int n, int l, int r)
	{
		z[n] = MV;
		if(r-l>1)
		{
			int m = l + ((r-l)>>1);
			init(n<<1, l, m), init(n<<1|1, m, r);
			up(n);
		}
		else
			v[n] = u[n] = a[l]-p[l];
	}
	void init(int s) {init(1, 0, this->s = s);}
	void upd(int n, int l, int r, int ql, int qr, ll q)
	{
		if(ql <= l&&r <= qr)
			return set(n, l, r, q);
		down(n, l, r);
		int m = l + ((r-l)>>1);
		if(ql < m) upd(n<<1, l, m, ql, qr, q);
		if(m < qr) upd(n<<1|1, m, r, ql, qr, q);
		up(n);
	}
	void upd(int ql, int qr, ll q) {return upd(1, 0, s, ql, qr, q);}
	int find(int n, int l, int r, int ql, ll q)
	{
		if(v[n] < q) return r;
		if(r-l==1) return l;
		down(n, l, r);
		int m = l + ((r-l)>>1), t;
		if(ql < m)
		{
			t = find(n<<1, l, m, ql, q);
			if(t < m) return t;
		}
		return find(n<<1|1, m, r, ql, q);
	}
	int find(int ql, ll q) {return find(1, 0, s, ql, q);}
	ll qry(int n, int l, int r, int ql, int qr)
	{
		if(ql<=l&&r<=qr) return u[n];
		down(n, l, r);
		int m = l + ((r-l)>>1);
		ll f = 0LL;
		if(ql<m) f += qry(n<<1, l, m, ql, qr);
		if(m<qr) f += qry(n<<1|1, m, r, ql, qr);
		return f;
	}
	ll qry(int ql, int qr) {return qry(1, 0, s, ql, qr);}
};
ST<MN*3> t;
void add(int i, int x)
{
	if(!x) return;
	ll c = t.qry(i, i+1) + x;
	int k = t.find(i, c);
	assert(i<k);
	t.upd(i, k, c);
}
void sum(int l, int r)
{
	printf("%lld\n", t.qry(l, r)+(q[r]-q[l]));
}
void AQ(void)
{
	char o;
	int a, b;
	scanf(" %c%d%d", &o, &a, &b), a--;
	if(o=='+')
		add(a, b);
	else
		sum(a, b);
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;i++) scanf("%lld", a + i);
	for(int i = 0;i < N-1;i++) scanf("%lld", k + i), p[i+1] = p[i]+k[i], q[i+2] = q[i+1]+p[i+1];
	t.init(N);
	scanf("%d", &Q);
	for(;Q--;)
		AQ();
	return 0;
}