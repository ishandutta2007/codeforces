#include<bits/stdc++.h>
#define int long long
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int xx=2e5+5;
int n,m,sa[xx],rk[xx];
const int mod=998244353;
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
ll C(ll a,ll b)
{
	if(a<b)return 0;
	ll ans=1,res=1;
	for(int i=a-b+1;i<=a;i++)ans*=i,ans%=mod;
	for(int i=1;i<=b;i++)res*=i,res%=mod;
	return ans*ksm(res,mod-2)%mod;
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)sa[i]=read()+1;
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	int tt=0;
	for(int i=1;i<n;i++)
		if(rk[sa[i]+1]<rk[sa[i+1]+1])tt++;
//	cout<<tt<<"\n";
	cout<<C(m+tt,n)<<"\n";
	return 0;
}