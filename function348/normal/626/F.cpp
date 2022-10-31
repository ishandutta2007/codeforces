#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=210,M=1010,p=1000000007;
int n,m;
int a[N];
int f[N][N][M];
void add(int &x,int y) { x+=y;if (x>=p) x-=p;}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	f[0][0][m]=1;
	for (int i=0;i<n;i++)
	for (int j=0;j<=n;j++)
	for (int k=0;k<=m;k++)
	if (f[i][j][k]!=0)
	{
		int k2=k-(a[i+1]-a[i])*j;
		if (k2<0) continue;
		add(f[i+1][j  ][k2],1LL*f[i][j][k]*(j+1)%p);
if (j>0)add(f[i+1][j-1][k2],1LL*f[i][j][k]*j%p);
		add(f[i+1][j+1][k2],f[i][j][k]);
	}
	int ans=0;
	for (int k=0;k<=m;k++) add(ans,f[n][0][k]);
	printf("%d\n",ans);
	return 0;
}