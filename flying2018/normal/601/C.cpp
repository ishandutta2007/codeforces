#include<iostream>
#include<cstdio>
#include<cstring>
#define N 110
#define M 100010
#define db double
using namespace std;
db f[N][M],g[M];
int s[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int s0=0;
	for(int i=1;i<=n;i++) scanf("%d",&s[i]),s0+=s[i];
	db d=1.0/(m-1);
	f[0][0]=g[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=i*m;j++)
		{
			int lf=max(i-1,j-m),rf=min((i-1)*m,j-1);
			f[i][j]=d*g[rf]-(lf?d*g[lf-1]:0)-(lf<=j-s[i] && j-s[i]<=rf?d*f[i-1][j-s[i]]:0);
		}
		for(int j=1;j<=i*m;j++) g[j]=g[j-1]+f[i][j];
	}
	db ans=0;
	for(int j=n;j<s0;j++) ans+=f[n][j];
	printf("%.10lf",ans*(m-1)+1);
	return 0;
}