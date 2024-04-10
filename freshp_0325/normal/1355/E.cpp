#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a,b,m,h[100005];
LL calc(LL x) {
	LL p=0,q=0;
	for(LL i=1; i<=n; ++i) {
		if(h[i]>=x)	p+=h[i]-x;
		else	q+=x-h[i];
	}
	return q*a+p*b+min(p,q)*min(0ll,m-a-b);
}
int main() {
	scanf("%lld %lld %lld %lld",&n,&a,&b,&m);
	for(LL i=1; i<=n; ++i)	scanf("%lld",&h[i]);
	m=min(a+b,m);
	LL l=0,r=1e9,ans=1e18;
	while(l<=r) {
		LL mid1=l+(r-l)/3,mid2=l+(r-l)/3*2,ans1=calc(mid1),ans2=calc(mid2);
		ans=min(ans,min(ans1,ans2));
		if(ans1<ans2)	r=mid2-1;
		else	l=mid1+1;
	}
	printf("%lld",ans);
	return 0;
}