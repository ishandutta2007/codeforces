#include<cstdio>
#include<algorithm>
using namespace std;
long long n,x,c[200005],tot[200005],now,from,ans,res;
void pre()
{
	long long t=x;
	for(int i=n;i>=1;i--)
	{
		if(t>=c[i])
		{
			t-=c[i];
			now+=tot[i];
			from=i;
		}
		else break;
	}
	res=t;
//	printf("%d\n",res);
}
int main()
{
	scanf("%lld%lld",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
		tot[i]=c[i]*(c[i]+1)/2;
	}
	pre();
	for(int i=1;i<=n;i++)
	{
		res-=c[i];
		now+=tot[i];
		while(res<0)
		{
//			printf("%d\n",res);
			res+=c[from];
			now-=tot[from];
			from=from%n+1ll;
		}
//		printf("ans=%d,now=%d,res=%d,from=%d\n",ans,now,res,(from+n-2)%n+1ll);
		ans=max(ans,now+res*(2*c[(from+n-2)%n+1ll]-res+1)/2);
	}
	printf("%lld\n",ans);
}