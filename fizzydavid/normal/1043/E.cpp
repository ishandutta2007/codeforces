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
int n,m;
ll d[300111],a[300111],b[300111];
ll ans[300111];
pair<ll,int> pp[300111];
void solve()
{
	sort(pp+1,pp+n+1);
	ll sum=0;
	for(int i=1;i<=n;)
	{
		int ir=i;
		while(ir<=n&&pp[i].FF==pp[ir].FF)ir++;
		for(int j=i;j<ir;j++)
		{
			int id=pp[j].SS;
			ans[id]+=(i-1)*b[id]+sum;
		}
		for(int j=i;j<ir;j++)
		{
			int id=pp[j].SS;
			sum+=a[id];
		}
		i=ir;
	}
	sum=0;
	for(int i=n;i>=1;)
	{
		int il=i;
		while(il>0&&pp[i].FF==pp[il].FF)il--;
		for(int j=i;j>il;j--)
		{
			int id=pp[j].SS;
			sum+=b[id];
		}
		for(int j=i;j>il;j--)
		{
			int id=pp[j].SS;
			ans[id]+=(n-il)*a[id]+sum;
		}
		i=il;
	}
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)
	{
		getii(a[i],b[i]);
		d[i]=a[i]-b[i];
		pp[i]=MP(d[i],i);
	}
	solve();
//	for(int i=1;i<=n;i++)puti(ans[i]);
	for(int i=1;i<=n;i++)
	{
		ll cur=a[i]+b[i];
		ans[i]-=cur;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		ll cur=min(a[x]+b[y],a[y]+b[x]);
		ans[x]-=cur;
		ans[y]-=cur;
	}
	for(int i=1;i<=n;i++)puti(ans[i]);
	return 0;
}