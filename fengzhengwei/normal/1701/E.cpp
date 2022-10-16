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
struct pr{int x,y;};
int n,m,k,q,a[xx],b[xx];
char s[xx],c[xx];
int f[xx],g[xx];
int t[5005][5005];
int id[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		scanf("%s",s+1);
		scanf("%s",c+1);
		for(int i=1;i<=n+1;i++)
		for(int j=1;j<=m+1;j++)t[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1];
			if(f[i]!=m)
			{
				f[i]+=(c[f[i]+1]==s[i]);
				if(f[i]!=f[i-1])id[f[i]]=i;
			}
		}
		g[n+1]=m+1;
		for(int i=n;i>=1;i--)
		{
			g[i]=g[i+1];
			if(g[i]!=1)g[i]-=(c[g[i]-1]==s[i]);
		}
		if(f[n]!=m)
		{
			puts("-1");
			continue;
		}
		for(int i=n;i>=1;i--)
			for(int j=m;j>=1;j--)
				t[i][j]=(s[i]==c[j])?t[i+1][j+1]+1:0;
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(f[i-1]>=j-1&&g[i+t[i][j]]<=j+t[i][j]+1)
				{
					// 
//					ans=min(ans,id[j-1]+(j!=1)+(m-j+1)-t[i][j]);
//					cerr<<i<<" "<<j<<" "<<j-1+(j!=1)+(m-j+1)-t[i][j]<<"#\n";
					ans=min(ans,i-1+(i!=1)+(m-j+1)-t[i][j]);
					// 
				}
//					ans=max(ans,t[i][j]);
			}
		}
//		cerr<<ans<<"$\n";
		cout<<ans+n-m<<"\n";
	}
	pc('1',1);
	return 0;
}