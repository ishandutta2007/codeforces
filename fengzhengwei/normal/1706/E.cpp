#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar g
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
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
struct pr{int x,y;};
int n,m,k,q,a[xx],b[xx];
char s[xx];
int fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct seg
{
	int mx[xx<<2],val[xx];
	void build(int k,int l,int r)
	{
		if(l==r)return mx[k]=val[l],void();
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		mx[k]=max(mx[k<<1],mx[k<<1|1]);
	}
	int ask(int k,int l,int r,int x,int y)
	{
		if(x>y)return 0;
		if(x<=l&&r<=y)return mx[k];
		int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return max(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
	}
}s1,s2;
//; 
struct nod{int next,to,v;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
int siz[xx];
int son[xx],f[xx],fv[xx],dep[xx],id[xx],top[xx],dfn[xx],cst;
void dfs(int x,int y)
{
	f[x]=y,dep[x]=dep[y]+1;
	siz[x]=1,son[x]=0;
	int mx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		fv[e[i].to]=e[i].v;
		dfs(e[i].to,x),siz[x]+=siz[e[i].to];
		if(siz[e[i].to]>mx)mx=siz[e[i].to],son[x]=e[i].to;
	}
}
void dfss(int x,int y)
{
	top[x]=y;
	dfn[x]=++cst,id[cst]=x;
	if(!son[x])return;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
int ask(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=max(ans,s1.ask(1,1,n,dfn[top[x]],dfn[x]));
		x=f[top[x]];
	}
	if(dfn[x]<dfn[y])swap(x,y);
	ans=max(ans,s1.ask(1,1,n,dfn[y]+1,dfn[x]));
	return ans;
}
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read(),q=read();
		cst=cnt=0;
		memset(h,0,sizeof(h[0])*(n+1));
		// 
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int a=read(),b=read();
			if(find(a)!=find(b))
				add(a,b,i),add(b,a,i),fa[find(a)]=b;
		}
		dfs(1,0),dfss(1,1);
		for(int i=1;i<=n;i++)s1.val[dfn[i]]=fv[i];
		s1.build(1,1,n);
		for(int i=1;i<n;i++)
			s2.val[i]=ask(i,i+1);
		s2.build(1,1,n-1);
		while(q--)
		{
			int x=read(),y=read();
			cout<<s2.ask(1,1,n-1,x,y-1)<<"\n";
		}
	}
	pc('1',1);
	return 0;
}