#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000005],bag,t,n,m,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&bag,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		bool flag=true;
		for(int i=1;i<=n-1;i++)
		{
			bag+=a[i]-max(a[i+1]-k,0);
			if(bag<0)
			{
				printf("NO\n");
				flag=false;
				break;
			}
		}
		if(flag) printf("YES\n");
	}
}