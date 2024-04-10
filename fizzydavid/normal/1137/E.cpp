//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
struct line
{
	ll k, b;
	line(ll K=0, ll B=0) : k(K), b(B) {}
	line operator + (const line &t) const {return line(k+t.k, b+t.b);}
	line operator - (const line &t) const {return line(k-t.k, b-t.b);}
	ll get(ll x) {return k*x+b;}
};
ll det(ll ax, ll ay, ll bx, ll by)
{
	long double est = 1.0*ax*by-1.0*ay*bx;
	if (est<-1e18) return -1e18;
	if (est>1e18) return 1e18;
	return ax*by-ay*bx;
}
bool check(pair<ll,line> x, pair<ll,line> y, pair<ll,line> z, line lz)
{
	x.SS = x.SS+lz; y.SS = y.SS+lz; z.SS = z.SS+lz;
	ll ax = z.FF-x.FF;
	ll ay = z.SS.get(z.FF)-x.SS.get(x.FF);
	ll bx = y.FF-x.FF;
	ll by = y.SS.get(y.FF)-x.SS.get(x.FF);
	if (det(ax, ay, bx, by)>=0) return true; else return false;
}
struct Train
{
	int n;
	line lz;
	vector<pair<ll, line> > v;
	void clear(int k)
	{
		v.clear();
		v.PB(MP(0, line(0, 0)));
		n += k;
		lz = line(0, 0);
	}
	void add(int k)
	{
		v.PB(MP(n, line(0, 0)-lz));
		while (v.size()>=3)
		{
			if (check(v[v.size()-3], v[v.size()-2], v[v.size()-1], lz))
			{
				swap(v[v.size()-2], v.back());
				v.pop_back();
			}
			else break;
		}
		n += k;
	}
	void add_line(line l)
	{
		lz = lz + l;
	}
	void query()
	{
		while (v.size()>=2)
		{
			if ((lz+v.back().SS).get(v.back().FF)>=(lz+v[v.size()-2].SS).get(v[v.size()-2].FF)) v.pop_back();
			else break;
		}
		putsii(v.back().FF+1, (v.back().SS+lz).get(v.back().FF));
	}
}T;
int main()
{
	int n;
	geti(n);
	T.clear(n);
	int m;
	geti(m);
	for (int i=0; i<m; i++)
	{
		int ti, k;
		getii(ti, k);
		if (ti==1) T.clear(k);
		else if (ti==2) T.add(k);
		else
		{
			int b;
			geti(b);
			T.add_line(line(b, k));
		}
		T.query();
	}
	return 0;
}