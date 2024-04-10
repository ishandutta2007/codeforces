#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,T;
char a[15][10];
bool vis[15];
bool eq(int x,int y)
{
	for(int i=1;i<=4;i++)
	{
		if(a[x][i]!=a[y][i]) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(vis,false,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=4;j++)
			{
				scanf(" %c",&a[i][j]);
				if(j==1) vis[a[i][1]-'0']=true;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bool flag=false;
			for(int j=1;j<i;j++)
			{
				if(eq(i,j)) 
				{
					ans++;
					flag=true;
					break;
				}
			}
			if(!flag) continue;
			for(int j=0;j<=9;j++)
			{
				if(!vis[j]) 
				{
					vis[j]=true;
					a[i][1]=j+'0';
					break;
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			printf("%c%c%c%c\n",a[i][1],a[i][2],a[i][3],a[i][4]);
		}
	}
	return 0;
}