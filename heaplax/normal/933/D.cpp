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
#define N 1000001
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
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
int n,ans,m2[N],m4[N],m6[N],p2[N],p4[N],p6[N];
int mi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
main()
{
	re(n);
	for(int i=1;i<N;++i)
	{
		m2[i]=i*i%mod;
		m4[i]=m2[i]*m2[i]%mod;
		m6[i]=m2[i]*m4[i]%mod;
		p2[i]=(m2[i]+p2[i-1])%mod;
		p4[i]=(m4[i]+p4[i-1])%mod;
		p6[i]=(m6[i]+p6[i-1])%mod;
	}
	for(int x=0;x*x<=n;++x)
	{
		int y=sqrt(n-x*x);
		int res=0,x2=mi(x,2),x4=mi(x,4),x6=mi(x,6);
		res+=n%mod*((n+1)%mod)%mod*((n+2)%mod)%mod;
		res+=2*x6%mod;
		res-=3*(n+2)%mod*x4%mod;
		res+=(3*n+4)%mod*x2%mod;
		ans+=res%mod*(2*y%mod+1)%mod;
		ans+=4*p6[y]%mod;
		ans+=12*(x2*p4[y]%mod+x4*p2[y]%mod)%mod;
		ans-=12*(n+2)%mod*x2%mod*p2[y]%mod;
		ans-=6*(n+2)%mod*p4[y]%mod;
		ans+=2*(3*n+4)%mod*p2[y]%mod;
		ans%=mod;
		if(x==0)ans=ans*mi(2,mod-2)%mod;
	}
	ans=ans%mod*2%mod;
	ans=(ans*mi(6,mod-2)%mod+mod)%mod;
	printf("%lld\n",ans);
}