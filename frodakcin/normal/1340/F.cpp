#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
template<int MOD> struct mint
{
public:
	int val;
	mint(int _val = 0) : val(_val)
	{
		val = (-MOD <= val && val < MOD) ? val : val%MOD;
		if(val < 0) val += MOD;
	}
	explicit operator int () const {return val;}

	mint operator -() const {return mint(-val);}
	mint& operator += (mint m) {if((val += m.val) >= MOD) val -= MOD; return *this;}
	mint& operator -= (mint m) {if((val -= m.val) < 0) val += MOD; return *this;}
	mint& operator *= (mint m) {val = ti(tl(val)*m.val%MOD); return *this;}
	bool operator == (mint m) const {return val == m.val;}

	friend mint pow(mint a, int p)
	{
		mint r(1);
		for(;p;p>>=1, a*=a) if(p&1) r*=a;
		return r;
	}

	friend mint operator + (mint a, mint b) {return a += b;}
	friend mint operator - (mint a, mint b) {return a -= b;}
	friend mint operator * (mint a, mint b) {return a *= b;}
};
const int MK = 1e5 + 1;
const int MN = 1e5 + 10;

using mint0 = mint<1000000007>;
const mint0 base0 = mint0(MK);
mint0 pow0[MN];

struct hash
{
public:
	mint0 val0;
	hash(int x = 0)//x = type
	{
		val0 = mint0(x);
	}
	bool operator == (hash o) const
	{
		return val0 == o.val0;
	}
	hash& operator += (hash o) {val0 += o.val0; return *this;}
	hash& operator *= (int o) {if(o) val0 *= pow0[o]; return *this;}

	friend hash operator + (hash a, hash b) {return a += b;}
	friend hash operator * (hash a, int b) {return a *= b;}
};

//bbst
struct node
{
public:
	int s, v;
	char h;//realistically this won't be greater than 2*logN <= 40
	hash sum;
	int c[2];//l=0, r=1
};
const int pool_sz = 1<<23;//check constraints & fix this here
int pool_ctr = pool_sz;
node pool[pool_sz];
int nn()
{
	assert(pool_ctr > 1);
	return --pool_ctr;
}
void upd(int n)
{
	assert(n);
	pool[n].s = pool[pool[n].c[0]].s + pool[pool[n].c[1]].s + 1;
	pool[n].h = std::max(pool[pool[n].c[0]].h, pool[pool[n].c[1]].h)+1;
	pool[n].sum = hash(pool[n].v)*pool[pool[n].c[0]].s;
	if(pool[n].c[0]) pool[n].sum += pool[pool[n].c[0]].sum;
	if(pool[n].c[1]) pool[n].sum += pool[pool[n].c[1]].sum*(pool[pool[n].c[0]].s+1);
}
int nn(int x) {int f = nn(); pool[f].v = x; return upd(f), f;}
int copy(int x){int f = nn(); pool[f]=pool[x]; return f;}

int rot(int n, bool r, bool pst)
{
	int o = pst ? copy(pool[n].c[r]) : pool[n].c[r];
	pool[n].c[r] = pool[o].c[!r], pool[o].c[!r] = n;
	return upd(n), upd(o), o;
}
int bal(int n, bool pst) //only persist grandchild
{
	upd(n);
	int b = pool[pool[n].c[0]].h - pool[pool[n].c[1]].h;
	if(b > 1)
		if(pool[pool[pool[n].c[0]].c[0]].h+1 == pool[pool[n].c[0]].h)
			return rot(n, 0, 0);
		else
			return pool[n].c[0] = rot(pool[n].c[0], 1, pst), rot(n, 0, 0);
	else if(b < -1)
		if(pool[pool[pool[n].c[1]].c[1]].h+1 == pool[pool[n].c[1]].h)
			return rot(n, 1, 0);
		else
			return pool[n].c[1] = rot(pool[n].c[1], 0, pst), rot(n, 1, 0);
	else
		return n;
}
int merge(int a, int b, bool pst) //a, b - original
{
	if(!b) return a;
	if(!a) return b;
	if(pool[a].h < pool[b].h) return b=pst?copy(b):b, pool[b].c[0] = merge(a, pool[b].c[0], pst), bal(b, pst);
	else return a=pst?copy(a):a, pool[a].c[1] = merge(pool[a].c[1], b, pst), bal(a, pst);
}
int mwr(int l, int m, int r, bool pst) //lr original; m copy
{
	int b = pool[l].h - pool[r].h;
	if(b > 1)
		return l=pst?copy(l):l, pool[l].c[1]=mwr(pool[l].c[1], m, r, pst), bal(l, pst);
	else if(b < -1)
		return r=pst?copy(r):r, pool[r].c[0]=mwr(l, m, pool[r].c[0], pst), bal(r, pst);
	pool[m].c[0] = l, pool[m].c[1] = r, upd(m);
	return m;
}
struct cut
{
public:
	int l, r;
};
cut split(int n, int k, bool pst) //n original
{
	if(!k) return {0, n};
	if(k==pool[n].s) return {n, 0};
	if(pool[pool[n].c[0]].s < k)
	{
		cut x = split(pool[n].c[1], k-pool[pool[n].c[0]].s-1, pst);
		return {mwr(pool[n].c[0], pst?nn(pool[n].v):n, x.l, pst), x.r};
	}
	else
	{
		cut x = split(pool[n].c[0], k, pst);
		return {x.l, mwr(x.r, pst?nn(pool[n].v):n, pool[n].c[1], pst)};
	}
}
int splitR(int n, int k)//always persist
{
	if(k == pool[n].s) return 0;
	if(!k) return n;
	if(pool[pool[n].c[0]].s < k)
		return splitR(pool[n].c[1], k-pool[pool[n].c[0]].s-1);
	else
	{
		int x = splitR(pool[n].c[0], k);
		return mwr(x, nn(pool[n].v), pool[n].c[1], 1);
	}
}
hash getval(int n, int k)
{
	if(!k) return hash(0);
	if(pool[n].s == k) return pool[n].sum;
	if(pool[pool[n].c[0]].s < k)
		return pool[pool[n].c[0]].sum + hash(pool[n].v)*pool[pool[n].c[0]].s + getval(pool[n].c[1], k-pool[pool[n].c[0]].s-1)*(pool[pool[n].c[0]].s+1);
	else
		return getval(pool[n].c[0], k);
}

