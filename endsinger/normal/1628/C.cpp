#include<bits/stdc++.h>
using namespace std;
const int N=1005,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,a[N][N],c[N][N],s;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			c[i][j]=0;
	s=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int v=0;
			for(int d=0;d<4;d++)
			{
				int ki=i+dx[d],kj=j+dy[d];
				v^=c[ki][kj];
			}
			c[i+1][j]=!(v&1);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(c[i][j])
				s^=a[i][j];
	printf("%d\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}