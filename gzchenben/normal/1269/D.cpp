#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,a[300005],now[300005],sub;
long long ans,sum;
int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[n-i+1]);
	}
	for(int i=1;i<=n;i++)
	{
		now[i]=now[i-1]+sub;
		sub=-1;
		if((a[i]-now[i])%2 && i!=n)
		{
			sub=0;
			now[i]++;
		}
		if(now[i]==0) sub=0;
//		printf("%d ",now[i]);
	}
//	printf("\n");
	for(int i=1;i<=n;i++)
	{
		ans+=(a[i]-now[i])/2;
		if(i!=n) sum+=now[i];
		if(i==n) sum+=(now[i]+1)/2;
	}
	ans+=sum/2;
	printf("%I64d\n",ans);
	return 0;
}