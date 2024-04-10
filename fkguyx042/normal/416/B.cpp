#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int m,n,a[50005][10],f[50005][10];


int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
	}
	for(int i=1;i<=n;i++)printf("%d ",f[i][m]);
	return 0;
}