#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=1000000007;
int a[N][N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=-1;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int r;
		scanf("%d",&r);
		for(int j=1;j<=r;j++)
			a[i][j]=1;
		a[i][r+1]=0; 
	}
	for(int j=1;j<=m;j++)
	{
		int c;
		scanf("%d",&c);
		for(int i=1;i<=c;i++)
		{
			if(a[i][j]==0)
			{
				puts("0");
				return 0;
			}
			a[i][j]=1;
		}
		if(a[c+1][j]==1)
		{
			puts("0");
			return 0;
		}
		a[c+1][j]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==-1)
				ans=ans*2%mod;
	printf("%d\n",ans);
	return 0;
}