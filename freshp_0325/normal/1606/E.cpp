#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
char buf[1<<21],*p1=buf,*p2=buf;
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
LL QuickPow(LL x,LL p)
{
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=ans*base%MOD;
		base=base*base%MOD;
		p>>=1;
	}
	return ans;
}
LL fac[505],ifac[505];
LL C(LL n,LL m){return (n<m || m<0)?0:fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;}
LL n,x,dp[505][505];
int main(){
	n=read(),x=read();
	fac[0]=1;
	for(LL i=1;i<=500;++i)	fac[i]=fac[i-1]*i%MOD;
	ifac[500]=QuickPow(fac[500],MOD-2);
	for(LL i=499;~i;--i)	ifac[i]=ifac[i+1]*(i+1)%MOD;
	for(LL i=1;i<=x;++i)	dp[2][i]=i;
	for(LL i=3;i<=n;++i)
	{
		for(LL j=1;j<=x;++j)
		{
			if(i>j)	dp[i][j]=QuickPow(j,i);
			else
			{
				dp[i][j]=dp[i][i-1];
				for(LL k=0;k<=i-2;++k)
					dp[i][j]=(dp[i][j]+C(i,k)*dp[i-k][j-i+1]%MOD*QuickPow(i-1,k)%MOD)%MOD;
			}
		}
	}
	write(dp[n][x]);
	return 0;
}
/*
dp i,j: left i heroes. max is j.

initialize: for all i: dp 2,i = i

movement?

i>j: dp i,j = j^i
i<=j: dp i,j = dp i,i-1 + sum k=1 C(i,k) * dp i-k,j-i+1 * (i-1)^k 
*/