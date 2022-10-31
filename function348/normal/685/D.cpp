#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
using namespace std;
typedef pair<int,int> PII;
struct ques{int k,y,x;};
const int N=100010;
int n,k,num;
PII a[N];
int c[N*300],d[N*300];
long long ans[N];
ques q[N*2];
int cmp(ques a,ques b) { return a.y<b.y;}
int find(int x)
{
	int l=1,r=num;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (c[mid]==x) return mid;
		if (c[mid]<x) l=mid+1;else r=mid-1;
	}
	return l;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].FR,&a[i].SC);
	sort(a+1,a+1+n);
	a[n+1].FR=2000000000;
	num=0;
	for (int i=1;i<=n;i++) 
	for (int j=a[i].FR;j<a[i].FR+k&&j<a[i+1].FR;j++)
		c[++num]=j;
	for (int i=1;i<=n;i++)
	{
		q[i*2-1]=(ques){ 1,a[i].SC,a[i].FR};
		q[i*2  ]=(ques){-1,a[i].SC+k,a[i].FR};
	}
	sort(q+1,q+1+n*2,cmp);
	for (int i=1;i<=n*2;i++)
	{
		int p=find(q[i].x);
		for (int j=p;j<p+k;j++) 
		{
			ans[d[j]]+=q[i].y;
			d[j]+=q[i].k;
			ans[d[j]]-=q[i].y;
		}
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}