#include<bits/stdc++.h>
using namespace std;
const int N=1000005,mx=1000000,mod=1e9+7;
int fc[N],iv[N],t,n,m,k,s;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int c(int n,int m){return (n<m||m<0)?0:1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
int main()
{
	fc[0]=1;
	for(int i=1;i<=mx;i++)
		fc[i]=1ll*fc[i-1]*i%mod;
	iv[mx]=qp(fc[mx],mod-2);
	for(int i=mx-1;i>=0;i--)
		iv[i]=1ll*iv[i+1]*(i+1)%mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		s=0;
		for(int i=1;i<=m;i++)
			s=(s+1ll*qp((mod+1)/2,n-i)*c(n-1-i,m-i)%mod*i%mod)%mod;
		if(n==m)
			s=n;
		s=1ll*s*k%mod;
		printf("%d\n",s);
	}
	return 0;
}