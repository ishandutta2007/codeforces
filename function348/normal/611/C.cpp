#include<cstdio>
#include<iostream>
using namespace std;
const int N=510;
int n,m,ans,q;
int a[N][N],b[N][N],c[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		char ch;
		while ((ch=getchar())<=32);
		if (ch=='.') a[i][j]=1;else a[i][j]=0;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		if (a[i][j]&&a[i][j-1]) b[i][j]=1;else b[i][j]=0;
		if (a[i][j]&&a[i-1][j]) c[i][j]=1;else c[i][j]=0;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		b[i][j]+=b[i][j-1],c[i][j]+=c[i][j-1];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		b[i][j]+=b[i-1][j],c[i][j]+=c[i-1][j];
	scanf("%d",&q);
	while (q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=b[x2][y2]-b[x2][y1]-b[x1-1][y2]+b[x1-1][y1];
		ans+=c[x2][y2]-c[x2][y1-1]-c[x1][y2]+c[x1][y1-1];
		printf("%d\n",ans);
	}
	return 0;
}