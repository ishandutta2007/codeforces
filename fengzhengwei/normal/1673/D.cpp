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
const int xx=5e5+5,mod=1e9+7;
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
void fj(int n,vector<int>&v)
{
	v.clear();
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			v.push_back(i);
			while(n%i==0)n/=i;
		}
	}
	if(n!=1)v.push_back(n);
}
int main(){
	int T=read();
	while(T--)
	{
		//zy 
		ll b=read(),q=read(),y=read(),c=read(),r=read(),z=read();
		if(r%q||c<b||(c-b)%q)
		{
			puts("0");
			continue;
		}
		ll st=1+(c-b)/q,ed=1+(c+(z-1)*(r)-b)/q;
		if(ed>y)
		{
			puts("0");
			continue;
		}
		if(1+(c+(z)*r-b)/q>y)
		{
//			cout<<st<<" "<<ed<<" 11 "<<"\n";
//			puts("ASD");
			puts("-1");
			continue;
		}
		if(1+(c+(-1)*r-b)/q<1)
		{
			puts("-1");
			continue;
		}
		// 
		ll K=r/q,lenb=q;
		//K 
		ll d=gcd(lenb,K);
		vector<int>yz;
		fj(d,yz);
		for(auto it:yz)
			while(lenb%it==0)lenb/=it;
//		cout<<lenb<<" "<<K<<" "<<d<<"$%^\n";
//		cout<<lenb<<"#$\n";
		ll ans=0;
		for(ll i=1;i*i<=lenb;i++)
		{
			if(lenb%i==0)
			{
				ans+=i*i,ans%=mod;
//				cout<<i<<" "<<lenb/i<<" "<<ans<<"%$^\n";
				if(lenb/i!=i)ans+=(lenb/i)*(lenb/i),ans%=mod;
			}
		}
		cout<<ans<<"\n";
		
	}
	pc('1',1);
	return 0;
}