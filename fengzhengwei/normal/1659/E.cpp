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
const int xx=2e5+5,mod=998244353;
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
int n,m,k,a[xx];
char s[xx];
struct nod{int a,b,c;}e[xx<<1];
vector<int>v[xx];
struct bc
{
	int fa[xx],mn[xx];// 
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void init(){for(int i=1;i<=n;i++)fa[i]=i,mn[i]=2147483647;}
	void merge(int x,int y)
	{
//		cout<<x<<" "<<y<<"$%^\n";
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y;
	}
	void in(int x,int y){mn[find(x)]&=y;}
}q[31];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		e[i]={a,b,c};
		v[a].push_back(c),v[b].push_back(c);
	}
	for(int j=0;j<30;j++)
	{
		q[j].init();
		for(int i=1;i<=m;i++)
			if(e[i].c>>j&1)q[j].merge(e[i].a,e[i].b);
	}
	for(int i=1;i<=n;i++)
	{
		int Z=2147483647;
		for(auto it:v[i])Z&=it;
		for(int j=0;j<30;j++)q[j].in(i,Z);
	}
	int Q=read();
	while(Q--)
	{
		int x=read(),y=read(),ans=2;
		for(int i=0;i<30;i++)
			if(q[i].find(x)==q[i].find(y))ans=0;
//			,cerr<<i<<" "<<q[i].find(x)<<"$%\n";
		if(ans==0)
		{
			puts("0");
			continue;
		}
		for(int i=1;i<30;i++)
		if(!(q[i].mn[q[i].find(x)]>>0&1))ans=min(ans,1);
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}