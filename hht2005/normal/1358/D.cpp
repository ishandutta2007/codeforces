#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4e5+10;
int d[maxn],sum[maxn];
long long sumw[maxn],ans;
signed main() {
	int n,x;
	scanf("%lld%lld",&n,&x);
	for(int i=1;i<=n;i++)scanf("%lld",d+i);
	for(int i=1;i<=n;i++)d[i+n]=d[i];
	for(int i=1;i<=2*n;i++)sum[i]=sum[i-1]+d[i],sumw[i]=sumw[i-1]+1ll*d[i]*(d[i]+1)/2;
	for(int i=1;i<=n;i++) {
		int L=i,R=2*n-1;
		while(L<=R) {
			int mid=(L+R)>>1;
			if(sum[mid]-sum[i]+1<=x)L=mid+1;
			else R=mid-1;
		}
		int t=(x-(sum[L-1]-sum[i]+1));
		ans=max(ans,sumw[L-1]-sumw[i]+d[i]+1ll*t*(t+1)/2);
	}
	for(int i=n+1;i<=2*n;i++) {
		int L=1,R=i+1;
		while(L<=R) {
			int mid=(L+R)>>1;
			if(sum[i]-sum[mid-1]<=x)R=mid-1;
			else L=mid+1;
		}
		int t=(x-(sum[i]-sum[R]));
		ans=max(ans,sumw[i]-sumw[R]+1ll*t*(d[R]+d[R]-t+1)/2);
	}
	printf("%lld\n",ans);
	return 0;
}