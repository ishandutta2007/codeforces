#include <bits/stdc++.h>

using ll = long long;
int t;

int main() {
	scanf("%d",&t);
	while (t--) {
		ll a[10];
		ll ans = 0;
		int rk[15];
		for (int i = 1; i <= 4; ++ i) { scanf("%lld",&a[i]); rk[i] = i; }
		do {
			ll a1 = a[rk[1]], a2 = a[rk[2]], a3 = a[rk[3]], a4 = a[rk[4]];
			ans = std::max(ans,std::min(a1,a2) * std::min(a4,a3));
		} while(std::next_permutation(rk+1,rk+4+1));
		printf("%lld\n",ans);
	}
		
	return 0;
}