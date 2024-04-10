#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const int MOD=1e9+7;
inline int Add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
inline int Sub(int x,int y){return x<y?x-y+MOD:x-y;}
inline int Mul(int x,int y){return 1ll*x*y%MOD;}
int QuickPow(int x,int p)
{
	int ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=Mul(ans,base);
		base=Mul(base,base);
		p>>=1;
	}
	return ans;
}
int fac[800005],ifac[800005];
inline int C(int n,int m){return n<m || m<0?0:Mul(fac[n],Mul(ifac[m],ifac[n-m]));}
int n,a[200005];
int main(){
	n=read();
	for(int i=0;i<=n;++i)	a[i]=read();
	fac[0]=1;
	for(int i=1;i<=800000;++i)	fac[i]=Mul(fac[i-1],i);
	ifac[800000]=QuickPow(fac[800000],MOD-2);
	for(int i=799999;~i;--i)	ifac[i]=Mul(ifac[i+1],i+1);
	int ans=0;
	for(int i=0;i<=n;++i)	ans=Add(ans,C(i+a[i],i+1));
	write(ans);
	return 0;
}