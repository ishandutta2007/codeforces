#include<bits/stdc++.h>
using namespace std;
const int N=2000005,mod=1e9+7;
int n,m,mu[N],pr[N],zh[N],sum[N],p[N],t,ans,out;
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
int main()
{
	scanf("%d%d",&n,&m);
	mu[1]=1;
	for(int i=2;i<=m;i++)
	{
		if(!zh[i])
		{
			t++;
			pr[t]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=t&&i*pr[j]<=m;j++)
		{
			zh[i*pr[j]]=1;
			if(i%pr[j]==0)
				break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	for(int i=0;i<=m;i++)
		p[i]=qp(i,n);
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j+=i)
			sum[j]=((sum[j]+1ll*mu[i]*(p[j/i]-p[j/i-1]))%mod+mod)%mod;
		ans=(ans+sum[i])%mod;
		out=(out+(ans^i))%mod;
	}
	printf("%d\n",out);
	return 0;
}