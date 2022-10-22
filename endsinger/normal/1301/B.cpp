#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,a[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ans=0,mi=1e9+1,mx=-1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1)
			{
				if(i!=1&&a[i-1]!=-1) mi=min(mi,a[i-1]),mx=max(mx,a[i-1]);
				if(i!=n&&a[i+1]!=-1) mi=min(mi,a[i+1]),mx=max(mx,a[i+1]);
			}
			else
			{
				if(i!=1&&a[i-1]!=-1)
					ans=max(ans,abs(a[i]-a[i-1]));
			}
		}
		if(mx==-1)
		{
			puts("0 0");
			continue;
		}
		int k=(mi+mx)/2;
		ans=max(ans,mx-k);
		ans=max(ans,k-mi);
		printf("%d %d\n",ans,k);
	}
	return 0;
}