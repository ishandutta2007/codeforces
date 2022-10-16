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

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


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
int n,m,k,q,a[xx],b[xx];
int ans[xx];

struct nod{int next,to,id;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}


struct pr
{
	int x,y,id;
};
vector<pr>v;

int vis[xx],dep[xx],fid[xx];
void dfs(int x,int y)
{
	dep[x]=dep[y]+1;
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(vis[e[i].to])
		{
			if(dep[e[i].to]<dep[x])
			v.push_back({x,e[i].to,e[i].id});
		}
		else 
			ans[e[i].id]=1,fid[e[i].to]=e[i].id,dfs(e[i].to,x);
	}
}
int ct[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		v.clear();
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		
		for(int i=1;i<=max(n,m);i++)ans[i]=vis[i]=0;
		for(int i=1;i<=max(n,m);i++)ans[i]=ct[i]=0;
		for(int i=1;i<=m;i++)
		{
			int a=read(),b=read();
			add(a,b,i),add(b,a,i);
		}
		dfs(1,0);
		
		if(v.size()==3)
		{
			for(auto it:v)
			{
				ct[it.x]++;
				ct[it.y]++;
			}
			int mn=1e9;
			for(int i=1;i<=n;i++)if(ct[i])mn=min(mn,ct[i]);
			if(mn==2)
			{
				ans[v[0].id]=1;
				ans[fid[v[0].x]]=0;
			}
		}
		
		for(int i=1;i<=m;i++)cout<<ans[i];
		puts("");
	}
	pc('1',1);
	return 0;
}