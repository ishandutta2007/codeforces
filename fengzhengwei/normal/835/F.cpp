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
void wts(int x,char c)
{
    if(x<0)pc('-',0),x=-x;
    wt(x),pc(c,0);
}
const int xx=4e5+5;
struct node{int next,to,v;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].v=z;
}

int n;
vector<int>cl;
int vs,stk[xx],vis[xx],top;
void findc(int x,int y)// 
{
	if(vs)return;
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		stk[++top]=i;
		if(vis[e[i].to])
		{
			vs=1;
			while(e[stk[top]^1].to!=e[i].to)cl.push_back(stk[top--]);
			cl.push_back(stk[top--]);
			return;
		}
		findc(e[i].to,x);
		top--;
		if(vs)return;
	}
}
int inc[xx];
namespace Gzj
{
	ll f[xx],dp[xx];//fdp 
	void dfs(int x,int y)
	{
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y||inc[e[i].to])continue;
			dfs(e[i].to,x);
			dp[x]=max(dp[x],f[x]+f[e[i].to]+e[i].v);
			dp[x]=max(dp[x],dp[e[i].to]);
			f[x]=max(f[x],f[e[i].to]+e[i].v);
		}
//		cout<<x<<" "<<dp[x]<<"\n";
	}
}
int val[xx],id[xx];
namespace seg
{
	struct nod{ll lmx,rmx,mx,sm;}e[xx<<2];//lmxrmx 
	// 
	nod upd(nod a,nod b,int mid)//mid 
	{
		nod c;
		c.sm=a.sm+b.sm+val[mid];
		c.lmx=max(a.lmx,b.lmx+val[mid]+a.sm);
		c.rmx=max(b.rmx,a.rmx+val[mid]+b.sm);
		c.mx=max(a.mx,max(b.mx,a.rmx+b.lmx+val[mid]));
		return c;
	}
	void build(int k,int l,int r)
	{
		if(l==r)return e[k].lmx=e[k].rmx=Gzj::f[id[l]],e[k].sm=0,e[k].mx=-1e18,void();
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		e[k]=upd(e[k<<1],e[k<<1|1],id[mid]);
	}
	nod ask(int k,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y)return e[k];
		int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return upd(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y),id[mid]);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read(),c=read();
		add(a,b,c),add(b,a,c);
	}
	findc(1,0);
	reverse(cl.begin(),cl.end());
//	exit(0);
	int sz=cl.size();
	for(auto it:cl)inc[e[it].to]=1,val[e[it^1].to]=e[it].v;
	for(int i=0;i<sz;i++)cl.push_back(cl[i]);
	for(int i=1;i<=sz+sz;i++)id[i]=e[cl[i-1]^1].to;
	for(int i=1;i<=sz;i++)Gzj::dfs(id[i],0);
	seg::build(1,1,sz+sz);
	ll mn=1e18,mx=-1e18;
//	for(int i=1;i<=sz+sz;i++)cout<<id[i]<<"\n";
	for(int i=1;i<=sz;i++)mx=max(mx,Gzj::dp[id[i]]);
	for(int i=1;i<=sz;i++)
		mn=min(mn,max(mx,seg::ask(1,1,sz+sz,i,i+sz-1).mx));
	cout<<mn<<"\n";
	pc('1',1);
    return 0;
}