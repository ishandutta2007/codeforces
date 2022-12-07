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
int n,a,b,ans,inv,ea,eb,f[1005][2001];
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
int main()
{
	re(n),re(a),re(b);
	inv=mi((a+b)%mod,mod-2);
	ea=1ll*a*inv%mod;
	eb=1ll*b*inv%mod;
	f[1][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<n;++j)
		{
			f[i+1][j]=(f[i+1][j]+1ll*f[i][j]*ea)%mod;
			f[i][i+j]=(f[i][i+j]+1ll*f[i][j]*eb)%mod;
		}
	for(int i=1;i<=n;++i)
		for(int j=n;j<=n+n;++j)
			ans=(ans+1ll*f[i][j]*j)%mod;
	for(int i=0;i<n;++i)
	{
		int S=(i+n+1)%mod;
		ans=(ans+1ll*f[n+1][i]*(1ll*S*ea%mod-ea-S)%mod*mi(ea-1,mod-2))%mod;
	}
	printf("%d\n",(ans+mod)%mod);
}