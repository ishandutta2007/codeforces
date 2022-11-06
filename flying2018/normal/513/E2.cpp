#include<iostream>
#include<cstdio>
#include<cstring>
#define N 30010
#define M 210
using namespace std;
int f[N][M][4],a[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int _=0;_<4;_++) f[i][j][_]=-100000000;
	for(int i=0;i<=n;i++)
		for(int _=0;_<4;_++) f[i][0][_]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int t=1+(j!=1 && j!=m);
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][3])-t*a[i];
			f[i][j][1]=max(f[i-1][j][1],f[i][j][0]);
			f[i][j][2]=max(f[i-1][j][2],f[i-1][j-1][1])+t*a[i];
			f[i][j][3]=max(f[i-1][j][3],f[i][j][2]);
			if(t==2) f[i][j][1]=max(f[i][j][1],f[i-1][j-1][1]),f[i][j][3]=max(f[i][j][3],f[i-1][j-1][3]);
		}
	printf("%d\n",max(f[n][m][1],f[n][m][3]));
	return 0;
}