#include<cstdio>
#include<iostream>
#include<algorithm>
#define xx first
#define yy second
using namespace std;
int n;
pair<int,int> a[10000];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].xx,&a[i].yy);
	sort(a+1,a+1+n);
	int now=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i].yy<now) { now=a[i].xx;continue;}
		else now=min(a[i].xx,a[i].yy);
	}
	printf("%d\n",now);
	return 0;
}