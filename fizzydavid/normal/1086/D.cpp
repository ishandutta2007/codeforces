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
const int maxn = 200111;
struct BIT
{
	int a[maxn];
	void add(int x, int v) { for(int i=x; i<maxn; i+=i&(-i)) a[i]+=v;}
	int query(int x)
	{
		if (x<0) return 0;
		int ret = 0;
		for (int i=x; i; i-=i&(-i)) ret+=a[i];
		return ret;
	}
	int query(int l, int r) {return l>r?0:query(r)-query(l-1);}
}B[3];
int id[256];
int n, q;
set<int> S[3];
char s[maxn];
void add(int x)
{
	S[id[s[x]]].insert(x);
	B[id[s[x]]].add(x, 1);
}
void del(int x)
{
	S[id[s[x]]].erase(x);
	B[id[s[x]]].add(x, -1);
}
int l[3], r[3];
int query(int id)
{
	int x = (id+1)%3;
	int y = (id+2)%3;
	pair<int,int> seg1 = MP(r[y], r[x]);
	pair<int,int> seg2 = MP(l[x], l[y]);
	int ans1 = B[id].query(seg1.FF, seg1.SS);
	int ans2 = B[id].query(seg2.FF, seg2.SS);
	if (ans1>0&&ans2>0&&seg1.FF<seg2.SS)
	{
		return B[id].query(1, n);
	}
	else return ans1+ans2;
}
void query()
{
	for (int i=0; i<3; i++)
	{
		if (!S[i].size()) l[i] = n+1, r[i] = 0;
		else l[i] = *S[i].begin(), r[i] = *S[i].rbegin();
	}
	int ans = 0;
	ans += query(0);
	ans += query(1);
	ans += query(2);
	cout<<n-ans<<endl;
}
int main()
{
	id['R'] = 0;
	id['P'] = 1;
	id['S'] = 2;
	getii(n, q);
	for (int i=1; i<=n; i++)
	{
		s[i] = getreal();
		add(i);
	}
	query();
	for (int i=1; i<=q; i++)
	{
		int x;
		geti(x);
		char c = getreal();
		del(x);
		s[x] = c;
		add(x);
		query();
	}
	return 0;
}