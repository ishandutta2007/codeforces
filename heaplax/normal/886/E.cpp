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
#define LL long long
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
int n,m,fac[N],ans,f[N],g[N],inv[N],ifac[N];
int main()
{
	re(n),re(m);
	fac[0]=inv[0]=ifac[0]=inv[1]=1;
	for(int i=1;i<=n;++i)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		if(i>1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
	}
	f[1]=g[1]=1;
	for(int i=2;i<=n;++i)
	{
		f[i]=1ll*(g[i-1]-g[max(0,i-m-1)])*fac[i-2]%mod;
		g[i]=(g[i-1]+1ll*f[i]*ifac[i-1])%mod;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=(ans+1ll*f[i]*fac[n-1]%mod*ifac[i-1])%mod;
	ans=(ans+mod)%mod;
	ans=(fac[n]-ans+mod)%mod;
	printf("%d\n",ans);	
}