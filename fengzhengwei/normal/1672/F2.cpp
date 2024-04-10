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
int n,m,k,q,a[xx],b[xx],t[xx];
char s[xx];
vector<int>v[xx],w[xx];
void add(int x,int y){v[x].push_back(y);w[x].push_back(y);}
vector<int>lin;
int vis[xx],lst[xx],ct,st;
void Cl()
{
//	for(auto it:lin)cout<<it<<"ASD\n";
//	puts("");
	for(int i=0;i<lin.size();i++)
	{
		if(lst[lin[i]]!=-1)
		{
			for(int j=lst[lin[i]];j<i;j++)lst[lin[j]]=-1;
			lst[lin[i]]=i;
			ct++;
		}
		else lst[lin[i]]=i;
	}
	for(auto it:lin)lst[it]=-1;
}
void run(int x)
{
	if(x==st)
	{
		for(auto it:lin)vis[it]=0;
		lin.push_back(x);
		Cl();
		lin.clear();
		return;
	}
//	cout<<x<<"DFG\n";
	if(!st)st=x;
	lin.push_back(x);
	vis[x]=1;
	int A=*--v[x].end();
	v[x].pop_back();
//	cout<<x<<" "<<v[x].size()<<" "<<A<<"!!\n";
	run(A);
}
mt19937 G(time(0));
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	memset(lst,-1,sizeof(lst));
	int T=read();
	while(T--)
	{
		n=read();
		ll ans=0;
		for(int i=1;i<=n;i++)t[i]=0,v[i].clear(),w[i].clear();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)t[a[i]]++;
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,t[i]);
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++)add(a[i],b[i]);
		int cr=1;
		int W=40;
		if(n>1e5)W=15;
		while(W--)
		{
			for(int i=1;i<=n;i++)v[i]=w[i],shuffle(v[i].begin(),v[i].end(),G);
			//check 
			ct=0;
			for(int i=1;i<=n;i++)
				while(v[i].size())st=0,run(i);
	//			,cerr<<i<<" "<<v[i].size()<<"!!\n",puts("");
	//		cout<<ct<<"DFG\n";
			if(ct!=mx)cr=0;
		}
		if(cr)puts("AC");
		else puts("WA");
//		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}