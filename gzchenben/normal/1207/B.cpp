#include<cstdio>
using namespace std;
int n,m,a[55][55],b[55][55],cnt,ans[2505][2];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
			{
				b[i][j]=1;
				b[i+1][j]=1;
				b[i][j+1]=1;
				b[i+1][j+1]=1;
				cnt++;
				ans[cnt][0]=i;
				ans[cnt][1]=j;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}