#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')	f=(c=='-'?-1:f),c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
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
map<int,int> M;
int n,a[200005],k;
void Solve()
{
	M.clear();
	n=read(),k=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	for(int i=1;i<=n;++i)	M[a[i]]=1;
	for(int i=1;i<=n;++i)
	{
		if(M[a[i]+k])
		{
			puts("yes");
			return ;
		}
	}puts("NO");
}
int main(){
	int T=read();
	while(T-->0)	Solve();
	return 0;
}