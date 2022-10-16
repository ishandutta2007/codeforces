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
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx],p[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int f[xx],d[xx],mx;
void dfs(int x,int y)
{
	f[x]=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x),mx=max(mx,f[x]+f[e[i].to]+1),f[x]=max(f[x],f[e[i].to]+1);
	}
}
vector<int>I;
void line(int x,int y)
{
	I.push_back(x);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		line(e[i].to,x);
	}
}
int vis[xx];
int main(){
//	freopen("a.in","r",stdin);
	int T=read();
	int Re=0;
	while(T--)
	{
		mx=0;
		(++Re);
		n=read(),m=read();
//		if(Re==143)cout<<n<<" "<<m<<"\n";
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<=n;i++)d[i]=0;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
//		if(Re==143)cout<<a<<" "<<b<<"\n";
			add(a,b),add(b,a);
			d[a]++,d[b]++;
		}
		for(int i=1;i<=n;i++)p[i]=read();
//		for(int i=1;i<=n;i++)if(Re==143)cout<<p[i]<<" ";
//		if(Re==143)puts(""),exit(0);
		dfs(1,0),mx++;
//		cout<<mx<<"ASD\n";
		if(mx>=4)
		{
			puts("Alice");
			continue;
		}
		if(mx==3)// 
		{
			int id=0;
			for(int i=1;i<=n;i++)if(d[i]==n-1)id=i;
//			cout<<id<<"ASD\n";
			if(p[id]!=id&&(m==id||p[id]==m))
			{
				puts("Bob");
				continue;
			}
			if(p[id]!=id)//tokenid 
			{
				for(int i=1;i<=n;i++)
					if(p[i]==id)swap(p[i],p[id]);
				m=id;
			}
			
			for(int i=1;i<=n;i++)vis[i]=0;
			int par=0,cr=1,cts=0;
			for(int i=1;i<=n;i++)if(p[i]!=i)cr=0;
			for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				int ct=0,x=i;
				while(!vis[x])ct++,vis[x]=1,x=p[x];
				par^=((ct-1)&1);
				cts+=(ct-1);
			}
//			cout<<pr<<"ASD"
			if(cr)
			{
				puts("Alice");
				continue;
			}
			if(par&&m!=id&&(p[m]!=m||cts>1))
			{
//				puts("A");
				puts("Bob");
				continue;
			}
			if(!par&&m==id)
			{
				puts("Bob");
				continue;
			}
			
			
			puts("Alice");
			continue;
		}/*
		if(mx==4)
		{
			if(n==4)
			{
				I.clear();
				for(int i=1;i<=n;i++)
					if(d[i]==1)line(i,0);
				if((p[I[0]]==I[0]||p[I[0]]==I[1])&&(p[I[1]]==I[0]||p[I[1]]==I[1])&&(p[I[2]]==I[2]||p[I[2]]==I[3])&&(p[I[3]]==I[2]||p[I[3]]==I[3]))
				{
					puts("Alice");
				}
				else if((p[I[0]]==I[2]||p[I[0]]==I[3])&&(p[I[1]]==I[2]||p[I[1]]==I[3])&&(p[I[2]]==I[0]||p[I[2]]==I[1])&&(p[I[3]]==I[0]||p[I[3]]==I[1]))
				{
					puts("Alice");
					
				}else 
				puts("Bob");
				
				continue;
			}
			puts("Alice");
			continue;
		}
		puts("Alice");*/
	}
	pc('1',1);
	return 0;
}