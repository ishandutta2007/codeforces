#include<cstdio>
#include<iostream>
using namespace std;
const int N=510;
int n,k,ans,now,m,cnt;
int v[N][N],a[N][N],c[N][N],w[N*N],s[N*N];
void ch(int i,int j)
{
	if (i==0||i>n||j==0||j>n) return;
	if (a[i][j]==1) return;
//	printf("%d %d\n",i,j);
	if (v[i][j])
	{
		w[a[i][j]]--;
		if (w[a[i][j]]==0) now-=s[a[i][j]];
	}
	else
	{
		if (w[a[i][j]]==0) now+=s[a[i][j]];
		w[a[i][j]]++;
	}
	v[i][j]^=1;
}
void dfs(int i,int j)
{
	if (i==0||i>n||j==0||j>n) return;
	a[i][j]=m;cnt++;
	if (!a[i-1][j]) dfs(i-1,j);
	if (!a[i+1][j]) dfs(i+1,j);
	if (!a[i][j-1]) dfs(i,j-1);
	if (!a[i][j+1]) dfs(i,j+1);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		char ch;
		while ((ch=getchar())<=32);
		a[i][j]=ch=='X';
		c[i][j]=c[i][j-1]+a[i][j];
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		c[i][j]+=c[i-1][j];
	m=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (!a[i][j])
	{
		m++;cnt=0;
		dfs(i,j);
		s[m]=cnt;
	}
	for (int i=1;i+k-1<=n;i++)
	{
		for (int ii=i;ii<=i+k-1;ii++)
		for (int jj=1;jj<=k;jj++)
			ch(ii,jj);
		for (int ii=i;ii<=i+k-1;ii++) ch(ii,1+k);
		for (int jj=1;jj<=k;jj++) ch(i+k,jj),ch(i-1,jj);
		for (int j=1;j+k-1<=n;j++)
		{
			int tmp=now+c[i+k-1][j+k-1]-c[i-1][j+k-1]-c[i+k-1][j-1]+c[i-1][j-1];
			ans=max(ans,tmp);
			for (int ii=i;ii<=i+k-1;ii++) ch(ii,j-1),ch(ii,j+k+1);
			ch(i+k,j);ch(i+k,j+k);
			ch(i-1,j);ch(i-1,j+k);
		}
		for (int ii=i;ii<=i+k-1;ii++)
		for (int jj=n-k+2;jj<=n;jj++)
			ch(ii,jj);
		for (int ii=i;ii<=i+k-1;ii++) ch(ii,n-k+1);
		for (int jj=n-k+2;jj<=n;jj++) ch(i-1,jj),ch(i+k,jj);
	}
	printf("%d\n",ans);
	return 0;
}