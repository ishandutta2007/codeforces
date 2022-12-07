#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,t,c[1005],maxn;
bool vis[1005][1005];
char s[20]; 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&c[i]);
			for(int j=1;j<=c[i];j++)
			{
				int x;
				scanf("%d",&x);
				vis[i][x]=true;
			}
		}
		printf("? %d",n);
		for(int i=1;i<=n;i++)
		{
			printf(" %d",i);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d",&maxn);
		int L=1,R=n;
		while(L<R)
		{
			int mid=(L+R)/2;
			printf("? %d",mid-L+1);
			for(int i=L;i<=mid;i++)
			{
				printf(" %d",i);
			}
			printf("\n");
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x==maxn) R=mid;
			else L=mid+1;
		}
		int tmp=0;
		for(int i=1;i<=k;i++)
		{
			if(!vis[i][L]) continue;
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(!vis[i][j]) cnt++;
			}
			printf("? %d",cnt);
			for(int j=1;j<=n;j++)
			{
				if(!vis[i][j]) printf(" %d",j);
			}
			printf("\n");
			fflush(stdout);
			scanf("%d",&tmp);
		}
		printf("!");
		for(int i=1;i<=k;i++)
		{
			if(!vis[i][L]) printf(" %d",maxn);
			else printf(" %d",tmp);
		}
		printf("\n");
		fflush(stdout);
		scanf("%s",s+1);
	}
}