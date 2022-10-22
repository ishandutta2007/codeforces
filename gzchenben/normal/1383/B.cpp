#include<cstdio>
using namespace std;
int t,n,a[100005];
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
		bool flag=true;
		for(int i=30;i>=0;i--)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if((a[j]>>i)&1) cnt++;
			}
			if(cnt%2==0) continue;
			if(cnt==n) 
			{
				if(n%4==1) printf("WIN\n");
				else printf("LOSE\n");
			}
			else
			{
				if(cnt%4==3 && n%2==1) printf("LOSE\n");
				else printf("WIN\n");
			}
			flag=false;
			break;
		}
		if(flag) printf("DRAW\n");
	}
}