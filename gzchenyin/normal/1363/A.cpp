#include<cstdio>
using namespace std;
int n,x,t,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		bool flag=false;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i!=1 && (a[i]+a[i-1])%2==1) flag=true;
			sum=(sum+a[i])%2;
		}
		if(x==n)
		{
			if(sum%2==0) printf("No\n");
			else printf("Yes\n");
			continue;
		}
		if(!flag && x*a[1]%2==0) printf("No\n");
		else printf("Yes\n");
	}
	
}