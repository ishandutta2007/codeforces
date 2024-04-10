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
const int xx=2e6+5,mod=998244353;
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
int n,m,k,a[xx],b[xx];
char s[xx];
struct nod{int next,to;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int vis[xx<<1];
int cr[xx];
int ct,d[xx];
void dfs(int x,int y)
{
	ct+=d[x];
	cr[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(cr[e[i].to])continue;
		dfs(e[i].to,x);
	}
}
struct nd
{
	int a,b,c;
};
vector<nd>ans;
int re[4][xx];
int cur[xx];
// 
//dfsa 
int dfn[xx];
vector<int>to[xx];
int cst;
vector<int>ver;
void Dfs(int x,int y,int z)
{
//	cerr<<x<<"$$$\n";
	dfn[x]=++cst,ver.push_back(x);
	for(int i=h[x];i;i=e[i].next)
	{
		if(i==z)continue;
		// 
//		cerr<<i<<" "<<z<<"@@\n";
		if(!dfn[e[i].to])Dfs(e[i].to,x,i^1),ver.push_back(x);
		else if(!vis[i])vis[i]=vis[i^1]=1,ver.push_back(e[i].to),ver.push_back(x);
	}
}
char a1[3][xx],a2[3][xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
		d[a]++,d[b]++;
	}
	for(int i=1;i<=n+n;i++)
		if(!cr[i]&&d[i])
		{
			ct=0,dfs(i,0);
//			cerr<<ct<<" "<<i<<"ASD\n";
			if((ct/2)<=1)puts("-1"),exit(0);
		}
	// 
	//n+n+1
	// 
	int tt=0;
	for(int i=1;i<=n+n;i++)
	if(d[i]&&!dfn[i])
	{
		ver.clear();
		Dfs(i,0,0);
		int ce=0;
		
//		cerr<<ver.size()<<"!2\n";
		if((ver.size()-1)/2&1)
		{
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)re[1][j]=ver[ce++];
			for(int j=tt+(ver.size()-1)/2;j>=tt+1;j--)re[2][j]=ver[ce++];
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)a1[1][j]=(j-tt)&1?'L':'R';
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)a1[2][j]=(j-tt)&1?'L':'R';
			a1[1][tt+(ver.size()-1)/2]='U';
			a1[2][tt+(ver.size()-1)/2]='D';
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)a2[1][j]=(j-tt+1)&1?'L':'R';
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)a2[2][j]=(j-tt+1)&1?'L':'R';
			a2[1][tt+1]='U';
			a2[2][tt+1]='D';
		}
		else 
		{
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)re[1][j]=ver[ce++];
			for(int j=tt+(ver.size()-1)/2;j>=tt+1;j--)re[2][j]=ver[ce++];
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)a1[1][j]=(j-tt)&1?'L':'R';
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)a1[2][j]=(j-tt)&1?'L':'R';
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)a2[1][j]=(j-tt+1)&1?'L':'R';
			for(int j=tt+1;j<=tt+(ver.size()-1)/2;j++)a2[2][j]=(j-tt+1)&1?'L':'R';
			a2[1][tt+1]='U';
			a2[2][tt+1]='D';
			a2[1][tt+(ver.size()-1)/2]='U';
			a2[2][tt+(ver.size()-1)/2]='D';
		}
		tt+=(ver.size()-1)/2;
	}
	
	
	
	cout<<2<<" "<<n<<"\n";
	
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)cout<<re[i][j]<<" ";
		puts("");
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)cout<<a1[i][j];
		puts("");
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)cout<<a2[i][j];
		puts("");
	}
	
	pc('1',1);
	return 0;
}