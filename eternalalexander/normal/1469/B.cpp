#include <bits/stdc++.h>

int n,m,t,a[105],b[105];

int main() {
	int t;scanf("%d",&t);while(t--){
		scanf("%d",&n);
		for (int i = 1; i <= n; ++ i) { scanf("%d",&a[i]); a[i] += a[i-1]; }
		scanf("%d",&m);
		for (int i = 1; i <= m; ++ i) { scanf("%d",&b[i]); b[i] += b[i-1]; }
		int ans = 0;
		for (int i = 0; i <= n; ++ i)
		for (int j = 0; j <= m; ++ j)
			ans = std::max(ans,a[i] + b[j]);
		printf("%d\n",ans);
	} return 0;
}