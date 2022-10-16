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
	int prim[xx],mn[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
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
int n,m,k,q,a[xx];
char s[xx];
int c[xx][2],siz[xx],is[xx];
vector<char>v[xx];
void dfs(int x)
{
	siz[x]=1;
	if(c[x][0])dfs(c[x][0]),dfs(c[x][1]),siz[x]+=siz[c[x][0]]+siz[c[x][1]];
	v[x].resize(siz[x]);
	v[x][0]=s[x];
	if(c[x][0])
	{
		int cr=0;
		for(int i=0;i<siz[c[x][0]];i++)
		{
			if(v[c[x][0]][i]!=v[c[x][1]][i])
			{
				if(v[c[x][0]][i]>v[c[x][1]][i])swap(c[x][0],c[x][1]);
				cr=1;
				break;
			}
		}
		if(!cr)is[x]=1;
		for(int i=0;i<siz[c[x][0]];i++)v[x][i+1]=v[c[x][0]][i];
		for(int i=0;i<siz[c[x][0]];i++)v[x][i+siz[c[x][0]]+1]=v[c[x][1]][i];
	}
}
int f[xx];
void dp(int x)
{
	if(!c[x][0])f[x]=1;
	else 
	{
		dp(c[x][0]),dp(c[x][1]);
		if(is[x])f[x]=1ll*f[c[x][0]]*f[c[x][1]]%mod;
		else f[x]=1ll*f[c[x][0]]*f[c[x][1]]*2%mod;
	}
}
int main(){
	n=1<<read();
	--n;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(i*2<=n)c[i][0]=i*2,c[i][1]=i*2+1;
	dfs(1),dp(1);
	cout<<f[1]<<"\n";
	pc('1',1);
	return 0;
}