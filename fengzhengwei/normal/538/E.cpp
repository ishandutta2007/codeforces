#include<bits/stdc++.h>
#define ll long long
#define dd double
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
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int n,num,cr[xx];
void gnum(int x,int y)
{
	int vs=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		gnum(e[i].to,x);
		vs=0;
	}
	num+=vs;
	cr[x]=vs;
}
//dep=1 
int f[xx];
//11 
void dp(int x,int y,int dep)
{
	if(cr[x])return f[x]=1,void();
	int mn=1e9,sum=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dp(e[i].to,x,dep^1);
		sum+=f[e[i].to];
		mn=min(mn,f[e[i].to]);
	}
	if(dep&1)f[x]=mn;
	else f[x]=sum;
}
bool check1(int mid)//1>=mid 
{
	dp(1,0,1);
	return f[1]<=n-mid+1;
}
bool check2(int mid)//11<=mid 
{
	dp(1,0,0);
	return f[1]<=mid;
}
signed main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	gnum(1,0);
	// 
	dp(1,0,1);
//	for(int i=1;i<=n;i++)cout<<i<<" "<<f[i]<<"!!#$@\n";
	cout<<num+1-f[1]<<" ";
	dp(1,0,0);
	cout<<f[1]<<"\n";
//	int l=1,r=num,ans=0;
//	while(l<=r)
//	{
//		int mid=l+r>>1;
//		if(check1(mid))ans=mid,l=mid+1;
//		else r=mid-1;
//	}
//	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}