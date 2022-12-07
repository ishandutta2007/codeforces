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
#define N 100001
#define INF 0x3f3f3f3f
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
int n,q,a[N],e[N],ie[N],s[N],f[N][17],g[N][17];
int main()
{
	re(n),re(q);
	e[0]=ie[0]=1;
	for(int i=1;i<=n;++i)
	{
		re(a[i]);
		e[i]=e[i-1]*2%mod;
		ie[i]=ie[i-1]*(mod+1ll)/2%mod;
		s[i]=(s[i-1]+1ll*e[i]*a[i])%mod;
	}
	for(int i=1;i<=n;++i)
	{
		long long now=0;
		for(int j=i;j;--j)
		{
			now=(now+a[j])*2;
			if(now<=0)
			{
				f[i][0]=j-1;
				g[i][0]=(now%mod+mod)%mod;
				break;
			}
			if(now>2e9)
			{
				f[i][0]=-1;
				break;
			}
		}
	}
	for(int i=1;i<=16;++i)
		for(int j=1;j<=n;++j)
			if(!~f[j][i-1])
				f[j][i]=-1;
			else 
			{
				f[j][i]=f[f[j][i-1]][i-1];
				g[j][i]=(g[j][i-1]+g[f[j][i-1]][i-1])%mod;
			}
	for(int l,r;q--;)
	{
		re(l),re(r);
		int ans=0;
		for(int i=16;i>=0;--i)
			if(f[r][i]>l)
			{
				ans=(ans+g[r][i])%mod;
				r=f[r][i];	
			}	
		ans=((ans+1ll*(s[r]-s[l-1])*ie[l])%mod+mod)%mod;
		printf("%d\n",ans);
	}
}