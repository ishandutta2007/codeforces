#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
ll n,m;
ll a[xx],x[xx],b[xx];
int lb(int x){return x&-x;}
int sum[xx];
void add(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
void ad(int x,int y){add(x,1),add(y+1,-1);}
int cr[xx];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=n;i++)if(x[i]<i)puts("No"),exit(0);
//	for(int i=1;i<=n;i++)if(x[i]<x[i-1])puts("No"),exit(0);
	
	for(int i=1;i<=n;i++)
	{
		ad(i+1,x[i]);
		cr[x[i]+1]=1;
	}
	for(int i=1;i<=n;i++)if(cr[i]&&ask(i))puts("No"),exit(0);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+m;
		if(ask(i))b[i-1]=a[i]+m;
		if(b[i]==b[i-1])b[i]++;
	}
	for(int i=1;i<=n;i++)
		if(cr[i]&&a[i]+m<=b[i-1])puts("No"),exit(0);
	puts("Yes");
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";puts("");
	pc('1',1);
	return 0;
}