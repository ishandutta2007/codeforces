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
int n,m,k,q,a[xx],b[xx];
int t[xx];
int sum[xx];
int lb(int x){return x&-x;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
void add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
char s[xx];
ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
int main(){
	pre();
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++,add(a[i],1);
	for(int i=1;i<=m;i++)b[i]=read();
	ll ans=0;
	ll nowni=1;
	for(int i=1;i<=200000;i++)if(t[i])nowni*=ni[t[i]],nowni%=mod;
	// 
	for(int i=1;i<=m;i++)
	{
		if(i==n+1)break;
		ans+=jiec[n-i]*nowni%mod*(ask(b[i]-1))%mod;
		ans%=mod;
		if(!t[b[i]])break;
		add(b[i],-1);
		nowni*=jiec[t[b[i]]];
		nowni%=mod;
		t[b[i]]--;
		if(t[b[i]])nowni*=ni[t[b[i]]];
		nowni%=mod;
	}
	if(n<m)// 
	{
		for(int i=1;i<=200000;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[a[i]]++;
		for(int i=1;i<=n;i++)
			t[b[i]]--;
//			,cerr<<b[i]<<"!!!\n";
		int cr=1;
		for(int i=1;i<=200000;i++)
			if(t[i]<0)cr=0;
//	cout<<ans<<" "<<cr<<"!!\n";
//	puts("ASdsad");
		ans+=cr;
	}
	cout<<ans%mod<<"\n";
	pc('1',1);
	return 0;
}