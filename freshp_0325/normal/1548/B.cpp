#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
LL gcd(LL a,LL b){return !b?a:gcd(b,a%b);}
LL a[200005],p[200005];
LL n;
LL Abs(LL x){return x<0?-x:x;}
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define Mm LL mid=(l+r)>>1
LL tr[800005];
void build(LL l,LL r,LL now)
{
	if(l==r)
	{
		tr[now]=p[l];
		return ;
	}Mm;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
	tr[now]=gcd(tr[lc(now)],tr[rc(now)]);
}
LL query(LL l,LL r,LL now,LL x,LL y)
{
	if(x<=l && r<=y)	return tr[now];
	Mm,ans=0;
	if(x<=mid)	ans=gcd(ans,query(l,mid,lc(now),x,y));
	if(mid<y)	ans=gcd(ans,query(mid+1,r,rc(now),x,y));
	return ans;
}
int main(){
	LL T=read();
	while(T-->0)
	{
		n=read();
		for(LL i=1;i<=n;++i)	a[i]=read();
		if(n==1)
		{
			puts("1");
			continue;
		}
		for(LL i=1;i<n;++i)	p[i]=Abs(a[i+1]-a[i]);
		--n;
		build(1,n,1);
		LL ans=0,l=1,r;
		for(r=1;r<=n;++r)
		{
			while(l<=r && query(1,n,1,l,r)==1)	++l;
			ans=max(ans,r-l+1);
		}
		write(ans+1);puts("");
	}
	return 0;
}