#include <bits/stdc++.h>

int n,a[1000005];

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	int ans = std::min(n,2);
	int len = 0;
	for (int i = 3; i <= n; ++ i) {
		if (a[i] == a[i-1] + a[i-2]) len ++;
		else len = 0 ;
		ans = std::max(ans,len+2);
	} printf("%d",ans);
	return 0;
}