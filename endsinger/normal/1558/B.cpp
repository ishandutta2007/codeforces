#include<bits/stdc++.h>
using namespace std;
const int N=4000005;
int n,mod,f[N],p[N];
int main()
{
	scanf("%d%d",&n,&mod);
	f[n]=p[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		f[i]=p[i+1];
		for(int j=i+i,k=1;j<=n;j+=i,k++)
		{
			int l=j,r=min(n,l+k);
			f[i]=(f[i]+p[l])%mod;
			f[i]=(f[i]+mod-p[r+1])%mod;
		}
		p[i]=(p[i+1]+f[i])%mod;
	}
	printf("%d\n",f[1]);
	return 0;
}