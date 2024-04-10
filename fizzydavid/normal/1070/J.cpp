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
const int maxn=200111;
int Tn;
int n,m,K;
int cnt[26];
int dp[maxn];
void add(int c)
{
	if(c==0)return;
	for(int i=K-c;i>=0;i--)dp[i+c]+=dp[i];
}
void del(int c)
{
	if(c==0)return;
	for(int i=0;i<=K-c;i++)dp[i+c]-=dp[i];
}
int main()
{
	geti(Tn);
	while(Tn--)
	{
		getiii(n,m,K);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=K;i++)
		{
			char c=getreal();
			cnt[c-'A']++;
		}
		for(int i=0;i<=K;i++)dp[i]=0;
		dp[0]=1;
		for(int i=0;i<26;i++)add(cnt[i]);
//		for(int j=0;j<=K;j++)cerr<<dp[j]<<" ";cerr<<endl;
		ll ans=1e18;
		for(int i=0;i<26;i++)
		{
			del(cnt[i]);
//			for(int j=0;j<=K;j++)cerr<<dp[j]<<" ";cerr<<endl;
			for(int j=0;j<=K;j++)
			{
				if(dp[j])
				{
					int x=j,y=K-cnt[i]-x;
					int xl=max(0,n-x);
					int yl=max(0,m-y);
					if(xl+yl>cnt[i])continue;
					ans=min(ans,1ll*xl*yl);
				}
			}
			add(cnt[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}