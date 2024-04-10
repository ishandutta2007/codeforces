#include<cstdio>
#include<iostream>
using namespace std;
const int N=300010;
int a[N],c[N];
int n;
int ok(int w)
{
	int x=0;
	for (int i=1;i<=n;i++)
	if (c[i]==1) 
		if (w>=a[i]) w-=a[i],x+=a[i]/10;
		else return 0;
	else if (a[i]<=x) x-=a[i];
	else if (a[i]<=x+w) w-=a[i]-x,x=0;
	else return 0;
	return 1;
}
int check(int w)
{
	int tmp=w;
	for (int i=1;i<=n;i++) c[i]=0;
	for (int i=1;i<=n;i++)
	if (tmp>=a[i]) tmp-=a[i],c[i]=1;
	else
	{
		if (ok(w)) return 1;
		if (tmp>=1000)
		{
			for (int j=i+1;j<=n;j++)
			if (a[j]==1000)
			{
				c[j]=1;
				if (ok(w)) return 1;
				c[j]=0;
				break;
			}
			c[i]=1;
			for (int k=i-1;k>=1;k--)
			if (a[k]==1000)
			{
				c[k]=0;
				if (ok(w)) return 1;
				c[k]=1;
				break;
			}
		}
		return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1000,r=n*2000;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}