#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
#define int long long
int a[maxn],t[maxn];
signed main() {
	int n,k,x,sum=0;
	scanf("%lld%lld%lld",&n,&k,&x);
	int ans=n;
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)t[i]=a[i+1]-a[i];
	sort(t+1,t+n);
	for(int i=1;i<n;i++) {
		if(t[i]<=x) {
			ans--;
			continue;
		}
		sum+=(t[i]-1)/x;
		if(sum<=k)ans--;
	}
	printf("%lld\n",ans);
	return 0;
}