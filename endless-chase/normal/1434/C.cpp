#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test;
long long a,b,c,d,l,r,mid,p1,p2,n1,n2,tt,ans; 
bool can(long long x)
{
	long long cur;
	if (x<=p2) cur=x*d;
	else cur=p2*n2+p1*n1;
	return (cur<a);
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (a>b*c)
		{
			printf("-1\n");
			continue;
		}
		tt=min(c/d,a/(b*d));
		ans=a*(tt+1)-d*b*tt*(tt+1)/2;
		printf("%lld\n",ans);
	}
	return Accepted;
}