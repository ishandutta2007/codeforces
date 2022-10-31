#include<cstdio>
#include<iostream>
using namespace std;
const int N=510;
int n;
int a[N],f[N][N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int j=1;j<=n;j++)
	for (int i=1;i+j-1<=n;i++)
	{
		int k=i+j-1;
		f[i][k]=1000000000;
		if (i==k) { f[i][k]=1;continue;}
		f[i][k]=min(f[i][k],f[i+1][k]+1);
		if (a[i]==a[i+1]) f[i][k]=min(f[i][k],1+f[i+2][k]);
		for (int l=i+2;l<=k;l++)
		if (a[i]==a[l]) f[i][k]=min(f[i][k],f[i+1][l-1]+f[l+1][k]);
	}
	printf("%d\n",f[1][n]);
	return 0;
}