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
const int mod=998244353;
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
ll a[511];
ll pw(ll x,int p){ll ret=1;while(p--)ret=ret*x;return ret;}
map<ll,int> mp,mp2;
void fac(ll &x,int p)
{
	if(x==1)return;
	double t=pow(x,1.0/p);
	ll y=ll(t);
	while(pw(y,p)<x)y++;
	while(pw(y,p)>x)y--;
	if(pw(y,p)==x)
	{
		mp[y]+=p;
		x=1;
	}
}
const ll B=1e10;
void bfac(ll &x)
{
	bool flag=0;
	for(ll j=2;1ll*j*j<=B;j++)
	{
		if(x%j==0)
		{
			flag=1;
			int c=0;
			while(x%j==0)c++,x/=j;
			mp[j]+=c;
		}
	}
	if(flag&&x>1)
	{
		mp[x]++;
		x=1;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		fac(a[i],4);
		fac(a[i],2);
		fac(a[i],3);
		bfac(a[i]);
	}
//	for(int i=1;i<=n;i++)cerr<<a[i]<<" ";cerr<<endl;
	ll tcnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)continue;
		vector<pair<ll,int> > v;
		for(auto x:mp)
		{
			int c=0;
			while(a[i]%x.FF==0)
			{
				a[i]/=x.FF;c++;
			}
			if(c>0)v.PB(MP(x.FF,c));
		}
		for(int j=0;j<v.size();j++)mp[v[j].FF]+=v[j].SS;
		if(a[i]==1)continue;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(a[i]==a[j])continue;
			ll g=__gcd(a[i],a[j]);
			if(g>1)
			{
//				cerr<<"g="<<g<<endl;
				a[i]/=g;
				mp[g]++;
			}
		}
		if(a[i]>1)
		{
			if(a[i]<=B)mp[a[i]]++;
			else mp2[a[i]]++;
		}
	}
/*
	for(int i=1;i<=n;i++)cerr<<a[i]<<" ";cerr<<endl;
	for(auto x:mp)cerr<<x.FF<<","<<x.SS<<endl;
	cerr<<"------"<<endl;
	for(auto x:mp2)cerr<<x.FF<<","<<x.SS<<endl;
*/	
	ll ans=1;
	for(auto x:mp)ans=ans*(x.SS+1)%mod;
	for(auto x:mp2)
	{
		ans=ans*(x.SS+1)%mod;
		ans=ans*(x.SS+1)%mod;
	}
	cout<<ans<<endl;
	fflush(stdout);
	return 0;
}