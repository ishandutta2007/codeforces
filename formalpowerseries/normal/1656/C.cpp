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
const int MOD=998244353;
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
int n,a[100005];
void Solve()
{
	n=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	for(int i=2;i<=n;++i)	if(a[i]^a[i-1])	goto fail;
	puts("yes");
	return ;
	fail:;
	for(int i=1;i<=n;++i)	if(a[i]==1)	{goto fail2;}
	puts("yes");
	return ;
	fail2:;
	sort(a+1,a+1+n);
	for(int i=1;i<n;++i)	if(a[i+1]-a[i]==1)	{puts("NO");return ;}
	puts("yes");
}
int main(){
	int T=read();
	while(T-->0)	Solve();
	return 0;
}