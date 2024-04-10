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
const int mod=1000000007;
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
int L,n,m0,m1;
vector<int> v;
pair<int,int> s0[100111],s1[100111];
ll dp[2][400111],sum[2][400111];
int getid(int x){return upper_bound(v.begin(),v.end(),x)-v.begin();}
ll calc()
{
	int it0=1,it1=1,mx0=0,mx1=0;
	sum[0][0]=sum[1][0]=1;
	for(int i=1;i<=n;i++)
	{
		while(it0<=m0&&s0[it0].FF<=i)mx0=max(mx0,s0[it0++].SS);
		while(it1<=m1&&s1[it1].FF<=i)mx1=max(mx1,s1[it1++].SS);
		if(mx0<i)dp[0][i]=(sum[1][i-1]-(mx0==0?0:sum[1][mx0-1])+mod)%mod;
		if(mx1<i)dp[1][i]=(sum[0][i-1]-(mx1==0?0:sum[0][mx1-1])+mod)%mod;
		int l=v[i]-v[i-1];
		ll c=qpow(2,l-1)-1+mod;
		sum[0][i]=((c+1)*dp[0][i]+c*dp[1][i]+sum[0][i-1])%mod;
		sum[1][i]=(c*dp[0][i]+(c+1)*dp[1][i]+sum[1][i-1])%mod;
		if(i==n)return ((c+1)*(dp[0][i]+dp[1][i])%mod+mod)%mod;
	}
	return 1;
}
int main()
{
	v.PB(1);
	getiii(L,m0,m1);
	v.PB(L+1);
	for(int i=1;i<=m0;i++)
	{
		int l,r;
		getii(l,r);
		v.PB(l);
		v.PB(r);
		s0[i]=MP(r,l);
	}
	for(int i=1;i<=m1;i++)
	{
		int l,r;
		getii(l,r);
		v.PB(l);
		v.PB(r);
		s1[i]=MP(r,l);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	sort(s0+1,s0+m0+1);
	sort(s1+1,s1+m1+1);
	for(int i=1;i<=m0;i++)s0[i]=MP(getid(s0[i].FF),getid(s0[i].SS));
	for(int i=1;i<=m1;i++)s1[i]=MP(getid(s1[i].FF),getid(s1[i].SS));
	n=v.size()-1;
	putsi(calc());
	return 0;
}