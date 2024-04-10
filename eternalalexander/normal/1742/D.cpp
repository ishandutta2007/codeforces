#include <bits/stdc++.h>

int n,max[1005],a;

void solve() {
	int ans = -1;
	scanf("%d",&n);
	for (int i = 1; i <= 1000; ++ i) max[i] = 0;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a);
		max[a] = i;
	} 
	for (int i = 1; i <= 1000; ++ i) 
	for (int j = i; j <= 1000; ++ j) {
		if (max[i] && max[j]) {
			if (std::__gcd(i,j) == 1) ans = std::max(ans,max[i] + max[j]);
		}
	}
	printf("%d\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}