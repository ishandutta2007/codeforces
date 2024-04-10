#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
int n;
long long p;
struct point
{
	int x,y;
}a[200001];
inline bool cmp(point a,point b)
{
	return a.x<b.x || a.x==b.x && a.y<b.y;
}
inline bool cmp2(point a,point b)
{
	return a.y<b.y || a.y==b.y && a.x<b.x;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i=j)
	  {
	   for(j=i+1;j<=n && a[j].x==a[i].x;j++);
	   p+=(L)(j-i)*(j-i-1);
	  }
	for(i=1;i<=n;i=j)
	  {
	   for(j=i+1;j<=n && a[j].x==a[i].x && a[j].y==a[i].y;j++);
	   p-=(L)(j-i)*(j-i-1);
	  }
	sort(a+1,a+n+1,cmp2);
	for(i=1;i<=n;i=j)
	  {
	   for(j=i+1;j<=n && a[j].y==a[i].y;j++);
	   p+=(L)(j-i)*(j-i-1);
	  }
	cout<<p/2<<"\n";
	return 0;
}