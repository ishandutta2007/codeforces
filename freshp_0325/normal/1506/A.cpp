#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
typedef long long LL;
typedef pair<LL,LL> P;
#define mp make_pair
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
void Solve()
{
	LL n=read(),m=read(),x=read();
	LL X=(x+n-1)/n,Y=x%n==0?n:x%n;
	swap(X,Y);
	write((X-1)*m+Y),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}