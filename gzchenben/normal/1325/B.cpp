#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,a[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1]) ans++;
		}
		printf("%d\n",ans+1);
	}
}