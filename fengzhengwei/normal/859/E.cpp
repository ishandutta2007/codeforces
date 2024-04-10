#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
const int xx=2e5+5;
int n;
struct node{int next,to;}e[xx<<1];
int cnt=1,h[xx],rc[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int tt=0;
void dfs(int x)
{
	rc[x]=1;tt++;
	for(int i=h[x];i;i=e[i].next)
	{
		if(rc[e[i].to])continue;
		dfs(e[i].to);
	}
}
int vis[xx],cr,cr1;
void fc(int x,int y)//findcircle 
{
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(i==(y^1))continue;
		if(vis[e[i].to])
		{
			cr=1;
			if(e[i].to==x)cr1=1;
		}
		else fc(e[i].to,i);
	}
}
const int mod=1e9+7;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read();
//		if(a==b)continue;
		add(a,b),add(b,a);
	}
	ll ans=1;
	for(int i=1;i<=n+n;i++)
	{
		if(!rc[i])
		{
			tt=0;
			dfs(i);
			if(tt==1)continue;
			cr=0;cr1=0;
			fc(i,0);
			if(cr)
			{
				if(!cr1)
				ans*=2,ans%=mod;
			}
			else ans*=tt,ans%=mod;
		}
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}