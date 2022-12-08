#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn],b[maxn],sum[maxn],f[maxn];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)scanf("%lld",b+i);
	if(k>=2) {
		long long Min=1e16;
		for(int i=1;i<n;i++)Min=min(Min,b[i]);
		printf("%lld\n",max(max(0ll,sum[n]-Min),a[n]-b[n]));
	} else if(k==1) {
		long long Min=b[1];
		for(int i=n;i>=1;i--)f[i]=max(f[i+1],sum[n]-sum[i-1]-b[i]);
		long long Max=f[2]+max(a[1]-b[1],0ll);
		for(int i=2;i<n;i++) {
			Min=min(Min,b[i]);
			Max=max(Max,max(0ll,sum[i]-Min)+f[i+1]);
		}
		for(int i=2;i<=n;i++)
			Max=max(Max,max(sum[n]-a[i]-b[1],0ll)+max(a[i]-b[i],0ll));
		printf("%lld\n",Max);
	} else {
		long long Max=0;
		for(int i=1;i<=n;i++)Max=max(Max,sum[n]-sum[i-1]-b[i]);
		printf("%lld\n",Max);
	}
	return 0;
}