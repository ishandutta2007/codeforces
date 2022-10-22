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
LL n,m;
LL a[100005],d[100005];
void Solve()
{
	n=read(),m=read();
	for(LL i=1;i<=m;++i)	a[i]=read();
	sort(a+1,a+1+m);
	a[m+1]=a[1]+n;
	for(LL i=1;i<=m;++i)	d[i]=a[i+1]-a[i]-1;
	sort(d+1,d+1+m,greater<>());
	LL ans=0;
	for(LL i=1;i<=m;++i)
	{
		ans+=max(0ll,d[i]-4*(i-1)-1);
		if(d[i]==4*(i-1)+1)	++ans;
	}
	write(n-ans),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}