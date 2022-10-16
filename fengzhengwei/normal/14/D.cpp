#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int mod=1e9+7,xx=1e5+5;
int n;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
struct nod{int f[2];}f[xx];
void init(nod &a){a.f[0]=a.f[1]=0;}
nod merge(nod a,nod b)
{
	a.f[1]=max(a.f[1],a.f[0]+b.f[0]+1);
	a.f[0]=max(a.f[0],b.f[0]+1);
	a.f[1]=max(a.f[1],b.f[1]);
	a.f[1]=max(a.f[1],a.f[0]);
	return a;
}
nod merge2(nod a,nod b)
{
	a.f[1]=max(a.f[1],a.f[0]+b.f[0]);
	a.f[0]=max(a.f[0],b.f[0]);
	a.f[1]=max(a.f[1],b.f[1]);
	a.f[1]=max(a.f[1],a.f[0]);
	return a;
}
void dp(int x,int y){for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)dp(e[i].to,x),f[x]=merge(f[x],f[e[i].to]);}
nod fa[xx],pre[xx],suf[xx];
ll ans;
void dfs(int x,int y)
{
	vector<int>v;
	ans=max(ans,1ll*f[x].f[1]*fa[x].f[1]);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		v.push_back(e[i].to);
	}
	for(int i=0;i<v.size();i++)
	{
		init(pre[i]);
		if(i)pre[i]=pre[i-1];
		pre[i]=merge(pre[i],f[v[i]]);
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		init(suf[i]);
		if(i!=v.size()-1)suf[i]=suf[i+1];
		suf[i]=merge(suf[i],f[v[i]]);
	}
	for(int i=0;i<v.size();i++)
	{
		nod now;
		if(!i&&i==v.size()-1)init(now);
		else if(i&&i==v.size()-1)now=pre[i-1];
		else if(!i&&i!=v.size()-1)now=suf[i+1];
		else now=merge2(pre[i-1],suf[i+1]);
		if(x!=1)now=merge(now,fa[x]);
		fa[v[i]]=now;
	}
	for(auto it:v)dfs(it,x);
}
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dp(1,0);
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}