void out(int n)
{
	if(!n) return;
	out(pool[n].c[0]);
	printf("id: %3d(%d), c:[%3d, %3d], s[%2d], h[%2d], hash: (%d, %d)\n", n, pool[n].v, pool[n].c[0], pool[n].c[1], pool[n].s, pool[n].h, pool[n].sum.val0, -1);
	out(pool[n].c[1]);
}

int N, K, Q, s[MN];
//segtree
const int MS = 1 << 18;
struct state
{
public:
	int open, close;
	bool ok;
	state(int open, int close, bool ok) : open(open), close(close), ok(ok) {}
	state(int x = 0)
	{
		ok = 1;
		close = open = 0;
		if(x < 0)
			close = nn(-x);
		if(0 < x)
			open = nn(x);
	}
	void fail() {open = close = 0, ok = 0;}
	state& operator += (const state& o)
	{
		if(ok)
		{
			if(!o.ok)
				return fail(), *this;
			int b = pool[open].s - pool[o.close].s;
			if(b > 0)
			{
				cut x;
				if(!o.close)
					open = merge(o.open, open, 1);
				else if(pool[(x = split(open, pool[o.close].s, 1)).l].sum == pool[o.close].sum)
					open = merge(o.open, x.r, 1);
				else
					return fail(), *this;
			}
			else if(b < 0)
			{
				cut x;
				if(!open)
					open = o.open, close = merge(close, o.close, 1);
				else if(pool[(x = split(o.close, pool[open].s, 1)).l].sum == pool[open].sum)
					close = merge(close, x.r, 1), open = o.open;
				else
					return fail(), *this;
			}
			else
				if(!open || pool[open].sum == pool[o.close].sum)
					open = o.open;
				else
					return fail(), *this;
		}
		return *this;
	}
	friend state operator + (state a, state b) {return a += b;}
};
state st[MS];
int cur;
void build(int n, int l, int r)
{
	if(r-l>1)
	{
		int m = l+(r-l)/2;
		build(n<<1, l, m);
		build(n<<1|1, m, r);
		st[n] = st[n<<1] + st[n<<1|1];
	}
	else
		st[n] = state(s[l]);
}
void upd(int n, int l, int r, int x)
{
	if(r-l>1)
	{
		int m = l+(r-l)/2;
		if(x < m) upd(n<<1, l, m, x);
		else upd(n<<1|1, m, r, x);
		st[n] = st[n<<1] + st[n<<1|1];
	}
	else
		st[n] = state(s[l]);
}
void query(int n, int l, int r, int ql, int qr)
{
	if(ql <= l&&r <= qr)
	{
		if(~cur)
		{
			if(!st[n].ok) cur = -1;
			else if(pool[st[n].close].s > pool[cur].s) cur = -1;
			else if(!cur) cur = st[n].open;
			else if(getval(cur, pool[st[n].close].s) == pool[st[n].close].sum)
				cur = merge(st[n].open, splitR(cur, pool[st[n].close].s), 1);
			else cur = -1;
		}
	}
	else
	{
		int m = l+(r-l)/2;
		if(ql < m) query(n<<1, l, m, ql, qr);
		if(m < qr) query(n<<1|1, m, r, ql, qr);
	}
}

int main(void)
{
	pow0[0] = mint0(1);
	for(int i = 0;i+1<MN;++i)
		pow0[i+1] = pow0[i] * base0;
	scanf("%d%d", &N, &K);
	for(int i = 0;i < N;++i)
		scanf("%d", s+i);
	build(1, 0, N);
	//printf("mem: %d\n", pool_sz - pool_ctr);
	scanf("%d", &Q);
	for(int i = 0, x, y, z;i < Q;++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		if(x == 1)
			s[--y] = z, upd(1, 0, N, y);
		else
		{
			cur = 0;
			query(1, 0, N, --y, z);
			if(cur)
				printf("No\n");
			else
				printf("Yes\n");
		}
		if(pool_ctr < 1000)
		{
			memset(pool, 0, sizeof(pool));
			pool_ctr = pool_sz;
			build(1, 0, N);
		}
	}
	return 0; 
}