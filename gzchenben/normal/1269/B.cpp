#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[2005],b[2005],t[2005],ans=1e9+1;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		int ned=(b[i]-a[1]+m)%m;
		for(int j=1;j<=n;j++) t[j]=(a[j]+ned)%m;
		sort(t+1,t+n+1);
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(t[j]!=b[j]) flag=false;
		}
//		for(int j=1;j<=n;j++) printf("%d ",t[j]);
//		printf("\n");
//		for(int j=1;j<=n;j++) printf("%d ",b[j]);
//		printf("\n");
		if(flag) ans=min(ans,ned);
	}
	printf("%d\n",ans);
	return 0;
}