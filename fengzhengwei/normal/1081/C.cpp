#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,k;
const int mod=998244353;
ll ksm(ll x,int y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans*=x,ans%=mod;
		x*=x,x%=mod;
		y>>=1;
	}
	return ans;
}
ll jiec[65454];
ll C(ll x,ll y)
{
	return jiec[x]*ksm(jiec[y],mod-2)%mod*ksm(jiec[x-y],mod-2)%mod;
}
int main(){
	jiec[0]=1;
	for(int i=1;i<=5000;i++)jiec[i]=jiec[i-1]*i%mod;
	n=read();
	m=read();
	k=read();
	if(k>=n)puts("0");
	else cout<<m*ksm(m-1,k)%mod*C(n-1,k)%mod<<'\n';
	return 0;
}