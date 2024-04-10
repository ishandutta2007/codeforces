#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1000000007,maxn=200005;
int n,T,t1[maxn*2],t2[maxn*2],a[maxn*2];
int *p1=t1+maxn, *p2=t2+maxn;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==2) a[i]=-1;
			sum+=a[i];
		}
		for(int i=-2e5;i<=2e5;i++)
		{
			p1[i]=INF;
			p2[i]=INF;
		}
		p1[0]=p2[0]=0;
		int now1=0,now2=0;
		for(int i=1;i<=n;i++)
		{
			now1+=a[n+i];
			now2+=a[n-i+1];
			p1[now1]=min(p1[now1],i);
			p2[now2]=min(p2[now2],i);
		}
		int ans=INF;
		for(int i=-2e5;i<=2e5;i++)
		{
			if(-2e5<=sum-i && sum-i<=2e5)
				ans=min(ans,p1[i]+p2[sum-i]);
		}
		printf("%d\n",ans);
	}
}