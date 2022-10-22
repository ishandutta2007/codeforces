#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int nax = 100*1000+1;
int n,a[nax];
LL ans;

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n;i++) {
		if(a[i]>a[i-1]) {
			ans+=(LL)(a[i]-a[i-1])*(n-a[i]+1);
		}
		else if(a[i]<a[i-1]) {
			ans+=(LL)a[i]*(a[i-1]-a[i]);
		}
	}
	printf("%lld",ans);
}