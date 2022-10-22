#include<bits/stdc++.h>
using namespace std;
typedef __int128 LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')	f=(c=='-'?-1:f),c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(LL x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
LL n,a[200005];
void Solve()
{
	n=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	sort(a+1,a+1+n);
	int d=1;
	LL s=a[1]*(n-1);
	for(LL i=2;i<=n;++i)	s+=a[i];
	if(s>0)	return void(puts("INF"));
	for(LL i=2;i<n;++i)
	{
		s=s-a[1]+a[n];
		if(s<0)	d=i;
	}
//	s=s-a[1]+a[n];
	if(s<0)	return void(puts("INF"));
	LL ans=0;
	for(LL i=1;i<=d;++i)	ans+=a[i]*a[n]-a[d+1]*(a[i]+a[n]);
	for(LL i=d+1;i<n;++i)	ans+=a[1]*a[i]-a[d+1]*(a[1]+a[i]);
	write(ans),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}