#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct ques
{
	long long dif;
	long long ti;
}a[200005];
bool cmp(ques x,ques y)
{
	return x.ti<y.ti;
}
long long t,n,tim,th,te,ans,sumh[200005],sume[200005];
long long ext(long long x,long long ti)
{
	long long tmp1=ti/te;
	if(tmp1<=sume[x]) return tmp1;
	ti=ti-(sume[x]*te);
	long long tmp2=ti/th;
	if(tmp2>sumh[x]) tmp2=sumh[x];
	return tmp2+sume[x];
}
int main()
{
//	freopen("out.txt","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		memset(sumh,0ll,sizeof(sumh));
		memset(sume,0ll,sizeof(sume));
		scanf("%lld%lld%lld%lld",&n,&tim,&te,&th);
		for(long long i=1ll;i<=n;i++)
		{
			scanf("%lld",&a[i].dif);
		}
		for(long long i=1ll;i<=n;i++)
		{
			scanf("%lld",&a[i].ti);
		}
		a[n+1ll].ti=tim+1ll;
		sort(a+1ll,a+n+1ll,cmp);
		for(long long i=n;i>=1ll;i--)
		{
			sumh[i]=sumh[i+1ll]+a[i].dif;
			sume[i]=sume[i+1ll]+(1ll-a[i].dif);
		}
		long long ned=0ll;
		for(long long i=0ll;i<=n;i++)
		{
			if(i!=0ll) 
			{
				if(a[i].dif==0ll) ned+=te;
				else ned+=th;
			}
			if(a[i].ti==a[i+1ll].ti) continue;
			if(ned>a[i+1ll].ti-1ll) continue;
//			prlong longf("ans[%d]=%d\n",i,ext(i+1,a[i+1].ti-1-ned));
			ans=max(ans,i+ext(i+1ll,a[i+1ll].ti-1ll-ned));
		}
		printf("%lld\n",ans);
	}
	return 0;
}