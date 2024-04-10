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
ll d0[xx],d1[xx],p0[xx],s0[xx],p1[xx],s1[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		ll ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=2;i<=n;i++)ans+=abs(a[i]-a[i-1]);
		int mx=0,mn=1e9;
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]),mn=min(mn,a[i]);
		if(mx>=m&&mn<=1)
		{
			cout<<ans<<"\n";
			continue;
		}
		//i,i+1 
		for(int i=0;i<=n;i++)
		{
			if(i==0)d0[i]=abs(1-a[1]),d1[i]=abs(m-a[1]);
			else if(i==n)d0[i]=abs(1-a[n]),d1[i]=abs(m-a[n]);
			else d0[i]=-abs(a[i]-a[i+1])+abs(1-a[i])+abs(1-a[i+1]),d1[i]=-abs(a[i]-a[i+1])+abs(m-a[i])+abs(m-a[i+1]);
		}
		ll res=1e18;
		if(mx>=m)
		{
			for(int i=0;i<=n;i++)
				res=min(res,ans+d0[i]);
		}
		else if(mn<=1)
		{
			for(int i=0;i<=n;i++)
				res=min(res,ans+d1[i]);
		}
		else 
		{
			p0[0]=d0[0],p1[0]=d1[0];
			for(int i=1;i<=n;i++)p0[i]=min(p0[i-1],d0[i]),p1[i]=min(p1[i-1],d1[i]);
			s0[n]=d0[n],s1[n]=d1[n];
			for(int i=n-1;i>=0;i--)s0[i]=min(s0[i+1],d0[i]),s1[i]=min(s1[i+1],d1[i]);
			for(int i=0;i<n;i++)
			{
				res=min(res,ans+p0[i]+s1[i+1]);
				res=min(res,ans+p1[i]+s0[i+1]);
			}
			for(int i=0;i<=n;i++)
			{
				if(i==0)
				{
					res=min(res,ans+abs(1-m)+abs(m-a[1]));
					res=min(res,ans+abs(1-m)+abs(1-a[1]));
				}
				else if(i==n)
				{
					res=min(res,ans+abs(1-m)+abs(m-a[n]));
					res=min(res,ans+abs(1-m)+abs(1-a[n]));
				}
				else res=min(res,ans-abs(a[i]-a[i+1])+abs(a[i]-1)+abs(1-m)+abs(m-a[i+1])),res=min(res,ans-abs(a[i]-a[i+1])+abs(a[i]-m)+abs(1-m)+abs(1-a[i+1]));
			}
		}
		cout<<res<<"\n";
	}
	pc('1',1);
	return 0;
}