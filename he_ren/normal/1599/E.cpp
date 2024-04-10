#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e4 + 5;
const int mod = 1e9 + 7;
const ll linf = 0x3f3f3f3f3f3f3f3f;

template<typename T>
inline void chk_max(T &a,const T &b){ if(a<b) a=b;}
template<typename T>
inline void chk_min(T &a,const T &b){ if(a>b) a=b;}

inline int mod_add(int a,int b){ return a+b>=mod? a+b-mod: a+b;}
inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

struct Vector
{
	int a[2];
	Vector(void){ a[0] = a[1] = 0;}
	Vector(int a0,int a1){ a[0] = a0; a[1] = a1;}
	inline int& operator [] (int x){ return a[x];}
	inline int operator [] (int x) const { return a[x];}
};

inline Vector operator + (const Vector &p,const Vector &q)
{
	return Vector(mod_add(p[0], q[0]), mod_add(p[1], q[1]));
}
inline Vector& operator += (Vector &p,const Vector &q)
{
	return p = p + q;
}

struct Matrix
{
	int a[2][2];
	Matrix(void){ a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;}
	Matrix(int a00,int a01,int a10,int a11)
	{
		a[0][0] = a00; a[0][1] = a01;
		a[1][0] = a10; a[1][1] = a11;
	}
	inline int* operator [] (int x){ return a[x];}
	inline const int* operator [] (int x) const { return a[x];}
};

inline Vector operator * (const Matrix &a,const Vector &p)
{
	return Vector(
		(1ll * a[0][0] * p[0] + 1ll * a[0][1] * p[1]) %mod,
		(1ll * a[1][0] * p[0] + 1ll * a[1][1] * p[1]) %mod
	);
}
inline Matrix operator * (const Matrix &a,const Matrix &b)
{
	return Matrix(
		(1ll * a[0][0] * b[0][0] + 1ll * a[0][1] * b[1][0]) %mod,
		(1ll * a[0][0] * b[0][1] + 1ll * a[0][1] * b[1][1]) %mod,
		(1ll * a[1][0] * b[0][0] + 1ll * a[1][1] * b[1][0]) %mod,
		(1ll * a[1][0] * b[0][1] + 1ll * a[1][1] * b[1][1]) %mod
	);
}

inline Vector& operator &= (Vector &p,const Matrix &a)// left mul
{
	return p = a * p;
}

const Matrix Munit(1,0,0,1);

const int LB = 50;
Matrix Fmat1[LB], Fmat2[LB];

inline Matrix fibpw(int type,ll b)
{
	Matrix res = Munit;
	for(int i=0; b>>i; ++i)
		if((b>>i)&1) res = res * (type == 1? Fmat1[i]: Fmat2[i]);
	return res;
}
inline Matrix getfib(ll k)
{
	return k > 0? fibpw(1, k): fibpw(2, -k);
}

struct Data
{
	ll mx, mn, secmx, secmn;
	Data(void){}
	Data(ll _mx,ll _mn,ll _secmx,ll _secmn): mx(_mx), mn(_mn), secmx(_secmx), secmn(_secmn) {}
	Data(ll k): mx(k), mn(k), secmx(-linf), secmn(linf) {}
	inline int gettype(ll k) const
	{
		return k == mx? 0: k == mn? 1: 2;
	}
	inline ll getval(int id) const
	{
		return id == 0? mx: id == 1? mn: secmx;
	}
	inline void addmx(ll k)
	{
		if(mn == mx) mn += k;
		else if(secmn == mx) secmn += k;
		mx += k;
	}
	inline void addmn(ll k)
	{
		if(mx == mn) mx += k;
		else if(secmx == mn) secmx += k;
		mn += k;
	}
	inline void addall(ll k)
	{
		mn += k; mx += k;
		if(secmx != -linf) secmx += k;
		if(secmn != linf) secmn += k;
	}
};

inline Data operator + (const Data &p,const Data &q)
{
	Data res(max(p.mx, q.mx), min(p.mn, q.mn), -linf, linf);
	chk_max(res.secmx, res.mx == p.mx? p.secmx: p.mx);
	chk_max(res.secmx, res.mx == q.mx? q.secmx: q.mx);
	
	chk_min(res.secmn, res.mn == p.mn? p.secmn: p.mn);
	chk_min(res.secmn, res.mn == q.mn? q.secmn: q.mn);
	return res;
}

