//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
const ll mod=1e9+7;
int n,k,q,cnt[1000111],rev[1000111];
ll ans,delta[1000111],tres[1000111];
void addfac(int x)
{
	ans=(ans-tres[x]*delta[x]%mod+mod)%mod;
	cnt[x]++;
	if(cnt[x]==k)
	{
		tres[x]=1;
	}
	else
	{
		tres[x]=tres[x]*cnt[x]%mod*rev[cnt[x]-k]%mod;
	}
	ans=(ans+tres[x]*delta[x]%mod)%mod;
}
void add(int x)
{
	for(ll i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			addfac(i);
			if(x/i!=i)addfac(x/i);
		}
	}
}
ll kissme(ll x,ll p)
{
	ll ans=1;
	while(p>0)
	{
		if(p&1)ans=(ans*x)%mod;
		x=(x*x)%mod;
		p>>=1;
	}
	return ans;
}
int main()
{
	for(int i=1;i<=1000005;i++)rev[i]=kissme(i,mod-2);
	for(int i=1;i<=1000005;i++)delta[i]=i;
	for(int i=1;i<=1000005;i++)
	{
		for(int j=i*2;j<=1000005;j+=i)
		{
			delta[j]=(delta[j]-delta[i]+mod)%mod;
		}
	}
	getiii(n,k,q);
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		add(x);
	}
	for(int i=1;i<=q;i++)
	{
		int x;
		geti(x);
		add(x);
		putsi(ans);
	}
	return 0;
}