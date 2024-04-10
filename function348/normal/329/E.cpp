#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
struct rec {int x,y;};
const int N=100010;
rec a[N];
int n;
int b[N];
int cmp(rec a,rec b) { return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	LL ans=0;
	if (n%2==0)
	{
		int k1,k2,dx,dy,f1=0,f2=0;
		for (int i=1;i<=n;i++) b[i]=a[i].x;
		sort(b+1,b+1+n);
		for (int i=n/2+1;i<=n;i++) ans+=b[i];
		for (int i=1;i<=n/2;i++) ans-=b[i];
		k1=b[n/2+1]-b[n/2];dx=b[n/2+1]+b[n/2];
		for (int i=1;i<=n;i++) b[i]=a[i].y;
		sort(b+1,b+1+n);
		for (int i=n/2+1;i<=n;i++) ans+=b[i];
		for (int i=1;i<=n/2;i++) ans-=b[i];
		k2=b[n/2+1]-b[n/2];dy=b[n/2+1]+b[n/2];
		for (int i=1;i<=n;i++) 
		{
			if (a[i].x*2<=dx&&a[i].y*2<=dy&&(a[i].x*2!=dx||a[i].y*2!=dy)) f1=1;
			if (a[i].x*2< dx&&a[i].y*2> dy) f2=1;
		}
		if (f1&&f2) ans-=min(k1,k2);
		printf("%lld\n",ans*2);
		return 0;
	}
	int m=n/2+1,f=0,dx,dy;
	for (int i=1;i<=n;i++) b[i]=a[i].x;
	sort(b+1,b+1+n);dx=b[m];
	for (int i=1;i<=n;i++) b[i]=a[i].y;
	sort(b+1,b+1+n);dy=b[m];
	for (int i=1;i<=n;i++)
	if (a[i].x==dx&&a[i].y==dy) f=1;
	if (f)
	{
		int k1,k2,dx,dy,f1=0,f2=0;
		for (int i=1;i<=n;i++) b[i]=a[i].x;
		sort(b+1,b+1+n);
		for (int i=m+1;i<=n;i++) ans+=b[i];
		for (int i=1;i<m;i++) ans-=b[i];
		k1=max(b[m-1]-b[m],b[m]-b[m+1]);dx=b[m];
		for (int i=1;i<=n;i++) b[i]=a[i].y;
		sort(b+1,b+1+n);
		for (int i=m+1;i<=n;i++) ans+=b[i];
		for (int i=1;i<m;i++) ans-=b[i];
		k2=max(b[m-1]-b[m],b[m]-b[m+1]);dy=b[m];
		
		for (int i=1;i<=n;i++) 
		{
			if (a[i].x<=dx&&a[i].y<=dy&&(a[i].x!=dx||a[i].y!=dy)) f1=1;
			if (a[i].x< dx&&a[i].y> dy) f2=1;
		}
		if (f1&&f2) ans+=max(k1,k2);
		printf("%lld\n",ans*2);
		return 0;
	}

	for (int i=1;i<=n;i++) b[i]=a[i].x;
	sort(b+1,b+1+n);
	for (int i=m+1;i<=n;i++) ans+=b[i];
	for (int i=1;i<m;i++) ans-=b[i];

	for (int i=1;i<=n;i++) b[i]=a[i].y;
	sort(b+1,b+1+n);
	for (int i=m+1;i<=n;i++) ans+=b[i];
	for (int i=1;i<m;i++) ans-=b[i];
	printf("%lld\n",ans*2);
	return 0;
}