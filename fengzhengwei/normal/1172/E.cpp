#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
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
const int xx=4e5+5;
int n,m;
int lb(int x){return x&-x;};
ll sum[xx];
void ad(int x,ll y){x++;for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){x++;ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
void ad(int l,int r,ll v){/*cerr<<l<<" "<<r<<" "<<v<<"@#@\n";*/ad(l,v),ad(r+1,-v);}
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx],col[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
//sizsiz 
int lsiz[xx],siz[xx],fa[xx],f[xx],c[xx][2];
ll lsiz_[xx];
void dfs(int x,int y)
{
	fa[x]=y;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)dfs(e[i].to,x);
}
//**siz** 
void upd(int k){siz[k]=siz[c[k][0]]+siz[c[k][1]]+1+lsiz[k];}
bool nroot(int x){return c[f[x]][0]==x||c[f[x]][1]==x;}
void rotate(int x)
{
	int y=f[x],z=f[y],s=c[y][1]==x;
	c[y][s]=c[x][!s],f[c[x][!s]]=y;
	f[x]=z;if(nroot(y))c[z][c[z][1]==y]=x;
	f[c[x][!s]=y]=x,upd(y);/*upd(x);*/
}
void splay(int x)
{
	while(nroot(x))
	{
		int y=f[x],z=f[y];
		if(nroot(y))
		{
			if((c[z][1]==y)==(c[y][1]==x))rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
	upd(x);
}
ll sm;
//sum 
void access(int x)
{
	for(int y=0;x;x=f[y=x])
	{
		splay(x);
		lsiz[x]+=siz[c[x][1]],lsiz_[x]+=1ll*siz[c[x][1]]*siz[c[x][1]];
		c[x][1]=y;
		lsiz[x]-=siz[c[x][1]],lsiz_[x]-=1ll*siz[c[x][1]]*siz[c[x][1]];
		upd(x);
	}
}
//,linkx->fa[x] 
int get(int x){splay(x);while(c[x][0])x=c[x][0];return x;}
int ct[xx],vis[xx];
void link(int x)
{
	assert(!vis[x]);
	vis[x]^=1;
	int y=fa[x],z;
//	cerr<<siz[c[z][1]]<<"@#@#\n";
	access(y),splay(z=get(y)),sm-=1ll*siz[c[z][1]]*siz[c[z][1]];
	access(x),splay(x),sm-=lsiz_[x];
	splay(x),splay(y),f[x]=y,lsiz[y]+=siz[x],lsiz_[y]+=1ll*siz[x]*siz[x];
	access(x),splay(z=get(x)),sm+=1ll*siz[c[z][1]]*siz[c[z][1]];
//	cerr<<z<<" "<<siz[c[z][1]]<<" "<<c[z][1]<<" "<<x<<"^^\n";
}
void cut(int x)
{
	assert(vis[x]);
	vis[x]^=1;
	int y=fa[x],z;
	//x 
//	cerr<<sm<<"^^\n";
	access(x),splay(z=get(x)),sm-=1ll*siz[c[z][1]]*siz[c[z][1]];
	access(y);
//	cerr<<z<<" "<<c[z][1]<<" "<<siz[c[z][1]]<<"^^^\n";
//	cerr<<sm<<"^^\n";
	splay(x),splay(y),f[x]=0,lsiz[y]-=siz[x],lsiz_[y]-=1ll*siz[x]*siz[x];
	access(x),splay(x),sm+=lsiz_[x];
	access(y),splay(z=get(y)),sm+=1ll*siz[c[z][1]]*siz[c[z][1]];
//	cerr<<sm<<"^_^\n";
}
struct qu{int i,x;};// 
vector<qu>v[xx];
int id[xx],P[xx],T[xx],cc[xx];
signed main(){
	n=read(),m=read();
	for(int i=2;i<=n+1;i++)col[i]=cc[i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read()+1,b=read()+1;//1 
		add(a,b),add(b,a);
	}
	add(1,2),dfs(1,0);
	for(int i=2;i<=n+1;i++)ct[cc[i]]++;
	//col 
	for(int i=1;i<=n+1;i++)siz[i]=1;
	// 
	for(int i=1;i<=m;i++)
	{
		id[i]=read()+1,T[i]=read(),P[i]=col[id[i]];
		if(P[i]==T[i])continue;
		col[id[i]]=T[i],ct[T[i]]++,ct[P[i]]++;
	}
	// 
//	cerr<<ct[1]<<"\n";
	for(int i=1;i<=n;i++)v[i].resize(ct[i]),ct[i]=0;
	for(int i=2;i<=n+1;i++)v[cc[i]][ct[cc[i]]++]={0,i};
//	for(int i=1;i<=m;i++)if(P[i]!=T[i])cout<<i<<" "<<id[i]<<" "<<P[i]<<" "<<T[i]<<"^^^\n";
	for(int i=1;i<=m;i++)
	{
		if(P[i]==T[i])continue;
//		assert(id[i]);
		v[P[i]][ct[P[i]]++]={i,id[i]};
		v[T[i]][ct[T[i]]++]={i,id[i]};
	}
//	cerr<<ct[1]<<"@\n";
//	exit(0);
//	for(auto it:v[1])cout<<it.x<<" "<<it.i<<"@#@#\n";
//	exit(0);
	for(int i=2;i<=n+1;i++)link(i);
//	,cerr<<sm<<"@\n";
//	puts("ASdasd");
//	cerr<<sm<<"@#\n";
//	exit(0);
//	cerr<<sm<<"@#@\n";
	for(int i=1;i<=n;i++)
	{
//		cerr<<i<<"@#@\n";
//		puts("");
		int ls=0;
		for(auto it:v[i])
		{
//		cerr<<it.x<<" "<<it.i<<"@#@\n";
			if(ls!=it.i)ad(ls,it.i-1,sm),ls=it.i;
			if(vis[it.x])cut(it.x);
			else link(it.x);
		}
		ad(ls,m,sm); 
		for(auto it:v[i])if(!vis[it.x])link(it.x);
//		puts("");
//		exit(0);
	}
	
	for(int i=0;i<=m;i++)
		cout<<1ll*n*n*n-ask(i)<<"\n";
	pc('1',1);
	return 0;
}