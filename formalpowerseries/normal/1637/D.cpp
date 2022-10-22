#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const LL MOD=998244353;
inline LL Add(LL x,LL y){return x+y>=MOD?x+y-MOD:x+y;}
inline LL Sub(LL x,LL y){return x<y?x-y+MOD:x-y;}
inline LL Mul(LL x,LL y){return 1ll*x*y%MOD;}
LL QuickPow(LL x,LL p)
{
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=Mul(ans,base);
		base=Mul(base,base);
		p>>=1;
	}
	return ans;
}
LL n,a[105],b[105],sum[105],dp[105][10005];
void Solve()
{
	n=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	for(LL i=1;i<=n;++i)	b[i]=read();
	memset(sum,0,sizeof sum);
	for(LL i=n;i;--i)	sum[i]=sum[i+1]+a[i]+b[i];
	memset(dp,63,sizeof dp);
	dp[n+1][0]=0;
	for(LL i=n;i;--i)
	{
		for(LL j=0;j<=10000;++j)
		{
			dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i+1][j]+a[i]*j+b[i]*(sum[i+1]-j));
			dp[i][j+b[i]]=min(dp[i][j+b[i]],dp[i+1][j]+b[i]*j+a[i]*(sum[i+1]-j));
		}
	}
	LL ans=0;
	for(LL i=1;i<=n;++i)	ans+=(a[i]*a[i]+b[i]*b[i])*(n-1);
	LL minn=2e18;
	for(LL i=0;i<=10000;++i)	minn=min(minn,dp[1][i]);
	write(minn*2+ans),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}