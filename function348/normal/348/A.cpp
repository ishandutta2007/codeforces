#include<cstdio>
#include<iostream>
using namespace std;
const int N=100100;
int n;
int a[N];
int check(int mid)
{
	int x=0;
	for (int i=1;i<=n;i++)
	{
		if (x-a[i]>=0) return 1;
		x+=mid-a[i];
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	int l=0,r=2110000010;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),l=max(l,a[i]);
	while (l<r)
	{
		int mid=(0LL+l+r)>>1;
		if (check(mid)) r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}