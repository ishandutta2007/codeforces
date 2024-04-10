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
int t[xx],ini[xx];
char s[xx];
vector<int>v[xx];
int main(){
//	v[0].shrink_to_fit();
	int T=read();
	while(T--)
	{
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int ans=1e9;
		int mn=1e9;
		int M=0;
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
//		M=a[n];
		for(int mx=1e5;mx>=0;mx--)
		{
			int cr=1;
			int re=1e9;
			
			for(int i=n;i<=n;i++)
			{
				if(a[i]/(mx+1)+1<=k)
					re=min(re,(a[i]/(a[i]/(mx+1)+1)));
				else 
				{
					cr=0;
					break;
				}
			}
			if(!cr)break;
			mn=min(mn,mx);
		}
		for(int i=1;i<=n;i++)ini[a[i]]=0;
		for(int i=0;i<=1e5+1;i++)t[i]=0,v[i].clear();
		int tt=0;
		//nsqrt + t lim 
		// nm  
		
		// mx +1 
		for(int i=1;i<=n;i++)
			v[mn+1].push_back(a[i]);
		// 
		for(int mx=mn;mx<=1e5;mx++)
		{
			for(auto it:v[mx+1])
			{
				if(!ini[it]);
				else --t[ini[it]];
				ini[it]=(it/(it/(mx+1)+1));
				++t[ini[it]];
				if(it/(mx+1))
				{
					int ed=it/(it/(mx+1));
					v[ed+1].push_back(it);
				}
			}
			// 
			v[mx+1].clear(),v[mx+1].shrink_to_fit();
			while(!t[tt])++tt;
			ans=min(ans,mx-tt);
		}
		cout<<ans<<"\n";
//		ll ans=0;
//		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}