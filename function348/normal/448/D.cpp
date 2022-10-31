#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
LL n,m,k;
int check(LL mid)
{
	LL x=0;
	for (int i=1;i<=n;i++) x+=min(mid/i,m);
	if (x<k) return 1;else return 0;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	LL l=1,r=n*m,mid=(l+r)>>1;
	while (l<r)
	{
		if (check(mid)) l=mid+1;else r=mid;
		mid=(l+r)>>1;
	}
	printf("%I64d\n",mid);
	return 0;
}