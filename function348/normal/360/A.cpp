#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
struct rec {int kd,l,r,p;};
int n,m;
rec q[N];
int a[N],d[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) a[i]=500000000;
	for (int i=1;i<=m;i++) scanf("%d%d%d%d",&q[i].kd,&q[i].l,&q[i].r,&q[i].p);
	for (int i=1;i<=m;i++)
	if (q[i].kd==1)
	for (int j=q[i].l;j<=q[i].r;j++)
		d[j]+=q[i].p;
	else
	for (int j=q[i].l;j<=q[i].r;j++)
		a[j]=min(a[j],q[i].p-d[j]);
	int f=1;
	for (int i=1;i<=n;i++) d[i]=0;
	for (int i=1;i<=m;i++)
	if (q[i].kd==1) 
	for (int j=q[i].l;j<=q[i].r;j++)
		d[j]+=q[i].p;
	else
	{
		int mx=-500000000;
		for (int j=q[i].l;j<=q[i].r;j++)
			mx=max(mx,a[j]+d[j]);
		if (mx!=q[i].p) f=0;
	}
	if (f) 
	{
		printf("YES\n");
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
	}
	else printf("NO\n");
	return 0;
}