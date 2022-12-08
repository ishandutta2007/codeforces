#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

using ll = long long;
const int MN = 4e5+10;
const int MQ = 2e5+10;
const int MOD = 1e9+7;
int p[100], P, N, a[MN], Q;
ll f[MN], inv[100];
char s[999];

ll pow(ll b, int p)
{
	ll r=1;
	for(;p;p>>=1,b=b*b%MOD)
		if(p&1)
			r=r*b%MOD;
	return r;
}
struct dat
{
public:
	ll s, m, z, y;
	void operator += (dat o) {s=s*o.s%MOD, m|=o.m;assert(z==1&&y==0);}
	void mrg(const dat& a, const dat& b) {s = a.s*b.s%MOD, m=a.m|b.m;assert(z==1&&y==0);}
	void fil(int x)
	{
		for(int i=0;i<P;++i)
			if(x%p[i]==0)
				m|=1LL<<i;
		s=x;
	}
	void mul(dat v, int x)
	{
		z=z*v.z%MOD;
		y|=v.y;
		s=s*pow(v.z, x)%MOD;
		m|=v.y;
	}
} st[1 << 20], cur;

void build(int n, int l, int r)
{
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		build(n<<1, l, m);
		build(n<<1|1, m, r);
		st[n].z=1;
		st[n].mrg(st[n<<1], st[n<<1|1]);
	}
	else
		st[n].fil(a[l]);
}
void down(int n, int l, int r)
{
	int m=l+(r-l)/2;
	st[n<<1].mul(st[n], m-l);
	st[n<<1|1].mul(st[n], r-m);
	st[n].z=1, st[n].y=0;
}
dat qry(int n, int l, int r, int ql, int qr)
{
	if(ql <= l&&r<=qr)
		return st[n];
	else
	{
		down(n, l, r);
		int m=l+(r-l)/2;
		dat f{1ll, 0ll, 1ll, 0ll};
		if(ql < m) f+=qry(n<<1, l, m, ql, qr);
		if(m < qr) f+=qry(n<<1|1, m, r, ql, qr);
		return f;
	}
}
void upd(int n, int l, int r, int ql, int qr)
{
	if(ql <= l&&r <= qr)
		st[n].mul(cur, r-l);
	else
	{
		down(n, l, r);
		int m=l+(r-l)/2;
		if(ql < m) upd(n<<1, l, m, ql, qr);
		if(m < qr) upd(n<<1|1, m, r, ql, qr);
		st[n].mrg(st[n<<1], st[n<<1|1]);
	}
	//printf("%d: [%d, %d): %lld\n", n, l, r, st[n].s);
}
int main(void)
{
	for(int i=2;i<=300;++i)
	{
		bool g=1;
		for(int j=2;j<i;++j)
			if(i%j==0)
				g=0;
		if(g) inv[P] = pow(i, MOD-2), p[P++] = i;
	}
	scanf("%d%d", &N, &Q);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	build(1, 0, N);
	for(int i=0,l,r,x;i<Q;++i)
	{
		scanf(" %s", s);
		scanf("%d%d", &l, &r);
		if(s[0]=='T')
		{
			dat x=qry(1, 0, N, --l, r);
			for(int j=0;j<P;++j)
				if(x.m>>j&1)
					x.s=x.s*(p[j]-1)%MOD*inv[j]%MOD;
			printf("%lld\n", x.s);
		}
		else
		{
			scanf("%lld", &cur.z);
			cur.y=0;
			for(int j=0;j<P;++j)
				if(0==cur.z%p[j])
					cur.y|=1LL<<j;
			upd(1, 0, N, --l, r);
		}
	}
	return 0;
}