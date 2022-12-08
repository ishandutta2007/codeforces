/*
Bugs:
 * Used X instead of X-1 for segments
 * Put break statement outside of the if condition :facepalm:

*/
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <vector>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct mint
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
		mint& operator += (const mint& m) {if((val += m.val) >= MOD) val -= MOD; return *this;}
		mint& operator -= (const mint& m) {if((val -= m.val) < 0) val += MOD; return *this;}
		mint& operator *= (const mint& m) {val = ti(tl(val)*m.val%MOD); return *this;}

		template<typename T>
		friend mint pow(mint a, T p)
		{
			mint r(1);
			for(;p;p>>=1, a*=a) if(p&1) r*=a;
			return r;
		}

		friend mint operator + (mint a, const mint& b) {return a += b;}
		friend mint operator - (mint a, const mint& b) {return a -= b;}
		friend mint operator * (mint a, const mint& b) {return a *= b;}
};


const int MN = 2e3+10;

int N, K, L, x[MN], X, y[MN], Y;
struct Point
{
	public:
		int x,y,c;
		void in() {scanf("%d%d%d", &x, &y, &c);}
} a[MN];
std::multiset<int> set[MN];
mint ans;

struct segtree
{
public:
	int m[1<<12], m2[1<<12], z[1<<12];
	mint c[1<<12], s[1<<12];//min count, sum
	void reset()
	{
		memset(m2, 0x3f, sizeof m2);
		memset(z, -1, sizeof z);
		memset(m, 0, sizeof m);
	}
	void up(int n)
	{
		if(m[n<<1] < m[n<<1|1])
			m[n] = m[n<<1], c[n] = c[n<<1], m2[n] = std::min(m2[n<<1], m[n<<1|1]);
		else if(m[n<<1] > m[n<<1|1])
			m[n] = m[n<<1|1], c[n] = c[n<<1|1], m2[n] = std::min(m2[n<<1|1], m[n<<1]);
		else
			m[n] = m[n<<1], c[n] = c[n<<1] + c[n<<1|1], m2[n] = std::min(m2[n<<1], m2[n<<1|1]);
		s[n]=s[n<<1]+s[n<<1|1];
	}
	void build(int n, int l, int r)
	{
		c[n]=mint(x[r]-x[l]);
		s[n]=mint(0);
		if(r-l>1)
		{
			int mm=l+(r-l)/2;
			build(n<<1, l, mm);
			build(n<<1|1, mm, r);
			up(n);
		}
	}
	void upd(int n, int l, int r, int v)
	{
		assert(v < m2[n]);
		if(m[n] < v) s[n]+=c[n]*mint(v-m[n]), z[n] = m[n] = v;
	}
	void down(int n, int l, int r)
	{
		if(!~z[n]) return;
		int mm=l+(r-l)/2;
		upd(n<<1, l, mm, z[n]);
		upd(n<<1|1, mm, r, z[n]);
		z[n] = -1;
	}
	void upd(int n, int l, int r, int ql, int qr, int v)
	{
		if(v <= m[n]) return;
		if(v < m2[n] && ql <= l && r <= qr)
		{
			upd(n, l, r, v);
			return;
		}
		assert(r-l>1);
		int m = l + (r-l)/2;
		down(n, l, r);
		if(ql < m) upd(n<<1, l, m, ql, qr, v);
		if(m < qr) upd(n<<1|1,m,r, ql, qr, v);
		up(n);
	}
	mint qry(int n, int l, int r, int ql, int qr)
	{
		if(ql<=l&&r<=qr) return s[n];
		int m=l+(r-l)/2; mint f(0);
		down(n, l, r);
		if(ql<m) f+=qry(n<<1,l,m,ql,qr);
		if(m<qr) f+=qry(n<<1|1,m,r,ql,qr);
		return f;
	}
};
segtree st;

int main()
{
	scanf("%d%d%d", &N, &K, &L);
	for(int i=0;i<N;++i)
	{
		a[i].in();
		x[X++]=a[i].x;
		y[Y++]=a[i].y;
	}
	x[X++]=-1, y[Y++]=-1;
	x[X++]=L, y[Y++]=L;
	std::sort(x, x+X); X=std::unique(x, x+X)-x;
	std::sort(y, y+Y); Y=std::unique(y, y+Y)-y;
	for(int i=0;i<N;++i)
	{
		a[i].x=std::lower_bound(x, x+X, a[i].x)-x;
		a[i].y=std::lower_bound(y, y+Y, a[i].y)-y;
	}
	std::sort(a, a+N, [](const Point& u, const Point& v) {return u.y>v.y;});
	mint all(L+1); all*=mint(L);

	//printf("X: "); for(int i=0;i<X;++i) printf("%d ", x[i]); printf("\n");
	//printf("Y: "); for(int i=0;i<Y;++i) printf("%d ", y[i]); printf("\n");
	for(int i=1;i<Y;++i)
	{
		for(int j=0;j<N;++j)
			if(a[j].y>=i)
				set[a[j].c].insert(a[j].x);
		bool ok=1;
		for(int j=1;ok&&j<=K;++j)
			if(set[j].empty())
				ok=0;
		if(!ok) break;

		st.reset();
		st.build(1, 0, X-1);

		for(int j=1;j<=K;++j)
		{
			auto it=set[j].begin();
			st.upd(1, 0, X-1, 0, X-1, x[*it]);
			for(std::multiset<int>::iterator nx=set[j].begin(); nx!=set[j].end();)
			{
				it=nx++;
				if(*it < X-1) st.upd(1, 0, X-1, *it, X-1, nx==set[j].end()?L:x[*nx]);
			}
		}
		mint cst(y[i]-y[i-1]);//const for this row

		//printf("%d NIL %d %d\n", i, all, st.qry(1, 0, X-1, 0, X-1));
		for(int j=Y-1,k=0;j>=i;--j)
		{
			for(;k<N && a[k].y==j;++k)
			{
				auto x=a[k];
				auto it=set[x.c].find(x.x);
				int lb=-1;
				if(it == set[x.c].begin())
					lb=0;
				else
					lb=*std::prev(it);
				auto nx=std::next(it);
				assert(lb < *it);
				st.upd(1, 0, X-1, lb, *it, nx==set[x.c].end()?L:(::x[*nx]));//technically you can upd from either (lb, *nx) or (lb, *it), or heck even (lb, X-1)
				set[x.c].erase(it);

				if(set[x.c].empty())
				{
					ok=0;
					break;
				}
			}
			if(!ok) break;
			//printf("%d %d %d %d\n", i, j, all, st.qry(1, 0, X-1, 0, X-1));
			ans += mint(y[j]-y[j-1])*cst*(all-st.qry(1, 0, X-1, 0, X-1));
		}

		for(int j=1;j<=K;++j)
			set[j].clear();
	}
	printf("%d\n", ans);
	return 0;
}