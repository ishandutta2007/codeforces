#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int mod=998244353;
ll ksm(ll a,ll b)
{
	a%=mod,a+=mod,a%=mod;
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
//	cout<<ans<<'\n';
	return ans;
}
ll n,m,l,r;
int main(){
	n=read(),m=read();
	l=read(),r=read();
	ll v=(r-l+1)/2,v1=(r-l+1)-v;
	if((n&1)&&(m&1))cout<<ksm(r-l+1,n*m)<<"\n";
	else  
	cout<<(ksm(v+v1,n*m)+ksm(v-v1,n*m))%mod*ksm(2,mod-2)%mod<<"\n";
	return 0;
}