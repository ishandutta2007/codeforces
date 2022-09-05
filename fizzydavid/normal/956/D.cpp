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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n;
ll w;
ll X[100111],V[100111];
struct frac
{
	ll p,q;
	frac(ll P=0,ll Q=1)
	{
		p=P;q=Q;
		if(q<0)p=-p,q=-q;
	}
	bool operator<(const frac &t)const
	{
		return p*t.q<q*t.p;
	}
	bool operator==(const frac &t)const{return p==t.p&&q==t.q;}
};
frac a[100111],b[100111];
map<frac,ll> cnt;
frac va[100111];
int van;
pair<frac,int> pp[100111];
int getid(frac f)
{
	return lower_bound(va,va+van,f)-va+1;
}
int tab[100111];
void add(int x)
{
	x=100002-x;
	for(int i=x;i<=100005;i+=i&(-i))tab[i]++;
}

int query(int x)
{
	x=100002-x;
	int ret=0;
	for(int i=x;i;i-=i&(-i))ret+=tab[i];
	return ret;
}
void Add(int x)
{
	int id=getid(a[x]);
	add(id);
}
int Query(int x)
{
	int id=getid(a[x]);
	return query(id);
}
int main()
{
	getii(n,w);
	for(int i=1;i<=n;i++)
	{
		getii(X[i],V[i]);
		a[i]=frac(V[i]+w,X[i]);
		b[i]=frac(V[i]-w,X[i]);
		cnt[b[i]]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=cnt[b[i]]-1;
	}
	ans/=2;
	for(int i=1;i<=n;i++)
	{
		va[van++]=a[i];
	}
	sort(va,va+van);
	van=unique(va,va+van)-va;
	for(int i=1;i<=n;i++)pp[i]=MP(b[i],i);
	sort(pp+1,pp+n+1);
	int it=1;
	for(int i=1;i<=n;i++)
	{
		while(pp[it].FF<pp[i].FF)
		{
			Add(pp[it++].SS);
		}
		ans+=Query(pp[i].SS);
	}
	cout<<ans<<endl;
	return 0;
}