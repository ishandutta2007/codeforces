#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int d[maxn];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		long long ans=0,sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",d+i);
		sort(d+1,d+n+1);
		for(int i=2;i<=n;i++) {
			ans+=1ll*d[i]*(i-1)-sum;
			sum+=d[i];
		}
		ans-=d[n];
		printf("%lld\n",-ans);
	}
	return 0;
}