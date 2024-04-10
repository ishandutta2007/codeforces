#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,t,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		int sum=0;
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
//			printf("--\n");
			if(a[i]%x!=0) flag=true;
			sum+=a[i];
		}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		if(sum%x!=0) 
		{
			printf("%d\n",n);
			continue;
		}
		int ans1,ans2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%x==0) continue;
			ans1=n-i;
			break;
		}
		for(int i=n;i>=1;i--)
		{
			if(a[i]%x==0) continue;
			ans2=i-1;
			break;
		}
		printf("%d\n",max(ans1,ans2));
	}
}