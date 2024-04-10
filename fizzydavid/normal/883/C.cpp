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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
ll n,T,v0;
ll a1,v1,p1;
ll a2,v2,p2;
int main()
{
	getiii(n,T,v0);
	getiii(a1,v1,p1);
	getiii(a2,v2,p2);
	if(v1>v2)
	{
		swap(a1,a2);
		swap(v1,v2);
		swap(p1,p2);
	}
	ll ans=1ll*mod*mod;
	for(int i=0;i<=n;i++)
	{
//		cerr<<"i="<<i<<endl;
		ll lft=max(0ll,n-a1*i);
		ll curt=(n-lft)*v1;
		if(v2<v0)
		{
			if(lft*v2+curt>T)continue;
			if(lft*v0+curt<=T)
			{
				ans=min(ans,p1*i);
				continue;
			}
			ll l=(-T+curt+lft*v0+v0-v2-1)/(v0-v2);
			assert(l>=0);
//			cerr<<"l="<<l<<endl;
			ans=min(ans,((l+a2-1)/a2)*p2+p1*i);
		}
		else
		{
			if(lft*v0+curt<=T)
			{
				ans=min(ans,p1*i);
			}
		}
	}
	if(ans==1ll*mod*mod)puts("-1");
	else putsi(ans);
	return 0;
}