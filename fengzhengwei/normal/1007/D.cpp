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
int n;
namespace tj
{
	const int xx=1.6e7+5;
	struct node{int next,to;}e[xx<<1];
	int cnt,h[xx],tt;
	void add(int x,int y){if(!y)return;cnt++;e[cnt]={h[x],y};h[x]=cnt;}
//	void ad(int x,int y){add(x,y),add(y,x);}
	int dfn[xx],low[xx],stk[xx],vis[xx],bel[xx],bcc,top,cst;
	void tj(int x)
	{
		dfn[x]=low[x]=++cst;stk[++top]=x,vis[x]=1;
		for(int i=h[x];i;i=e[i].next)
		{
			if(!dfn[e[i].to])tj(e[i].to),low[x]=min(low[x],low[e[i].to]);
			else if(vis[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
		}
		if(dfn[x]==low[x])
		{
			bcc++;
			while(stk[top]!=x)bel[stk[top]]=bcc,vis[stk[top--]]=0;
			bel[stk[top]]=bcc,vis[stk[top--]]=0;
		}
	}
	int to[xx],vs[xx];
	void check(vector<pair<int,int> >&v)
	{
		for(int i=1;i<=tt;i++)if(!dfn[i])tj(i);
		for(auto it:v)
			if(bel[it.first]==bel[it.second])puts("NO"),exit(0);
		puts("YES");
		for(auto it:v)to[bel[it.first]]=bel[it.second],to[bel[it.second]]=bel[it.first];
		for(int i=1;i<=bcc;i++)
			if(!vs[i])vs[i]=1,vs[to[i]]=2;
		for(auto it:v)
		{
			if(vs[bel[it.first]]==1)cout<<1<<"\n";
			else cout<<2<<"\n";
		}
		return;
	}
}
const int xx=1e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
int size[xx],f[xx],son[xx],dep[xx],top[xx],dfx[xx];
void dfs(int x,int y)
{
	int mx=-1;
	size[x]=1,f[x]=y,dep[x]=dep[y]+1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);size[x]+=size[e[i].to];
		if(size[e[i].to]>mx)mx=size[e[i].to],son[x]=e[i].to;
	}
}
int cst;
void dfss(int x,int y)
{
	top[x]=y;dfx[x]=++cst;
	if(!son[x])return;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=son[x]&&e[i].to!=f[x])dfss(e[i].to,e[i].to);
}
/// 
int id[xx<<2],tag[xx<<2];
void build(int k,int l,int r)
{
	id[k]=tag[k]=0;
	if(l==r)return ;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void cg(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return;
	if(x<=l&&r<=y)
	{
		++tj::tt;
		tj::add(tj::tt,tag[k]);
		tag[k]=tj::tt,tj::add(tag[k],z);
		++tj::tt;
		tj::add(tj::tt,id[k]);
		tj::add(tj::tt,z);
		id[k]=tj::tt; 
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	++tj::tt;
	tj::add(tj::tt,id[k<<1]);
	tj::add(tj::tt,id[k<<1|1]);
	tj::add(tj::tt,tag[k]);
	id[k]=tj::tt;
}
void lk(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return;
	tj::add(z,tag[k]); 
	if(x<=l&&r<=y)return tj::add(z,id[k]);
	int mid=l+r>>1;
	if(x<=mid)lk(k<<1,l,mid,x,y,z);
	if(mid<y)lk(k<<1|1,mid+1,r,x,y,z);
}
int idu[xx],idv[xx],ua[xx],va[xx],ub[xx],vb[xx];
void jump1(int x,int y,int z)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		cg(1,1,n,dfx[top[x]],dfx[x],z);
		x=f[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	cg(1,1,n,dfx[y]+1,dfx[x],z);
}
void jump(int x,int y,int z)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		lk(1,1,n,dfx[top[x]],dfx[x],z);
		x=f[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	lk(1,1,n,dfx[y]+1,dfx[x],z);
}
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0),dfss(1,1);
	build(1,1,n);
	int m=read();
	for(int i=1;i<=m;i++)
	{
		ua[i]=read(),va[i]=read();
		ub[i]=read(),vb[i]=read();
		idu[i]=++tj::tt,idv[i]=++tj::tt;
	}
	for(int i=1;i<=m;i++)
	{
		jump(ua[i],va[i],idu[i]);
		jump1(ua[i],va[i],idv[i]);
		
		jump(ub[i],vb[i],idv[i]);
		jump1(ub[i],vb[i],idu[i]);
	}
	build(1,1,n);
	for(int i=m;i>=1;i--)
	{
		jump(ua[i],va[i],idu[i]);
		jump1(ua[i],va[i],idv[i]);
		
		jump(ub[i],vb[i],idv[i]);
		jump1(ub[i],vb[i],idu[i]);
	}
	vector<pair<int,int> >v;
	for(int i=1;i<=m;i++)v.push_back(make_pair(idu[i],idv[i]));
	tj::check(v);
	pc('1',1);
	return 0;
}