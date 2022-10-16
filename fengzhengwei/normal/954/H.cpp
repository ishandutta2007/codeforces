#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int mod=1e9+7;
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
const int xx=1e4+5;
int n;
ll pi[xx],ni[xx],a[xx],ans[xx],res[xx],v[xx];
ll C(ll s)//Cs 2 
{return s*(s-1)/2%mod;}
//i-i 
int main(){
	n=read();
	pi[0]=1;
	for(int i=1;i<n;i++)a[i]=read(),pi[i]=pi[i-1]*a[i]%mod;
	v[1]=1;
	for(int i=2;i<=n;i++)v[i]=v[i-1]*a[i-1]%mod;
	for(int i=1;i<n;i++)ni[i]=ksm(pi[i],mod-2);
	ni[0]=1;
	// 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			res[i+j]+=(pi[i-1]*pi[j-1]);
			res[i+j]%=mod;
//			cout<<i+j<<" "<<res[i+j]<<"\n";
		}
	}
	for(int i=1;i<n;i++)//lca 
	{
		for(int j=i;j<=n;j++)
		{
			res[i+j]+=mod-((pi[i-1]*pi[j-1])%mod);
			res[i+j]%=mod;
		}
		for(int j=i+1;j<=n;j++)// 
			ans[j-i]+=pi[j-1]*ni[i-1]%mod*v[i]%mod,ans[j-i]%=mod;
		for(int j=i+i+2;j<=n+n;j++)
		{
			ans[j-i-i]+=res[j]*ni[i]%mod*ni[i]%mod*C(a[i])%mod*v[i]%mod*2%mod;
			ans[j-i-i]%=mod;
		}
		for(int j=i+1;j<=n;j++)
		{
			ans[j+j-i-i]+=mod-(pi[j-1]*pi[j-1]%mod*ni[i]%mod*ni[i]%mod*C(a[i])%mod*v[i])%mod;
			ans[j+j-i-i]%=mod;
		}
	}
	for(int i=1;i<=n+n-2;i++)cout<<ans[i]<<" \n"[i==n+n+2];
	pc('1',1);
	return 0;
}