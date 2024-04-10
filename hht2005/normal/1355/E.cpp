#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,r,m,h[100010];
int calc(int H) {
	int A=0,R=0,ans=0;
	for(int i=1;i<=n;i++)
		if(h[i]<H)A+=H-h[i];
		else R+=h[i]-H;
	ans+=min(A,R)*m;
	if(A>R)ans+=(A-R)*a;
	if(R>A)ans+=(R-A)*r;
	return ans;
}
signed main() {
	scanf("%lld%lld%lld%lld",&n,&a,&r,&m);
	m=min(m,a+r);
	for(int i=1;i<=n;i++)scanf("%lld",h+i);
	int L=0,R=1e9;
	while(L<=R) {
		int mid=(L+R)>>1;
		if(calc(mid)>calc(mid+1))L=mid+1;
		else R=mid-1;
	}
	printf("%lld\n",calc(L));
	return 0;
}