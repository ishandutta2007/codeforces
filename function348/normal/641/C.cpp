#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000100;
int n,q,d,p;
int a[N];
int main()
{
	scanf("%d%d",&n,&q);
	while (q--)
	{
		int kd,x;
		scanf("%d",&kd);
		if (kd==1)
		{
			scanf("%d",&x);
			d+=x;
			if (d<0) d+=n;
			if (d>=n) d-=n;
		}
		if (kd==2)
		{
			if ((p+d)%2==0) p++;else p--;
		}
	}
	p=(p%n+n)%n;
	for (int i=1;i<=n;i++)
	if ((i+p)%2==0) a[i]=i+p;else a[i]=i-p;
	for (int i=1;i<=n;i++)
	{
		int now=(i-d+n-1)%n+1;
		printf("%d ",(a[now]-1+n)%n+1);
	}
	return 0;
}