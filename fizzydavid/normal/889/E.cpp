//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
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
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
set<pair<ll,ll> > st;
ll sz,K;
int n;
void modmodmod(ll m)
{
	if(m>=sz)
	{
		K++;
		return;
	}
	sz=m;
	ll mx=0;
	while(st.size()>0)
	{
		pair<ll,ll> cur=*(--st.end());
		if(cur.FF<=m)break;
		st.erase(--st.end());
		mx=max(mx,cur.SS+1ll*(cur.FF-cur.FF%m-m)*K);
		if(cur.FF%m!=0)st.insert(MP(cur.FF%m,1ll*(cur.FF-cur.FF%m)*K+cur.SS));
	}
	st.insert(MP(m,mx));
	K++;
}
int main()
{
	geti(n);
	sz=10000000000000ll;
	st.insert(MP(sz,0));
	for(int i=1;i<=n;i++)
	{
		ll x;
		geti(x);
		modmodmod(x);
	}
	ll ans=0;
	foreach(it,st)
	{
		ans=max(ans,1ll*(it->FF-1)*n+it->SS);
	}
	cout<<ans<<endl;
	return 0;
}