#include<cstdio>
#include<cmath>
using namespace std;
int a[200005],b[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,ans;
		bool flag=false;
		scanf("%d%d",&n,&a[1]);
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(abs(a[i]-a[i-1])>=2)
			{
				flag=true;
				ans=i-1;
			}
		}
		if(flag) printf("YES\n%d %d\n",ans,ans+1);
		else printf("NO\n");
	}
	return 0;
}