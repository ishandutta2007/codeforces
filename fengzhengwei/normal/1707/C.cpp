#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
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

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int dfn[xx];
int sum[xx];
void Add(int x,int y,int z){sum[x]+=z,sum[y+1]-=z;}
int cst;

int f[xx][21];
int siz[xx];
int dep[xx];
void dfs(int x,int y)
{
	siz[x]=1;
	f[x][0]=y;
	for(int i=1;i<=20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	dfn[x]=++cst;
	dep[x]=dep[y]+1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
	dfs(e[i].to,x);siz[x]+=siz[e[i].to];
	}
}
int lg[xx];
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=20;i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return f[x][0];
}
int fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);
}
int jump(int x,int y)
{
	while(dep[x]!=y)
		x=f[x][lg[dep[x]-y]];
	return x;
}
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read(),m=read();
	vector<pr>v;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		if(find(a)!=find(b))
		{
			add(a,b),add(b,a);
			fa[find(a)]=b;
		}
		else v.push_back({a,b});
	}
	
	dfs(1,0);
	
	for(auto it:v)
	{
		int a=it.x,b=it.y;
		
		int L=lca(a,b);
		
		if(L!=a&&L!=b)
		{
			Add(dfn[a],dfn[a]+siz[a]-1,1);
			Add(dfn[b],dfn[b]+siz[b]-1,1);
		}
		else 
		{
			if(L==a)
			{
				Add(1,n,1);
				int ty=jump(b,dep[a]+1);
				Add(dfn[ty],dfn[ty]+siz[ty]-1,-1);
				Add(dfn[b],dfn[b]+siz[b]-1,1);
			}
			else 
			{
				swap(a,b);
				Add(1,n,1);
				int ty=jump(b,dep[a]+1);
				Add(dfn[ty],dfn[ty]+siz[ty]-1,-1);
				Add(dfn[b],dfn[b]+siz[b]-1,1);
			}
		}
	}
	
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
	
	
	
	for(int i=1;i<=n;i++)
	{
		if(sum[dfn[i]]==v.size())
		{
			cout<<1;
		}
		else cout<<0;
	}
	puts("");
	pc('1',1);
	return 0;
}