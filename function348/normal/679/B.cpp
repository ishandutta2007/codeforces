#include<cstdio>
#include<iostream>
typedef long long LL;
using namespace std;
struct rec {LL x,t;};
const int N=1000010;
rec a[N],b[N];
int m;
int get(LL x)
{
	int l=1,r=100000;
	while (l<r)
	{
		int mid=(l+r+1)>>1;
		if (1LL*mid*mid*mid<=x) l=mid;else r=mid-1;
	}
	return l;
}
int main()
{
	int c=0;
	scanf("%lld",&a[1].x);
	a[1].t=0;
	int n=1;
	while (1)
	{
		for (int j=1;j<=n;j++)
		if (a[j].x>0) 
		{
	//		printf("%lld %lld %d\n",a[j].x,a[j].t,c);
			int i=get(a[j].x);
				b[++m]=(rec){a[j].x-1LL*i*i*i,a[j].t+1LL*i*i*i};

			if (i>1)
				b[++m]=(rec){3LL*i*i-3*i,a[j].t+1LL*(i-1)*(i-1)*(i-1)};
		}
		if (m==0) break;
		c++;
		for (int j=1;j<=m;j++) a[j]=b[j];
		n=m;m=0;
	}
	LL t=0;
	for (int i=1;i<=n;i++) t=max(t,a[i].t);
	printf("%d %lld\n",c,t);
	return 0;
}