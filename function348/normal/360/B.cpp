#include<cstdio>
#include<iostream>
using namespace std;
const int N=2010;
int n,m;
int a[N],f[N];
int abs(int n) { return n>0?n:-n;}
int check(int mid)
{
	int ans=n;
	for (int i=1;i<=n;i++)
	{
		f[i]=i-1;
		for (int j=1;j<i;j++)
		if (abs(a[i]-a[j])<=1LL*(i-j)*mid) f[i]=min(f[i],f[j]+i-j-1);
		ans=min(ans,f[i]+n-i);
	}
	return ans<=m;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=0,r=2000000000;
	while (l<r)
	{
		int mid=(0LL+l+r)/2;
		if (check(mid)) r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}