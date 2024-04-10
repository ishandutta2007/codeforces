#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=200010;
int n,num;
int a[N],p[N];
LL b[N];
double ans;
int main()
{
//	freopen("data.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);ans=-1;
	for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	
	for (int i=1;i<=n;i++)
	{
		int l=0,r=min(i-1,n-i);
		if (a[i]==a[i+1]) continue;
		int median=a[i];
		while (l<r)
		{
			int mid=(l+r+1)>>1;
			mid--;
			LL a1=b[n]-b[n-mid]+b[i]-b[i-mid-1],b1=2*mid+1;
			mid++;
			LL a2=b[n]-b[n-mid]+b[i]-b[i-mid-1],b2=2*mid+1;
			if (a1*b2<a2*b1) l=mid;else r=mid-1;
		}
		double aver=1.0*(b[n]-b[n-l]+b[i]-b[i-l-1])/(2*l+1);
		if (ans<aver-median)
		{
			ans=aver-median;num=0;
			for (int j=i-l;j<=i;j++) p[++num]=a[j];
			for (int j=n-l+1;j<=n;j++) p[++num]=a[j];
		}
	}
	for (int i=1;i<n;i++)
	{
		if (a[i]==a[i+1]&&a[i+1]==a[i+2]) continue;
		int l=0,r=min(i-1,n-i-1);
		double median=1.0*(a[i]+a[i+1])/2;
		while (l<r)
		{
			int mid=(l+r+1)>>1;
			mid--;
			LL a1=b[n]-b[n-mid]+b[i+1]-b[i-mid-1],b1=2*mid+2;
			mid++;
			LL a2=b[n]-b[n-mid]+b[i+1]-b[i-mid-1],b2=2*mid+2;
			if (a1*b2<a2*b1) l=mid;else r=mid-1;
		}
		double aver=1.0*(b[n]-b[n-l]+b[i+1]-b[i-l-1])/(2*l+2);
		if (ans<aver-median)
		{
			ans=aver-median;num=0;
			for (int j=i-l;j<=i+1;j++) p[++num]=a[j];
			for (int j=n-l+1;j<=n;j++) p[++num]=a[j];
		}
	}
	printf("%d\n",num);
	for (int i=1;i<=num;i++) printf("%d ",p[i]);
	return 0;
}