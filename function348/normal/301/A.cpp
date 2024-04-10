#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2001;
int n,ans;
int a[N];
int abs(int n) { return n>0?n:-n;}
int main()
{
	scanf("%d",&n);
	ans=-1000000000;
	for (int i=1;i<=n*2-1;i++) scanf("%d",&a[i]);
	int f=0,c=0,all=0;
	for (int i=1;i<=n*2-1;i++)
	{
		if (a[i]<0) c++;
		all+=abs(a[i]);
		a[i]=abs(a[i]);
	}
	sort(a+1,a+1+n*2-1);
	if (c%2==1&&n%2==0) all-=2*a[1];
	printf("%d\n",all);
	return 0;
}