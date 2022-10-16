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
const int xx=5e6+5,mod=2;
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
char s[xx];
ll jiec[xx],ni[xx];
//ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
ll bin(ll n,ll m){return ((n&m)==m)?1:0;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
// 
// 
//TT-1T-2 
ll pw[xx];
struct F
{
	int T;//T 
	ll ans[xx];
	ll get(int M)
	{
		if(M<T)return 0;
		if(T<=0)return pw[M];
		return (pw[M]-ans[M]+2)%2;
	}
	void pre()
	{
		if(T<=0)return;
		for(int i=0;i<T;i++)ans[T]+=bin(T,i),ans[T]%=2;
		for(int i=T+1;i<=n;i++)
			ans[i]=(ans[i-1]*2-bin(i-1,T-1)+2)%2;
	}
}A,B,C;
int res[xx];
int main(){
	pw[0]=1;
	//0 
	//mod 2 
//	pre();
	n=read(),k=read();
	for(int i=1;i<=n;i++)b[i]=read();
	A.T=k,B.T=k-1,C.T=k-2;
	A.pre(),B.pre(),C.pre();
	for(int i=1;i<=n;i++)
	{
		ll npw=b[i];
//		,fn=0;
		for(int j=i;j<=n;j++)
		{
			if(j!=i)
			{
				if(b[j]<=20)npw*=(1<<b[j]);
				else break;
				if(npw>=(1<<20))break;
			}
//			cout<<npw<<"$%^\n";
			int rem=i-1+n-j;
			if(i==1&&j==n)
			{
				res[npw]+=A.get(rem);
				res[npw]%=2;
			}
			else if(i==1)
			{
				res[npw]+=B.get(rem-1);
				res[npw]%=2;
			}
			else if(j==n)
			{
				res[npw]+=B.get(rem-1);
				res[npw]%=2;
			}
			else 
			{
				res[npw]+=C.get(rem-2);
				res[npw]%=2;
			}
		}
	}
	int id=0;
	for(int i=xx-1;i>=0;i--)
		if(res[i]){id=i;break;}
	for(int i=id;i>=0;i--)cout<<res[i];
	puts("");
	pc('1',1);
	return 0;
}