#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
const LL MOD=1e9+7;
LL QuickPow(LL x,LL p)
{
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=(ans*base)%MOD;
		base=(base*base)%MOD;
		p>>=1;
	}
	return ans;
}
LL fac[3000016],ifac[3000016],st[3000016][4];
LL n,q;
int main(){
	n=read(),q=read();
	fac[0]=1;
	for(LL i=1;i<=3000015;++i)	fac[i]=fac[i-1]*i%MOD;
	ifac[3000015]=QuickPow(fac[3000015],MOD-2);
	for(LL i=3000014;~i;--i)	ifac[i]=ifac[i+1]*(i+1)%MOD;
	st[1][1]=(3*n-1)*n%MOD*ifac[2]%MOD;
	st[1][2]=(3*n+1)*n%MOD*ifac[2]%MOD;
	st[1][3]=(3*n+3)*n%MOD*ifac[2]%MOD;
	for(LL i=2;i<=3*n;++i)
	{
		LL st1=i*st[i-1][1]%MOD,st2=i*st[i-1][2]%MOD,tmp=fac[3*n+1]*ifac[3*n-i]%MOD*ifac[i+1]%MOD*fac[i]%MOD;
		st[i][1]=(tmp+MOD-st1+MOD-st1+MOD-st2)*ifac[3]%MOD*2%MOD;
		st[i][2]=(st[i][1]+st1)%MOD;
		st[i][3]=(st[i][2]+st2)%MOD;
	}
	while(q-->0)
	{
		LL x=read();
		write(st[x][3]*ifac[x]%MOD),puts("");
	}
	return 0;
}