struct Segment_Tree
{
	Data p[MAXN<<2][2];
	Vector fib[MAXN<<2][3][3];
	ll mxtag[MAXN<<2][2], mntag[MAXN<<2][2], addtag[MAXN<<2][2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	
	inline void push_up(int u)
	{
		p[u][0] = p[ls(u)][0] + p[rs(u)][0];
		p[u][1] = p[ls(u)][1] + p[rs(u)][1];
		for(int i=0; i<3; ++i) for(int j=0; j<3; ++j)
			fib[u][i][j] = Vector();
		for(int v: {ls(u), rs(u)})
			for(int i=0; i<3; ++i) for(int j=0; j<3; ++j)
			{
				ll x = p[v][0].getval(i), y = p[v][1].getval(j);
				fib[u][ p[u][0].gettype(x) ][ p[u][1].gettype(y) ] += fib[v][i][j];
			}
	}
	inline void updmx(int u,ll k,int id)
	{
		if(!k) return;
		mxtag[u][id] += k; p[u][id].addmx(k);
		Matrix mat = getfib(k);
		for(int i=0; i<3; ++i)
			(id == 0? fib[u][0][i]: fib[u][i][0]) &= mat;
	}
	inline void updmn(int u,ll k,int id)
	{
		if(!k) return;
		if(p[u][id].mn == p[u][id].mx)
		{
			updmx(u, k, id);
			return;
		}
		mntag[u][id] += k; p[u][id].addmn(k);
		Matrix mat = getfib(k);
		for(int i=0; i<3; ++i)
			(id == 0? fib[u][1][i]: fib[u][i][1]) &= mat;
	}
	inline void updadd(int u,ll k,int id)
	{
		if(!k) return;
		addtag[u][id] += k; p[u][id].addall(k);
		Matrix mat = getfib(k);
		for(int i=0; i<3; ++i) for(int j=0; j<3; ++j)
			fib[u][i][j] &= mat;
	}
	inline void push_down(int u)
	{
		int l = ls(u), r = rs(u);
		for(int i=0; i<=1; ++i)
		{
			if(addtag[u][i])
			{
				updadd(l, addtag[u][i], i);
				updadd(r, addtag[u][i], i);
				addtag[u][i] = 0;
			}
			if(mxtag[u][i])
			{
				ll curmx = max(p[l][i].mx, p[r][i].mx);
				if(p[l][i].mx == curmx) updmx(l, mxtag[u][i], i);
				if(p[r][i].mx == curmx) updmx(r, mxtag[u][i], i);
				mxtag[u][i] = 0;
			}
			if(mntag[u][i])
			{
				ll curmn = min(p[l][i].mn, p[r][i].mn);
				if(p[l][i].mn == curmn) updmn(l, mntag[u][i], i);
				if(p[r][i].mn == curmn) updmn(r, mntag[u][i], i);
				mntag[u][i] = 0;
			}
		}
	}
	
	void build(int u,int l,int r,ll a0[],ll a1[])
	{
		if(l == r)
		{
			p[u][0] = Data(a0[l]); p[u][1] = Data(a1[l]);
			fib[u][0][0] = getfib(a0[l] + a1[l]) * Vector(0,1);
			return;
		}
		int mid = (l+r)>>1;
		build(lson(u),a0,a1); build(rson(u),a0,a1);
		push_up(u);
	}
	
	void chkmax(int u,int l,int r,int ql,int qr,ll k,int id)
	{
		if(p[u][id].mn >= k) return;
		if(ql<=l && r<=qr && p[u][id].secmn > k)
		{
			updmn(u, k - p[u][id].mn, id);
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) chkmax(lson(u),ql,qr,k,id);
		if(mid<qr) chkmax(rson(u),ql,qr,k,id);
		push_up(u);
	}
	void chkmin(int u,int l,int r,int ql,int qr,ll k,int id)
	{
		if(p[u][id].mx <= k) return;
		if(ql<=l && r<=qr && p[u][id].secmx < k)
		{
			updmx(u, k - p[u][id].mx, id);
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) chkmin(lson(u),ql,qr,k,id);
		if(mid<qr) chkmin(rson(u),ql,qr,k,id);
		push_up(u);
	}
	void update_add(int u,int l,int r,int ql,int qr,ll k,int id)
	{
		if(ql<=l && r<=qr)
		{
			updadd(u, k, id);
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update_add(lson(u),ql,qr,k,id);
		if(mid<qr) update_add(rson(u),ql,qr,k,id);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr)
		{
			int res = 0;
			for(int i=0; i<3; ++i) for(int j=0; j<3; ++j)
				add_mod(res, fib[u][i][j][0]);
			return res;
		}
		push_down(u);
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) add_mod(res, query(lson(u),ql,qr));
		if(mid<qr) add_mod(res, query(rson(u),ql,qr));
		return res;
	}
}tree;

ll a0[MAXN], a1[MAXN];

int main(void)
{
	Fmat1[0] = Matrix(1, 1, 1, 0);
	Fmat2[0] = Matrix(0, 1, 1, mod-1);
	for(int i=1; i<LB; ++i)
		Fmat1[i] = Fmat1[i-1] * Fmat1[i-1],
		Fmat2[i] = Fmat2[i-1] * Fmat2[i-1];
	
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%lld",&a0[i]);
	for(int i=1; i<=n; ++i) scanf("%lld",&a1[i]);
	
	tree.build(1,1,n,a0,a1);
	
	while(Q--)
	{
		int type,id,l,r,x;
		scanf("%d",&type);
		if(type == 4)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",tree.query(1,1,n,l,r));
			continue;
		}
		
		scanf("%d%d%d%d",&id,&l,&r,&x);
		--id;
		if(type == 1) tree.chkmin(1,1,n, l,r,x,id);
		if(type == 2) tree.chkmax(1,1,n, l,r,x,id);
		if(type == 3) tree.update_add(1,1,n, l,r,x,id);
	}
	return 0;
}