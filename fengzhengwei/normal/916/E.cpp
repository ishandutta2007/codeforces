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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int n,m;
const int xx=1e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int dep[xx],f[xx][20],son[xx],dfx[xx],top[xx],size[xx],id[xx],a[xx],cst;
void dfs(int x,int y)
{
	dep[x]=dep[y]+1;f[x][0]=y;size[x]=1;
	for(int i=1;i<20;i++)f[x][i]=f[f[x][i-1]][i-1];
	int mx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>mx)mx=size[e[i].to],son[x]=e[i].to;
	}
}
void dfss(int x,int y)
{
	dfx[x]=++cst;top[x]=y;id[cst]=x;
	if(son[x])dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x][0]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]][0];
	}
	return dep[x]<dep[y]?x:y;
}
ll sum[xx<<2],adt[xx<<2];
void build(int k,int l,int r)
{
	if(l==r)return sum[k]=a[id[l]],void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
void ad(int k,int l,int r,ll z)
{
	sum[k]+=1ll*(r-l+1)*z;
	adt[k]+=z;
}
void pd(int k,int l,int r)
{
	if(adt[k])
	{
		int mid=l+r>>1;
		ad(k<<1,l,mid,adt[k]);
		ad(k<<1|1,mid+1,r,adt[k]);
		adt[k]=0;
	}
}
void cg(int k,int l,int r,int x,int y,ll z)
{
	if(x<=l&&r<=y)return ad(k,l,r,z);
	pd(k,l,r);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
ll ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return sum[k];
	pd(k,l,r);
	int mid=l+r>>1;
	ll ans=0;
	if(x<=mid)ans+=ask(k<<1,l,mid,x,y);
	if(mid<y)ans+=ask(k<<1|1,mid+1,r,x,y);
	return ans;
}
bool in(int a,int b){return dfx[a]<dfx[b]&&dfx[b]<dfx[a]+size[a];}
bool cmp(int a,int b){return dep[a]>dep[b];}
int jp(int a,int b){while(dep[a]!=dep[b]+1)a=f[a][(int)log2(dep[a]-(dep[b]+1))];return a;}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0);dfss(1,1);
	build(1,1,n);
	int rt=1;
	while(m--)
	{
		int op=read();
		if(op==1)rt=read();
		if(op==2)
		{
			int u=read(),v=read(),x=read(),L;
			int a=lca(u,rt),b=lca(v,rt),c=lca(u,v);
			if(cmp(b,a))swap(a,b);
			if(cmp(c,a))swap(a,c);
			L=a;
			if(L==rt)cg(1,1,n,1,n,x);
			else if(in(rt,L)||lca(rt,L)!=L)cg(1,1,n,dfx[L],dfx[L]+size[L]-1,x);
			else 
			{
				int y=jp(rt,L);
				cg(1,1,n,1,n,x),cg(1,1,n,dfx[y],dfx[y]+size[y]-1,-x);
			}
		}
		if(op==3)
		{
			int u=read();
			if(u==rt)cout<<ask(1,1,n,1,n)<<"\n";
			else if(in(rt,u)||lca(rt,u)!=u)cout<<ask(1,1,n,dfx[u],dfx[u]+size[u]-1)<<"\n";
			else 
			{
				int y=jp(rt,u);
				cout<<ask(1,1,n,1,n)-ask(1,1,n,dfx[y],dfx[y]+size[y]-1)<<"\n";
			}
		}
	}
	pc('1',1);
	return 0;
}