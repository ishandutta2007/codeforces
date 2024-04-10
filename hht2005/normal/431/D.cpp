#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
ll C[70][70],m;
ll calc(ll n) {
	int cnt=0;
	ll sum=0;
	for(int i=60;i>=0&&cnt<=k;i--) {
		if(!(n>>i&1))continue;
		sum+=C[i][k-cnt];
		cnt++;
	}
	return sum;
}
signed main() {
	C[0][0]=1;
	for(int i=1;i<=60;i++) {
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	scanf("%lld%d",&m,&k);
	ll l=1,r=1e18;
	while(l<=r) {
		ll mid=(l+r)>>1;
		if(calc(2*mid)-calc(mid)>=m)r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r+1);
	return 0;
}