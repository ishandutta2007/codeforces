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
int p[505][505];
bool vis[250005];
void Solve()
{
	int n=read(),k=read();
	for(int i=1;i<=n*k;++i)	vis[i]=false;
	int a=1,b=2;
	for(int i=1;i<=n;++i)
	{
		if(i&1)	for(int j=1;j<=k;++j)	p[i][j]=a,a+=2;
		else	for(int j=1;j<=k;++j)	p[i][j]=b,b+=2;
	}
	for(int i=1;i<=n;++i)	for(int j=1;j<=k;++j)	if(p[i][j]>n*k){puts("No");return ;}else	vis[p[i][j]]=true;
	for(int i=1;i<=n*k;++i)	if(!vis[i])	{puts("No");return ;}
	puts("Yes");
	for(int i=1;i<=n;++i,puts(""))	for(int j=1;j<=k;++j)	write(p[i][j]),putchar(' ');
}
int main(){
	int T=read();
	while(T-->0)	Solve();
	return 0;
}