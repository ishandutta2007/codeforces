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
typedef unsigned long long ull;
const int maxn = 200111;
const int maxtot = 8000111;
ull a[maxtot];
const int s_msk = (1<<23)-1;
const int mn_msk = (1<<18)-1;
int getmn(int p) {return a[p]&mn_msk;}
int getrs(int p) {return (a[p]>>18)&s_msk;}
int getls(int p) {return (a[p]>>41)&s_msk;}
int tot;
int add(int x, int y, int l, int r, int q)
{
	if (l==r) return q+1;
	int p = ++tot;
	assert(p<maxtot);
	int qls = getls(q), qrs = getrs(q);
	if (x<=l&&r<=y)
	{
		a[p]=(ull)qls<<41|(ull)qrs<<18|getmn(q)+1;
		return p;
	}
	int m = l+r>>1;
	int tag = getmn(q)-min(l==m?qls:getmn(qls), m+1==r?qrs:getmn(qrs));
	int ls, rs, mn;
	if (x<=m) ls = add(x,y,l,m,qls); else ls = qls;
	if (m<y) rs = add(x,y,m+1,r,qrs); else rs = qrs;
	mn = min(l==m?ls:getmn(ls), m+1==r?rs:getmn(rs));
	a[p] = (ull)ls<<41|(ull)rs<<18|mn+tag;
	return p;
}
int query(int x, int y, int dlt, int l, int r, int p)
{
	if (l==r) return p+dlt;
	if (x<=l&&r<=y) return getmn(p)+dlt;
	int ls = getls(p), rs = getrs(p);
	int m = l+r>>1;
	dlt += getmn(p)-min(l==m?ls:getmn(ls), m+1==r?rs:getmn(rs));
	if (x<=m&&m<y) return min(query(x,y,dlt,l,m,ls),query(x,y,dlt,m+1,r,rs));
	else if(x<=m) return query(x,y,dlt,l,m,ls);
	else return query(x,y,dlt,m+1,r,rs);
}
int n, m, rt[maxn];
pair<int,int> A[maxn];

int main()
{
	getii(n, m);
	for (int i=1; i<=n; i++) geti(A[i].FF), A[i].SS = i;
//	n = 200000; m = 23333;
//	for (int i=1; i<=n; i++) A[i] = MP(rand(), i);
	int L = n-m+1;
	sort(A+1, A+n+1);
	for (int i=1; i<=n; i++) rt[i] = add(max(1,A[i].SS-m+1), min(L,A[i].SS), 1, L, rt[i-1]);
	int q;
	geti(q);
	int ans = 0;
	for (int i=1; i<=q; i++)
	{
		int l, r, x;
		getiii(l, r, x);
		x ^= ans;
		x = lower_bound(A+1, A+n+1, MP(x,0))-A-1;
		ans = query(l, r, 0, 1, L, rt[x]);
		putsi(ans);
	}
	return 0;
}