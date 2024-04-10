#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=100010;
int n,m;
LL a[N],b[N];
LL abs(LL n) { return n>0?n:-n;}
int check(LL x)
{
	int j=1;
	for (int i=1;i<=n;i++)
	{
		int k=j;
		while (min(abs(a[i]-b[j]),abs(a[i]-b[k]))+abs(b[j]-b[k])<=x&&k<=m) k++;
		j=k;
		if (j>m) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=m;i++) scanf("%lld",&b[i]);
	LL l=0,r=20000000000LL;
	while (l<r)
	{
		LL mid=(l+r)>>1;
		if (check(mid)) r=mid;else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}