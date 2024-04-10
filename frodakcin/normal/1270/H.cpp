#include <cstdio>

const int MN = 5e5 + 100;
const int MA = 1 << 20;

struct ST
{
public:
	int c[MA*2], v[MA*2], z[MA*2];
	void upd(int n, int d)
	{
		v[n] += d;
		z[n] += d;
	}
	void up(int n)
	{
		c[n] = c[n<<1|1], v[n] = v[n<<1|1];
		if(!c[n] || v[n<<1]<v[n])
			c[n] = c[n<<1], v[n] = v[n<<1];
		else if(v[n] == v[n<<1])
			c[n] += c[n<<1];
	}
	void down(int n)
	{
		if(z[n])
		{
			upd(n<<1, z[n]);
			upd(n<<1|1, z[n]);
			z[n] = 0;
		}
	}
	void upd(int n, int l, int r, int ql, int qr, int d)
	{
		if(ql <= l && r <= qr)
			upd(n, d);
		else
		{
			int m = l + (r-l)/2;
			down(n);
			if(ql < m) upd(n<<1, l, m, ql, qr, d);
			if(m < qr) upd(n<<1|1, m, r, ql, qr, d);
			up(n);
		}
	}
	void tog(int n, int l, int r, int q)
	{
		if(r-l>1)
		{
			int m = l+(r-l)/2;
			down(n);
			if(q < m) tog(n<<1, l, m, q);
			else tog(n<<1|1, m, r, q);
			up(n);
		}
		else
			c[n] = !c[n];
	}
	int qry(int n)
	{
		return v[n]==1?c[n]:0;
	}
	int qry(int n, int l, int r, int ql, int qr)
	{
		if(ql <= l && r <= qr)
			return qry(n);
		else
		{
			int m = l + (r-l)/2, f = 0;
			down(n);
			if(ql < m) f += qry(n<<1, l, m, ql, qr);
			if(m < qr) f += qry(n<<1|1, m, r, ql, qr);
			return f;
		}
	}
};
ST seg;

int N, Q;
int a[MN];
int main(void)
{
	scanf("%d%d", &N, &Q);
	for(int i = 0;i < N;++i)
		scanf("%d", a+i), seg.tog(1, 0, MA, a[i]);
	for(int i = 0;i+1 < N;++i)
		if(a[i]>a[i+1])
			seg.upd(1, 0, MA, a[i+1], a[i], 1);

	/*
	if(a[0] < a[N-1]) printf("1\n");
	else printf("%d\n", 1+seg.qry(1, 0, MA, a[N-1], a[0]));
	*/

	for(int i = 0, p, x;i < Q;++i)
	{
		scanf("%d%d", &p, &x);
		--p;
		if(p)
		{
			if(a[p-1] > a[p]) seg.upd(1, 0, MA, a[p], a[p-1], -1);
			if(a[p-1] > x) seg.upd(1, 0, MA, x, a[p-1], 1);
		}
		if(p+1<N)
		{
			if(a[p] > a[p+1]) seg.upd(1, 0, MA, a[p+1], a[p], -1);
			if(x > a[p+1]) seg.upd(1, 0, MA, a[p+1], x, 1);
		}
		seg.tog(1, 0, MA, a[p]);
		seg.tog(1, 0, MA, a[p]=x);
		if(a[0] < a[N-1]) printf("1\n");
		else printf("%d\n", 1+seg.qry(1, 0, MA, a[N-1], a[0]));
	}
	return 0;
}