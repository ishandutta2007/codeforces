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
struct node{
	LL x,id;
	node(LL X=0,LL I=0){x=X,id=I;}
	bool operator < (node ano) const {return x<ano.x;}
}a[100005];
LL n,m;
void Solve()
{
	n=read(),m=read();
	for(LL i=1;i<=n;++i)
	{
		LL w=0;
		for(LL j=1;j<=m;++j)	w+=j*read();
		a[i]=node(w,i);
	}
	sort(a+1,a+1+n);
	write(a[n].id),putchar(' '),write(a[n].x-a[n-1].x),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}