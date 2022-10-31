#include<cstdio>
#include<iostream>
#include<map>
#define MP make_pair
using namespace std;
const int N=13,mo=1000000007;
int n,m,k,ans;
int a[N][N],c[N][N];
int v[N],d[N];
int xx[1<<N];
int dfs(int i,int j)
{
	if (j==m+1) i++,j=1;
	if (i==n+1) return 1;
	c[i][j]=c[i][j-1]|c[i-1][j];
	int t=(1<<k)-1-c[i][j];
	if (a[i][j]!=0)
	{
		if (t&(1<<(a[i][j]-1)))
		{
			c[i][j]^=1<<(a[i][j]-1);
			return dfs(i,j+1);
		}
		return 0;
	}
	int tmp=-1,ans=0;
	for (int ii;t;t-=ii)
	{
		ii=t&-t;
	
		c[i][j]^=ii;
		int jj=xx[ii]+1;
		d[jj]++;
		if (d[jj]==1)
		{
			if (tmp==-1) tmp=dfs(i,j+1);
			ans+=tmp;
			if (ans>=mo) ans-=mo;
		}
		else
		{
			ans+=dfs(i,j+1);
			if (ans>=mo) ans-=mo;
		}
		d[jj]--;
		c[i][j]^=ii;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if (n+m-1>k) { printf("0\n");return 0;}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		d[a[i][j]]++;
	for (int i=0;i<k;i++) xx[1<<i]=i;
	printf("%d\n",dfs(1,1));
	return 0;
}