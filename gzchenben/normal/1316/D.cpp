#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1005][1005][2],f[1005][1005];
int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
bool vis[1005][1005];
void dfs(int x,int y,int u,int v)
{
	for(int i=1;i<=4;i++)
	{
		if(!vis[x+dx[i]][y+dy[i]] && a[x+dx[i]][y+dy[i]][0]==u && a[x+dx[i]][y+dy[i]][1]==v)
		{
			vis[x+dx[i]][y+dy[i]]=true;
			f[x+dx[i]][y+dy[i]]=((i-1)^1)+1;
			dfs(x+dx[i],y+dy[i],u,v);
		}
	}
}
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d",&a[i][j][0],&a[i][j][1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j][0]==i && a[i][j][1]==j)
			{
				vis[i][j]=true;
				dfs(i,j,i,j);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
//			printf("%d %d\n",i,j);
			if(vis[i][j]) continue;
			if(a[i][j][0]!=-1 || a[i][j][1]!=-1)
			{
				printf("INVALID\n");
				return 0;
			}
			bool flag=false;
			for(int k=1;k<=4;k++)
			{
				if(a[i+dx[k]][j+dy[k]][0]==-1 && a[i+dx[k]][j+dy[k]][1]==-1)
				{
					f[i][j]=k;
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				printf("INVALID\n");
				return 0;
			}
		}
	}
	printf("VALID\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]==0) printf("X");
			if(f[i][j]==1) printf("D");
			if(f[i][j]==2) printf("U");
			if(f[i][j]==3) printf("R");
			if(f[i][j]==4) printf("L");
		}
		printf("\n");
	}
}