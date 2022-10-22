#include<cstdio>
#include<cstring>
using namespace std;
int n,m,t,a[100005],b[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			char x;
			scanf(" %c",&x);
			a[i]=x-'0';
		} 
		for(int i=1;i<=n;i++)
		{
			char x;
			scanf(" %c",&x);
			b[i]=x-'0';
		} 
		int tmp=a[1];
		int cnt=0;
		for(int i=n;i>=1;i--)
		{
			if(i!=n) 
			{
				if((n-i)%2==0) tmp=a[1+(n-i)/2];
				else tmp=1-a[i+(n-i+1)/2];
			}
			if(tmp==b[i]) cnt++;
			cnt++;
		}
		printf("%d ",cnt); 
		tmp=a[1];
		for(int i=n;i>=1;i--)
		{
			if(i!=n) 
			{
				if((n-i)%2==0) tmp=a[1+(n-i)/2];
				else tmp=1-a[i+(n-i+1)/2];
			}
			if(tmp==b[i]) printf("%d ",1);
			printf("%d ",i);
		}
		printf("\n");
	}
}