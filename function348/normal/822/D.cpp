#include<cstdio>
#include<iostream>
using namespace std;
const int N=5000010,p=1000000007;
int f[N],pr[N],num;
int main()
{
	f[1]=0;
	for (int i=2;i<=5000000;i++)
	{
		if (f[i]==0) pr[++num]=i,f[i]=1LL*i*(i-1)/2%p;
		for (int j=1;j<=num;j++)
		{
			if (1LL*i*pr[j]>N) break;
			f[i*pr[j]]=(f[i]+1LL*i*pr[j]*(pr[j]-1)/2)%p;
			if (i%pr[j]==0) break;
		}
	}
	int t,l,r;
	scanf("%d%d%d",&t,&l,&r);
	int ans=0;
	for (int i=r;i>=l;i--) ans=(1LL*ans*t+f[i])%p;
	printf("%d\n",ans);
	return 0;
}