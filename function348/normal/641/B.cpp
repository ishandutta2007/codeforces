#include<cstdio>
#include<iostream>
using namespace std;
const int N=10010;
int n,m,q;
int kd[N],x[N],y[N],z[N];
int a[110][110];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&kd[i]);
		if (kd[i]<3) scanf("%d",&x[i]);
		else scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	for (int i=q;i>=1;i--)
	if (kd[i]==1)
	{
		int tmp=a[x[i]][m];
		for (int j=m;j>=1;j--) a[x[i]][j]=a[x[i]][j-1];
		a[x[i]][1]=tmp;
	}
	else if (kd[i]==2)
	{
		int tmp=a[n][x[i]];
		for (int j=n;j>=1;j--) a[j][x[i]]=a[j-1][x[i]];
		a[1][x[i]]=tmp;
	}
	else if (kd[i]==3)
		a[x[i]][y[i]]=z[i];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		printf("%d%c",a[i][j],j<m?' ':'\n');
	return 0;
}