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
int n,K,m;
char s[2000111];
int pre[2000111],last[26];
ll dp[2000111],sum[2000111];
int main()
{
	scanf("%d%d",&m,&K);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=last[s[i]-'a'];
		last[s[i]-'a']=i;
	}
	for(int i=n+1;i<=n+m;i++)
	{
		int mn=0;
		pre[i]=last[0];
		for(int j=0;j<K;j++)
		{
			if(last[j]<pre[i])
			{
				mn=j;
				pre[i]=last[j];
			}
		}
		last[mn]=i;
	}
	dp[0]=sum[0]=1;
	ll ans=1;
	for(int i=1;i<=n+m;i++)
	{
		dp[i]=sum[i-1];
		if(pre[i]>0)dp[i]=(dp[i]-sum[pre[i]-1]+mod)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
		ans=(ans+dp[i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}