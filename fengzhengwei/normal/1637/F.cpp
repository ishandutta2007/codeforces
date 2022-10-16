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
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
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
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
	int prim[xx],vis[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!vis[i])prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				vis[i*prim[j]]=1;
				if(i%prim[j]==0)break;
			}
		}
	}
}
const int xx=5e5+5,mod=998244353;
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
int n,m,k,q,a[xx],t[xx];
char s[xx];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt]={h[x],y};
	h[x]=cnt;
}
ll mx[xx],v[xx],fa[xx];
ll f[xx],g[xx];
int isl[xx],d[xx];
void dfs(int x,int y)
{
	fa[x]=y;
	mx[x]=v[x];
	int vs=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		vs=1;
		mx[x]=max(mx[x],mx[e[i].to]);
		
	}
	if(!vs)
	{
		f[x]=v[x];
		isl[x]=1;
		return;
	}
	int Cr=0;
	ll MM=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		f[x]+=f[e[i].to];
		if(mx[e[i].to]>=v[x])Cr=1;
		MM=max(MM,mx[e[i].to]);
	}
	g[x]=f[x];
	if(!Cr)f[x]+=v[x]-MM;//dltg 
}
//mx 
struct no{ll mx,se;}E[xx];
no upd(no a,ll x)
{
	if(a.mx<x)a.se=a.mx,a.mx=x;
	else a.se=max(a.se,x);
	return a;
}
ll ans=1e18;
ll F[xx],Fmx[xx],Mx;
// 
//mx 
void dp(int x,int y)//2 
{
	if(isl[x])
	{
		ans=min(ans,F[x]+max(0ll,v[x]-Fmx[x]));
		// 
		return;
	}
	E[x].mx=Fmx[x];// 
	E[x].se=-1e9;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)E[x]=upd(E[x],mx[e[i].to]);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		ll to=(mx[e[i].to]==E[x].mx)?E[x].se:E[x].mx;
		// 
		F[e[i].to]=g[x]-f[e[i].to]+F[x]+max(0ll,v[x]-to);
		Fmx[e[i].to]=max(to,v[x]);
		dp(e[i].to,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)v[i]=read(),Mx=max(Mx,v[i]);
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
		d[a]++,d[b]++;
	}
	int rt=0;
	for(int i=1;i<=n;i++)
		if(v[i]==Mx)rt=i;
	dfs(rt,0);
//	cout<<rt<<" "<<f[rt]<<"!!\n";
	if(d[rt]==1)
	{
		cout<<Mx+f[rt]<<"\n";
		exit(0);
	}
	dp(rt,0);
	cout<<ans+Mx<<"\n";
	pc('1',1);
	return 0;
}