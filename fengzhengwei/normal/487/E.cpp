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
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
//vector  
struct node{int next,to;}e[xx<<1];
int cs,h[xx];
void add(int x,int y)
{
	cs++;
	e[cs].next=h[x];
	h[x]=cs;
	e[cs].to=y;
}
vector<int>v[xx];
int n,m,q;
int dfn[xx],low[xx],stk[xx],tp,cnt,cst;
void tj(int x)
{
	dfn[x]=low[x]=++cst,stk[++tp]=x;
	for(auto to:v[x])
	{
		if(!dfn[to])
		{
			tj(to),low[x]=min(low[x],low[to]);
			if(low[to]>=dfn[x])
			{
				cnt++;
				while(stk[tp]!=to)add(cnt,stk[tp]),add(stk[tp],cnt),tp--;
				add(cnt,stk[tp]),add(stk[tp],cnt),tp--;
				add(cnt,x),add(x,cnt);
			}
		}
		else low[x]=min(low[x],dfn[to]);
	}
}
int size[xx],son[xx],f[xx],top[xx],dfx[xx],dep[xx],id[xx],val[xx];
void dfs(int x,int y)
{
	size[x]=1,f[x]=y,dep[x]=dep[y]+1;
	int mx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>mx)mx=size[e[i].to],son[x]=e[i].to;
	}
}
int css;
void dfss(int x,int y)
{
	top[x]=y;dfx[x]=++css,id[css]=x;
	if(!son[x])return ;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
multiset<int>s[xx];
int mn[xx<<2];
void build(int k,int l,int r)
{
	if(l==r)return mn[k]=val[id[l]],void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
void cg(int k,int l,int r,int x)
{
	if(l==r)return mn[k]=val[id[l]],void();
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x);
	else cg(k<<1|1,mid+1,r,x);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
int ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return mn[k];
	int mid=l+r>>1;
	if(y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
	return min(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
}
int ans;
void jump(int x,int y)
{
	ans=1e9;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=min(ans,ask(1,1,cnt,dfx[top[x]],dfx[x]));
		x=f[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	ans=min(ans,ask(1,1,cnt,dfx[y],dfx[x]));
	int L=dep[x]<dep[y]?x:y;
	if(L>n)ans=min(ans,val[f[L]]);
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cnt=n;
	tj(1);
	dfs(1,0);
	dfss(1,1);
	for(int i=1;i<=n;i++)
		if(f[i])s[f[i]].insert(val[i]);
	for(int i=n+1;i<=cnt;i++)val[i]=*s[i].begin();
//	for(int i=1;i<=cnt;i++)cout<<i<<" qq "<<val[i]<<"\n";
	build(1,1,cnt);
	while(q--)
	{
		char c;
		while((c=getchar())!='A'&&c!='C');
		if(c=='A')
		{
			int a=read(),b=read();
			jump(a,b);
			cout<<ans<<"\n";
		}
		else 
		{
			int a=read(),w=read();
			if(f[a])s[f[a]].erase(s[f[a]].find(val[a]));
			val[a]=w;cg(1,1,cnt,dfx[a]);
			if(f[a])s[f[a]].insert(val[a]),val[f[a]]=*s[f[a]].begin(),cg(1,1,cnt,dfx[f[a]]);
		}
	}
	pc('1',1);
	return 0;
}