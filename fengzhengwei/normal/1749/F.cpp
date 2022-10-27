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


struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}

void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
void ad(int &a,ll b){(a=(a+b)%mod);}
int red(int x){return x>=mod?x-=mod:x;}

random_device R;
mt19937 G(218);
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}

}

int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=4e5+5,mod=998244353;
//mod1e9+7998 

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


#define Pr pair<int,int>
#define fi first
#define se second
int n,m,k,q,a[xx],b[xx];

struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int dep[xx],dfx[xx],top[xx],siz[xx],son[xx],f[xx],jp[xx][21],cst;
void dfs(int x,int y)
{
	jp[x][0]=y,dep[x]=dep[y]+1;
	for(int i=1;i<=20;i++)jp[x][i]=jp[jp[x][i-1]][i-1];
	f[x]=y;
	int Mx=-1;
	siz[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x),siz[x]+=siz[e[i].to];
		if(siz[e[i].to]>Mx)Mx=siz[e[i].to],son[x]=e[i].to;
	}
}
void dfss(int x,int y)
{
	dfx[x]=++cst,top[x]=y;
	if(!son[x])return;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
void pre(int rt){dfs(rt,0),dfss(rt,rt);}
struct seg
{
	int lb(int x){return x&-x;}
	int sum[xx];
	void Add(int x,int y){if(!x)return;for(;x<xx;x+=lb(x))sum[x]+=y;}
	int Ask(int x){/*cerr<<x<<"!!\n";*/ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
	void dg(int x,ll y){/*cerr<<dfx[x]<<" "<<y<<"@@\n";*/Add(dfx[x],y);}
	void one(int x,ll y){dg(x,y),dg(f[x],-y);}
	int get(int x){return /*cerr<<x<<" "<<dfx[x]<<"$$\n",*/Ask(dfx[x]+siz[x]-1)-Ask(dfx[x]-1);}
}s[21];
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	pre(1);
//	cerr<<dfx[3]<<"#\n";
//	exit(0);
	q=read();
	while(q--)
	{
		int op=read();
		if(op==1)
		{
			int x=read();
			int ans=0;
			int dp=0;
			while(x)
			{
//				cerr<<x<<" "<<s[1].get(x)<<"!\n";
				if(dp>20)break;
				for(int i=0;i<=20;i++)
					if(i>=dp)ans+=s[i].get(x);
				++dp,x=f[x];
			}
			cout<<ans<<"\n";
		}
		else 
		{
			int u=read(),v=read(),k=read(),d=read(),L=lca(u,v);
			s[d].dg(u,k),s[d].dg(v,k),s[d].dg(L,-2*k);
			if(d!=0)
			{
				k=-k,--d;
				s[d].dg(u,k),s[d].dg(v,k),s[d].dg(L,-2*k);//lca   
				++d,k=-k;
			}
			//lca 
			while(d>=0&&L)
			{
//				cout<<d<<"!!\n";
				s[d].one(L,k);
//				cerr<<L<<" "<<d<<" "<<k<<" "<<s[d].get(L)<<" "<<dfx[L]<<" "<<siz[L]<<"#\n";
				if(d>1&&f[L])s[d-2].one(L,-k);
				L=f[L],--d;
			}
//			cout<<s[2].get(5)<<" "<<s[1].get(5)<<" "<<s[2].get(2)<<" "<<s[1].get(2)<<" "<<s[2].get(1)<<"#\n";
		}
	}
	pc('1',1);
	return 0;
}