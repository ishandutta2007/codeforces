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
const int xx=4e6+5,mod=998244353;
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
int ans[xx],sum[xx];
int g(int l,int r)
{
	if(r<=0)return 0;
	if(l<=0)return sum[r];
	return sum[r]-sum[l-1];
}
int cf[xx<<2];//4 
const int D=xx+xx;
void ad(int A,int B)
{
	if(A>n*m)return;
	cf[A+D]+=B;
}
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		scanf("%s",s+1);
		//0+ 
		for(int i=1;i<=n*m;i++)ans[i]=a[i]=sum[i]=cf[i]=0;
		for(int i=-n*m;i<=n*m+m;i++)cf[i+D]=0;
		for(int i=1;i<=n*m;i++)sum[i]=sum[i-1]+(s[i]-'0');
		int zz=m,ct=m;
		for(int i=1;i<=n*m;i++)
		{
			a[zz]+=s[i]-'0';
			if((s[i]-'0')==1&&a[zz]==1)ct--;
			ans[i]+=ct;// 
			zz--;
			if(zz==0)zz=m;
		}
		//n*m00-n*m+1 
		for(int i=-n*m+1;i<=n*m-m+1;i++)
		{
			if(!g(i,i+m-1))ad(i+m-1,1),ad(i-1+n*m+m,-1);
//			,cout<<i<<"#$\n";s
			
		}
		for(int i=-n*m+1+m;i<=n*m;i++)cf[i+D]+=cf[i+D-m];
		for(int i=1;i<=n*m;i++)ans[i]+=cf[i+D];
//		for(int i=1;i<=n*m;i++)cout<<ans[i]<<"~~\n";
		for(int i=1;i<=n*m;i++)
			cout<<n+m-ans[i]<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}