#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n,s1,s2;
int a[N],b[N][20],c[N][20];
int nxt[N],xx[N];
int abs(int n) { return n>0?n:-n;}
int q1(int l,int r)
{
	int k=xx[r-l+1];
	return max(c[l][k],c[r-(1<<k)+1][k]);
}
int q2(int l,int r)
{
	int k=xx[r-l+1];
	return min(b[l][k],b[r-(1<<k)+1][k]);
}
int check(int u)
{
	for (int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while (l<r)
		{
			int mid=(l+r+1)>>1;
			if (q1(i,mid)<=a[i]+u&&q2(i,mid)>=a[i]-u) l=mid;else r=mid-1;
		}
		nxt[i]=l;
	}
	int k=0,last=0;
	for (int i=1;i<=n;i++) if (abs(a[i]-s1)<=u) k=i;else break;
	for (int i=1;i<=n;i++) if (abs(a[i]-s2)<=u) k=max(k,i);else break;
	while (1)
	{
		int t=0;
		for (int i=last+1;i<=k;i++) t=max(t,nxt[i]);
		if (t==n) return 1;
		if (k==t) return 0;
		last=k,k=t;
	}
}
int main()
{
	scanf("%d%d%d",&n,&s1,&s2);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[i][0]=c[i][0]=a[i];
	for (int i=2;i<=n;i++) xx[i]=xx[i/2]+1;
	for (int j=1;j<=18;j++)
	for (int i=1;i+(1<<j)-1<=n;i++)
	{
		b[i][j]=min(b[i][j-1],b[i+(1<<(j-1))][j-1]);
		c[i][j]=max(c[i][j-1],c[i+(1<<(j-1))][j-1]);
	}
	int l=abs(s1-s2),r=1000000000;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}