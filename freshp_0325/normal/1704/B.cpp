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
LL n,x;
LL a[200005];
void Solve()
{
	n=read(),x=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	LL f=0,maxn=0,minn=1e9;
	for(LL i=1;i<=n;++i)
	{
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(maxn-minn>2*x)	++f,maxn=minn=a[i];
	}
	write(f),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}