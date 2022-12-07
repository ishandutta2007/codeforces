#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 600005
#define int long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
const int mod=1000000007;
int fac[N+N],ifac[N+N],inv[N+N],mi[N+N];
char s[N],t[N];
int n,ans,sum[N];
int sa,ta,sb,tb,sq,tq,ls,lt;
int cnt,mu[N],p[N];
bool vis[N];
int C(int n,int m)
{
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void init()
{
	fac[0]=inv[0]=inv[1]=ifac[0]=mi[0]=1;
	for(int i=1;i<N+N;++i)
	{
		if(i>1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		mi[i]=(mi[i-1]+mi[i-1])%mod;
		fac[i]=1ll*fac[i-1]*i%mod;
		ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
	}
	mu[1]=1;
	for(int i=2;i<N;++i)
	{
		if(!vis[i])
		{
			p[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1,k;j<=cnt && (k=i*p[j])<N;++j)
		{
			vis[k]=1;
			if(i%p[j])mu[k]=-mu[i];
			else break;
		}
	}

}
main()
{
	init();
	scanf("%s%s",s+1,t+1);
	re(n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n/i;++j)
			sum[i]=(sum[i]+1ll*mu[j]*(n/i/j)*(n/i/j))%mod;
	ls=strlen(s+1);
	for(int i=1;i<=ls;++i)
		if(s[i]=='A')++sa;
		else if(s[i]=='B')++sb;
		else ++sq;
	lt=strlen(t+1);
		for(int i=1;i<=lt;++i)
			if(t[i]=='A')++ta;
			else if(t[i]=='B')++tb;
			else ++tq;
	bool same=(ls==lt);
	int xjb=0;
	if(same)
		for(int i=1;i<=ls;++i)
			if(s[i]==t[i])xjb+=s[i]=='?';
			else if(s[i]!='?'&&t[i]!='?')same=0;
	if(same)ans=1ll*(mi[n+1]-2)*(mi[n+1]-2)%mod*mi[xjb]%mod;
	int coprime=0;
	for(int i=1;i<=n;++i)
		coprime=(coprime+1ll*sum[i]*mi[i])%mod;
	for(int d=-tq;d<=sq;++d)
	{
		int f=C(sq+tq,tq+d);
		int x=sa-ta+d,y=sb-tb+sq-tq-d;
		if(same && x==0 && y==0)f=(f-mi[xjb]+mod)%mod;
		if(x==0 && y==0)ans=(ans+1ll*f*coprime)%mod;
		else if((x<0&&y>0)||(x>0&&y<0))ans=(ans+1ll*f*(mi[n/(max(abs(x),abs(y))/__gcd(abs(x),abs(y)))+1]-2))%mod;
	}
	printf("%lld\n",ans);
}