#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
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
LL n,k;
void Solve()
{
	n=read(),k=read();
	LL pb=1,ans=0;
	while(pb<min(n,k))	++ans,pb*=2;
	ans+=(n+k-1-pb)/k;
	write(ans),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}