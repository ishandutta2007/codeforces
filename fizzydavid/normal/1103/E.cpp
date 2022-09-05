//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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
const int maxn = 100000;
typedef unsigned long long ull;
template <int p> //p must be prime
struct number
{
	ull a[p];
	number(int x = 0)
	{
		memset(a, 0, sizeof(a));
		a[0] = x;
	}
	number operator + (const number &t) const
	{
		number ret;
		for (int i=0; i<p; i++) ret.a[i] = a[i]+t.a[i];
		return ret;
	}
	number operator - (const number &t) const
	{
		number ret;
		for (int i=0; i<p; i++) ret.a[i] = a[i]-t.a[i];
		return ret;
	}
	number operator * (const number &t) const
	{
		number ret;
		for (int i=0; i<p; i++)
		{
			if (!a[i]) continue;
			for (int j=0; j<p; j++) ret.a[(i+j)%p] += a[i]*t.a[j];
		}
		return ret;
	}
	ull getint() {return a[0]-a[1];}
	void debug() {for (int i=0; i<5; i++) cerr<<a[i]<<","; cerr<<endl;}
};
typedef number<5> num;
num qpown(num x, int k) {return k==0?num(1):(k&1?qpown(x*x, k>>1)*x:qpown(x*x, k>>1));}
ull qpow(ull x, ull k) {return k==0? 1: qpow(x*x,k>>1)*(k&1?x:1);}
const int n = 100000;
const int dn = 10;
const int dim[10] = {2, 5, 2, 5, 2, 5, 2, 5, 2, 5};
num a[n];
num root[6][6];
void DFT(num a[], int coef)
{
	for (int i=0; i<dn; i++)
	{
		num na[n];
		int d = dim[i];
		int p = 1;
		for (int j=0; j<i; j++) p *= dim[j];
		for (int j=0; j<n; j++)
		{
			int id = (j/p)%d;
			int x = j-id*p;
			na[j] = num();
			for (int k=0; k<d; k++)
			{
				int y = x+k*p;
				if (coef==1) na[j] = na[j]+root[d][(k*id)%d]*a[y];
				else na[j] = na[j]+root[d][d-(k*id)%d]*a[y];
			}
		}
		for (int j=0; j<n; j++) a[j] = na[j];
	}
}
int i_to_m(int x)
{
	int ret = 0, pw = 1;
	for (int i=0; i<dn/2; i++)
	{
		ret += (x%2)*pw;
		pw *= 2;
		ret += (x%5)*pw;
		pw *= 5;
		x /= 10;
	}
	return ret;
}
int m_to_i(int x)
{
	int ret = 0, pw = 1;
	for (int i=0; i<dn; i+=2)
	{
		int c2 = x%2;
		x /= 2;
		int c5 = x%5;
		x /= 5;
		for (int t=0; t<10; t++) if(t%2==c2&&t%5==c5) ret = ret+t*pw;
		pw *= 10;
	}
	return ret;
}
int main()
{
	root[2][0].a[0] = 1;
	root[2][1].a[0] = -1;
	root[2][2].a[0] = 1;
	for (int i=0; i<=5; i++) root[5][i].a[i%5] = 1;
	 
	int k;
	geti(k);
	for (int i=1; i<=k; i++)
	{
		int x;
		geti(x);
		a[i_to_m(x)].a[0]++;
	}
	DFT(a, 1);
	for (int i=0; i<n; i++) a[i] = qpown(a[i], k);
	DFT(a, -1);
	ull inv5 = qpow(5, (1ull<<63)-1);
	ull coef = qpow(inv5, dn>>1);
	for (int i=0; i<k; i++)
	{
		int id = i_to_m(i);
		ll cur = a[id].getint();
		cur = cur>>(dn>>1);
		cur = cur*coef;
		putsi(cur&((1ull<<58)-1));
	}
	return 0;
}