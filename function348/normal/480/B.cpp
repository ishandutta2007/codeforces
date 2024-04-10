#include<cstdio>
#include<iostream>
#include<algorithm>
#define xx first
#define yy second
using namespace std;
const int N=100010;
int n,l,x,y;
int d[N];
int check(int p)
{
	for (int i=1,j=1;i<=n;i++)
	{
		while (d[i]-d[j]>p) j++;
		if (d[i]-d[j]==p) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d%d%d",&n,&l,&x,&y);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	int x1=check(x),x2=check(y);
	if (x1&&x2) { printf("0\n");return 0;}
	if (x1)
	{
		printf("%d\n%d\n",1,y);return 0;
	}
	if (x2)
	{
		printf("%d\n%d\n",1,x);return 0;
	}
	int p;
	p=y+x;
	for (int i=1,j=1;i<=n;i++)
	{
		while (d[i]-d[j]>p) j++;
		if (d[i]-d[j]==p) { printf("%d\n%d\n",1,d[j]+x);return 0;}
	}
	
	p=y-x;
	for (int i=1,j=1;i<=n;i++)
	{
		while (d[i]-d[j]>p) j++;
		if (d[i]-d[j]==p&&d[j]>x) { printf("%d\n%d\n",1,d[j]-x);return 0;}
		if (d[i]-d[j]==p&&d[i]+x<=l) { printf("%d\n%d\n",1,d[i]+x);return 0;}
	}
	printf("%d\n%d %d\n",2,x,y);
	return 0;
}