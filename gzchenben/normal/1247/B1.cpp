#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,k,d,a[200005],cnt[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d%d",&n,&k,&d);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
		}
		int now=0,ans=1e9;
		for(int i=1;i<=d;i++)
		{
			if(cnt[a[i]]==0) now++;
			cnt[a[i]]++;
		}
		for(int i=1;i<=n-d+1;i++)
		{
			ans=min(ans,now);
			if(cnt[a[i]]==1) now--;
			cnt[a[i]]--;
			if(cnt[a[i+d]]==0) now++;
			cnt[a[i+d]]++;
		}
		printf("%d\n",ans);
		for(int i=n-d;i<=n+1;i++)
		{
			cnt[a[i]]=0;
		}
	}
}