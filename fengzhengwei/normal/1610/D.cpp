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
ll pw[xx];
ll ct[31];

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
	pw[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i-1]*2%mod;
//	int T=read();
//	while(T--)
//	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int re=0;
		for(int i=1;i<=n;i++)re+=(a[i]%2==0);
//		ll f[2]={1,0};
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i]&1)
//			{
//				ll s=f[0]+f[1];
//				f[0]=f[1]=s%mod;
//			}
//			else 
//			{
//				f[0]*=2,f[1]*=2;
//				f[0]%=mod,f[1]%=mod;
//			}
//		}
		for(int i=1;i<=n;i++)
		{
			int num=0;
			int x=a[i];
			while(x%2==0)num++,x/=2;
			ct[num]++;
		}
		ll ans=((pw[n]-1)-(pw[re]-1)+mod)%mod;
		ll sum=re;
		for(int i=1;i<=30;i++)
		{
			for(int j=2;j<=ct[i];j+=2)
			{
//			cout<<i<<" "<<ct[i]<<" "<<j<<" "<<"Asd\n";
				ans+=C(ct[i],j)*pw[sum-ct[i]]%mod;
				ans%=mod;
			}
			sum-=ct[i];
		}
		
		cout<<ans<<"\n";
//	}
	pc('1',1);
	return 0;
}