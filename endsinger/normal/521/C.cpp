#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,mod=1e9+7;
int n,k,a[N],fc[N],iv[N],ans,f[N],g[N],p,x;
string str;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int c(int n,int m){return n<m?0:fc[n]*iv[m]%mod*iv[n-m]%mod;}
signed main()
{
	ios::sync_with_stdio(false);
	fc[0]=iv[0]=1;
	for(int i=1;i<=200000;i++)
		fc[i]=fc[i-1]*i%mod,iv[i]=qp(fc[i],mod-2);
	cin>>n>>k>>str;
	for(int i=1;i<=n;i++)
		a[i]=str[i-1]-'0';
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			ans=(ans*10%mod+a[i])%mod;
		cout<<ans<<endl;
		return 0;
	}
	p=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=c(n-i-1,k-1);
		g[i]=(g[i-1]+f[i]*p%mod)%mod;
		p=p*10%mod;
	}
	p=1;
	for(int i=n;i>=1;i--)
	{
		x=(x+a[i]*p%mod)%mod;
		p=p*10%mod;
		ans=(ans+x*c(i-2,k-1)%mod)%mod;
	}
	for(int i=1;i<=n;i++)
		ans=(ans+g[n-i]*a[i]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}