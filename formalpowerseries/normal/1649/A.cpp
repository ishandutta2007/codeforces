/*

DONT NEVER AROUND . //
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
const int MOD=998244353;
inline int Add(int u,int v){return u+v>=MOD?u+v-MOD:u+v;}
inline int Sub(int u,int v){return u-v>=0?u-v:u-v+MOD;}
inline int Mul(int u,int v){return LL(u)*LL(v)%MOD;}
int QuickPow(int x,int p)
{
	if(p<0)	p+=MOD-1;
	int ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=Mul(ans,base);
		base=Mul(base,base);
		p>>=1;
	}
	return ans;
}
int a[105],n;
void Solve()
{
	n=read();
	int x=0;
	for(int i=1;i<=n;++i)	x+=(a[i]=read());
	if(x==n)
	{
		puts("0");
		return ;
	}
	int sum=n+1;
	for(int i=1;i<=n;++i)
	{
		if(!a[i])	break;
		--sum;
	}
	for(int i=n;i;--i)
	{
		if(!a[i])	break;
		--sum;
	}
	write(sum),puts("");
}
int main(){
	int T=read();
	while(T-->0)	Solve();
	return 0;
}