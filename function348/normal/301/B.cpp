#include<cstdio>
#include<iostream>
using namespace std;
const int N=110;
int n,d;
int a[N],x[N],y[N],v[N],f[N];
int c[N][N];
int abs(int n) { return n>0?n:-n;}
int check(int mid)
{
	for (int i=1;i<=n;i++) f[i]=-1,v[i]=0;
	f[1]=mid;
	for (int i=1;i<=n;i++)
	{
		int k=0;
		for (int j=1;j<=n;j++)
		if (!v[j]&&(k==0||f[j]>f[k])) k=j;
		v[k]=1;
		for (int j=1;j<=n;j++)
		if (f[k]-c[k][j]>=0)
			f[j]=max(f[j],f[k]-c[k][j]+a[j]);
	}
	return f[n]>=0;
}
int main()
{
	scanf("%d%d",&n,&d);
	for (int i=2;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i!=j)
		c[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*d;
	else c[i][j]=100000000;
	int l=0,r=100000000;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}