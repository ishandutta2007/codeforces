#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int t,n,k,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		bool flag=false;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>k) a[i]=1;
			else if(a[i]==k) a[i]=0;
			else if(a[i]<k) a[i]=-1;
			if(a[i]==0) flag=true;
		}
		if(!flag) 
		{
			printf("no\n");
			continue;
		}
		if(n==1) 
		{
			printf("yes\n");
			continue;
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]>=0 && a[i-1]>=0) 
			{
				flag=false;
				break;
			}
		}
		for(int i=3;i<=n;i++)
		{
			if(a[i]>=0 && a[i-2]>=0)
			{
				flag=false;
				break;
			}
		}
		if(flag) printf("no\n"); 
		else printf("yes\n");
	}
}