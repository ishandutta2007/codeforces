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
#define N 2001
#define LL long long
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
const int mod=998244353;
int n,a,b,p,f[N],g[N][N],st[N],mp[N],mq[N];
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
	re(n);re(a);re(b);
	p=1ll*a*mi(b,mod-2)%mod;
	mp[0]=mq[0]=1;
	for(int i=1;i<=n;++i)
	{
		mp[i]=1ll*mp[i-1]*p%mod;
		mq[i]=1ll*mq[i-1]*(1-p)%mod;
		st[i]=g[i][0]=g[i][i]=1;
		for(int j=1;j<i;++j)
		{
			g[i][j]=(1ll*g[i-1][j]*mq[j]+1ll*g[i-1][j-1]*mp[i-j])%mod;
			st[i]=(st[i]-1ll*st[j]*g[i][j])%mod;
			f[i]=(f[i]+(1ll*j*(i-j)+j*(j-1ll)/2+f[j]+f[i-j])%mod*st[j]%mod*g[i][j])%mod;
		}
		f[i]=(f[i]+i*(i-1ll)/2%mod*st[i])%mod*mi(1-st[i],mod-2)%mod;
	}
	printf("%d\n",(f[n]+mod)%mod);
}