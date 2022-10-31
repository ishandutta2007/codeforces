#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=150010;
int n,m,h;
int a[N],b[N];
int t[N*4],tag[N*4];
void build(int i,int l,int r)
{
	if (l==r)
	{
		tag[i]=0;
		if (l>0) t[i]=l-m-1;
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	t[i]=min(t[i*2],t[i*2+1])+tag[i];
}
void change(int i,int l,int r,int rr,int d)
{
	if (r<=rr)
	{
		tag[i]+=d;
		t[i]+=d;
		return;
	}
	int mid=(l+r)>>1;
	change(i*2,l,mid,rr,d);
	if (rr>mid) change(i*2+1,mid+1,r,rr,d);
	t[i]=min(t[i*2],t[i*2+1])+tag[i];
}
int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+1+m,greater<int>());
	for (int i=1;i<=m;i++) b[i]=max(h-b[i],1);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,0,m);
	for (int i=1;i<=n;i++) 
	{
		int l=0,r=m;
		while (l<r)
		{
			int mid=(l+r+1)>>1;
			if (b[mid]<=a[i]) l=mid;else r=mid-1;
		}
		a[i]=l;
	}
	for (int i=1;i<=m-1;i++) change(1,0,m,a[i],1);
	int cnt=0;
	for (int i=m;i<=n;i++)
	{
		change(1,0,m,a[i],1);
		if (t[1]>=0) cnt++;
		change(1,0,m,a[i-m+1],-1);
	}
	printf("%d\n",cnt);
	return 0;
}