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
const int mod=1e9+7;
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
const int maxn = 30011;
bitset<maxn> all1;
int n, m, b[maxn];
struct data
{
	bitset<maxn> pf[61], sf[61];
	int dlt;
	int gi(int x) const {return (x+dlt)%m;}
	ll len, ans[61];
	data shift(int d)
	{
		data ret = (*this);
		ret.dlt = (ret.dlt+d)%m;
		return ret;
	}
	void init1()
	{
		len = 1; dlt = 0;
		for (int i=0; i<m; i++)
		{
			pf[i].reset();
			for (int j=0; j<n; j++) pf[i][j] = b[j]>=i;
			sf[i].reset();
			sf[i][0] = 1;
			for (int j=0; j<n-1; j++) sf[i][j+1] = b[j]>=i;
			ans[i] = n==1&&b[0]>=i;
		}
	}
	void debug()
	{
		cerr<<"===debug==="<<endl;
		cerr<<"len = "<<len<<" dlt = "<<dlt<<" ans = "<<ans[0]<<endl;
		for (int t=0; t<m; t++)
		{
			for (int i=0; i<n; i++) cerr<<pf[t][i];
			cerr<<",";
		} cerr<<endl;
		for (int t=0; t<m; t++)
		{
			for (int i=0; i<n; i++) cerr<<sf[t][i];
			cerr<<",";
		} cerr<<endl;
	}
};
data merge(const data &l, const data &r)
{
	data ret;
	ret.len=l.len+r.len;
	ret.dlt=0;
	for (int i=0; i<m; i++)
	{
		ret.pf[i] = l.pf[l.gi(i)];
		if (l.len<n) ret.pf[i] &= r.pf[r.gi(i)]>>l.len|all1<<(n-l.len);
		ret.sf[i] = r.sf[r.gi(i)];
		if (r.len<n) ret.sf[i] &= l.sf[l.gi(i)]<<r.len|all1>>(maxn-r.len);
		ret.ans[i] = l.ans[l.gi(i)]+r.ans[r.gi(i)];
		int tmp = min(l.len, (ll)n-1);
		int tmpl = max(1ll, n-r.len);
		if (tmp>=tmpl)
		{
			ret.ans[i] += (((l.sf[l.gi(i)]&(r.pf[r.gi(i)]))>>tmpl)<<(maxn-tmp+tmpl-1)).count();
		}
	}
	return ret;
}
int K;
data A[66];
int d, gen[66];
data solve(ll N)
{
	assert(N>0);
	for (int i=K; i>=0; i--)
	{
		if (N==A[i].len) return A[i];
		if (N>A[i].len)
		{
			data ret = A[i];
			for (int j=1; j<d; j++)
			{
				if (N>A[i].len*(j+1)) ret = merge(ret, A[i].shift(gen[j]));
				else
				{
					ret = merge(ret, solve(N-A[i].len*j).shift(gen[j]));
					return ret;
				}
			}
			assert(false);
		}
	}
}
ll calc(ll N)
{
	if (N<=0) return 0;
	data cur = solve(N);
//	cur.debug();
	return cur.ans[cur.gi(0)];
}
int main()
{
	all1.set();
	getii(d, m);
	for (int i=0; i<d; i++) geti(gen[i]);
	geti(n);
	for (int i=0; i<n; i++) geti(b[i]);
	A[0].init1();
	while (true)
	{
		K++;
		A[K] = A[K-1];
		bool exceed = 0;
		for (int i=1; i<d; i++)
		{
			A[K] = merge(A[K], A[K-1].shift(gen[i]));
			if (A[K].len>2e18)
			{
				exceed = 1;
				break;
			}
		}
		if (exceed)
		{
			K--;
			break;
		}
	}
	ll l, r;
	getii(l, r);
	cout<<calc(r)-calc(l+n-2)<<endl;
	return 0;
}