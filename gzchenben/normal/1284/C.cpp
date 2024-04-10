#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long n,mod,inv[250005],ans;
int main()
{
	scanf("%lld%lld",&n,&mod);
	inv[0]=1;
	for(int i=1;i<=n;i++)
	{
		inv[i]=inv[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++)
	{
		long long tmp=(n-i+1)*(n-i+1)%mod*inv[i]%mod*inv[n-i]%mod;
		ans=(ans+tmp)%mod;
//		printf("%lld\n",tmp);
	}
	printf("%lld\n",ans);
}