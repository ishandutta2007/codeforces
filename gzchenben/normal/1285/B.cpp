#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[100005];
long long sum,now,minn,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		bool flag=false;
		scanf("%d",&n);
		ans=now=sum=0;
		minn=1e15+1ll;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			now+=a[i];
			ans=max(ans,now-minn);
			minn=min(minn,now);
			if(i!=n && now>=sum) flag=true;
		}
//		printf("%d %d\n",ans,sum);
		if(sum>ans && !flag) printf("YES\n");
		else printf("NO\n");
	}
}