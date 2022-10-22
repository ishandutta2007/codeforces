#include<cstdio>
#include<cstring>
using namespace std;
int n,k,t,tot;
bool cnt[200005];
int main()
{
	scanf("%d",&t);
	for(int x=1;x<=t;x++)
	{
		memset(cnt,false,sizeof(cnt));
		tot=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			cnt[x]=true;
		}
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]) tot++;
		}
		if(tot>k) 
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",n*k);
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(cnt[i]) printf("%d ",i);
			}
			for(int i=tot+1;i<=k;i++)
			{
				printf("1 ");
			}
		}
		printf("\n");
	}
}