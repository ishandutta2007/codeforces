#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];
int main() {
	int T,n;
	long long k;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",a+i);
		long long g=0;
		for(int i=2;i<=n;i++)
			g=__gcd(g,abs(a[i]-a[i-1]));
		if((k-a[1])%g)puts("NO");
		else puts("YES");
	}
	return 0;
}