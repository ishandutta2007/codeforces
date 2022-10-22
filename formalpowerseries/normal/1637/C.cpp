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
// LL!!
LL n,a[100005];
void Solve()
{
	n=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	if(n==3 && (a[2]&1))	return void(puts("-1"));
	for(LL i=2;i<n;++i)	if(a[i]!=1)	goto haha;
	puts("-1");
	return ;
	haha:;
	LL ans=0;
	for(LL i=2;i<n;++i)	ans+=(a[i]+1)/2;
	write(ans),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}