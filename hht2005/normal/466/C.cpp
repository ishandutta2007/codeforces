#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6;
int a[maxn];
signed main() {
	int n,sum=0,t=0;
	long long ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		sum+=a[i];
	}
	if(sum%3) {
		puts("0");
		return 0;
	}
	sum/=3;
	int Sum=0;
	for(int i=1;i<n;i++) {
		Sum+=a[i];
		if(Sum==sum*2)ans+=t;
		if(Sum==sum)t++;
	}
	printf("%lld\n",ans);
	return 0;
}