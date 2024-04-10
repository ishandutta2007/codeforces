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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
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
const int xx=25;
ll ni[50];
ll a[xx];
ll C(ll n,ll m)
{
	if(n<m)return 0;
	ll ans=1;
	for(ll i=n;i>n-m;i--)ans=ans*(i%mod),ans%=mod;
	return ans*ni[m]%mod;
}
int main(){
	ni[0]=1;
	for(int i=1;i<50;i++)ni[i]=ni[i-1]*ksm(i,mod-2)%mod;
	int n=read();
	ll s=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ll ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		int ct=0;
		for(int j=0;j<n;j++)ct+=i>>j&1;
		ll now=s+n-1;
		for(int j=0;j<n;j++)
			if(i>>j&1)now-=a[j+1]+1;// 
		if(ct&1)ct=-1;
		else ct=1;
		ans+=C(now,n-1)*(mod+ct)%mod,ans%=mod;
	}
	cout<<ans<<"\n";
	
	pc('1',1);
	return 0;
}