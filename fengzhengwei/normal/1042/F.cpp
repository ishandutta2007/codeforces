#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=1000005;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx],ds[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[xx],g[xx],n,k;//f ()
void dfs(int x,int y)
{
	int vs=1;g[x]=1e9;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		f[x]+=f[e[i].to];
		if(g[e[i].to]+1+g[x]<=k)f[x]--,g[x]=max(g[x],g[e[i].to]+1);
		else g[x]=min(g[x],g[e[i].to]+1);
		vs=0;
	}
	if(vs)f[x]=1,g[x]=0;
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
		ds[a]++,ds[b]++;
	}
	int rt=0;
	for(int i=1;i<=n;i++)if(ds[i]>1)rt=i;
	dfs(rt,0);
	cout<<f[rt]<<'\n';
	return 0;
}