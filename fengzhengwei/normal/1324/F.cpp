#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int xx=2e5+5;
int n,a[xx];
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[xx];
void dfs(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		f[x]+=max(0,f[e[i].to]);
	}
	f[x]+=a[x];
}
int ans[xx],g[xx];
void dfss(int x,int y)
{
	ans[x]=f[x]+max(0,g[x]);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		g[e[i].to]=ans[x]-max(0,f[e[i].to]);
		dfss(e[i].to,x);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=!read()?-1:1;//0-1 
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0);
	dfss(1,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";puts("");
	return 0;
}