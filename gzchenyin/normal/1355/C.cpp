#include<cstdio>
#include<algorithm>
using namespace std;
long long a,b,c,d;
long long ans;
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	for(int z=c;z<=d;z++)
	{
		long long minnx=max(a,z-c+1),maxnx=b;
//		printf("%lld %lld\n",minnx,maxnx);
		if(maxnx<minnx) continue;
		long long minn1y=max(z-minnx+1ll,b),maxn1y=c;
		long long minn2y=max(z-maxnx+1ll,b),maxn2y=c;
//		printf("%lld %lld %lld %lld\n",minn1y,maxn1y,minn2y,maxn2y);
		ans+=((maxn1y-minn1y+1ll)+(maxn2y-minn2y+1ll))*((maxn2y-minn2y+1ll)-(maxn1y-minn1y+1ll)+1ll)/2ll;
		ans+=(maxn2y-minn2y+1ll)*((maxnx-minnx+1ll)-((maxn2y-minn2y+1ll)-(maxn1y-minn1y+1ll)+1ll));
	}
	printf("%lld\n",ans);
}