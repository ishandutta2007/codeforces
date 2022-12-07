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
#define N 5001
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
int n,k,ans,a[N],f[N];
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
int xjm(int n,int m)
{
	int res=1;
	for(int i=n;i>=n-m+1;--i)
		res=1ll*res*i%mod;
	return res;
}
int main()
{
	re(n),re(k);
	f[0]=1;
	for(int i=1;i<=n;++i)
	{
		re(a[i]);
		for(int j=i;j;--j)
			f[j]=(1ll*f[j]*a[i]-f[j-1])%mod;
		f[0]=1ll*f[0]*a[i]%mod;
	}
	ans=f[0];
	for(int i=0;i<=n;++i)
		ans=(ans-1ll*f[i]*mi(mi(n,i),mod-2)%mod*xjm(k,i))%mod;
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
}